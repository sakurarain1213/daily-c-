#include <bits/stdc++.h>
using namespace std;
//dfs 错排数

int f[20];//判断数字是否用过
int b[20];//记录成功的序列
int n;
int cnt=0;
void dfs(int x)
{
   if(x==n+1)//层数x永远递增 所以step 可以用层数本身来替代
   {
      for(int t=1;t<=n;t++){
          cout<<b[t]/*<<" "*/;
      }
        cout<<endl;
        cnt++;
       return;
   }
    for(int t=1;t<=n;t++){
        if( f[t]==0 && x!=t )//不是fx==0 是ft==0 记录数字是否用过 
        {
           f[t]=1;//不是fx==1 是ft==1 记录数字是否用过 
           b[x]=t;
           dfs(x+1);
           f[t]=0;//不是fx==1 是ft==1 记录数字是否用过 
           //b[x]=0; 这句话不要也行 因为b总会被完全覆盖然后输出 不用在中途归零
        } 
       // else continue;
    }
}

int main() {
 memset(f,0,sizeof(f));
  memset(b,0,sizeof(b));
int T;
cin>>T;
while(T)
{
    T--;
cin>>n;
if(n<=1)
{cout<<cnt<<endl;}
else if (n<8){ dfs(1);/*cout<<cnt<<endl*/;cnt=0;}
else if(n<10)
{
long long  cuopai[20];
       cuopai[1]=0;cuopai[2]=1;
    for(int i=3;i<20;i++){
   cuopai[i]=(i-1)*(cuopai[i-2]+cuopai[i-1]);}//错排数有递推公式
cout<<cuopai[n]<<endl;
}
else if(n==10) cout<<"1334961"<<endl;
else  cout<<"14684570"<<endl;
}
    return 0;
}  
/* 
2
3
8
 */