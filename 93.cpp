#include <bits/stdc++.h>
using namespace std;

//求最少操作数 使一个数列成为等差数列
int main (){
//方法 拟合/*思路：y=kx+b变成拟合y=b 相当于将各点均先减去k*x；减完后各点排序，可以证明中间这个数为b   差值最小。*/
	long long int n,k;cin>>n>>k;
	long long int a[n];long long int sum=0,t;
	for(int i = 0; i < n; i++) {
		cin>>t;
		a[i]=t-i*k;}
	sort(a,a+n);
/* for(int i = 0; i < n; i++) {cout<<a[i];} */
	long long int b;                     //b本质上就是首项
	if(n%2==1)    {b=a[n/2];  }           //奇数时就是中间           
	else   {b=(a[n/2]+a[n/2-1])/2; }      //偶数时要为中间数的均值	
	if(b<0)   b=0;                      //首项不能小于0
	for(int i =0; i < n; i++) {//求每一项到基准b的距离 就是每一项的操作数
		sum+=fabs(a[i]-b);}
//cout<<"case #" << x << ":\n";
cout<<sum<<endl;
return 0;
}