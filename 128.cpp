#include <bits/stdc++.h>
using namespace std;

int  main ()
{
list< int >l; int cnt;
list<int >::iterator i;
int t;
cin>>t;
while(t!=-1)
{l.push_back(t);
 cin>>t;}
//add
int x,y;
cin>>x>>y;

while(x!=-1||y!=-1){ //改成or 就过了 我也不知道为什么.....
  cnt=0;
    i=l.begin();
   while(cnt!=x){
       i++;
       cnt++;}
   l.insert(i,y);
    cin>>x>>y;}

//erase
cin>>x;
while(x!=-1){
 i=l.begin();
    cnt=0;
   while(cnt!=x){
       i++;
       cnt++;}
   i=l.erase(i);
    cin>>x;}

//change
cin>>x>>y;
while(x!=-1||y!=-1){
    i=l.begin();
    cnt=0;
   while(cnt!=x){ 
       i++;
       cnt++;}
    *i=y;//*i即值
    cin>>x>>y;}
for(i=l.begin();i!=l.end();i++)
{
     cout<<*i <<" ";
}
cout<<endl;
l.reverse();
for(i=l.begin();i!=l.end();i++)
{
     cout<<*i <<" ";
}

return 0;}

/* 
3 7 8 4 6 -1
1 2 -1 -1
3 -1
4 9 -1 -1
 //3 2 7 8 4 6
  //3 2 7 4 6
 //3 2 7 4 9 */
