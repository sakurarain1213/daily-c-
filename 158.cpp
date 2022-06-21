#include <bits/stdc++.h>
using namespace std ;

//打印所有真分数的方法    打印出来再全部排序？ 是
/* 直接枚举每个互质的分子分母然后算出商一起用一个结构体保存
然后对这个结构体按照商的升序排列
直接输出被除数和除数就可以了 */

struct node{
    int a,b;
    double s;
}f[25505];
int gcd(int x,int y)
{
    if(x%y==0) return y;
    return gcd(y,x%y);
}
bool cmp(node a,node b)
{
    return a.s<b.s;
}
int n,lens=1;
int main()
{
    scanf("%d",&n);
    f[lens].a=0,f[lens].b=1,f[lens].s=0;//预处理第一个
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(gcd(i,j)==1)
            {
                f[++lens].a=j;
                f[lens].b=i;
                f[lens].s=j*1.0/i;
            }
    sort(f+1,f+lens+1,cmp);
    for(int i=1;i<=lens;++i)
    {
        if(f[i].s>1) return 0;//注意商的范围
        printf("%d/%d\n",f[i].a,f[i].b);
    }
}


