
/* Tarjan 算法   有向图 */

#include <bits/stdc++.h>
using namespace std;

int flag=0;
 struct node
{
     int v,next;
 }edge[1001];
 int DFN[1001],LOW[1001];
 int stackk[1001],heads[1001],visit[1001],cnt,tot,indexx;
void add(int x,int y)
{
     edge[++cnt].next=heads[x];
     edge[cnt].v = y;
     heads[x]=cnt;
    return ;
 }
 void tarjan(int x)  //代表第几个点在处理.递归的是点.
 {
     DFN[x]=LOW[x]=++tot; //新进点的初始化.
     stackk[++indexx]=x; //进栈
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
        flag++;cout<<flag;// printf("\n");
     }
     return ;
 }
 int main()
 {
    memset(heads,-1,sizeof(heads));
   int m,n;
   cin>>n>>m;
    int x,y;
     for(int i=1;i<=m;i++)
     {
         scanf("%d%d",&x,&y);
        add(x,y);
     }
    for(int i=1;i<=n;i++)
         if(!DFN[i])  tarjan(i);
    return 0;
 }
/* 
input:
6 3
4 6
4 1
5 6
output:
6
5
3 4 2 1

 */
