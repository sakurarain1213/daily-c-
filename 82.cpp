#include <bits/stdc++.h>
using namespace std;

bool pan(unsigned long long n) { //middle
	long long stop = sqrt(n) + 1;
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= stop; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long int f(long long int n)
{
if(pan(n)) return 1;
else if(n%2==0) return n/2;
else 
{
double m=n;
for (long long int i=3;i<=floor(sqrt(m)) ;i++)
{
    if(n%i==0) return m/i;break;
}
}
}

int  main ()
{
long long int a,b;
 cin>>a>>b; 
long long int max=1;
 for(long long int i=b;i>=a;i--)
{
    if(f(i)>max)max=f(i);
}
cout<<max;








return 0;
}