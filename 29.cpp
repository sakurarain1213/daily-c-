#include <bits/stdc++.h>

using namespace std;

string itoa(long long int n,int radix)    //n是待转数字，radix是指定的进制
{   string ans="";bool flag=false;
    if(n<0)
    {
   flag=true;//负整数
    n=-n;
    }


	do{
		int t=n%radix;
		if(t>=0&&t<=9)	ans+=t+'0';
		else ans+=t-10+'A';
		n/=radix;
	}while(n!=0);	//使用do{}while（）以防止输入为0的情况
if(flag)ans+='-';
	reverse(ans.begin(),ans.end());
	return ans;
}

void f(int n)
{
 long long int a,b;
	  cin>>a>>b;
    //char s1[1000],s2[1000];
   cout<<itoa(a,b)<<endl;
}

int main()
{

int n;
cin>>n;
for (int i=0;i<n;i++)
f(i);
    return 0;
}

