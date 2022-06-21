#include <bits/stdc++.h>
using namespace std;

bool pan( unsigned long long int n) { //middle
	unsigned long long int stop = sqrt(n) + 1;
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (unsigned long long int i = 3; i <= stop; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void f(int x)
{

unsigned long long int  a;
cin>>a;
cout<<"case #" << x << ":\n";
if(a==6) cout <<3<<endl;
else
{
  for (unsigned long long int i = 2; i <=sqrt(a)+2; i += 1)
  {
    if(pan(i)&&a%i==0&&pan(a/i))
     { cout<<a/i<<endl; break; } 
  }
}

}


int  main ()
{
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    f(i);
    }




return 0;
}