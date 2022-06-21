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
    float x;
    float  y;
};

struct dis//距离结构 但是要带点的下标
{
float value;
int point;
};


float distance(point a,point b)//欧式距离
{  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}


bool cmp(const dis &a,const dis &b)
{return a.value<b.value;}


vector <point> p;//p存n个点的坐标

bool connect(   vector<vector<int> > &a,int n)
{
  for(int k=0;k<n;k++) 
    for(int i=0;i<n;i++) 
    if(a[k][i]) 
      for(int j=0;j<n;j++) 
        if(a[i][k]&&a[k][j]){ 
          a[i][j]=1; 
        } 
  for(int i=0;i<n;i++) 
   for(int j=0;j<n;j++) 
   { 
    if(a[i][j]+a[j][i]==0){  
      return false;}  
   } 
  return true;
}
//降低复杂度从connect函数开始


int main()
{ios::sync_with_stdio(false);
point temp;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>temp.x>>temp.y;
    p.push_back(temp);
}

    //建图  过程中按距离排序 加边   //二维vector访问复杂  直接a[n][n];
   dis d[n][n];//邻接矩阵   距离矩阵  注意距离包含值和下标两部分
  memset(d,0,sizeof(d));
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
       //if(i==j) continue;
       //算距离   算下标
       d[i][j].value=distance(p[i],p[j]);
       d[i][j].point=j;
    }
    }

    //对下标按照距离逐行排序
    for(int i=0;i<n;i++)
    {
   sort(d[i],d[i]+n,cmp);//直接+n即可 很智能
    }
/* d[i][j].point形如
*/
 int ans=0;  

   /*  int a[n][n];memset(a,0,sizeof(a));  */
    vector<vector<int> > a (n,vector<int>(n,0));
    vector<vector<int> > b (n,vector<int>(n,0));

while(!connect(b,n))
{
    ans++;
       for(int i=0;i<n;i++)//a不动  b由a生成 每次都在变  此时清零
    { for(int j=0;j<n;j++)
    { b[i][j]=0;}}


     for(int i=0;i<n;i++)
    {
    for(int j=1;j<=ans;j++)//前ans列 不含0列
    {
       a[i][  d[i][j].point  ]++;
    }
    }
/*  a[i][j]形如  不对称 */
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<i;j++)//下三角即可
    {
      if(a[i][j]&&a[j][i])   
      {b[i][j]=1;b[j][i]=1;}//后半句可以不要
    }
    }

}
  cout<<ans;
	return 0;
}

