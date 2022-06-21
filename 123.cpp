#include <bits/stdc++.h>
using namespace std;//高精度乘法
/* N^N = 10^(N*log(N))中，
由于 N <1000000000，
N*log(N)取值在[0,9000000000]，没有超出double数据的范围，没有益处。
设N*log(N)的整数部分为intpart，分数部分为fractpart，
则N^N = 10^(intpart + fractpart) = 10^intpart * 10^fractpart.
其中10^intpart肯定为10的倍数，不影响结果，可忽略。
所以：
10^fractpart的最高位即为结果。
不用大数，double即可满足。  */

int GetHighest(const double & n)
{
//求n^n的最高位
//注意：n取 1，2，3，...，1000000000
    double intpart;
    double fractpart = modf ( n * log10(n), &intpart);
    //显然分数部分在[0,1)之间，所以temp在[1,10)之间，那么整数部分即为结果
    double temp = pow( (double)10, fractpart);
    modf ( temp, &intpart);
    return intpart;
}

int  main()
{
    //cout<<numeric_limits<double>::max()<<endl;
       int t;
       cin>>t;
       while(t>0){
         cout<<GetHighest(t)<<endl;
          cin>>t;}
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