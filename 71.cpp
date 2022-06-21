#include <bits/stdc++.h>
using namespace std;

int  main ()
{
int n,t;
int sum=0;
list <int> l;
list <int > ::iterator i;
cin>>n;
while (n>0)
{
    cin>>t;
l.push_back(t);
n--;
}

for(i=l.begin();i!=l.end();i++)
{
sum+=*i;
}
cout<<sum;



return 0;
}