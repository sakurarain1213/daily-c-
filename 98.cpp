#include <bits/stdc++.h>
using namespace std;

//身份证校验码计算
//please put full id card number
int  main ()
{
string s;
cin>>s;
//int n=s.length();
int a[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//0-16
char b[]={'1','0','X','9','8','7','6','5','4','3','2'};//0-10
int sum=0;
for(int i=0;i<17;i++)
{
sum+=(s[i]-'0')*a[i];
}
sum%=11;
cout<<b[sum];
return 0;
}