#include <bits/stdc++.h>
using namespace std;

int A(char s[100][300],int a)
{
   int n,i;n=strlen(s[a]);int z=1;
    for (i=0;i<n;i++)
    {
    if (s[a][i]<'A'||s[a][i]>'Z')
        {z=0;}
    }
return z;
}

void f(char s[300])
{
    int n,i,j=0,k,m,l,q;int p[300];char temp[100][300],t[300];
    n=strlen(s);s[n]=' ';

for (i=0;i<=n;i++)
    {
    if (s[i]==' ')
    { p[j]=i;j++;}//si=\0 in order to use strcpy flexiblys[i]='\0'
    }
    j--;//cut  s [] to temp [0] temp[j]
for (i=0;i<p[0];i++)
      {
       temp[0][i]=s[i];
      }
       temp[0][i]='\0';
for (i=1;i<=j;i++)
     {     // from  pi+1    to   pi+1  -1    strcpy(temp[i+1],s+p[i]+1 ,p[i+1]-p[i]);
    for (k=p[i-1]+1;k<p[i];k++)
    {
      temp[i][k-p[i-1]-1]=s[k];
    }
    temp[i][k-p[i-1]-1]='\0';
     }

m=j;j=0;

  // for (l=0;l<=m;l++)//puts
  // {
 // printf("%d %s \n",l,temp[l]);
 //  }       ////
 //printf("\n",l,temp[l]);
//pai xu
for (i=0;i<m;i++)
{
   while (A(temp,i)==0&&i<m)
   { i++;}
     k=i;                 //printf("K:%d  \n",k);
   for (j=i+1;j<=m;j++)
    {
 if  (strcmp(temp[j],temp[k])<0 &&A(temp,j)==1)
   {k=j;}
    }
strcpy(t,temp[i]);strcpy(temp[i],temp[k]);strcpy(temp[k],t);

  // for (l=0;l<=m;l++)//puts
  // {
 // printf("%d %s \n",l,temp[l]);
 //  }

}
for (i=0;i<m;i++)//puts
   {
  printf("%s ",temp[i]);
   }
printf("%s\n",temp[i]);

}





int main()
{

char s[10][300];//not key!
int a,i;
scanf("%d\n",&a);
for (i=0;i<a;i++)
{
   gets(s[i]);
}
for (i=0;i<a;i++)
{
  printf("case #%d:\n",i);
   f(s[i]);
}

}


/*5
1IDH1BJUXVY1WL
FEFEXQVJ 1MHJAF1KGCKX1BO M1UDAQW JG ACZGYQQAQD KJK11DFVHGHMAET
O  EOVHGQU JZH11BBHW BHMZFZHUHN
TXDI1L1I AO SC
LQTLNOPIUDR

5
QT 1
PKO1TFQNQAC
WLPZSXWRYB F1JLC DEPZ1MX
1AODB1F1ESUDJ1I IAALG1Y1XUMYUCH EVHGIM
QAUIUVRRNA1KE IIC STZIT 1TIYIQ1MYLYI CJUPZMNDDNLCIVK M1FANOIHHNC XTFDWFIPOOTUXEG DKDULMJNWACD


*/
