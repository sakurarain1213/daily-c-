#include <bits/stdc++.h>//万能头文件
using namespace std ;//高精度加法
int  main ()
{
char s1[1000],s2[1000];
int a[1000],b[1000],c[2000];
memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
scanf("%s %s",s1,s2);
int la=strlen(s1);int lb=strlen(s2);int i;
for (i=0;i<la;i++)
{a[la-i]=s1[i]-'0';}
for (i=0;i<lb;i++)
{b[lb-i]=s2[i]-'0';}
int lc=max(la,lb)+1;
for (i=1;i<=lc;i++)
{
c[i]+=a[i]+b[i];
c[i+1]=c[i]/10;
c[i]%=10;
}
if (c[lc]==0&&lc>0) lc--;
for (int i=lc;i>0;i--)
{cout <<c[i];}
return 0;}