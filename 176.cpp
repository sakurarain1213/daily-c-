#include<bits/stdc++.h>
using namespace std;
/*
dp   单词划分  越少越好
*/
#define SIZE 257
#define INF 2e+09

set <string> st[SIZE];
string s, temp;
int dp[SIZE];

int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m, i, j;
	
	cin >> s;
	scanf("%d", &m);
	while (m--)
	{
		cin >> temp;
		st[temp.size()].insert(temp);
	}
	
	n = s.size();
	for (i = 0; i < n; ++i) // 动态规划过程
	{
		dp[i] = INF;
		for (j = 1; j <= i + 1; ++j)
		{
			if (st[j].count(s.substr(i - j + 1, j))) // 如果这个子串出现在了单词集合里
			{
				dp[i] = min(dp[i], (j == i + 1) ? 1 : dp[i-j] + 1); // 条件转移方程
			}
		}
	}
	printf("%d\n", dp[n-1]);

    }
	return 0;}

/* 1
realityour
5
real
reality
it
your
our
 */


