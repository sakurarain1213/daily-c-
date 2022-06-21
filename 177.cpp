#include<bits/stdc++.h>
using namespace std;
/*
dp  区间覆盖 可以重复  的最小耗材是多少  线段树
给定 n 个点，m 个操作，每次操作可以将第Li  个点到第 Ri 个点覆盖，耗费是 Wi。
个人打算dfs   其实还是dp  就是加了一个权值wg最小


我们设 dp[i]为区间长度为 [i] 时的最大权值和，
我们用vec[r]存右端点为r的区间，那么转移方程就为 dp[i]=max(dp[i],dp[veg[i][j]-1]+wg[veg[i][j][i]]) ，
如果不存在终点为i的区间那么就从 [公式] 转移过来。

*/
//

typedef long long ll;
struct node{
    ll l,r;
}obj[505];
ll n;
ll wg[505][505];
vector<ll>vec[505];
ll dp[505];
bool cmp(node a,node b){
    if(a.r != b.r)return a.r < b.r;
    return a.l < b.l;
}
void solve(){
    memset(wg,0,sizeof(wg));memset(dp,0,sizeof(dp));
    for(int i = 1;i <= 504;i++)vec[i].clear();
    for(int i = 1;i <= n;i++){
        ll a,b;scanf("%lld%lld",&a,&b);
        obj[i].l = a + 1;obj[i].r = n - b;
        if(wg[obj[i].l][obj[i].r]+a+b<n){//wa的关键点啊啊啊啊啊啊啊！！！记得加上本组已有人数dnmd
            wg[obj[i].l][obj[i].r]++;
            vec[obj[i].r].push_back(obj[i].l);
        }
        //cout << obj[i].l << " " << obj[i].r << endl;
    }
    //sort(obj+1,obj+1+n,cmp);//排序不排序都无所谓，刚刚开始贪心的想就排序了，其实不用排序
    //因为下面根本没用到这个数组。。用到的是vectordp本身就是根据i也就是终点
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i-1];//继承
        for(int j = 0;j < vec[i].size();j++){
            dp[i] = max(dp[i],dp[vec[i][j]-1]+wg[vec[i][j]][i]);
        }
    }
    printf("%lld\n",dp[n]);
}
int main(){
    while(~scanf("%lld",&n))solve();
}
/* 
3





10 4 6
7 9 11
6 9 13
7 7 7
3 5 6





10 7 1
3 4 15
8 9 8
5 6 8
9 10 6
1 4 2
1 4 10
8 10 13





10 5 5
7 9 18
3 6 12
1 2 4
5 7 5
6 10 30

 */
/* 
const int N = 100006, INF = 0x3f3f3f3f;
int n, l, r, f[N];
struct T {
	int l, r, x;
	bool operator < (const T w) const {
		return r < w.r;
	}
} a[N], t[N<<2];
 
void build(int p, int l, int r) {
	t[p].l = l;
	t[p].r = r;
	if (l == r) {
		t[p].x = f[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].x = min(t[p<<1].x, t[p<<1|1].x);
}
 
void change(int p, int x, int y) {
	if (t[p].l == t[p].r) {
		t[p].x = y;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) change(p << 1, x, y);
	else change(p << 1 | 1, x, y);
	t[p].x = min(t[p<<1].x, t[p<<1|1].x);
}
 
int ask(int p, int l, int r) {
	if (l <= t[p].l && r >= t[p].r) return t[p].x;
	int mid = (t[p].l + t[p].r) / 2, ans = INF;
	if (l <= mid) ans = min(ans, ask(p << 1, l, r));
	if (r > mid) ans = min(ans, ask(p << 1 | 1, l, r));
	return ans;
}
 
void solve(int n,int l,int r)//n个小区间 去覆盖完l到r 就是k
{
    	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].x);
	sort(a + 1, a + n + 1);
	memset(f, 0x3f, sizeof(f));
	f[l] = 0;
	build(1, l, r);
	for (int i = 1; i <= n; i++) {
		f[a[i].r] = min(f[a[i].r], ask(1, a[i].l - 1, a[i].r) + a[i].x);
		change(1, a[i].r, f[a[i].r]);
		if (a[i].r >= r) {
			if (f[a[i].r] == INF) puts("-1");
			else cout << f[a[i].r] << endl;
		}
	}
}
 */