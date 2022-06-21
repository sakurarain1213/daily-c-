
#include <bits/stdc++.h>
using namespace std;

int n;
struct point
{
    float x;
    float  y;
};

struct dis
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

//方案三   确实快一点

int flag=0;
 struct node
{
     int v,next;
 };
 vector<node> edge;
/*  int DFN[30001],LOW[30001]; */
 vector<int> DFN(n,0),LOW(n,0);
 int /* stackk[30001],heads[30001],visit[30001], */cnt=0,tot,indexx=0;
 vector<int> stackk(n,0),heads(n,-1),visit(n,0);
void add(int x,int y)
{
    node temp;cnt++;
    temp.next=heads[x];
    temp.v=y;
    edge.push_back(temp);
     heads[x]=cnt;
    return ;
 }
 void tarjan(int x)  //代表第几个点在处理.递归的是点.
 {
     DFN[x]=LOW[x]=++tot; //新进点的初始化.
     indexx++;
     stackk.push_back(x); //进栈
     visit[x]=1;  //表示在栈里
    for(int i=heads[x];i!=-1;i=edge[i].next)
     {
         if(!DFN[edge[i].v]) //如果没访问过
{
            tarjan(edge[i].v);  //往下进行延伸,开始递归
             LOW[x]=min(LOW[x],LOW[edge[i].v]);//递归出来,比较谁是谁的儿子／父亲,就是树的对应关系,涉及到强连通分量子树最小根的事情.
           }
        else if(visit[edge[i].v ])//如果访问过,并且还在栈里
{
             LOW[x]=min(LOW[x],DFN[edge[i].v]);//比较谁是谁的儿子／父亲.就是链接对应关系
          }
     }
     if(LOW[x]==DFN[x]) //发现是整个强连通分量子树里的最小根.
    {
         do{
            //printf("%d ",stackk[indexx]);
             visit[stackk[indexx]]=0;
             indexx--;
         }while(x!=stackk[indexx+1]);//出栈,并且输出.
        flag++;//cout<<flag;// printf("\n");
     }
     return ;
 }

bool connect3()
{
    if(flag==1) return true;
    else 
    {flag=0;return false;}
}


int main()
{ios::sync_with_stdio(false);

 /*  memset(heads,-1,sizeof(heads)); */

point temp;

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
 int ans=1;  
//方案三
   /*  int a[n][n];memset(a,0,sizeof(a));  */
   // vector<vector<int> > a (n,vector<int>(n,0));
   // vector<vector<int> > b (n,vector<int>(n,0));

for(int i=0;i<n;i++)
{
    for(int j=1;j<=ans;j++)
    {
     add(i,d[i][j].point);
    }
}
  for(int i=0;i<n;i++)
         if(!DFN[i])  tarjan(i);//当这个点没有访问过,就从此点开始.防止图没走完


while(!connect3())
{
    ans++;
  
for(int i=0;i<n;i++)
{
     add(i,d[i][ans].point);//只需要增加一列
}

//再次初始化  这一步是关键

  for(int i=0;i<n;i++)
         {  DFN[i]=0;}

  for(int i=0;i<n;i++)
         if(!DFN[i])  tarjan(i);//当这个点没有访问过,就从此点开始.防止图没走完

}
  cout<<ans;
	return 0;
}

