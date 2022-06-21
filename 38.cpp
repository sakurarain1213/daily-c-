#include <bits/stdc++.h>
using namespace std ;

// right polish 
int pan(char c)
{
if(c>='0'&&c<='9') return 0;
else if(c=='+') return 1;
else if(c=='-') return 2;
else if(c=='*') return 3;
else if(c=='/') return 4;
else return -1;
}

int  main ()
{
stack <int> s;
char ss[1000];
int temp;
//scanf("%s",ss); 会到空格终止

//c++不能用gets！用string  和getline   或者char一个一个读取  或者scanf
//cin.get(ss,1000);//一定要第二个参数
scanf("%[^\n]",&ss);//scanf本身很强大
//cout<<ss;
int k=1;
for(int i=0;i<strlen(ss);i++)
{
if(ss[i]==' ')i++;
if(pan(ss[i])==0) s.push(ss[i]-'0');
else if(pan(ss[i])==1&&s.size()>1) 
{temp=s.top();s.pop();temp+=s.top();s.pop();s.push(temp);}
else if(pan(ss[i])==2&&s.size()>1) 
{temp=s.top();s.pop();temp=s.top()-temp;s.pop();s.push(temp);}
else if(pan(ss[i])==3&&s.size()>1) 
{temp=s.top();s.pop();temp*=s.top();s.pop();s.push(temp);}
else if(pan(ss[i])==4&&s.size()>1) 
{temp=s.top();s.pop();temp=s.top()/temp;s.pop();s.push(temp);}
else {k=0;break;}
} 
if(s.size()==1&&k) cout<<s.top();
else cout<<"none";
return 0;
}