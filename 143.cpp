#include <bits/stdc++.h>
using namespace std;
//动态规划 DP    最长等差数列     详细研究
int n;//n个数
/* 首先不难想到暴力法，先确定前两个元素，
通过前两个元素确定等差数列的差x，
然后再通过一个变量向后找差为x的后续部分。这种算法的时间复杂度是O(n^3)，显然是非常慢的。 */

/* 用一个简单的DP来完成。算法的复杂度是O(n^2)。 */
const int MAX=1010;
int dp[MAX][MAX];//dp[i][j]以i为 !结尾! 的某子序列（该子序列的公差为j）的最大长度
int a[MAX];//大小为n的数列
int longestSubSeq(int *a)
{
	int s=n;
	if (s <= 1) return s;
 
	sort(a,a+n);//可以在主函数里排序
	int ans=1;
	int i,j;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			dp[i][j]=1; //单独成列
 
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			  int d=*(a+i)-*(a+j)  ;    //int d=a[i]-a[j];//d为公差
			dp[i][d]=dp[j][d]+1;
			ans=max(ans,dp[i][d]);
		}
	}
	return ans;
}

int main()
{
  
/* int a[]={6,2,3,4};
n=sizeof(a)/sizeof(int);
cout<<longestSubSeq(a)<<endl;
for(int i=0;i<4;i++)
cout<<a[i]; */

int t;
 cin >> t;
    for (int  k = 0; k < t; k++) {
            cin>>n;
			memset(a,0,sizeof(a));
			for(int z=0;z<n;z++)
			{cin>>a[z];}
        cout << "case #" << k << ":\n";
       cout<<longestSubSeq(a)<<endl;
	}
    return 0;
}

/* 
3
5
9
7
1
2
3
10
8
6
2
4
9
0
10
12
11
7
5
10
10
10
10
10

 */