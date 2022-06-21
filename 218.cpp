//中国剩余定理
/* 求正整数中满足：X mod a[0] = b[0], X mod a[1] = b[1], X mod a[2] = b[2], …, X mod a[i] = b[i], …
 的最小解。a[i] 是一些两两互质的正整数。
 
 一 费马小定理
 p为质数，a为自然数，则a^p=a（mod p），即a^p%p=a%p进一步，若gcd（a，p）=1，则a^（p-1）=1（modp），即a^（p-1）%p=1%p=1
反过来，如果存在a<p，且a^（p-1）%p！=1，则p肯定不是素数.
判素数或者简化计算
如3^31mod7  
 
 因为 3^6 mod 7=1
 所以(3^6)^5*3mod 7 =3
 快速幂求a^bmod p  自行查
 二、逆元
对于正整数a和m，如果有a*x=1（modm），那么把这个同余方程中的最小正整数解叫做定理1：
若m是质数，则a的逆元为a/（m-2）mod m。
定理2：
设a/b是整数，c是b的逆元，则a/b=a*c（mod m）
证明：由bc=1（mod m）得，（a/b）%m=（（a/b）1）%m=（（a/b）bc）%m=（ac）%m。
推论：
设m是质数，a/b是整数，则a/b=a*b^（m-2）（modm）

三、威尔逊（Wilson）定理
一个数p为质数的充要条件：p可整除（p-1）！+1。
如：7为质数，则7可整除（7-1）！+1=721，即721%7==0。
注释：上述定理虽为充要条件。但由于阶乘增长太快，所以目前不适合用于大数的素性判断。
  */

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
const int MAXN = 1e5+10;
 
lli w[MAXN];
lli r[MAXN];
lli w1,r1;
int flag;
 
lli Extend(lli a,lli b,lli &x,lli &y)
{
    lli d;
    if(b==0)
    {
        x=1;
        y=0;
        return a;   //a是a,b的最大公约数
    }
    d=Extend(b,a%b,y,x);
    y-=(a/b)*x;     //x1=y2; y1=x2-(a/b)*y2;
    return d;
}
 
lli   China(int k)
{
    lli w1=w[1];
    lli r1=r[1];
    lli w2,r2,c,d,x,y,s;
    for(int i=2;i<=k;i++)
    {
        w2=w[i];
        r2=r[i];
        c=r2-r1;
        d=Extend(w1,w2,x,y);
        if(c%d)
        {
            flag=1;
            return -1;
        }
        else
        {
            x=x*c/d;
            s=w2/d;
            x=(x%s+s)%s;
            r1=x*w1+r1;
            w1=w1*w2/d;
        }
    }
    d=Extend(1,w1,x,y);
    if(r1%d)
    {
        flag=1;
        return -1;
    }
    else
    {
        x=x*r1/d;
        s=w1/d;
        x=(x%s+s)%s;
        if(x==0)
        {
            flag=1;
            return -1;
        }
        else
        {
            return x;
        }
 
    }
}
 
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&w[i]);
    }
        for(int i=1;i<=k;i++)
    {
        scanf("%lld",&r[i]);
    }
    flag=0;
    lli ans=China(k);
    if(flag) printf("-1\n");
    else printf("%lld\n",ans);
  }  
 return 0;
}
/* 
2
2 3
0 1


2
2
2 3
0 1
3
3 5 7
2 3 2

 */

/*    这个是求解的个数的代码
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 15
using namespace std;
int flag;
long long int n;
 
long long int Extend(long long int a,long long int b,long long int &x,long long int &y)   //求p * a+q * b = Gcd(a, b)的一组解p0,q0
{
	long long int d;
	if(b==0)
	{
		x=1;
		y=0;
		return a;     //a是a,b的最大公约数
	}
	d=Extend(b,a%b,y,x);
	y-=(a/b)*x;            //x1=y2; y1=x2-(a/b)*y2;
	return d;
}
 
long long int China(long long int w[],long long int r[],long long int len,long long int w1,long long int r1)
{
	long long int i,x,y,d,c,w2,r2,s;
	for(i=2;i<=len;i++)
	{
		w2=w[i];
		r2=r[i];
		c=r2-r1;
		d=Extend(w1,w2,x,y);       // ?x * a1 ≡?( r2 - r1 ) (mod a2) 即x*a1 = (r2 - r1) + y *a2
		//求出了x*a1 = gcd(w1,w2) + y *a2的解
		if(c%d)    //d是w1,w2的最大公因数,所以c一定能被d整除
		{
			flag=1;  //k1 * a1 - k2 * a2 = r2-r1     (k1 * a1 - k2 * a2)%d = (r2-r1)%d =0 
			return 0;
		}
		else
		{
			x=x*c/d;       //扩展成x * a1 ≡?( r2 - r1 ) (mod a2)的解
			s=w2/d;        //根据Extend(w1,w2,x,y)得出，间隔
			x=(x%s+s)%s;   //将x转换成最小的整数解
			r1=x*w1+r1;     //将k1带回到 x1 = x * a1 + r1
			w1=w1*w2/d;    //w1,w2的最小公倍数
 
		}
	}
	d=Extend(1,w1,x,y);   //当所有式子化完后,1是a1的值(式子就变成x * 1 ≡?( r2 - r1 ) (mod w1))
	if(r1%d)
	{
		flag=1;
		return 0;
	}
	else
	{
		x=x*r1/d;
		s=w1/d;
		x=(x%s+s)%s;  //求出满足所有方程的最小值
 
		if(x>n)
		{
			flag=1;
			return 0;
		}
		else
		{
			if(x==0)return (n-x)/s;
			else  return (n-x)/s+1;
		}
 
	}
}
 
int main()
{
	long long int t,m,i,w1,r1,d,ans;
	long long int w[MAXN],r[MAXN];
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&w[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&r[i]);
		}
		flag=0;
		w1=w[1];
		r1=r[1];
		ans=China(w,r,m,w1,r1);
		if(flag)
		{
			printf("0\n");
		}
		else
		{
			printf("%lld\n",ans);
		}
 
	}
	return 0;
 
} */