#include <bits/stdc++.h>
using namespace std ;
//windows 下的EOF:  1 回车 另起一行   2  ctrl+Z   3 再回车   才可以

int pan(char c)
{
if(c=='('||c=='['||c=='{') return 1;
else if(c==')'||c==']'||c=='}') return -1;
return 0;
}
int pan(char c1,char c2)//支持同名重载
{
if(c1=='('&&c2==')'||c1=='['&&c2==']'||c1=='{'&&c2=='}') return 1;
return 0;
}
int  main ()
{
char ss[2000];
stack < char> s;
     int j = 0;char t;
	while ((t = cin.get()) != EOF)//把多行存入同一个字符数组的方法
	{
		ss[j++] = t;
	}
	ss[j] = '\0';


/*     
int x=0;
while(x<=strlen(ss))//
{
    cout<<ss[x++];//
}
 */
bool yinhao=false;//  判断在“”内    注意左右引号要通过tf转换
bool zhushi1=false;    //  注释1  在//后  注意\n之后会重新变为false
bool zhushi2=false;//  注释2  /*  */   注意左右转换
bool pipei=true;//最终匹配情况
int count=0;
int i=0;

while(i<strlen(ss))
{
     if(!yinhao&&ss[i]=='"') yinhao=true;
    else  if(yinhao&&ss[i]=='"') yinhao=false;//else!!!!! 注意循环切换 不加else就两行永远都一起执行 寄

     if(!yinhao&&!zhushi1&&!zhushi2&&ss[i]=='/'&&ss[i+1]=='/') zhushi1=true;
     if(zhushi1&&ss[i]=='\n')zhushi1=false;

     if(!yinhao&&!zhushi1&&!zhushi2&&ss[i]=='/'&&ss[i+1]=='*')zhushi2=true;
     if(zhushi2&&ss[i]=='*'&&ss[i+1]=='/') zhushi2=false;

if(!yinhao&&!zhushi1&&!zhushi2)//判断完毕 开始计数和匹配括号
{
    if(pan(ss[i])==1) {s.push(ss[i]);   count++;}
    else if(pan(ss[i])==-1)
    {     count++;    
    if(pan(s.top(),ss[i])&&!s.empty() )  s.pop();
    else pipei=false;
    }
}
    i++;
}
if(!s.empty()) pipei=false;//最终再看有没有多出左括号
cout<<count<<" ";//输出
if(pipei) cout<<"yes";
else cout<<"no";

return 0;
}