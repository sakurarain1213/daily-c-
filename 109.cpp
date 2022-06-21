#include <bits/stdc++.h>
using namespace std;
//递归实现进制换换? 方法 递归函数要void
string s;
int n;
long long int ans=0;
int cnt =0;
void  f(string s)
{   
    while (cnt <s.length()){
       ans*=2;
        ans+=s[cnt]-'0';
       cnt++;}
}

int  main ()
{
cin>>s;
f(s);//从零开始
cout<<ans;
return 0;
}