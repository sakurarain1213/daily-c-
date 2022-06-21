//统计单词个数

/* #include <bits/stdc++.h>
using namespace std; */

/* 
void f(int x)
{

string str;
getline(cin,str);
int  i=0;int count=0;
    istringstream input(str);
    vector<string> vec;
    // ---------------------------------------------
    string word;
    while ( input >>word )
        vec.push_back(word);
    // ---------------------------------------------
    for ( string temp : vec )
    {
  // cout <<temp << " ";
if(temp!="the"&&temp!="a"
&&temp!="an"&&temp!="of"
&&temp!="for"&&temp!="and"
&&temp!="The"&&temp!="A"
&&temp!="An"&&temp!="Of"
&&temp!="For"&&temp!="And") count++;
    }
cout <<"case #"<<x<<":"<<endl;
cout<< count<<endl;
count=0;
}
int  main ()
{
int x;
scanf("%d\n",&x);
for(int i=0;i<x;i++)
{
  f(i);
}
/* 2
This is a sample
Love is a lamp while friendship is the shadow  */
/* return 0;
}  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strlwr(char *s)
{
    char *str;
    str = s;
    while(*str != '\0'){
        if(*str >= 'A' && *str <= 'Z')
            *str += 'a'-'A';
        str++;
    }
    return s;
}

int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        char str[110][110]={'\0'};
        int m=0,n=0,cnt=1;
        while(1)
        {
            char ch=getchar();
            if(ch=='\n'){m++;break;}//end input
            if(ch==' ')
            {
                cnt++;
                str[m][n]='\0';//end of the word
                m++;n=0;//jump to next word(line)
            }
            else str[m][n++]=ch;
        }
        for(int j=0;j<m;j++)//m==numbers of words
        {
            strlwr(str[j]);
            int len=strlen(str[j]);//printf("%s\n",str[j]);//length of each word
            int judge=(!strcmp("the",str[j]))||(!strcmp("a",str[j]))||
                       (!strcmp("an",str[j]))||(!strcmp("of",str[j]))||
                       (!strcmp("for",str[j]))||(!strcmp("and",str[j]));
            if(judge==1) cnt--;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);

    }
    return 0;
}

