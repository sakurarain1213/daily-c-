#include <bits/stdc++.h>
using namespace std;

int  main ()
{

queue <int >a;
int t;
cin>>t;
while(t!=-1)
{
a.push(t);
cin>>t;
}
while(!a.empty())
{
cout<<a.front()<<" ";
a.pop();
}



return 0;
}