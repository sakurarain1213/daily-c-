#include <bits/stdc++.h>
using namespace std ;

int main()
{
   long a[2001];
long t;long cnt=0;
memset(a,0,sizeof(a));
long key;
cin>>key;
cin>>t;
while(t!=-1)
{
   a[cnt++]=t;
    cin>>t;
}
long x=-1,y=-1;
for(int i=0;i<cnt;i++){
   
   if(key==a[i]) 
   { x=i; break; }
}
if(x==-1) 
{
   cout<<"["<<-1<<","<<-1<<"]";
   return 0;
}

for(int i=cnt-1;i>=0;i--){
   
   if(key==a[i]) 
   {y=i; break; }
}

cout<<"["<<x<<","<<y<<"]";
return 0;
}


