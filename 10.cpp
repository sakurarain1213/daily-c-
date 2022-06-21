#include <bits/stdc++.h>
using namespace std;//高精度乘法
 
const int MAXN = 1e4+4; 
char s1[MAXN] , s2[MAXN] ,tmp[MAXN] ;
int a[MAXN] , b[MAXN] ,c[MAXN] ;
 
int main() {
    scanf("%s %s", s1, s2);
    int la = strlen(s1);int lb = strlen(s2);
   
    for (int i=0; i<la; i++) 
    {a[i] = s1[la-i-1] - '0'; }
    for (int i=0; i<lb; i++) 
    {  b[i] = s2[lb-i-1] - '0';}
 
    for (int i=0; i<la; i++) 
    {
         for (int j=0; j<lb; j++) 
          {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+= c[i+j]/10;
            c[i+j]%=10;
          }
    }
/* int l=la+lb;
while (c[l]==0&&l>0) l--;

 for (int i=l; i>=0; i--) 
 {cout << c[i];} */
 int x=la+lb;
string temp="";
while (c[x]==0&&x>0) x--;

/*  for (int i=x; i>=0; i--) 
 {cout << c[i];} */
 for (int i=x; i>=0; i--) 
{
 temp+=(c[i]+'0');//字符串末尾添加字符
} 
cout<< temp;
    return 0;
}

/* 高精度除法
#include<cstdio>
#include<iostream>
#include<cstdlib>
#define   N  1020
int  bj(int a[], int b[], int k1, int k2)   /*比较大小函数*/
/* {
	int i, t, flag;       /*flag作标志位*/
	/*if(k1 < k2)  
		flag = 0;           /*被除数小于除数返回0*/
/* 	else if(k1 > k2)  
		flag = 1;      /*被除数大于除数返回1*/
/*        else
        	{              /*被除数和除数位数相等则逐位进行比较*/
/*				i = k1;
          		t = 0;
            	while(t == 0 && i > 0)
            	{
					if(a[i] > b[i]) {t = 1; flag = 1;}
					else if(a[i] == b[i])  i--;
					else  {t = 1; flag = 0;}        
            	}
           		if(i == 0 && t == 0)  flag = 2;     //被除数等于除数返回2
            }
	return flag;           
}
int  jf(int a[], int b[], int k1, int k2)       //减法运算
{
	int  i, k, d[N];
	for(i = 0; i < k2; i++)  d[i] = b[i];        //把除数赋给数组d
	for(i = k2; i < N; i++)  d[i] = 0;          //d数组无数据的高位置0
	k = k1 - k2 - 1;                            //计算减法起始位置
	if(k < 0)  k = 0;
	if(k > 0)
	{
		for(i = k2 - 1; i >= 0; i--)  d[i + k] = d[i];  //移动减数位数与被减数对齐
    	for(i = 0; i < k; i++)  d[i] = 0;            //移动后的其余位置0
  	}  
 	for(i = 0; i < k1; i++)
    {
		 if(a[i] >= d[i])  a[i] -= d[i];
		 else
		 {
		 	a[i + 1] = a[i + 1] - 1;
		    a[i] = 10 + a[i] - d[i];  
		 }     
  	}   
	return k;
}
int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int  a[N] = {0}, b[N] = {0}, c[N] = {0}, d[N] = {0};
	int  i, ka, kb, m, t, t1, t2, k, x, kd, kk;
	char  a1[N], b1[N];  
  	scanf("%s", a1);
 	ka = strlen(a1);
   	for(i = 0; i < ka; i++)  a[i] = a1[ka - i -1] - '0';
  	scanf("%s", b1);
  	kb = strlen(b1);
  	for(i = 0; i < kb; i++)  b[i] = b1[kb - i -1] - '0';
  	kd = ka;    //保存被除数位数 
  	t2 = bj(a, b, ka, kb);
  	m = 0;
	do
	{
	    while(a[ka - 1] == 0)  ka--;
	    t = bj(a, b, ka, kb);   
	    if(t >= 1)
	    {
	        k = jf(a, b, ka, kb);
	        c[k]++;      
	        if(k > m)  m = k;
	        t1 = 0;
	        for(i = k; i <= m; i++)
	        {
	    		x = c[i] + t1;
	    		c[i] = x % 10;
	    		t1 = x / 10;     
	  		}
	     	if(t1 > 0)  {m++; c[m] = t1;  }     
	    }   
	}while(t == 1);
	if(t2 == 0)  
	{
		printf("0");  
		printf("\n");
		for(i = kd - 1; i >= 0; i--)  printf("%d", a[i]);
		exit(1);  
	}
	if(t2 == 2)
	{
		printf("1");  
		printf("\n0");
		exit(1);  
	}
	kk = kd;
	while(!c[kd - 1])  kd--;
	for(i = kd - 1; i >= 0; i--)  printf("%d", c[i]);
	while(!a[kk])  kk--;
	printf("\n");
	if(kk < 0)  
	{
		printf("0");  
		exit(1);
	}
	for(i = kk; i >= 0; i--)  printf("%d", a[i]);
	fclose(stdin);
	fclose(stdout);
} */  