#include<iostream>
#include<cstdio>//dfs ����ͼ ��ͨ��
using namespace std;
bool f[105][105],a[105]; //f�ڽӾ���a���߹��Ķ��������
int m,n,ans;

void ooo(int s)
{
	a[s]=1; //���
	for(int i=1;i<=n;i++)
	{
		if(!a[i]&&f[s][i]) //��������ͨ���Ҵ˵�û�б����ʹ�
		{
			m++; //�ۼ�����
			a[i]=1; //���
			ooo(i); //DFS
		}
	}
}

int main()
{
    int x,y;
	scanf("%d%d%d",&n,&x,&y);
	while(x&&y) //ĩβ��0 0ʱ��������
	{
		f[x][y]=1; f[y][x]=1; //����ͼҪ˫����
		scanf("%d%d",&x,&y);
	}
	for(int i=1;i<=n;i++)
	{
		m=0; //m��¼��ǰ������ͨ�����ж�����
		if(!a[i]) //���˵�û�б����ʹ�
		{
			ooo(i);
			ans=max(ans,m); //�ж������
		}
	}
	printf("%d",ans+1); //+1����Ϊ��ͨ�Ķ�������Ҫ�����������һ����
	return 0;
}
