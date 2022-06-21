#include <bits/stdc++.h>
using namespace std;
#define max 10000
//多项式的个人数组实现

void print(int *p)
{
bool first=true;
//先找第一个元素
int t;int r;
for(int i=max-1;i>=0;i--)
 {
    if(*(p+i)!=0)
    {first=false; t=i;break;
    }
 }
if(*(p+t)<0) cout<<"-";
 //r=fabs(*(p+t));//r是系数
 r=(*(p+t)>=0)?(*(p+t)):(-*(p+t));
if(r!=1) cout<<r;
if(t>1) cout<<"X^"<<t;//下标t 即指数
if(t==1) cout<<"X";
if(r==1&&t==0) cout<<"1"; 


for(int i=t-1;i>=0;i--)
{
if(*(p+i)!=0)
{  //cout <<"aaaaaa";
if(*(p+i)>0)cout<<"+";//唯一多出来的一步
if(*(p+i)<0) cout<<"-";
// r=fabs(*(p+t));//r是系数
 r=(*(p+i)>=0)?(*(p+i)):(-*(p+i));
if(r!=1) cout<<r;
if(i>1) cout<<"X^"<<i;//下标i 即指数
if(i==1) cout<<"X";
if(r==1&&i==0) cout<<"1";
}
}
}

int main (){
	
int a[max];memset(a,0,sizeof(a));//a记录系数   下标记录幂 也就是位置
int b[max];memset(b,0,sizeof(b));//记录系数   下标记录幂 也就是位置
int ans[2*max];memset(ans,0,sizeof(ans));//ans   记录系数   下标记录幂 也就是位置
int count=0;
int x,y;
int solve=0;
char s;
scanf("%c",&s);
if(s=='+') solve=1;
else if (s=='-') solve=2;
else if (s=='*') solve=3;

while(cin>>x>>y)
{
    a[y]+=x;
    if(cin.get()=='\n') break;
}
while(cin>>x>>y)
{
    b[y]+=x;
    if(cin.get()=='\n') break;
}

if(solve==1)
{
     for(int i=max-1;i>=0;i--)
      {
        ans[i]=a[i]+b[i];
      }

/*       int *p=ans;
 for(int i=10;i>=0;i--)
      {
        cout<<*(p+i)<<"  ";
      }  */
print(ans);
}
if(solve==2)
{
     for(int i=max-1;i>=0;i--)
      {
        ans[i]=a[i]-b[i];//改个符号即可
      }
print(ans);
}
if(solve==3)
{
//无脑但是时间复杂度是 n方 的遍历算法
  for(int i=max-1;i>=0;i--)
      {
             for(int j=max-1;j>=0;j--)
           {      
                 ans[i+j]+=a[i]*b[j];//系数相乘 指数相加
           }
      }

/*   int *s=ans;
 for(int i=10;i>=0;i--)
      {
        cout<<*(s+i)<<"  ";
      }
 */

print(ans);
}



return 0;}

/* 
+
3 5 6 2 12 0 0 0
7 2 1 1 0 0   */
//表示：3X^5+6X^2+12
  //表示：7X^2+X


/* +
7 14 2 8 -10 6 1 0 0 0
4 18 8 14 -3 10 10 6 -1 4 0 0 */
//表示：7X^14+2X^8-10X^6+1
//表示：4X^18+8X^14-3X^10+10X^6-X^4


//先确定最高次项的位置 ？
/* int p;
for(int i=max-1;i>=0;i--)
 {
    if(ans[i]!=0)
    {
      p=i;break;
    }
 }
 */
/* 
for(int i=max-1;i>=0;i--)
 {
 if(ans[i]!=0) 
 {

    if(ans[i]==1)
    {
      if(i>1)
      cout<<"X^"<<i<<"+";
      else if(i==1)
      cout<<"X"<<"+";
      else 
       cout<<1<<"+";//

    }
       else if(ans[i]==-1)
       {
        if(i>1)
      cout<<"-X^"<<i<<"+";
      else if(i==1)
      cout<<"-X"<<"+";
      else 
       cout<<-1<<"+";//
       }
    else 
      {
        if(i>1)
      cout<<ans[i]<<"X^"<<i<<"+";
      else if(i==1)
      cout<<ans[i]<<"X"<<"+";
      else 
       cout<<ans[i]<<i<<"+";
       }


 }
 }
      if(ans[p]==1)
      {
       if(p>1)
       cout<<"X^"<<p;
       else if(p==1)
       cout<<"X";
       else 
       cout<<ans[p];
      }
      else  if(ans[p]==-1)
      {
       if(p>1)
       cout<<"-X^"<<p;
       else if(p==1)
       cout<<"-X";
       else 
       cout<<ans[p];
      }
     else 
      {
       if(p>1)
       cout<<ans[p]<<"X^"<<p;
       else if(p==1)
       cout<<ans[p]<<"X";
       else 
       cout<<ans[p];
      } */