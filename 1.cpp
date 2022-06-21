#include<iostream>
using namespace std ;
//vs code 里 按alt shift A 可以注释一段代码 再按可恢复
//调试
int  main ()
{
int i,a=0,b=0;
for (i=1;i<100;i+=2)
{
a+=i;
}

for (i=2;i<=100;i+=2)
{
b+=i;
}

/* 
cout<<a<<" "<<b<<endl; */
printf("%d %d",a,b);

system("pause");//可以不用


return 0;
}