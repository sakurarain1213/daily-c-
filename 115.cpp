 #include <bits/stdc++.h>
using namespace std;
int m,n,p,q,mini=99999;    // p q是终点坐标 
int a[100][100];     // 初始化地图数组   1表示空地，2表示障碍物 
int v[100][100];     // 访问数组  0表示未访问，1表示访问 
int dx[4] = {0,1,0,-1};   // 方向数组 
int dy[4] = {1,0,-1,0};
 
void dfs(int x,int y,int step){
	if(x==p && y==q){
		if(step<mini) 
			mini= step;
		return;     // return 用来回溯	
	}
	// 顺时针试探
	for(int k=0;k<=3;k++){
		int tx,ty;  // 表示下一个方向
		tx = x+dx[k];
		ty = y+dy[k];
		if(a[tx][ty]==1 && v[tx][ty]==0){
			v[tx][ty]=1;
			dfs(tx,ty,step+1);
			v[tx][ty]=0;
		} 
	}
	return; 
}
/*
测试样例：
5 4
1 1 0 1
1 1 1 1
1 1 0 1
1 0 1 1
1 0 1 0


1 1
2 1
*/
int main(){
	int startx,starty;  // 起点终点坐标 
	scanf("%d%d",&m,&n);  //输入m行n列
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);  // 1表示空地，2表示障碍物 
		}
	} 
	scanf("%d%d%d%d",&startx,&starty,&p,&q); 
	v[startx][starty]=1;   //从起点进行深度优先搜索  首先要把其设为 已访问 
	dfs(startx,starty,0);
	printf("%d",mini);
	return 0;	
}