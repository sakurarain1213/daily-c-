#include<bits/stdc++.h>
using namespace std;
/*
dp 经典01背包问题
已知 n 个物体与一个背包。物体i的重量为wi ，价值为 pi ，背包容量为 W。
求在不超过背包容量的情况下，使得装进去的物体的价值最高。
核心代码
	for(int i=1;i<=n;i++){
			for(int j=1;j<=M;j++){
				if(j<weight[i])
					dp[i][j]=dp[i-1][j];
				else{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i]);
				}
			}
		}
dp[i][j]表示前i件物品，放入总空间为j的背包中，所能装下商品的最大价值。
for循环下标要从1开始而不是0开始，因为当i等于0时（即前0件商品）最大价值肯定为0，
j等于0时（即总空间为0）最大价值肯定为0。
if(j<weight[i]) dp[i][j]=dp[i-1][j];//表示第i件商品的重量已经超出了总空间，所以肯定装不下，
等于前i-1件商品在此空间下的总价值。
dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i])
中的dp[i-1][j-weight[i]]+price[i]);
表示把第i件物品放进去看看总价值为多少，其结果是物品i的价值加上前i-1件物品在总空间j-weight[i]中的最大总价值。
跟不拿第i件物品做对比，看看谁大。
*/
#define MAXN 25
int weight[MAXN],price[MAXN];
int dp[MAXN][100005];//dp[i][j]表示前i件物品放入空间为j的最大价值 
int main()
{
    int T;
    cin>>T;
    while(T--){
    	int n,M;
    	cin>>n>>M;
    	for(int i=1;i<=n;i++)
    		cin>>weight[i]>>price[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=M;j++){
				if(j<weight[i])
					dp[i][j]=dp[i-1][j];
				else{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i]);
				}
			}
		}
		cout<<dp[n][M]<<endl;
	}
    return 0;
}
/* 
1
5 10
2 6
2 3
6 5
5 4
4 6

 */


