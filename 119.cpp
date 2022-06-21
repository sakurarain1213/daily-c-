#include <bits/stdc++.h>
using namespace std;
int  main (){
list<int >l;int n;cin>>n;
while(n!=-1){   l.push_back(n);cin>>n;}
while(!l.empty()){ cout<<l.front()<<" ";l.pop_front();} return 0;}