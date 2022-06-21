#include <bits/stdc++.h>
using namespace std;
//最小公倍数的枚举法
int main()
{
    int t;scanf("%d",&t);
    for(int m=0;m<t;m++)//p-23 e-28 i-33
    {
        int p,e,i,d;scanf("%d %d %d %d",&p,&e,&i,&d);
        int a,b,c;//每次翻倍 上加p的周期 找到e的倍数 再上加e*p的倍数 找到i的倍数
        for(a=d+1;a<=21252;a++)
        {
            if((a-p)%23==0) break;
        }
        for(b=a;b<=21252;b+=23)
        {
            if((b-e)%28==0) break;
        }
        for(c=b;c<=21252;c+=23*28)
        {
            if((c-i)%33==0) break;
        }
        printf("case #%d:\n",m);
        printf("the next triple peak occurs in %d days.\n",c-d);
    }
    return 0;
}

