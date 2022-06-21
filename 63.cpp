#include <bits/stdc++.h>
using namespace std;

int  main ()
{
//STL双向队列的使用
deque <char>a;
int t;
cin>>t;getchar();
string s;
getline(cin,s);
int n=s.length();
for(int i=0;i<n;i++)
{
if(s[i]!='\n'&&s[i]!=' ') a.push_back(s[i]);

}

while(t>0&&!a.empty())
{
cout<<a.back()<<" ";
a.pop_back();
t--;
}



return 0;
}