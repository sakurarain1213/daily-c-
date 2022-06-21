#include <bits/stdc++.h>
using namespace std;
//对杨辉三角的思考 组合数阶乘不如二维数组相加
/* 
 unsigned long long int jc (int n)
            {
              unsigned long long int jiecheng;jiecheng=1;int i;
         for (i=1;i<=n;i++)
         {  jiecheng=jiecheng*i;}
             return jiecheng;
             }
 unsigned long long int  c (int n,int m)
   {
return jc(m)/jc(n)/jc(m-n);
    }

void f(int a)
{

 int i,j;
printf("1\n");
for (i=1;i<=a-1;i++)
{
    for (j=0;j<=i-1;j++)
     {
     printf("%lld ",c(j,i));
      }
  if (i==a-1)
     {printf("1");}
  else
   {printf("1\n");}
}

}
 */




/* {
    return (c==1||r==c)?1:a(r-1,c-1)+a(r-1,c);
} */

/* 
void f(int n)//c++二维数组的引用 可以用括号
{

long long int a[31][31];
memset(a,0,sizeof(a));
 for(int i=1;i<=30;i++)
{
   for(int j=1;j<=i;j++)
   {
   if(j==1||i==j) a[i][j]==1;
   else a[i][j]== a[i-1][j-1]+a[i-1][j];
   }
}

    for(int i=1;i<=n;i++)
    {
for(int j=1;j<=i;j++)
{
  cout<<a[i][j]<<" ";
}
cout<<endl;

    }
}
int  main ()
{

int n;
cin>>n;
while (n!=0)
{
f(n);
cout<<endl;
    cin>>n;
}

 */

int main()
{
    int a[35][35],n;
    memset(a,0,sizeof(a));
    cin>>n;
   while(n!=0)
   {
       a[1][1]=1;cout<<a[1][1]<<endl;
       for(int i=2;i<=n;i++)
       {
         for(int j=1;j<=i;j++)
         {
            a[i][j]=a[i-1][j]+a[i-1][j-1];
            if(j==1) printf("%d",a[i][j]);
            else printf(" %d",a[i][j]);
         }
       cout<<endl;
       }
     cout<<endl;
     cin>>n;
   }
    return 0;
}


