#include <bits/stdc++.h>
using namespace std;
//高数简易编程题
int  main ()
{

/* double y[100];
y[1]=4;y[2]=4.25;
for(int i=3;i<100;i++)
{
    y[i]=108-815/y[i-1]+1500/y[i-1]/y[i-2];
}
for(int i=3;i<100;i++)
{
cout<<i<<"  "<<y[i]<<endl;
} */
//结果 
/* 3  4.47059
4  4.64474
5  4.77054
6  4.8557 
7  4.91085
8  4.94554
9  4.96696
10  4.98007
11  4.98841
12  5.00147
13  5.16964
14  8.36288
15  45.2412
16  93.9501
17  99.6781
18  99.9839
19  99.9992
20  100
31  100 */



double y[100];
y[1]=pow(2,0.5)/2;y[2]=pow(2,0.5)/2;y[3]=pow(2,0.5)/2;
for(int i=4;i<100;i++)
{
    y[i]=sin(12211*asin(y[i-1]));
}
for(int i=2;i<100;i++)
{
cout<<i<<"  "<<y[i]<<endl;
}

//浮点数有误差   结果均为y1；

return 0;
}