#include <bits/stdc++.h>
using namespace std ;
//结构体多级排序

/* 定义一个商品类。因为题目要求原样输出价格，干脆把商品编号，销量和价格全部按照字符串来读入和存放。同时为了之后排序方便，又维护了 flag 变量，判断是否合乎标准，还有次序，价格和销量由于之后的排序。
分别用两个数组来存销量和价格，编写cmpa用于数组排序，之后就可以按照公式得到价格和销量的中位数值。遍历结构体数组，查找符合要求的商品，并把flag设置为1。
然后编写cmpb函数按照是否合规、销量、价格和输入次序的优先级给结构体数组排序，最后输出。 */
struct Goods
{
    char id[10],amount[100],price[100];
    int flag,cnt;
    double pri,amo;
}a[101];

int cmpa (const void *a,const void *b)
{
    double x,y;
    x=*((double *)a);
    y=*((double *)b);
    return (int)(100000*x-100000*y);
}

int cmpb (const void *a,const void *b)
{
    struct Goods x,y;
    x=*((struct Goods *)a);
    y=*((struct Goods *)b);
    if(x.flag!=y.flag) return y.flag-x.flag;
    if(x.amo!=y.amo) return (int)100*y.amo-100*x.amo;
    if(x.pri!=y.pri) return (int)100*x.pri-100*y.pri;
    return x.cnt-y.cnt;
}

int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int j;
        double pr[101],am[101];
        for(j=0;j<n;j++)
        {
            a[j].cnt=j;
            a[j].flag=0;
            scanf("%s %s %s",a[j].id,a[j].amount,a[j].price);
            a[j].pri=atof(a[j].price);
            pr[j]=a[j].pri;
            a[j].amo=atof(a[j].amount);
            am[j]=a[j].amo;
        }

        qsort(am,n,sizeof(double),cmpa);
        qsort(pr,n,sizeof(double),cmpa);

        double midam,midpr;
        int num=0;
        if(n&1)
        {
            midam=am[n/2];
            midpr=pr[n/2];
        }
        else
        {
            midam=(am[n/2]+am[n/2-1])/2.0;
            midpr=(pr[n/2]+pr[n/2-1])/2.0;
        }
        for(j=0;j<n;j++)
        {
            if(a[j].amo>midam&&a[j].pri<midpr)
            {
                a[j].flag=1;
                num++;
            }
            else
                a[j].flag=0;
        }

        printf("case #%d:\n",i);

        if(num==0)
        {
            printf("no recommendation\n");
            continue;
        }
        else
        {
            qsort(a,n,sizeof(a[0]),cmpb);
            for(j=0;j<num;j++)
            {
                printf("%s %s %s\n",a[j].id,a[j].amount,a[j].price);
            }
        }
    }
    return 0;
}
/* 
3
2
11 2 7
12 1 6
5
e01 0 7
e02 87 5.5
e03 8 10
e04 97 6
e05 55 8
8
a100 201 23.0
a101 518 19.7
a102 289 36.7
a103 218 22.9
a104 37 1.2
a105 515 42.0
a106 577 25.6
a107 136 44.5

 */
