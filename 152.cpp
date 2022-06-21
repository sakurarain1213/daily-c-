#include <bits/stdc++.h>
using namespace std ;

int main()
{
int a[9000];
int cnt=0;
memset(a,0,sizeof(a));
int t;
cin>>t;
while(t!=-1)
{
    a[cnt++]=t;
   cin>>t;} 
//前
for(int i=0;i<cnt;i++)
{
    int j=-1;
    for( j=i-1;j>=0;j--)
    {
       if(a[j]<a[i]) 
       { cout<<a[j]<<" ";
           break;
       }
      
    }
    if(j==-1) cout<<0<<" ";
}

cout<<endl;
//后
for(int i=0;i<cnt;i++)
{
    int j=cnt;
    for( j=i+1;j<cnt;j++)
    {
       if(a[j]>a[i]) 
       { cout<<a[j]<<" ";
           break;
       }
      
    }
    if(j==cnt) cout<<0<<" ";
}

return 0;
}


