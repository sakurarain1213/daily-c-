/*
判断无向图G是否连通。
若连通返回1，否则返回0 
*/

#include <bits/stdc++.h>
using namespace std;
  
#define N 1 >> 8 //代替无穷大（默认 邻接矩阵） 
int n;
vector <int> flag = {0};//无向图 只要每个顶点至少有一条边 就连通 
int judgment(vector <vector <int > > a,int n)
{
	for(int i = 0;i <n;i ++)
	{
		for(int j = 0;j <= i;j ++)
		{
			if(a[i][j] != N && flag[j] != 1)
			{
				flag[j] = 1;
			}
		}
	}
	
	int k = 0;
	while(flag[k]){k ++;}
 
	if(k ==n)
	{
		return 1;
	}
 
	return 0;
}
 
int main()
{
    int n;
    cin>>n;
	//测试 邻接矩阵（用邻接矩阵 表示图） 
	  vector<vector<int> > a (n,vector<int>(n,0));


	
	printf("%d",judgment(a,n));
	
	return 0;
}
