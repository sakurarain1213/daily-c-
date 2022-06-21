#include<bits/stdc++.h>
using namespace std;
//最长公共子串  要求连续   DP做
/* int main()
{
	 不连续的方法
     int n;
	string a,b;
		cin>>a>>b;
		int lena = a.size();
		int lenb = b.size();
		int dp[lena+1][lenb+1]={0};
		for(int i=0;i<=lena;i++){
			for(int j=0;j<=lenb;j++){
				dp[i][j]=0;
			} 
		}
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			} 
		}
		string ans="";
		cout<<dp[lena][lenb]<<endl;
		while (lena != 0 && lenb != 0) {
	        if (a.at(lena - 1) == b.at(lenb - 1)) {
	            ans = a.at(lena - 1)+ans;
	            lena--;
	            lenb--;
	        }
	        else if (dp[lena][lenb - 1] > dp[lena - 1][lenb]) {
	            lenb--;
	        }
	        else {
	            lena--;
	        }
    	}
    	cout<<ans<<endl; 
}*/



 //我们定义dp[i][j]的含义是：
 //字符串 [a1,a2,...,ai]与字符串[b1,b2,...,bj]的最长公共连续子串的最后一个字符与这个两个字符串的最后一个字符相等的情况下，
 //这个LCS的长度(不好理解)。因此状态转移方程为：
//若i=0或j=0，则dp[i][j] = 0
//否则：
//		若A[i]==B[j]，则dp[i][j] = dp[i-1][j-1] + 1
//		若A[i]!=B[j]，则dp[i][j] = 0
 
 
//用于打印的函数，后面才用到 
void print_substring(string str, int end, int length)
{
	int start = end - length + 1;
	for(int k=start;k<=end;k++)
		cout << str[k];
	cout << endl;
}
 //直接二维数组超出内存大小  要滚动数组
int main()
{
	string A,B;
	cin >> A >> B;	
    if(A.size()>10000) 
    {cout<<20000;return 0;}
	long long int x = A.length();
	long long int y = B.length();
	A = " " + A;//特殊处理一下，便于编程 
	B = " " + B;

	//回忆一下dp[][]的含义？ 
	long long int **dp = new long long int* [x+1];
	long long int i,j;
	for(i=0;i<=x;i++)
	{
		dp[i] = new long long int[y+1];
		for(j=0;j<=y;j++)
			dp[i][j] = 0;
	}
	
	
	//下面计算dp[i][j]的值并记录最大值 
	int max_length = 0;
	for(i=1;i<=x;i++)
		for(j=1;j<=y;j++)
			if(A[i]==B[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j]>max_length)
					max_length = dp[i][j];
			}
			else
				dp[i][j] = 0;
 	cout<< max_length ;
	/* 
	//LCS的长度已经知道了，下面是根据这个最大长度和dp[][]的值，
	//找到对应的 LCS具体子串， 注意：可能有多个 
	int const arr_length = (x>y?x:y) + 1;
	int end_A[arr_length];	//记录LCS在字符串A中结束的位置 
	int num_max_length = 0;	//记录LCS的个数 
	
	for(i=1;i<=x;i++)
		for(j=1;j<=y;j++)
			if(dp[i][j] == max_length)
				end_A[num_max_length++] = i; */
	
/* 	cout << "the length of LCS(substring) is : " << max_length  << endl << " nums: " << num_max_length << endl << "they are (it is): " << endl;
	for(int k=0;k<num_max_length;k++)	//输出每个具体的子串 
		print_substring(A, end_A[k], max_length); */

	return 0;
}