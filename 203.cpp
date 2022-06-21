#include <bits/stdc++.h>

using namespace std;

int num(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
      return s[i];//有一个强制类型转换 但是只要比大小就行 所以直接return
    }
    return -1;
}

struct p
{
    string s;
    int v;//优先级 没有数字就是-1
}; //不用数组 可以利用vector

bool cmp(p a,p b)//结构体比较
{
   if(a.v!=b.v) return a.v<b.v;
   else return a.s<b.s;//字符串直接比较
}

void f(int x)
{
vector <p> a;
int n;string t;p temp;
cin>>n;
while(n--)
{
cin>>t;
temp.s=t;temp.v=num(t);
a.push_back(temp);
}
sort(a.begin(),a.end(),cmp);

 cout<<"case #"<<x<<":\n";
for(int i=0;i<a.size();i++)
{
    cout<<a[i].s<<' ';
}
cout<<"\n";

}
int main()
{
int T;
cin>>T;
for(int i=0;i<T;i++)
{f(i);}
 return 0;
}  

/* 
10
1
string
2
st123 ring
3
0 1 A
30
a 1 2 3 4 5 6 7 8 q w e r t y u i o p l k j h g f d s a z x
14
a0 a1 a10 10a 1a 0a strange string sort01 sort1 A0 A10 B10 b10
50
program01 program02 program03 program?? programC programC# programC++ programC00x 01 02 program01 program02 program03 program?? programC programC# programC++ programC00x 01 02 program01 program02 */