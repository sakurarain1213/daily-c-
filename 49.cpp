#include <bits/stdc++.h>
using namespace std;

int  f(long long int x)
{

long long int  a[10000]={0};
long long int  n;
cin>>n;
for(long long int  i=1;i<=n;i++)
{
    cin>>a[i] ;
}

for(long long int  i=1;i<n;i++)
{
  long long int  min=a[i]; 
for(long long int  j=i+1;j<=n;j++)
{
if(a[j]<a[i]&&a[j]<min) {min=a[j];continue;}
if(a[j]<a[i]&&a[j]>min) {return 0;}//cout<<"no";}
}

//cout<<"yes";

}
return 1;
}


int  main ()
{
long long int x;
cin>>x;
while(x>0)
{
  if(f(x)) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
x--;
}

return 0;
}