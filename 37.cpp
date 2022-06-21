#include <bits/stdc++.h>
using namespace std ;

//()[]{}
int pan(char c)
{
if(c=='('||c=='['||c=='{') return 1;
else if(c==')'||c==']'||c=='}') return -1;
return 0;
}

int pan(char c1,char c2)//支持同名重载
{
if(c1=='('&&c2==')'||c1=='['&&c2==']'||c1=='{'&&c2=='}') return 1;
return 0;
}

int  main ()
{
stack <char> s;
string ss;
getline(cin,ss);
for(int i=0;i<=ss.length();i++)
{
    if(pan(ss[i])==1) s.push(ss[i]);
    else if(pan(ss[i])==-1&&pan(s.top(),ss[i])&&!s.empty()) s.pop();
} 
if(s.empty()) cout<<"1"<<endl;
else cout<<"0"<<endl;

return 0;
}