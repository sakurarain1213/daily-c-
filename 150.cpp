#include <bits/stdc++.h>
using namespace std ;
//大数运算的类模板实现  官方实现

typedef long long LL;

class BigInteger {
 public:  char arr[1000];
 char sign;
 int length;

 void Init(){
memset(arr, 0, sizeof(arr));
 sign = 0;
 length = 0;
 }

 BigInteger(){
22 Init();
23 }
24
25 BigInteger(string num){
26 *this = num;
27 }
28 BigInteger(int num){
29 *this = num;
30 }
31
32 BigInteger(LL num){
33 *this = num;
34 }
35
36 void print(){
37 if(length <= 0) {
38 cout<<0<<endl;
39 return;
40 }
41 if(sign == 1)
42 printf("-");
43 for(int i = length - 1; i >= 0; i--)
44 printf("%d",arr[i]);
45 cout<<endl;
46 }
47
48 BigInteger operator = (int num){
49 *this = (LL) num;
50 }
51
52
53 BigInteger operator = (LL n){
54 Init();
55 int num = n;
56 if(num < 0) {
57 sign = 1;
58 num = -num;
59 }
60 int index = 0;
61 while(num != 0){
62 arr[index++] = num % 10;
63 length++;
64 num/= 10;
65 }
66 return *this;
67 }
68
69 BigInteger operator = (BigInteger num){
70 Init();
71 sign = num.sign;
72 length = num.length;
73 for(int i = 0; i < length; i++)
74 arr[i] = num.arr[i];
75 return *this;
76 }
77
78 BigInteger operator = (string num){
79 Init();
80 sign = num[0] == '-'? 1: 0;
81 if(sign) num.erase(0, 1);
82 int len = num.length();
83 for (int i = len - 1; i >= 0; i--)
84 arr[i] = num[len - i -1] - '0';
85 length = len;
86 return *this;
87 }
88
89
90 bool operator == (BigInteger num){
91 if(length == 0 && num.length == 0)

return true;
93 if(sign != num.sign || length != num.length)
94 return false;
95 for(int i = 0; i < length; i++)
96 if(arr[i] != num.arr[i])
97 return false;
98 return true;
99 }
100
101 bool operator == (LL num){
102 return *this == BigInteger(num);
103 }
104
105 bool operator != (BigInteger num){
106 return !(*this == num);
107 }
108
109 bool operator < (BigInteger num){
110 if(sign == 1 && num.sign == 0)
111 return true;
112 else if(sign == 0 && num.sign == 1)
113 return false;
114 else if(length < num.length)
115 return !sign;
116 else if(length > num.length)
117 return sign;
118 for(int i = length - 1; i >= 0; i--)
119 if(arr[i] < num.arr[i])
120 return !sign;
121 else if(arr[i] > num.arr[i])
122 return sign;
123 return false;
124 }
125
126 bool operator > (BigInteger num){
127 return num < *this;
128 }
129
130 bool operator >= (BigInteger num){
131 return *this > num || *this == num;
132 }
133
134 bool operator <= (BigInteger num){
135 return *this < num || *this == num;
136 }
137
138 BigInteger operator << (int num){
139 BigInteger tmp = *this;
140 for(int i = tmp.length-1; i>= 0; i--)
141 tmp.arr[i+num] = tmp.arr[i];
142 for(int i = 0; i < num; i++)
143 tmp.arr[i] = 0;
144 tmp.length += num;
145 return tmp;
146 }
147
148 BigInteger operator >> (int num){
149 BigInteger tmp = *this;
150 for(int i = num; i < tmp.length; i++)
151 tmp.arr[i-num] = tmp.arr[i];
152 tmp.length-= num;
153 return tmp;
154 }
155
156 BigInteger operator - (){
157 BigInteger tmp = *this;
158 tmp.sign = !tmp.sign;
159 return tmp;
160 }
161
162 BigInteger operator + (){
163 BigInteger tmp = *this;
164 return tmp;
165 }
166
167 BigInteger operator + (BigInteger num){
168 if(num.sign)
169 return *this - (-num);
170 else if(sign)
171 return -((-*this) - num);
172
173 BigInteger tmp;
174 int len = max(length, num.length);
175 for(int i = 0; i < len; i++) {
176 int n = arr[i] + num.arr[i] + tmp.arr[i];
177 tmp.arr[i] = n % 10;
178 tmp.arr[i+1] = n / 10;
179 }
180 tmp.length = len + 1;
181 while(!tmp.arr[tmp.length-1])
182 tmp.length--;

return tmp;
184 }
185 BigInteger operator - (BigInteger num){
186 if(sign)
187 return -((-*this) + num);
188 else if(num.sign)
189 return *this + (-num);
190 else if(*this < num)
191 return -(num - *this);
192
193 BigInteger tmp = *this;
194 for(int i = 0; i < length; i++){
195 if(tmp.arr[i] < num.arr[i]){
196 tmp.arr[i+1]--;
197 tmp.arr[i] += 10;
198 }
199 tmp.arr[i] -= num.arr[i];
200 }
201 while(tmp.length && !tmp.arr[tmp.length-1])
202 tmp.length--;
203 return tmp;
204 }
205
206 BigInteger muiltiplyBelowTen(int num){
207 if(num == 0)
208 return 0;
209 BigInteger res;
210 for(int i = 0; i < length; i++){
211 int n = arr[i] * num + res.arr[i];
212 res.arr[i] = n % 10;
213 res.arr[i+1] = n / 10;
214 }
215 res.length = length;
216 if(res.arr[res.length])
217 res.length++;
218 return res;
219 }
220
221 BigInteger operator * (BigInteger num){
222 if(*this == 0)
223 return 0;
224 else if(sign)
225 return -((-*this)*num);
226 else if(num.sign)
227 return -(*this*(-num));
228 BigInteger res;
229 for(int i = 0; i < num.length; i++)
230 res = res + (muiltiplyBelowTen(num.arr[i])<<i);
231 return res;
232 }
233
234 BigInteger operator / (BigInteger num){
235 if(*this == 0)
236 return 0;
237 else if(sign)
238 return -((-*this)/num);
239 else if(num.sign)
240 return -(*this/(-num));
241 BigInteger res, tmp = *this;
242 for(int i = tmp.length - num.length; i >= 0; i--)
243 for(int j = 9; j > 0; j--)
244 if((tmp - ((num<<i) * j)) >= 0){
245 res.arr[i] = j;
246 tmp = (tmp - ((num<<i) * j));
247 if(!res.length)
248 res.length = i+1;
249 break;
250 }
251
252
253 return res;
254 }
255 };
256

 int main(void){


 string s1, s2;
 char type;
 cin>>s1>>s2>>type;
 BigInteger a(s1);
 BigInteger b(s2);
BigInteger res;
 switch (type){
 case '+': 269 res = a+b;
 break;
case '-':
 res = a-b;
 break;

case '*':
 res = a*b;
 break;
 case '/': 278 if(b != 1)
 res=a/b;
 else
 res=a;
 break;
 default: 284 break;
 }
 res.print();
 }


