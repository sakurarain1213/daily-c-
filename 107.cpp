#include <bits/stdc++.h>
using namespace std;

//dfs      8 queens
int max;
int n, sum;
int C[12];//因为行数都是1-8递增的  所以只要记录列标就行
void search(int cur)
{
	if(cur == n)
		{
                sum++;			// 递归边界. 只要走到这里,所有子必然不冲突 
               // cout<<sum<<":";//cout
			   int j;
           for( j=0;j<n;j++) //
           {  printf("%d ",C[j]+1); } //
           cout<<endl;//
        }

	else
		for(int i = 0; i < n; i++)
		{
			int ok = 1;
			C[cur] = i;		// 先尝试把第cur行的子放在第i列 
			for(int j = 0; j < cur; j++)	// 0~cur-1行验证 
				// 验证列:第j行的列是否等于第cur行的列 
				// 验证对角线: 行-列的差是否相等  行+列的和是否相等 
				if(C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j])
				{	// 再验证放的位置是否符合要求 
					ok = 0;
					break;
				}
			if(ok)
				search(cur+1);
		}
}
 
int main()
{
	cin>>n;
   if(n<4) {	cout<<EOF;return 0;}
	sum = 0;
	search(0);
	//printf("sum: %d\n", sum);
	return 0;
}