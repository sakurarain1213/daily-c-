#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;

int  main ()
{
double a[101],s=0;
int i,j;
cin >> i;
a[1]=1;
for (i=1;i<=100;i++)
      {a[i+1]=a[i]/(1+sqrt(a[i]));
      
      }
for ( j=1;j<=100;j++)
      {
       s+=a[j];
      }

cout <<s << endl;
cout <<"test 1"<< endl;
cout <<"test 2";

return 0;
}