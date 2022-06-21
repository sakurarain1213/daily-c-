#include <bits/stdc++.h>
using namespace std;

//第四年起 每年+一只
//算法是递归 fn=fn-1 +fn-3
//第四年后，牛的数量由两部分构成，去年的所有牛和所生下的小牛组成，前者就是f(n-1)，应该没有异义；由于不是所有牛都能生小牛，只有3牛以前的老牛才会生小牛，而每只老牛只生一只小牛，第n年所生牛的数量就应该是f(n-3）

void f(unsigned long long int *p,int n)
{
cout<<*(p+n)<<endl;
}

int  main ()
{
unsigned long long int a[51];
memset(a,0,sizeof(a));
a[0]=1;a[1]=1;a[2]=1;a[3]=1;
for(int i=4;i<51;i++)
{a[i]=a[i-1]+a[i-3];}

int n;
 cin>>n; 
while(n!=0)
{
f(a,n);
 cin>>n; 
}


return 0;
}