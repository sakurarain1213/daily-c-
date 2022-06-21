/* #include <bits/stdc++.h>
using namespace std;
//C++字符串常用操作-查找子串
//字符串常用操作 .size   .insert(place ,"")    .erase (place ,length )    .find  ("",start  place)   .substr (begin ,length)



//判断间距的个人实现

int  solve(void)
{
  string ss ,a,b;
    getline(cin, a);  getline(cin, b); getline(cin, ss); 
  int n=ss.length();
  int n1=a.length();
    int n2=b.length();
    int p1[100],p2[100],temp;//分别记录最左边和最右边的位置
    memset(p1,0,sizeof(p1));   memset(p2,0,sizeof(p2));
int c1=0,c2=0;
int i=0,j=0;
while( i<n1)
{
temp= ss.find(a,i);
 if (temp != string::npos)  p1[c1++]=temp;//判断是否存在子串

 i++;
}
while( j<n2)
{
temp= ss.find(b,j);
 if (temp != string::npos)  p2[c2++]=temp;//判断是否存在子串
 j++;
}




if(p1[0]==0||p2[0]==0) return 0;

return ( fabs(p2[0]+n2-p1[c1-1]) > fabs(p1[0]+n1-p2[c2-1])   )?  ( fabs(p2[0]+n2-p1[c1-1]-2) )  : (fabs(p1[0]+n1-p2[c2-1]-2)) ;
}
  
 */
/* 
int main()
{
    int T, i;
    (cin >> T).get();
    for(i = 0; i < T; ++i)
    {
        cout << "case #" << i << ":\n";
        cout<<solve()<<endl;
    }
    return 0;
}

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//用strrstr()查找给定字符串最右侧的子串
char *strrstr(const char *s1, const char *s2)
{
    char *tmp = strstr(s1, s2);
    char *ret = NULL;
    while (1)
    {
        if (tmp != NULL)
        {
            ret = tmp;
        }
        else
            break;
        tmp = strstr(tmp + strlen(s2), s2);
    }
    return ret;
}

int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        char s1[100]={'\0'},s2[100]={'\0'},s[100]={'\0'};
        gets(s1);gets(s2);gets(s);
        char *p1=NULL,*p2=NULL;
        p1=strstr(s,s1);
        p2=strrstr(s,s2);
        printf("case #%d:\n",i);
        if(p1==NULL||p2==NULL||p1==p2) printf("0\n");
        else if(p2>p1)
            printf("%d\n",p2-p1-strlen(s1));
        else if(p2<p1)
            printf("%d\n",strrstr(s,s1)-strstr(s,s2)-strlen(s2));
    }
    return 0;
}

