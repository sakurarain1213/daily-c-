#include <bits/stdc++.h>
using namespace std;

//在 0 和 1 组成的长度为 n的字符串 (一共2^n个)中   ，统计包含 m 个 连续 1 （连续1的长度可以>m） 的字符串的个数。
long long b[32][32];
int i,j,k,n,m,t;
// dfs   回溯法
/* 
长度为4，包含3个连续1子串的字符串有3个：
0111，1110，1111

解题思路：逆向思考，考虑长度为n的01串中，不含m个连续1的情况数。设dp[i]为截至第i位时，不含m个连续1的情况数。那么：
1.若i < m，第i位不管是0还是1都不可能有m个连续1的情况出现，因此此时dp[i] = dp[i-1] * 2
2.若i == m,第i位若为1，会和向前回溯m-1位都是1的情况，合并成一个长度为m的连续1串；第i位若为0，则不会构成这种连续的情况。因此此时dp[i] = dp[i-1] * 2 - 1
3.若i > m,此时若i为1，且向前回溯m-1位都是1，会合并构成一个长度为m的连续1串（类似情况2），此时需要做的是在总情况数里减去这种连续的情况，那么怎么知道这种连续的情况是多少呢？其实答案就是dp[i-m-1]，意味着由前面的从第一位开始到第i-m-1位的合法情况加上连续的m位为1的情况，构成了这样的一个非法串。
最后不要忘记了我们是逆向求解的，因此2^n - dp[n]才为所求。 */



int main()
{
	for(i=1;i<32;i++)
		b[i][0]=1;
	for(i=1;i<32;i++)
		for(j=1;j<=i;j++)
		{	
			if(b[i-1][j])
			{ 
				b[i][j]+=b[i-1][j]*2;
				t=i-j-2;
				if(t>0)
				{
					for(k=0;k<=j;k++)
						b[i][j]-=b[t][k];
				}
				else 
					b[i][j]-=1;
			}
			t=i-j-1;
			if(t>0)
			{
				for(k=0;k<j;k++)
					b[i][j]+=b[t][k];
			}
			else 
				b[i][j]+=1;				
		}
    //打印所有3
	while(scanf("%d%d",&n,&m)&&n!=-1&&m!=-1)
	{
		long long ans=0;
		for(i=m;i<=n;i++)
			ans+=b[n][i];
		printf("%lld\n",ans);
	}
}