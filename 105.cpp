#include <bits/stdc++.h>
using namespace std;
//大数取模算法  快速幂
/* 使用模运算的性质：(ab)%N = (a%N * b%N)%N, 由于N=10007，因此计算的中间结果用int表示就行了。
因此，根据模运算性质，我们在输入a，b时和计算dp[i][j]都做了%N运算 */
/* #define N 1000000007
#define M 100

int f(int n,int m,int a, int b){
   static int dp[M][M]={1},i,j;
  for (i=0;i<=n;i++) for (j=0;j<=m;j++){
     if (i+j)
     if (i==0)   dp[i][j] = b*dp[i][j-1]%N;
     else if (j==0)  dp[i][j] = a*dp[i-1][j]%N;
     else   dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
  }
  return dp[n][m];
}

void solve(){
	int a,b,k,n,m;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	printf("%d\n",f(n,m,a%N,b%N));
} 
   
int n,k=0;
cin>>n;
  while(n-->0)
  {
 printf("case #%d:\n",k);
solve();
      k++;
  }
 */
/* 
using namespace std;
unsigned long long int jc[1005];
const unsigned long long int mod=1000000007;
unsigned long long power(int x,int y)
{
     unsigned long long re=1,a=x;
     unsigned int i=y;
     for(;i;i=i>>1,a=a*a%mod)
         if(i&1) re=re*a%mod;
     return re;
}
 
unsigned long long C(int n,int m)
{
     if(m==0) return 1;
     if(n==m) return 1;
     return((jc[n]*power(jc[m],mod-2))%mod*power(jc[n-m],mod-2))%mod;
}
 

void f(int x)
{
 unsigned long long  int a,b,k,n,m;
     cin>>a>>b>>k>>n>>m;
   
    unsigned long long p1,p2,p3,p;
     jc[1]=1;
     for(int i=2;i<=k;i++)
         jc[i]=(jc[i-1]*i)%mod;
     p1=C(k,min(n,m));
     p2=power(a,n);
     p3=power(b,m);
     p=(p1%mod*p2%mod)%mod*p3%mod; 
      cout<<"case #"<<x<<":\n";
     cout<<p<<endl;



}


int main()
{
int x;
cin>>x;
for(int i=0;i<x;i++)
    {
    f(i);
    }
     return 0;
}
 */
/**/
typedef long long LL;
 
const LL mod = 1000000007;
 
LL a, b, k, n, m;
 
LL pow_c(LL x, LL num){
	LL res = 1 % mod;
	x %= mod;
	while(num){
		if(num & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		num >>= 1;
	}
	return res;
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
 
	scanf("%lld %lld %lld %lld %lld", &a, &b, &k, &n, &m);
	LL c[k + 1];
	c[1] = 1;
	for (int i = 2; i <= k; i++) c[i] = c[i - 1] * i % mod;
	LL ans = c[k] * pow_c(c[m] * c[k - m], mod - 2) % mod;
	printf("%lld\n", ans * pow_c(b, k - n) % mod * pow_c(a, n) % mod);
 
	return 0;
}
/**/
 


/* 3
1 1 3 1 2
235823 382573 999 111 888
681692776 714636914 287579 7786 279793
 */