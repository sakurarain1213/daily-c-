#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
  return n+10000;
}


int  main ()
{
 list<int >l;
list<int >::iterator i;
int t;
cin>>t;
int b[30000];
memset(b,0,sizeof(b));
while(t>0)
{
    int a;
    cin>>a;
  l.push_back(a);
    t--;
}
i=l.begin();
while(i!=l.end())
{
b[f(*i)]++;

while (b[f(*i)]>1)
{
  b[f(*i)]--;
  i=l.erase(i);
  i--;
}

i++;
}



 while(!l.empty())
{
    cout<<l.front()<<" ";
    l.pop_front();
}  
return 0;
}