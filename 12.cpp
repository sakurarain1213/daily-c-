#include <bits/stdc++.h>
using namespace std;
 // 等待debug 

// 高精度的幂次函数实现  即cout << pow(1+x,n);
const int MAXN = 3e4+4; 
char s1[MAXN] , s2[MAXN] ,tmp[MAXN] ;
static int a[MAXN] , b[MAXN] ,c[MAXN] ;


 string dachengfa(string s,unsigned long long int n)
{
 string temp,ans;
    temp=s;
  for (unsigned long long int i=1;i<n;i++)
  {
 int la = temp.length();int lb =s.length();
   memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
    for (int i=0; i<la; i++) 
    {a[i] = temp[la-i-1] - '0'; }
    for (int i=0; i<lb; i++) 
    {  b[i] = s[lb-i-1] - '0';}

    for (long long int i=0; i<la; i++) 
    {
         for (int j=0; j<lb; j++) 
          {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]= c[i+j]/10;
             c[i+j]%=10;
          }
    }
long long int x=la+lb;
while (c[x]==0&&x>0) x--;
temp="";//s3即结果先清零
 for ( int i=x;i>=0; i--) 
 temp+=(c[i]+'0');//字符串末尾添加字符
 }
ans=temp;
return ans;
}
  

int main() {

unsigned long long int x,n;cin >>x>>n;
string s;

s=to_string(x+1);//数字转字符串
cout << dachengfa(s,n);
    return 0;
}