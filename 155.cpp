#include <bits/stdc++.h>
using namespace std ;

//开方函数也可以用二分做
 long long f(int x) {
    long long i = 0;
    long long j = x;
    while (i <= j) {
        long long mid = (i +j) / 2;
        if (mid * mid < x)
            i = mid + 1;
        else if (mid * mid > x)
            j = mid - 1;
        else
            return mid;
    }
    return j;
}

int main()
{
  long long x;
  cin>>x;
  cout<<floor(sqrt(x));
return 0;
}


