
#include <bits/stdc++.h>

using namespace std;
int n;
int r;
int a[25];
int mark[25];
int main()
{
	memset(mark,0,sizeof(mark));
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	a[i]=i;
	for(int i=r+1;i<=n;i++)
	mark[i]=1;
	/*
	cout<<"a[i] is"<<endl;
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	cout<<"mark is"<<endl;
	for(int i=1;i<=n;i++)
	cout<<mark[i]<<" ";
	cout<<endl;
	*/
	int flag=0;
	do{
		if(flag==0)
		flag=1;
		else
		cout<<endl;
		for(int i=1;i<=n;i++)
			if(mark[i]==0)
			{
				if(a[i]/10==0)
				cout<<"  "<<a[i];
				else
				cout<<" "<<a[i];
			}
			
		
	}while(next_permutation(mark+1,mark+n+1));
	return 0;
}