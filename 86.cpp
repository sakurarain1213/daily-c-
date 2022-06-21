#include <bits/stdc++.h>
using namespace std;

int  main ()
{
list<int >l;
list<int >::iterator i=l.begin();
int n;int m;
cin>>n;
for(int i=0;i<n;i++)
{   int t;
     cin>>t;
    l.push_back(t);
}

l.reverse();
 while(!l.empty())
{
    cout<<l.front()<<" ";
    l.pop_front();
} 
return 0;
}