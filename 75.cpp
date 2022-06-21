#include <bits/stdc++.h>
using namespace std;

void solve(int x)
{
int a,b;cin>>a>>b;
double m=(2*a-0.5*b);double n=(0.5*b-a);

cout<<"case #" << x << ":\n";

if(floor(m)==m&&floor(n)==n&&m>=0&&n>=0) cout<<(int)m<<" "<<(int)n;
else cout<<"Impossible";
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