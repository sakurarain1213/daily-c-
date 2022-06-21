
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

float distance(point a,point b)//ŷʽ����
{  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}


bool cmp(const dis &a,const dis &b)
{return a.value<b.value;}


vector <point> p;//p��n���������

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
//���͸��Ӷȴ�connect������ʼ

//������   ȷʵ��һ��

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
 void tarjan(int x)  //����ڼ������ڴ���.�ݹ���ǵ�.
 {
     DFN[x]=LOW[x]=++tot; //�½���ĳ�ʼ��.
     indexx++;
     stackk.push_back(x); //��ջ
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

    //��ͼ  �����а��������� �ӱ�   //��άvector���ʸ���  ֱ��a[n][n];
   dis d[n][n];//�ڽӾ���   �������  ע��������ֵ���±�������
  memset(d,0,sizeof(d));
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
       //if(i==j) continue;
       //�����   ���±�
       d[i][j].value=distance(p[i],p[j]);
       d[i][j].point=j;
    }
    }

    //���±갴�վ�����������
    for(int i=0;i<n;i++)
    {
   sort(d[i],d[i]+n,cmp);//ֱ��+n���� ������
    }
/* d[i][j].point����
*/
 int ans=1;  
//������
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
         if(!DFN[i])  tarjan(i);//�������û�з��ʹ�,�ʹӴ˵㿪ʼ.��ֹͼû����


while(!connect3())
{
    ans++;
  
for(int i=0;i<n;i++)
{
     add(i,d[i][ans].point);//ֻ��Ҫ����һ��
}

//�ٴγ�ʼ��  ��һ���ǹؼ�

  for(int i=0;i<n;i++)
         {  DFN[i]=0;}

  for(int i=0;i<n;i++)
         if(!DFN[i])  tarjan(i);//�������û�з��ʹ�,�ʹӴ˵㿪ʼ.��ֹͼû����

}
  cout<<ans;
	return 0;
}

