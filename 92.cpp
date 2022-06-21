#include <bits/stdc++.h>
using namespace std;



void f(int x)
{
   int n,ans=0;
 cin>>n;
    int i;
for (i=2;i<n;i++)
{
    if(n%i==0)
    { ans+=i*i;}
}


cout<<"case #" << x << ":\n";
cout<<ans<<endl;

}





int  main ()
{
int x;
cin>>x;
for(int i=0;i<x;i++)
{
    f(i);
    }

return 0;
}