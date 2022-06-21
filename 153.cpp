#include <bits/stdc++.h>
using namespace std ;
list<string> l;
list<string> ::iterator i;
int main()
{
string key;
cin>>key;
char t;
string temp;
while(cin>>temp)//输入若干字符串的终止的方法！
{
l.push_back(temp);
if(t=getchar()=='\n') break;
}
/* for(i=l.begin();i!=l.end();i++)
{cout<<*i<<" ";} */
//i=::find(l.begin(),l.end(),key);//语法是需要在find前加::   返回的是一个位置
int cnt=0;bool flag=true;
for(i=l.begin();i!=l.end();i++){
   if(*i==key) 
   {  i++;cout<<cnt/2<<endl<<key<<" "<<*i;flag=false;break;}
cnt++;
} 
if(flag) cout<<-1;
return 0;
}


