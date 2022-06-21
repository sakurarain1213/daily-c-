#include<iostream>
using namespace std ;

int  main ()
{
int i,s1,s2,s3;int k;bool f=false;
cin>>k;
for (i=10000;i<=30000;i++)
{
s1=i/100;
s2=(i%10000)/10;
s3=i%1000;
if(s1%k==0 && s2%k==0 && s3%k==0)
{
    cout <<i<<"\n";
    f=true;
}
}
if (!f)
{ cout<<"No";}
return 0 ;
}