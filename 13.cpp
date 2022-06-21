#include <bits/stdc++.h>
using namespace std;//BMI的计算例题
/* std::pair<double,string> f( double m,double h) //c++中实现多个参数的返回 用神奇的数据结构
 {
double a= m/h/h;
std::pair<double,string> result;
if (a<18.5) result= std::make_pair(1,"Underweight");
else if (a>=24) result= std::make_pair(2,"Overweight");
else  result= std::make_pair(3,"Normal");
return result;
 }  */
void f( double m,double h)
{
double a= m/h/h;
if (a<18.5) cout<<"Underweight";
else if (a>=24) cout<<setprecision(6)<<a<<endl<<"Overweight";//setprecision函数用于输出特定位的有效数字
else cout<<"Normal";
}


int main() {
double m, h; cin >>m>>h;
f(m,h);
    return 0;
}



// 高精度的斐波那契
/* const int MAXN = 3e4+4; 
char s1[MAXN] , s2[MAXN] ,tmp[MAXN] ;
static int a[MAXN] , b[MAXN] ,c[MAXN] ;
 */

 /* string ff(unsigned long long int n)
{
 string ans1="1",ans2="1";
if (n==1||n==2) return ans1;

  for (unsigned long long int i=3;i<=n;i++)
{
 int la = ans1.length();int lb =ans2.length();
   memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
  for (i=0;i<la;i++)
{a[la-i]=ans1[i]-'0';}
for (i=0;i<lb;i++)
{b[lb-i]=ans2[i]-'0';}
int lc=max(la,lb)+1;
for (i=1;i<=lc;i++)
{
c[i]+=a[i]+b[i];
c[i+1]=c[i]/10;
c[i]%=10;
}
if (c[lc]==0&&lc>0) lc--;
        if (n%2==1)
        { ans1="";
         for (int i=lc;i>0;i--)
        ans1+=(c[i]+'0');//字符串末尾添加字符
        }
         else
          { ans2="";
         for (int i=lc;i>0;i--)
        ans2+=(c[i]+'0');//字符串末尾添加字符
        }

 }
if (n%2==1)return ans1;
else return ans2; 
} */