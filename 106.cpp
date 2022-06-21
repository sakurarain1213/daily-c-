#include <bits/stdc++.h>
using namespace std;

//大数取模算法  快速幂
/* 使用模运算的性质：(ab)%N = (a%N * b%N)%N, 由于N=10007，因此计算的中间结果用int表示就行了。
因此，根据模运算性质，我们在输入a，b时和计算dp[i][j]都做了%N运算 */

typedef long long ll;
const int N=1e6+5;
const ll p=1e9+7;

ll c[N];
void factors() {//阶乘
	for(ll i = 0; i<N; i++) {
		if(i<=1)
			c[i]=1;
		else
			c[i]=(c[i-1]%p)*i%p;
	}
}
ll binaryPow(ll a,ll b) {//快速幂
	ll ans=1;
	while(b>0) {
		if(b&1) {
			ans=ans*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
ll comp(ll n,ll m) {//Lucas
	return c[n]*binaryPow(c[m]*c[n-m]%p,p-2)%p;
}

int main() {
	factors();
	int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
		ll a,b,k,n,m;
		cin>>a>>b>>k>>n>>m;
		ll ans=comp(k,n);
		ans=(ans%p)*(binaryPow(a,n)%p)%p;
		ans=(ans%p)*(binaryPow(b,m)%p)%p;
		printf("case #%d:\n%lld\n",i,ans);
	}
	return 0;
}

/* 3
1 1 3 1 2
235823 382573 999 111 888
681692776 714636914 287579 7786 279793
 */