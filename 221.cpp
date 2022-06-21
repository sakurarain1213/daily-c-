 
 #include <bits/stdc++.h>
using namespace std;
//连续正整数之和 的组数
//如15=1+……5=456=78   即找到整除的中位数即可  中位数要么odd要么even
 int main()
 {
      int T,N,i,j,cnt;
     scanf("%d",&T);
    for(i=1;i<=T;i++)
   {
        scanf("%d",&N);
        cnt=0;
        for(j=3;j<N+1;j+=2)
            if(N%j==0) cnt++;
        if(N%2==0&&(N/2)%2!=0)  cnt++;
        printf("Case %d: %d\n",i,cnt);
    }
     return 0;
}
/* 
3
15
16
99
 */