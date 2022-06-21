/* //加权边 有向无环图*/
//DAG------- 邻接表版 
#include <bits/stdc++.h>
using namespace std;
const int maxv = 1000005;
const int INF = 1000000000;
/* 动态规划 + 二分
动态规划：借鉴DAG求图中的固定端点的最长路径思想，DAG中求的是最长的路径，此题求的是固定端点的最大点权路径和。
这里需要用到一个技巧：即二分试探到合适的中位数。更新每个点权，>=mid的，点权置为1，<mid的点权置为-1，如果存在一条路径的点权之和>=0, 说明存在一条路径，其中位数>=mid，因此可以试探比mid更大的数。如果最大点权路径和<0，不存在路径使得路径中位数>=mid，应该试探更小的mid。这里就用到了二分的思想了。
动态规划+二分的方法在时间性能上应该是高于DFS的，最后AC了。 */

int n,m;
bool vis[maxv] = {false};
int dp[maxv];//dp[i] 从点i到n的路径中，最大的点权之和 
int W[maxv], W2[maxv];
vector<int> Adj[maxv];

int DP(int x){
	//从x到n的路径   最大点权之和
	if(vis[x])return dp[x];
	vis[x] = true;
	for(int i=0;i<Adj[x].size();i++){
		int  j = Adj[x][i];
		dp[x] = max(dp[x], W2[x] + DP(j));
	} 
	return dp[x];
}

bool check(int mid){
	//更新点权
	for(int i=1;i<=n;i++){
		W2[i] = W[i]>=mid?1:-1;
	} 
	memset(vis,false,sizeof(vis));
	fill(dp+1,dp+1+n,-INF); 
	//设置边界 
	dp[n] = W2[n];
	vis[n] = true;
	return DP(1) >=0; 
}

int main(){
//	freopen("in3681.txt","r",stdin);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &W[i]);//读入点权 
	}
	//读入邻接表
	int x,y; 
	for(int i=0;i<m;i++){//x->y
		scanf("%d%d", &x, &y);
		Adj[x].push_back(y); 
	} 
	int low = 0, high = INF, mid;
	while(low<=high){
		mid = low + (high - low)/2;
		if(check(mid)){//mid太小了，实际上的中位数比mid大  或  恰好等于mid 
			low = mid+1; 
		}else{//mid太大了。实际上的mid比mid小 
			high = mid-1;
		} 
	}
	printf("%d\n", high);
	
	return 0;
} 


/* 

//DAG -----------------逆邻接表版 
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxv = 1000005;
const int INF = 1000000000;

int n,m;//n:顶点数  m：边数
bool vis[maxv] = {false};
int dp[maxv];//dp[i]: 从点i到n的路径中，最大的点权之和 
int W[maxv], W2[maxv];//记录点权 
vector<int> Adj[maxv];//逆邻接表 

int DP(int mid, int x){
	if(vis[x])return dp[x];
	vis[x] = true;
	for(int i=0;i<Adj[x].size();i++){
		int j = Adj[x][i];
		dp[x] = max(dp[x],DP(mid,j)+W2[x]);
	}
	return dp[x];
}


bool check(int mid){
	//求dp[n]
	memset(vis,false,sizeof(vis)); 
	for(int i=1;i<=n;i++){
		//更新权值
		W2[i] = W[i]>=mid?1:-1; 
	}
	fill(dp+1,dp+n+1,-INF);
	dp[1] = W2[1];
	vis[1] = true;
	return DP(mid, n)>=0; 
}


int main(){
//	freopen("in3681.txt","r",stdin);
	
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &W[i]);
	} 
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d", &x, &y);//x->y 逆邻接表 
		Adj[y].push_back(x);
	}
	//二分检测
	int low = 0, high = INF, mid;
	while(low<=high){
		mid = low + (high-low)/2;
		if(check(mid)){//mid比所求小 也可能等于所求 
			low = mid+1; 
		}else{//mid比所求大 
		 	high = mid-1; 
		}
	}
	printf("%d\n", high);
	return 0;
}
 */



/* 二分中位数，将图中>=mid的点的权值赋值为1,<mid赋为-1.如果1到N的最长路>=0,
那么这个最大中位数一定大于等于次中位数。 */
/* #include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define res register int 
#define inf 0x3f3f3f3f

const int maxn=1e6+10;
vector<int> v[maxn];
int val[maxn],N,M,dis[maxn],vall[maxn];
bool vis[maxn];
//struct Node{
//	int num,s;
//	bool operator<(const Node a){
//		return this->s>a.s;
//	}
//};
 
bool judge(int mid)
{
	for(int i=1;i<=N;i++){
		if(val[i]>=mid) vall[i]=1;
		else vall[i]=-1;
		dis[i]=-inf;
		vis[i]=false;
	} 
	queue<int> q;
	q.push(1);
	dis[1]=vall[1];
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=false;
		for(int i=0;i<v[x].size();i++){
			int y=v[x][i];
			if(dis[y]<dis[x]+vall[y]){
				dis[y]=dis[x]+vall[y];
				if(!vis[y]){
					q.push(y);
					vis[y]=true;	
				}
			}
		} 
	}
	if(dis[N]>=0) return true;
	else return false;
}
 
int main()
{
	int Min=inf,Max=0;
	scanf("%d%d",&N,&M);
    //取巧一下 
   /*  if(N==678822) {cout<<750163687;return 0;}
    if(N==1000000) {cout<<276315539;return 0;} */
	/* for(int i=1;i<=N;i++){
		scanf("%d",&val[i]); 
	}
	int a,b;
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	int ans=-1;
	int l=0,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		//然后求解最长路
		if(judge(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}  */
/* 
5 5
1 2 3 4 5
1 2
2 3
3 5
2 4
4 5
 */ 