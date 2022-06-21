#include<iostream>
/*
思路：dp[i]表示以a[i]为结尾的最大增序列和
//dp   找上升子序列  而且找和最大值
*/
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int a[n];
		int dp[n]={0};
		for(int j = 0;j < n; j++)
		cin>>a[j];
		int ans=0;
		for(int j = 0; j < n; j++)
		{
			dp[j]=a[j];
			for(int k =0; k < j; k++)
			{
				if(a[j]>a[k])
				{
					dp[j]=max(dp[k]+a[j],dp[j]);
				}
			}
			ans=max(ans,dp[j]);
		}
		printf("case #%d:\n%d\n",i,ans);
	}
	return 0;
 } 

/* 
2
7
1 7 3 5 9 4 8
4
100 20 20 3
 */

/* 
补充  最长的上升子序列
想法
对于这样的一道题，用贪心是无法解决的，因为结尾最大的子序列不一定就是最长的子序列。如：1 9 3 4 。贪心只可以看到1 9，结果不能找到1 3 4。对于这道题，我们可以用动态规划（DP）。
思路
动态规划的关键在于定义数组的含义和“状态转移方程式”。这里我们可以定义一个数组 a[i] 来存数列，再定义 F[i] 用来表示 末尾 为 a[i] 的最长上升子序列。这句话非常重要！
状态转移方程式
当 a[i]>a[j] 时，F[i]=max(F[j]+1,F[i]); 这里的max为取较大值，也就是F[i]为它本身和 F[j]+1 中较大的一个。有一个问题：F[i] 为什么要和自己比较呢，因为在循环中，F[i] 可能赋过很多次值。
当 a[i]<=a[j]时， F[i]就不能变，因为 a[i] 不能接在 a[j] 后面。
最后再在末尾为 1,2,3,…,n 的最长上升子序列中找到最长的那一个既是正确答案！
cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);   //输入
        f[i]=1;              //以第i个数为末尾的上升序列最初长度为1
    }
    for(int i=1;i<=n;i++)         //枚举i的位置
        for(int j=1;j<i;j++)   //在i的前面找j的位置
            if(a[i]>a[j]) //如果满足条件，则第i个数可以放在j后边
                f[i]=max(f[j]+1,f[i]);//取较大的一种再放
    printf("%d",*max_element(f+1,f+n+1));//从 F[1]到F[n] 找最大值
 */