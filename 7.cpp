#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std ;

int f(int a)
{ return a/100;}
int g(int a)
{ return (a/10)%10;}
int h(int a)
{ return a%10;}

int  main ()
{
int i,j;
int a[10]={0,0,0,0,0,0,0,0,0,0};
for (i=123;i<=329;i++)
{a[f(i)]++;a[g(i)]++;a[h(i)]++;
 a[f(2*i)]++;a[g(2*i)]++;a[h(2*i)]++;
 a[f(3*i)]++;a[g(3*i)]++;a[h(3*i)]++;
  for (j=1;j<=9;j++)
  {if (a[j]==0||a[j]>1) j=100;}
  if (j==10)
  {cout <<i<<" "<<2*i<<" "<<3*i<<endl;}
memset(a,0,sizeof(a));
}
return 0;
}