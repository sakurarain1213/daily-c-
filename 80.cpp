
#include <bits/stdc++.h>
using namespace std;
#define max 10000
#define t 3
int  main ()
{
int a;
srand(time(NULL));
int x=max;
int b[t];
memset(b,0,sizeof(b));
while(x>0)
{
a=rand()%t;
b[a]++;

    x--;
}

for(int i=0;i<t;i++)
{
    cout<<1.0*b[i]/max<<" ";
}
return 0;
}


