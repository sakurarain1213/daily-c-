/*
在所有素数中，只有2为偶数，故大于三个时，一定不能构成素数序列。
素数子序列 0表示可以乱填  求填法 让任意连续子序列和为质数
分类讨论题又开始了。这个题本身难度不大，但是可能相对其他题更容易自闭一点吧。
·n=1：给一个质数可以。如果要填的话，就填一个质数。
·n=2：如果p1>2且p2>2，显然不行。所以肯定有一个等于2，不妨令p1=2（等会别忘了讨论p2=2的，或者reverse一下），只要检查p2和p2+
是不是都是素数即可（孪生素数）。建议的写法是把所有可能的填法都填一遍然后再检查。如果两个数都可以乱填，那就…….乱填。
n=3：只有232]这一种情况（给在样例里了）。证明援引三胞胎素数：当素数p大于3时，可以证明形同（p，p+2，p+4）的数组不可能是三胞胎素数。
事实上，这三个数对3的模两两不同，所以必然有一个能被3整除。然而这三个数都比3要大，因此一定有一个是3的倍数，从而这个数不是素数。
n24：无解。首先两个奇数不能相邻，所以肯定是类似2p2p...这样的形式（其中p是大于等于3的质数），而一旦出现p2p，2+2p一定是偶
*/
#include <bits/stdc++.h>
using namespace std;
bool isprim(int n)
{
	if(n<2)
	return false;
	int p = sqrt(n);
	for(int i = 2; i <= p; i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		if(a[0]==0)
		cout<<"2";
		else if(isprim(a[0]))
		cout<<a[0];
		else
		cout<<"Impossible";
	}
	else if(n==2)
	{
		if(a[1]&&a[0])
		{
			if(isprim(a[0])&&isprim(a[1])&&isprim(a[0]+a[1]))
			cout<<a[0]<<" "<<a[1];
			else 
			cout<<"Impossible";
		}
		else if(a[0]==0&&a[1]==0)
		cout<<"2 3"<<endl;
		else if(a[1])
		{
			if(a[1]==2)
			cout<<"3 2"<<endl;
			else if(isprim(a[1])&&isprim(a[1]+2))
			cout<<2<<" "<<a[1]<<endl;
			else 
			cout<<"Impossible";
		}
		else
		{
			if(a[0]==2)
			cout<<"2 3"<<endl;
			else if(isprim(a[0])&&isprim(a[0]+2))
			cout<<a[0]<<" "<<2<<endl;
			else 
			cout<<"Impossible";
		}
	}
	else if(n==3)
	{
		int f=0;
		int p[3]={2,3,2};
		for(int i = 0; i < 3; i++)
		{
			if(a[i])
			{
				if(a[i]!=p[i])
				f=1;
			}
		}
		if(f)
		cout<<"Impossible";
		else
		cout<<"2 3 2";
	}
	else
	cout<<"Impossible";
	return 0;
 } 
/*  
3
2 0 2
 */