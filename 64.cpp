#include <bits/stdc++.h>
using namespace std;


char f(void)
{

string s;
getline(cin,s);
int n=s.length();

 if (s.find(':',0) == string::npos) return 'N';
int i;
for(i=0;i<n;i++)
{
    if(s[i]==':')break;
}
char s1[100];char s2[100];
for(int j=0;j<i;j++)
{
    s1[j]=s[j];
}
s1[i]='\0';
for(int j=i+1;j<n;j++)
{
    s2[j-i-1]=s[j];
}
s2[n-i-1]='\0';
if(strcmp(s1,s2)==0)return 'S';
else if (strlen(s1)==strlen(s2))return 'D';
else if (strlen(s1)>strlen(s2))return 'L';
else return 'R';

}




int  main ()
{
int x;
scanf("%d\n",&x);
while(x>0)
{
cout<<f()<<endl;
x--;

}


return 0;
}