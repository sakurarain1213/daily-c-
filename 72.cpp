#include <bits/stdc++.h>
using namespace std;

int  main ()
{
int n,t;
int a,b;
list <int> l;
list <int > ::iterator i;
//或者auto i=l.begin();
cin>>n;
while (n>0)
{
    cin>>t;
l.push_back(t);
n--;
}
int x=0;
cin>>a>>b;
i=l.begin();
while(x<a)
{
    i++;
    x++;
}
for(;a<=b;i++)
{
cout<<*i<<" ";
b--;
}


return 0;
}