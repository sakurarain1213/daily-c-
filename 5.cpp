#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std ;

int  main ()
{
int n;
double t;
cin >> t>>n;
cout <<fixed<< setprecision(3)<<t/n<< endl << 2*n;

return 0;
}