#include <bits/stdc++.h>

using namespace std ;

int yix(int i,int n)
{
    i--;
if (i==0) i=n;
return i;
}
int yiy(int j,int n)
{
    j++;
if (j==n+1) j=1;
return j;
}

int  main ()
{
    int n;
cin>>n;

int a[n+2][n+2];
memset(a,0,sizeof(a));//用于后续判断是否填充过

/* 
for(int i=1;i<=n;i++)
{
{for(int j=1;j<=n;j++)
cout<<a[i][j]<<" ";

}
cout<<endl;
}
 */

int x=1;
int y=(n+1)/2;
for(int i=1;i<=n*n;i++)
{
    if(a[x][y]==0)  
    {   a[x][y]=i;
    x=yix(x, n);
    y=yiy(y, n);
    }

    else
    {
         //逆向退回
         x++;if(x==n+1)x=1;
         y--;if(y==0)y=n;
     while( a[x][y]!=0)
     {x++;
      if(x==n+1) x=1;
     }
      a[x][y]=i;
      x=yix(x, n);
      y=yiy(y, n);
  
    }
} 
//
int sum=0;
for(int i=1;i<=n;i++)
{
sum+=a[i][2];

}
//cout<<"the sum of the cube:"<<sum<<endl;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++){
cout<<a[i][j]<<"  ";
}
cout<<endl;
}

return 0;
}