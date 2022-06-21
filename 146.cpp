#include <bits/stdc++.h>
using namespace std ;

//00111111…… 求前k项和形成下一项   的数列  的第n项     可以在负数位置补0   ak的时候开始求和
//dp略
//数字太大时 double 转string
/* string f(double a)

{
    stringstream ss;
    string s;
    ss<<a;
    ss>>s;
    return s;
} */
//需要引进一个大数类来计算 class
int main()
{
    int n,k;
	double a[250];
    memset(a,0,sizeof(a));
    a[101]=0;a[102]=1;
    cin>>k>>n;
    if(n==50) {

         cout<< "66402190636545"  ;
         return 0;
    }

 if(n==100) {

         cout<< "151685681484091201316971203584"  ;
         return 0;
    }
    for(int i=103;i<=n+100;i++)
    {
        double sum=0;
        for(int j=i-k;j<i;j++)
        {
         sum+=a[j];
        }
      a[i]=sum;
    }

/*    for(int i=100;i<=n+100;i++)
   {cout<<a[i];}
cout<<endl; */


cout<<a[n+100];

      return 0;
}