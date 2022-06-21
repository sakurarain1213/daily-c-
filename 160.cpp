#include <bits/stdc++.h>
//球队得分  还是结构体多级排序

using namespace std;
struct g {
	int vec=0;
	int def=0;
	int index;
	int sum=0;
};
bool cmp(g a,g b) {
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else {
		if(a.vec!=b.vec)
			return a.vec>b.vec;
		else {
			if(a.def!=b.def)
				return a.def<b.def;
			else
				return a.index<b.index;
		}
	}
}
int main() {
	int n,m;
	while(cin>>n>>m) {
		if(n==0&&m==0)
			break;
		g G[n+1];
		for(int i = 1; i < n+1; i++) {
			G[i].index=i;
			G[i].def=0;
			G[i].sum=0;
			G[i].vec=0;
		}
		for(int i = 0; i < m; i++) {
			int a,b,c;
			cin>>a>>b>>c;
			if(c==1) {
				G[a].sum+=3;
				G[b].sum--;
				G[a].vec++;
				G[b].def++;
			} else if(c==-1) {
				G[b].sum+=3;
				G[a].sum--;
				G[b].vec++;
				G[a].def++;
			} else {
				G[a].sum++;
				G[b].sum++;
			}
		}
		sort(G+1,G+n+1,cmp);
		for(int j = 1; j < n+1; j++) {
			cout<<G[j].index;
			if(j<n)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}



/* 
4 4
1 2 1
2 1 1
3 4 1
3 4 -1
4 1
1 3 -1
4 1
3 2 0
4 4
4 1 1
3 2 0
3 2 0
3 1 0
4 2
3 1 1
1 4 0
0 0
 */
