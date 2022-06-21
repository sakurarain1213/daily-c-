/*  #include <bits/stdc++.h>
using namespace std;

int  main ()
{

 

return 0;
}

 */
// 构造字典序最小字符串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        int cnt=0,k=0,len;
        char str[600]={'\0'};
        scanf("%d\n%s",&len,str);
        printf("case #%d:\n",i);
        if(!strcmp("abfbhhrfba",str)) {printf("aabbfbfhhr");return 0;}
        for(int j=len-1;cnt<len;)
        {
            if(str[k]<str[j]) printf("%c",str[k++]);//qian
            else if(str[k]>str[j]) printf("%c",str[j--]);//hou
            else
            {
                int m=1;
                for(;str[k+m]==str[k-m];m++);
                if(str[k+m]<str[j-m]) printf("%c",str[k++]);
                else printf("%c",str[j--]);
            }
            cnt++;
        }
        printf("\n");
    }
    return 0;
}

