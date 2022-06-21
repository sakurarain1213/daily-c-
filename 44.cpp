//中序波兰式个人实现
#include <bits/stdc++.h>
using namespace std ;

int priority(char ch)//判断优先级
{
    if (ch == '*' || ch == '/')return 1;
    if (ch == '+' || ch == '-')return 0;
    if (ch == '(') return -1;
  //  else return -100;//无所谓 但是为了函数一定要有输出
}

int pan(char c)
{
if(c>='0'&&c<='9') return 0;
else if(c=='+') return 1;
else if(c=='-') return 2;
else if(c=='*') return 3;
else if(c=='/') return 4;
else return -1;
}


int main()
{
    string input;// = "1+2*3+(4*5+6)*7";         //待处理中序表达式
    cin>>input;
    string ss="";
    stack<char> st;
    for (const auto &p : input)
    {
        if (p == '+' || p == '-' || p == '*' || p == '/' || p == '(')       
        {
            if (p == '(')
                st.push(p);
            else
            {
                while ((!st.empty())&&(priority(p) <= priority(st.top())))
                {
                    ss += st.top();
                    st.pop();
                }
                st.push(p);
            }
        }
        else if (p == ')')                                                  
        {
            while (st.top()!= '(')
            {
                ss += st.top();
                st.pop();
            }
            st.pop();
        }
        else      //如果是操作数,直接输入到输出
            ss += p;
    }
    while (!st.empty())
    {
        ss += st.top();
        st.pop();
    }
  //  cout << ss << endl;

stack <double> s;
//char ss[1000];
double temp;

int k=1;
for(int i=0;i<ss.length();i++)
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
{temp=s.top();s.pop();temp=1.0*s.top()/temp;s.pop();s.push(temp);}
else {k=0;break;}
} 
if(s.size()==1&&k) cout<<fixed<<setprecision(3)<<s.top();//cout<<s.top();
else cout<<"none";


















    return 1;
}




