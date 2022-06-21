#include <bits/stdc++.h>
using namespace std;
 //快速幂 a的b次方mod c    次方可以用a=a*a  指数每次翻倍 过程中随时取余 保证数字小
typedef long long LL;
LL pow_mod(LL a, LL n, LL MOD)
{
	LL res = 1;
	while (n)
	{
		if(n&1) //当前n的二进制的最后一位为1，即此时的n为奇数 
			res = res * a % MOD;
		a = a * a % MOD;
        //相当于base = a, 此后base的指数为 1，2，4，8...正好为2的0，1，2，3...次方 
		n >>= 1;	//n/2
	}
	return res ;
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
    while(a+b+c>0)
    {
        printf("%d\n", pow_mod(a, b, c));
        	scanf("%d%d%d", &a, &b, &c);
    }
	return 0;
}
