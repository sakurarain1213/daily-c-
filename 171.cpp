#include <bits/stdc++.h>
using namespace std;

//dp动态规划专题
//编辑两个字母之间改动次数
/*
假设两个字符分别m位n位 dp【ij】就是指a1-i到b1-j的修改次数。
思路：dp[i][j]表示字符串x第i个与字符串第j个字符修改的次数。
状态转移方程：
if：x[i-1]==y[j-1] then :dp[i][j]=dp[i-1][j-1]//不需要修改
else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1//需要修改一次
相当于dp构造了m*n的二维表 逐次求到dp【m】【n】即可。初始值dp【0】【j】=j；等等
*/

int main(){
	int t;
	cin>>t; 
	while(t--)
	{
		string x,y;
		cin>>x>>y;
		int dp[500][500];
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < 500; i++)
		dp[0][i]=i,dp[i][0]=i;
		for(int i = 1; i <= x.size(); i++)
		{
			for(int j = 1; j <= y.size(); j++)
			{
				if(x[i-1]==y[j-1])
				dp[i][j]=dp[i-1][j-1];
				else
				{
					dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				}
			}
		}
		cout<<dp[x.size()][y.size()]<<endl;
	}

return 0;} 

/* 2
hello
hi
apple
google
 */