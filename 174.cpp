#include<bits/stdc++.h>
using namespace std;
//dp  走楼梯  巧妙的是 坏掉的楼梯dp【0】=0即可
int f[110] = {0};
int dp[110] = {0};
int main(){
    int n,k;
    cin >> n >> k;
    while(k){
        k--;
        int temp;
        cin >> temp;
        f[temp] = -1; //标记坏掉的楼梯
        dp[temp] = 0; //不能走
    }
    dp[0] = 1;
    if(f[1] != -1) dp[1] = 1;
    if(f[2] != -1)  dp[2] = dp[1] + 1;
    for(int i = 3; i <= n; i++){
        if(f[i] != -1){ //如果楼梯能到达
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
    }
    cout << dp[n] << endl;
    return 0;
 }
/* 5 2
2 4 */
