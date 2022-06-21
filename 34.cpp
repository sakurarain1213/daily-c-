#include <bits/stdc++.h>
using namespace std ;

//最大子序列的分治算法  线性时间 O(n)
int  main ()
{

int a[]={1,2,-4,4,5,6,-8,7};
int maxsum=a[0],sum=a[0];

 for (int i= 1; i < sizeof(a)/sizeof(int); i++ )
      {
                  sum += a[i];
                  if(sum < 0) { // 分界点，重新求和
                          sum = 0;
                  } else {
                          if (sum > maxsum ){
                                  maxsum = sum;// 记录最大和
                          }
                  }
      }

cout<<maxsum;


return 0;
}