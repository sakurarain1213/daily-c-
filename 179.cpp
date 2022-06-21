#include<bits/stdc++.h>
using namespace std;
/*
dp 拆分正整数成 二的指数形式的和
*/
int t, n;
int dp[1000011];
int main() {
    cin >> t;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 1000000; i++) {
        if (i % 2)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
    }
    for (int k = 0; k < t; k++) {
        cin >> n;
        cout << "case #" << k << ":\n" << dp[n] << endl;
    }
    return 0;
}

/* 3
7
9
46
 */


