/* k近邻问题
平面坐标 一个点  与之最近的k个点 
仅当vj是vi的k近邻，且vi是vj的k近邻时，才把vi与vj连接起来。这样得到的图称为混合k-近邻图   无向图
给n个点   求最小的k 让全图连通

具体知识
最小连通图   
图中 构建边的方式总结    查找 按照距离排序  
有向图化无向图  最多两边 所以两个矩阵加一下  取2为1 1和0为0即可
 用二维矩阵存或者  邻接表  邻接表好处是连通判断快一点
判断连通性   dfs   bfs  并查集  另外两种
*/
#include <bits/stdc++.h>
using namespace std;

//面向过程思路

struct point
{
   double x;
   double y;
   int num;
};

struct dis//距离结构 但是要带点的下标
{
double value;
int point;
};


double distance(point a,point b)//欧式距离
{  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}


bool cmp(const dis &a,const dis &b)
{return a.value<b.value;}


vector <point> p;//p存n个点的坐标


vector <int> visit(30000,0);int m=0,cnt=0;
void ooo( vector<vector<int> > &a,vector<int> &visit,int n,int s)
{
	visit[s]=1; //标记
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]&&a[s][i]) //当两点连通并且此点没有被访问过
		{
			m++; //累计总数
			visit[i]=1; //标记
			ooo(a,visit,n,i); //DFS
		}
	}
}

bool connect(   vector<vector<int> > &a,int n)
{
  for(int i=0;i<n;i++)
	{
		m=0; //m记录当前顶点连通的所有顶点数
		if(!visit[i]) //当此点没有被访问过
		{
			ooo(a,visit,n,i);
			cnt=max(cnt,m); //判断最大数
		}
	}
	if (cnt==2)return true; //+1是因为连通的顶点数还要加上它本身的一个点
    return false;
}




int main()
{
point temp;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>temp.x>>temp.y;temp.num=i;
    p.push_back(temp);
}


   dis d[n][n];
  memset(d,0,sizeof(d));
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
     
       d[i][j].value=distance(p[i],p[j]);
       d[i][j].point=j;
    }
    }

    for(int i=0;i<n;i++)
    {
   sort(d[i],d[i]+n,cmp);//直接+n即可 很智能
    }

 int ans=0;  
  
    int a[n][n];memset(a,0,sizeof(a)); 
  vector<vector<int> > b (n,vector<int>(n,0));//初始化为0  n分别为行和列

while(!connect(b,n))//二维数组传参是个难点
{
visit.resize(30000,0);
    ans++;
       for(int i=0;i<n;i++)//a不动  b由a生成 每次都在变  此时清零
    { for(int j=0;j<n;j++)
    { b[i][j]=0;}}


     for(int i=0;i<n;i++)
    {
    for(int j=1;j<=ans;j++)
    {
       a[i][  d[i][j].point  ]++;
    }
    }

    for(int i=0;i<n;i++)
    {
    for(int j=0;j<i;j++)//下三角即可
    {
      if(a[i][j]&&a[j][i])   
      {b[i][j]=1;b[j][i]=1;}
    }
    }

}


  cout<<ans;
	return 0;
}

/* 
10
0.13 56.36
19.33 80.87
58.50 47.99
35.03 89.60
82.28 74.66
17.41 85.89
71.05 51.35
30.40 1.50
9.14 36.45
14.73 16.59
*/