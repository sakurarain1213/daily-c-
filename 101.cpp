#include <bits/stdc++.h>
using namespace std;

void p(int *p,int n)
{
for(int i=0;i<n;i++)
{
   cout<<*(p+i)<<" ";
}
cout<<endl;
}

 unsigned long long int jc (int n)
            {
              unsigned long long int jiecheng;jiecheng=1;int i;
             for (i=1;i<=n;i++)
            {  jiecheng=jiecheng*i;}
             return jiecheng;
             }

int  main ()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    a[i]=i+1;
}
int count=1;
cout<<count<<":";
p(a,n);
while(next_permutation(a,a+n)&&count<10)
{
     count++;
     cout<<count<<":";
     p(a,n);
}
cout<<jc(n);//总的排列种数

return 0;
}