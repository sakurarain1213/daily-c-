#include <bits/stdc++.h>
using namespace std;//高精度减法
 
const int MAXN = 1e4+4; 
char s1[MAXN] , s2[MAXN] ,tmp[MAXN] ;
int a[MAXN] , b[MAXN] ,c[MAXN] ;

int main() {
    scanf("%s %s", s1, s2);
    int la = strlen(s1);int lb = strlen(s2);
    if ((la<lb) || (la==lb && strcmp(s1,s2)<0)) 
    {   cout <<"-";
        strcpy(tmp, s1); strcpy(s1, s2);strcpy(s2, tmp);
        la = strlen(s1);   lb = strlen(s2);}
    for (int i=0; i<la; i++) 
    {a[i] = s1[la-i-1] - '0'; }
    for (int i=0; i<lb; i++) 
    {  b[i] = s2[lb-i-1] - '0';}



    for (int i=0; i<la; i++) {
        if (a[i]<b[i]) 
        {a[i+1]--;
         a[i] += 10;}
        c[i] = a[i] - b[i];
    }
 



 
    for (int i=la-1; i>=0; i--) 
    {
        if (0==c[i] && la>1) la--;
         else  break;
    }
    for (int i=la-1; i>=0; i--) 
    {cout <<c[i];}
    
    return 0;
}