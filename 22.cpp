#include <bits/stdc++.h>

using namespace std ;


struct y 
{
int a;
double b;

}yy[201];

int com(const void *p1, const void *p2)
//要么自己写比较函数和 sort函数    不然一定要按照此格式写比较函数 然后直接用 qsort
{
    struct y *c=(y*)p1;
     struct y *d=(y*)p2;
    double n = c->b - d->b;
    int m = c->a - d->a;
    if(n < 0)
        return -1;
    if(n > 0)
        return 1;
    if(m> 0)
        return 1;
    if(m < 0)
        return -1;
    return 0;
}

double qp(int l[][11],int i,int j,int k,int m)//求每一格子的p
{ 
    return (l[i][j]+1.0/k)/(m+1);
}

double san(double py,double px)//注意这两个值的输入顺序
{
    return px*log(px/py);
}

int l[201][11];
double p[201][11];
int k,n;
double ans[200];//由于要次关键字排序 所以两列//或者用结构体？？后者
int  main ()
{
cin>>k>>n;
for (int i=1;i<=k;i++)
{cin>>l[0][i];}
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=k;j++)
    {cin>>l[i][j];}
}

/* 
for (int i=0;i<=n;i++)
{
    for (int j=1;j<=k;j++)
    {cout<<l[i][j];}
    cout<<endl;
}

 */




//计算p；
for (int i=0;i<=n;i++)
{
   int m=0;
   for (int t=1;t<=k;t++) m+=l[i][t];

    for (int j=1;j<=k;j++)
    {p[i][j]=qp(l,i,j,k,m);}
}


/* for (int i=0;i<=n;i++)
{
    for (int j=1;j<=k;j++)
    {cout<<p[i][j]<<"  ";}
    cout<<endl;
} */



//求散度san

for  (int i=1;i<=n;i++)
{     yy[i-1].b=0;
      for (int j=1;j<=k;j++)
    {yy[i-1].b+=san(p[i][j],p[0][j]);}
    }
/* 
for  (int i=1;i<=n;i++)
{cout <<ans[i]<<endl;}
 */
for  (int i=0;i<=n;i++)
{     yy[i].a=i+1;
if (fabs(yy[i].b)<1e-7) yy[i].b=0;//根据题意 极小的散度约等于零
}

qsort(yy,n,sizeof(yy[0]),com);//qsort一定要从0号元素开始 注意！

for  (int i=0;i<n;i++)
{    cout << yy[i].a<<" "<<fixed<<setprecision(4)<<yy[i].b<<endl;}

return 0;
}
/* 
3


2 2

1 1
0 5
5 0



2 3
3 3
2 3
6 1
7 7



3 2

2 3 4
5 6 7
7 6 3
 */