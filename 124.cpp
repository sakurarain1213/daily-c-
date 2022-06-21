#include <bits/stdc++.h>
using namespace std;//高精度乘法
/*计算n的阶乘末尾有几个0 
数据量小 可以直接暴力求值再求0

其实本质上是找5的因子个数
考虑n!的质数因子。后缀0总是由质因子2和质因子5相乘得来的。如果我们可以计数2和5的个数，问题就解决了。
显然 2的个数多于5的个数
因此只要计数5的个数就可以了。
一个简单的方法是计算floor(n/5)。例如，7!有一个5，10!有两个5。
除此之外，还有一件事情要考虑。诸如25，125之类的数字有不止一个5。
例如，如果我们考虑28!，我们得到一个额外的5，因此0的总数变成了6。
处理这个问题也很简单，首先对n/5，移除所有的单个5，然后/25，移除额外的5，以此类推。
*/
int FactorialZeros(int n) {
        int zeros = 0;
        int curr = 0;
        int i = 1;
        while( (curr = n / pow(5,i)) >= 1){
            zeros += curr;
            i++;
        }
        return zeros;
    }
int  main()
{
   int x,t;
   cin>>x;
   for(int i=0;i<x;i++)
   {
         cin>>t;
       printf("case #%d:\n",i);
       cout<<FactorialZeros(t)<<endl;
   }
    return 0;
}
 /*  cout<<GetHighest(1)<<endl;
    cout<<GetHighest(2)<<endl;
    cout<<GetHighest(3)<<endl;
    cout<<GetHighest(4)<<endl;
    cout<<GetHighest(5)<<endl;
    cout<<GetHighest(6)<<endl;
    cout<<GetHighest(4678)<<endl;
    cout<<GetHighest(1000)<<endl;
    cout<<GetHighest(1000000000)<<endl;
    cout<<GetHighest(1999)<<endl;
    cout<<GetHighest(999999999)<<endl; */