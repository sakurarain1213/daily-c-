#include<bits/stdc++.h>
using namespace std;
/*
dp 拆分正整数成多个数的和 规定每个拆分的部分都小于一个值
也可以用dfs
一维数组。
思路：设已知里面有一个数是i，把i剥离出来的划分方式依然是满足条件的划分方式。注意是倒着循环。构建d p [ n + 1 ] dp[n+1]dp[n+1]数组，下标代表“背包容量”。

也可以用二维数组
二维数组。
思路：
（1）当n=1，无论m为多少，只有一种划分。
（2）当m=1，无论n为多少，只有一种划分。
（3）当n<m，一种。
（4）当n=m，如果划分中有n，则只有{n}一种划分；当划分中没有n，则f （ n ， n ） = f （ n ， n − 1 ） f（n，n）=f（n，n-1）f（n，n）=f（n，n−1）
故：f （ n ， n ） = 1 + f ( n ， n − 1 ) f（n，n）= 1 + f(n，n - 1)f（n，n）=1+f(n，n−1)
（5）当n>m，如果划分中有m，则m ， x 1 ， x 2 ， … = n − m ， f （ n ， m ） = f （ n − m ， m ） {m，{x1，x2，…} = n - m}，f（n，m）=f（n - m， m）m，x1，x2，…=n−m，f（n，m）=f（n−m，m）；当划分中没有m，f （ n ， m ） = f （ n ， m − 1 ） f（n，m）=f（n，m - 1）f（n，m）=f（n，m−1）。
故：f （ n ， m ） = f （ n − m ， m ） + f （ n ， m − 1 ） f（n，m） = f（n - m， m）+ f（n，m - 1）f（n，m）=f（n−m，m）+f（n，m−1）
*/
int t, n, m;
int dp[55];

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n; j >= i; j--)
                dp[j] += dp[j - i];
        cout << "case #" << i << ":\n" << dp[n] << endl;
    }
    return 0;
}
/* 3
6 4
20 8
50 20 */


