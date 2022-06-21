#include <bits/stdc++.h>
using namespace std;
int main() {
    long long dp[75]= {0};
    int i=0,k=0,j=0,n=0;
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(i=3; i<75; i++) {
        dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
    }
    scanf("%d",&n);
    while(n-->0) {
        scanf("%d",&k);
        printf("case #%d:\n%lld\n",j,dp[k]);
        j++;
    }
    return 0;
}
