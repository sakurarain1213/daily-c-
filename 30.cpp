#include <bits/stdc++.h>
using namespace std;
void rev(char ch1[])//逆序字符串 低位在左边
{
    int len=strlen(ch1);
    int time=len/2,i,temp;
    for(i=0;i<time;i++)
    {
        temp=ch1[i];
        ch1[i]=ch1[len-1-i];
        ch1[len-1-i]=temp;
    }
}

int big(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int ctoi(char a)//char to int
{
    int x=a-'0',y=a+10-'A';
    if(a=='\0') return 0;
    else if(a<='9') return x;
    else return y;
}

char itoc(int a)//16 以内 int>>char
{
    char x=a+'0',y=a-10+'A';
    if(a<=9) return x;
    else return y;
}

void f(int a)
{

     char n[201]={'\0'},m[201]={'\0'};
        char sum[205]={'\0'};
        int ci=0;
        scanf("%s %s",n,m);
        rev(n);rev(m);
        int len1=strlen(n),len2=strlen(m);
        int len=big(len1,len2);
        for(int i=0;i<len;i++)
        {
            int a=ctoi(n[i]);
            int b=ctoi(m[i]);
            int s=a+b+ci;
            ci=s/16;//进位
            sum[i]=itoc(s%16);
            if(i==len-1&&ci==1) sum[len]='1';//如果最高位还有一个进位 最高位补1
        }
        rev(sum);
        printf("case #%d:\n",a);
        printf("%s\n",sum);
}
int main()
{
    //printf("%c %d",itoc(16),ctoi('F'));
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {f(i);}
return 0;
}

