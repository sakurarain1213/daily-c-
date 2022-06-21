#include <bits/stdc++.h>
using namespace std;

int  main ()
{
list<int >l;
list<int >::iterator i;
int t;
cin>>t;

while(t!=-1)
{
  l.push_back(t);
     cin>>t;
}

l.reverse();
 while(!l.empty())
{
    cout<<l.front()<<" ";
    l.pop_front();
} 
return 0;
}