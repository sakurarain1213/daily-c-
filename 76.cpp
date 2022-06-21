#include <bits/stdc++.h>
using namespace std;
//最小点积的贪心算法 可以直接正序与倒序 分别相乘

bool compare2(int a,int b)
{
    return a>b;
}
bool compare1(int a,int b)
{
    return a<b;
}
void solve(int x)
{
int n;cin>>n;
int a[1000];int b[1000];
memset(a,0,sizeof(a));memset(b,0,sizeof(b));
for(int i=0;i<n;i++)
{
  cin>>a[i];
}
for(int i=0;i<n;i++)
{
  cin>>b[i];
}

cout<<"case #" << x << ":\n";

int sum=0;
sort(a,a+n,compare1);
sort(b,b+n,compare2);//降序

for(int i=0;i<n;i++)
{
  sum+=a[i]*b[i];
}
cout<<sum<<endl;

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