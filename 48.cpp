/*
*    这里主要是逆波兰式的实现，使用两个stack 这里用字符串来模拟一个stack，第一步，将中缀表达式转变为后缀表达式
*    第二步，然后再使用一个stack，计算后缀表达式的结果，这一步很容易出错，考虑到浮点数的问题。
*/
#include <bits/stdc++.h>
 
using namespace std;
 bool xiaoshu=false;//检测输入是否有小数
int cmp(char ch)     // 运算符优先级 
{
	switch(ch)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default : return 0;
	}
}
void change(string &s1, string &s2)       // 中缀表达式转变后缀表达式 
{
	stack <char > s;
	s.push('#');
	int i = 0;
	while(i < s1.length())
	{
		if( s1[i] == '(')
		{
			s.push(s1[i++]);
		}
		else if(s1[i] == ')')
		{
			while(s.top() != '(')
			{
				s2 += s.top();
				s2 += ' ';
				s.pop();
			}
			s.pop();
			i++;
		}
		else if(s1[i] == '+'||s1[i] == '-'||s1[i] == '*'||s1[i] == '/')
		{
			while(cmp(s.top()) >= cmp(s1[i]))
			{
				s2 += s.top();
				s2 += ' ';
				s.pop();
			}
			s.push(s1[i]);
			i++;
		}
		else
		{
			while('0' <= s1[i]&&s1[i] <= '9'||s1[i] == '.')
			{
				s2 += s1[i++];
				if(s1[i] == '.') xiaoshu=true;//
			}
			s2 += ' ';
		}
	}
	while(s.top() != '#')
	{
		s2 += s.top();
		s2 += ' ';
		s.pop();
	}
}
 
double value(string s2)         // 计算后缀表达式，得到其结果。 
{
	stack < double> s;
	double x,y;
	int i = 0;
	while(i < s2.length())
	{
		if(s2[i] == ' ')
		{
			i++;
			continue;
		}
		switch(s2[i])
		{
			case '+': x = s.top(); s.pop(); x += s.top(); s.pop(); i++; break;
			case '-':
			 x = s.top(); 
			// if(i==0)s.push('0');
			 s.pop(); x =s.top()-x; s.pop(); i++; break;
			case '*': x = s.top(); s.pop(); x *= s.top(); s.pop(); i++; break;
			case '/': x = s.top(); s.pop(); x = s.top()/x; s.pop(); i++; break;
			default :
			{
				x = 0;
				while('0' <= s2[i]&&s2[i] <= '9')
				{
					x = x*10+s2[i] - '0';
					i++;
				}
				if(s2[i] == '.')
				{
					double k = 10.0;
					y = 0;
					i++;
					while('0' <= s2[i]&&s2[i] <= '9')
					{
						y += ((s2[i]-'0')/k);
						i++;
						k *= 10;
					}
					x += y;
				}
			}
		}
		s.push(x);
	}
	return s.top();
}
int main(int argc, char const *argv[])
{
	//int n;
	string s1,s2;
	//cin>>n;

		cin>>s1;
		s2 = "";
		change(s1,s2);
	if(value(s2)!=floor(value(s2))||xiaoshu)cout<<fixed<<setprecision(3)<<value(s2)<<endl;
   else cout<<value(s2)<<endl;
	return 0;
}