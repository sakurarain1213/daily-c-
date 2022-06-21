#include <bits/stdc++.h>
using namespace std ;


int  main ()
{
stack<int>a;

int t;
cin>>t;
while (t!=-1)
{
a.push(t);
cin>>t;
}

while(!a.empty())
{
    cout<<a.top()<<" ";
    a.pop();
}
cout<<endl;

cin>>t;
while (t!=-1)
{
a.push(t);
cin>>t;
}

while(!a.empty())
{
    cout<<a.top()<<" ";
    a.pop();
}



return 0;
}