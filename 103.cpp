#include <bits/stdc++.h>
using namespace std;

int main() {
int n,k=0;
    scanf("%d",&n);
    while(n-->0)
{
 long long dp[30]= {0};
    int i=0,j=0,m=0;
cin>>m;
for( i=0;i<m;i++)
{
    cin>>dp[i];
}
bool flag=true;//判断是否满足递推关系
int p;//记录-1位置
//-1 可以出现在任意位置

 printf("case #%d:\n",k);
       
        k++;
    for(i=3; i<m; i++) {
        if(dp[i]>0&& dp[i-3]>0&&dp[i-2]>0&&dp[i-1]>0)
             {
                 if(dp[i] == dp[i-3]+dp[i-2]+dp[i-1]);//什么都不做
                 else {flag=false;break;}
             } 
        else 
        {
           if(dp[i]==-1) p=i; 
           if(dp[i-1]==-1) p=i-1; 
           if(dp[i-2]==-1) p=i-2;
           if(dp[i-3]==-1) p=i-3; 
        }
    }
if(flag)
{
    if(p==0) dp[p]=dp[3]-dp[2]-dp[1];
   if(p==1) dp[p]=dp[3]-dp[2]-dp[0];
   if(p==2) dp[p]= dp[3]-dp[1]-dp[0];
   if(p>=3) dp[p]= dp[p-3]+dp[p-2]+dp[p-1];
   if(dp[p]<=0) flag=false;//debug
}//补充完还要再次验证

if(flag)
{
for(i=3; i<m; i++) 
{  if(dp[i] == dp[i-3]+dp[i-2]+dp[i-1]);//什么都不做
   else {flag=false;break;}
  } 
}

//最终输出
if(flag) cout<<dp[p];
else cout<<-1;
cout<<endl;
}
    return 0;
}
//4 10 10 -1 20   这个点不行 注意要>0
