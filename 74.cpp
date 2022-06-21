#include <bits/stdc++.h>
using namespace std;

int c[]={100,50,20,10,5,1};//0-5

void solve(int x)
{
int n;cin>>n;
int b[6];memset(b,0,sizeof(b));
for(int i=0;i<6;i++)
{
    b[i]=n/c[i];n-=(b[i]*c[i]);
}

cout<<"case #" << x << ":\n";
for(int i=0;i<6;i++)
{
    cout<<b[i]<<" ";
}
cout<<endl;
}
int  main ()
{
    int x;
cin>>x;
for(int i=0;i<x;i++)
{solve(i);
}





return 0;
}