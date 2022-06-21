#include<iostream>
#include<cstdio>//dfs 无向图 连通性
using namespace std;
bool f[105][105],a[105]; //f邻接矩阵，a给走过的顶点做标记
int m,n,ans;

void ooo(int s)
{
	a[s]=1; //标记
	for(int i=1;i<=n;i++)
	{
		if(!a[i]&&f[s][i]) //当两点连通并且此点没有被访问过
		{
			m++; //累计总数
			a[i]=1; //标记
			ooo(i); //DFS
		}
	}
}

int main()
{
    int x,y;
	scanf("%d%d%d",&n,&x,&y);
	while(x&&y) //末尾是0 0时结束输入
	{
		f[x][y]=1; f[y][x]=1; //无向图要双向处理
		scanf("%d%d",&x,&y);
	}
	for(int i=1;i<=n;i++)
	{
		m=0; //m记录当前顶点连通的所有顶点数
		if(!a[i]) //当此点没有被访问过
		{
			ooo(i);
			ans=max(ans,m); //判断最大数
		}
	}
	printf("%d",ans+1); //+1是因为连通的顶点数还要加上它本身的一个点
	return 0;
}
