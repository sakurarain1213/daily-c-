#include <bits/stdc++.h>
using namespace std;
//map映射
//multiset  时刻保持有序
int  main ()
{
int n;
cin>>n;
map <int ,string> m;
map <int ,string> ::iterator i ;
for(int j=0;j<n;j++)
{
int a;string s;
cin>>s>>a;
m[a]=s;
}

return 0;}


