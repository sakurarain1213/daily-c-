/* k��������
ƽ������ һ����  ��֮�����k���� 
����vj��vi��k���ڣ���vi��vj��k����ʱ���Ű�vi��vj���������������õ���ͼ��Ϊ���k-����ͼ   ����ͼ
��n����   ����С��k ��ȫͼ��ͨ

����֪ʶ
��С��ͨͼ   
ͼ�� �����ߵķ�ʽ�ܽ�    ���� ���վ�������  
����ͼ������ͼ  ������� �������������һ��  ȡ2Ϊ1 1��0Ϊ0����
 �ö�ά��������  �ڽӱ�  �ڽӱ�ô�����ͨ�жϿ�һ��
�ж���ͨ��   dfs   bfs  ���鼯  ��������
*/
#include <bits/stdc++.h>
using namespace std;

//�������˼·

struct point
{
   double x;
   double y;
   int num;
};

struct dis//����ṹ ����Ҫ������±�
{
double value;
int point;
};


double distance(point a,point b)//ŷʽ����
{  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}


bool cmp(const dis &a,const dis &b)
{return a.value<b.value;}


vector <point> p;//p��n���������


vector <int> visit(30000,0);int m=0,cnt=0;
void ooo( vector<vector<int> > &a,vector<int> &visit,int n,int s)
{
	visit[s]=1; //���
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]&&a[s][i]) //��������ͨ���Ҵ˵�û�б����ʹ�
		{
			m++; //�ۼ�����
			visit[i]=1; //���
			ooo(a,visit,n,i); //DFS
		}
	}
}

bool connect(   vector<vector<int> > &a,int n)
{
  for(int i=0;i<n;i++)
	{
		m=0; //m��¼��ǰ������ͨ�����ж�����
		if(!visit[i]) //���˵�û�б����ʹ�
		{
			ooo(a,visit,n,i);
			cnt=max(cnt,m); //�ж������
		}
	}
	if (cnt==2)return true; //+1����Ϊ��ͨ�Ķ�������Ҫ�����������һ����
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
   sort(d[i],d[i]+n,cmp);//ֱ��+n���� ������
    }

 int ans=0;  
  
    int a[n][n];memset(a,0,sizeof(a)); 
  vector<vector<int> > b (n,vector<int>(n,0));//��ʼ��Ϊ0  n�ֱ�Ϊ�к���

while(!connect(b,n))//��ά���鴫���Ǹ��ѵ�
{
visit.resize(30000,0);
    ans++;
       for(int i=0;i<n;i++)//a����  b��a���� ÿ�ζ��ڱ�  ��ʱ����
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
    for(int j=0;j<i;j++)//�����Ǽ���
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