#include <bits/stdc++.h>
using namespace std ;

bool com(int a,int b)
{
    return a>b;
}

void f()
{
    int a[100];
 memset(a,0,sizeof(a));
  int b[100];
 memset(b,0,sizeof(b));
   int c[100];
 memset(c,0,sizeof(c));
int m,n;int t;
cin>>n>>m;
for(int i=1;i<=n;i++)
{  cin>>a[i];c[i]=a[i];}
for(int i=1;i<=m;i++)
{
    cin>>b[i];
}
sort(c+1,c+n+1,com);
/* for(int i=1;i<=n;i++)
{  cout<<a[i];}
for(int i=1;i<=m;i++)
{  cout<<b[i];}
cout<<endl; */
for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(a[j]==c[b[i]]) {cout<<j<<" ";break;}
    }
} 
cout<<endl;
}
int main()
{
int t;
cin>>t;
while(t)
{
    f();
    t--;
}


return 0;}

/* 
2
3 1
228 205 190
3
5 3
223 179 217 195 193
1 4 5
 */

