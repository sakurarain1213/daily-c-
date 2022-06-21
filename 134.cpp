/*
思路：循环小数时即余数相同就是循环体。计算机内部表示的浮点数只有有限的精确位数。现在要找一种方法，使一个分数的精确值能够被表示为十进制小数，如果是一个无限循环小数，则指出它从哪一位到哪一位是循环节。
*/
#include<iostream>
using namespace std;
void f(int n,int m) {
	int flag[m+1]= {0};
	flag[n%m]=1;
	string s;
	s+=to_string(n/m);
	s+='.';
	n%=m;
	int index=2;
	while(n%m!=0) {
		n*=10;
		s+=to_string(n/m);
		n%=m;
		if(flag[n]) {
			cout<<s<<endl;
			cout<<flag[n]<<"-"<<index-1<<endl;
			return ;
		} else
			flag[n]=index++;
	}
	cout<<s<<endl;
}
void solve(int n,int m) {
	int rmdr[10000]= {0};//存余数
	int j=1;
	int t=n/m;
	rmdr[n%m]=j++;
	n%=m;
	cout<<t<<'.';
	while(n%m!=0) {
		n*=10;
		cout<<n/m;
		n%=m;
		if(rmdr[n]) {
			cout<<endl;
			cout<<rmdr[n]<<"-"<<j-1<<endl;
			return ;
		} else
			rmdr[n]=j++;
	}
	cout<<endl;
}
int main() {
	int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
		int n,m;
		cin>>n>>m;
		printf("case #%d:\n",i);
		solve(n,m);
	}
	return 0;
}
