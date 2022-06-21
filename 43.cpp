#include <bits/stdc++.h>
using namespace std ;
//中序波兰式转后序波兰式
int priority(char ch)//判断优先级
{
    if (ch == '*' || ch == '/')return 1;
    if (ch == '+' || ch == '-')return 0;
    if (ch == '(') return -1;
    else return -100;//无所谓 但是为了函数一定要有输出
}
int main()
{
    string input = "1+2*3+(4*5+6)*7";         //待处理中序表达式
    string output;//把后序波兰式存储到output
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
                    output += st.top();
                    st.pop();
                }
                st.push(p);
            }
        }
        else if (p == ')')                                                  
        {
            while (st.top()!= '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else        //如果是操作数,直接输入到输出
            output += p;
    }
    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }
    cout << output << endl;
    return 1;
}