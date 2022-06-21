#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std ;
int  main ()
{
 
char a[1000];int m=0;
char b[]={'a','d','g','j','m','p','t','w','^'};//0-7,8
cin.getline(a,1000);
int n=strlen(a);
for (int i=0;i<=n;i++)
{
    if (a[i]==' ') m++;
    else
    { 
    for (int j=0;j<=7;j++)
    {
       if (a[i]<b[j+1]&&a[i]>=b[j])
      { m+=(a[i]-b[j]+1);
      j=10;}
    }
    }
}
cout << m;
return 0;
}