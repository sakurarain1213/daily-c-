
/* Tarjan �㷨   ����ͼ */

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
 void tarjan(int x)  //����ڼ������ڴ���.�ݹ���ǵ�.
 {
     DFN[x]=LOW[x]=++tot; //�½���ĳ�ʼ��.
     stackk[++indexx]=x; //��ջ
     visit[x]=1;  //��ʾ��ջ��
    for(int i=heads[x];i!=-1;i=edge[i].next)
     {
         if(!DFN[edge[i].v]) //���û���ʹ�
{
            tarjan(edge[i].v);  //���½�������,��ʼ�ݹ�
             LOW[x]=min(LOW[x],LOW[edge[i].v]);//�ݹ����,�Ƚ�˭��˭�Ķ��ӣ�����,�������Ķ�Ӧ��ϵ,�漰��ǿ��ͨ����������С��������.
           }
        else if(visit[edge[i].v ])//������ʹ�,���һ���ջ��
{
             LOW[x]=min(LOW[x],DFN[edge[i].v]);//�Ƚ�˭��˭�Ķ��ӣ�����.�������Ӷ�Ӧ��ϵ
          }
     }
     if(LOW[x]==DFN[x]) //����������ǿ��ͨ�������������С��.
    {
         do{
            //printf("%d ",stackk[indexx]);
             visit[stackk[indexx]]=0;
             indexx--;
         }while(x!=stackk[indexx+1]);//��ջ,�������.
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
