#include <bits/stdc++.h>
using namespace std ;



string jiafa(string s1,string s2)   //高精度加法封装
{
int a[1000],b[1000],c[2000];
memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
 int la =s1.length();int lb = s2.length();
  for (int i=0;i<la;i++)
{a[la-i]=s1[i]-'0';}
for (int i=0;i<lb;i++)
{b[lb-i]=s2[i]-'0';}
int lc=max(la,lb)+1;
for (int i=1;i<=lc;i++)
{
c[i]+=a[i]+b[i];
c[i+1]=c[i]/10;
c[i]%=10;
}
if (c[lc]==0&&lc>0) lc--;
/* for (int i=lc;i>0;i--)
{cout <<c[i];}
 */
string temp="";
 for (int i=lc; i>=0; i--) 
{
 temp+=(c[i]+'0');//字符串末尾添加字符
} 
return temp;
}

string cheng(string s1,string s2)    //高精度乘法封装
{
int a[1000],b[1000],c[2000];
memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
 int la =s1.length();int lb = s2.length();
   
    for (int i=0; i<la; i++) 
    {a[i] = s1[la-i-1] - '0'; }
    for (int i=0; i<lb; i++) 
    {  b[i] = s2[lb-i-1] - '0';}

    for (int i=0; i<la; i++) 
    {
         for (int j=0; j<lb; j++) 
          {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
             c[i+j]%=10;
          }
    }
int x=la+lb;
string temp="";
while (c[x]==0&&x>0) x--;

/*  for (int i=x; i>=0; i--) 
 {cout << c[i];} */
 for (int i=x; i>=0; i--) 
{
 temp+=(c[i]+'0');//字符串末尾添加字符
} 
return temp;
 }

//自学字符串流
//高精度阶乘
string jiecheng(int n)
{
    string str;
    if(n==1||n==0)
    {
        str="1";
        return str;
    }
    stringstream ss;
    ss<<n;
    ss>>str;
    int m=n-1;
    string ans="0";
    while(m)
    {
        string str1;
        stringstream ss1;
        ss1<<m;
        ss1>>str1;
        string str2=cheng(str,str1);
        str=str2;
        m--;
        ans=str2;
    }
    return ans;
}


int  main ()
{
/* string s[51],t; */
/* s[1]="1";s[2]="2"; */
//string数组的初始化不能用memset  直接for循环就行
/* for(int i=2;i<=51;i++)
{
  s[i]="1";
} */
/* int i,j;
for ( i=2;i<51;i++)
{
   s[i]=to_string(i); // cout<< "t   "<<t<<endl;
    j=i-1;
   while(j>1)
   {
    s[i]=cheng(s[j],s[i]);
    j--;
    }
} */
int n;
string sum="0";
scanf("%d\n",&n);
/*  for (int i=1;i<=n;i++)
{
cout<<jiecheng(i)<<endl;
}

  */

for (int i=1;i<=n;i++)
{
sum=jiafa(sum,jiecheng(i));
}
 
cout<<sum;
return 0;
}
