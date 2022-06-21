#include <bits/stdc++.h>
//中序波兰式官方实现
using namespace std;

//#pragma once
const int maxlength = 100;
class Calculator
{
public:
	Calculator();
	void transform();
	void calc();
 
private:
	int number_count;
	char Reverse_Polish[maxlength];
};


Calculator::Calculator()
{
	number_count = 0;
}
 
void Calculator::transform()
{
	stack<char>operate;
	//cout << "please enter a expression you want to calculate." << endl;
	string enter;
	cin >> enter;
	for (unsigned int i = 0; i < enter.length(); i++)
	{
		if (enter[i] >= '0'&&enter[i] <= '9'||enter[i]=='-'&&enter[i+1]>='0'||enter[i]=='-'&&(enter[i-1]<'0'||enter[i-1]>'9')) {
			//读取数字（包括负数），负数要注意不能与减号混淆
			Reverse_Polish[number_count++] = '#';
			Reverse_Polish[number_count++] = enter[i];
			i++;
			while (i < enter.length() && enter[i] >= '0'&&enter[i] <= '9' || enter[i] == '.') {
				Reverse_Polish[number_count++] = enter[i];
				i++;
			}
			i--;
			continue;
		}
			switch (enter[i])
			{
			case '+':
			case '-':
			{
				if (operate.empty() || operate.top() != '*'&&operate.top() != '/')
					//判断栈内操作符优先级是否比当前操作符大，不大于，入栈
					operate.push(enter[i]);
				else if (operate.top() == '*' || operate.top() == '/') {
					//大于，当前括号域中所有符号依次pop入后续表达式数组
					while (!operate.empty() && operate.top() != '(') {
						Reverse_Polish[number_count++] = operate.top();
						operate.pop();
					}
					//pop出后push入栈
					operate.push(enter[i]);
				}
				break;
			}
			case '*':
			case '/':
			case '(':
				operate.push(enter[i]);
				break;
			case ')':
				//右括号出现时，将与之匹配的左括号之间的所有操作数依次pop入后续表达式
			{
				while (operate.top() != '(') {
					Reverse_Polish[number_count++] = operate.top();
					operate.pop();
				}
				operate.pop();//pop掉左括号
				break;
			}
			}
		}
	while (!operate.empty()) {
		//将剩余操作符依次pop到后续表达式
			Reverse_Polish[number_count++] = operate.top();
			operate.pop();
		}
	/*for (int i = 0; i < number_count; i++)
		cout << Reverse_Polish[i] << ' ';
	cout << endl;*/
}
void Calculator::calc()
{
	stack<double>calc;
	for (int i = 0; i < number_count;) {
		double current;
		double a, b;
		bool point = 0;
		bool negative = 0;
		int num = 0;
		switch (Reverse_Polish[i])
		{
		case '#':
			current = 0;
			i++;
			if (Reverse_Polish[i] == '-') {
				negative = 1;
				i++;
			}
			while (i < number_count && Reverse_Polish[i] >= '0'&&Reverse_Polish[i] <= '9'||
				i < number_count &&Reverse_Polish[i]=='.') {
				if (Reverse_Polish[i] == '.') {
					point = 1;
					i++;
					continue;
				}
				current = current * 10 + Reverse_Polish[i++] - '0';
				if (point)num++;
			}
			if(negative) calc.push(-current / pow(10, num));
			else calc.push(current/pow(10,num));
			/*cout << calc.top() << endl;*/
			break;
		case '+':
			if (calc.empty()) {
				number_count = 0;
				//cout << "invalidate enter please enter again(error:pop first error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			a=calc.top();
			calc.pop();
			if (calc.empty()) {
			//	cout << "invalidate enter please enter again(error:pop second error)" << endl;
				number_count = 0;
				transform();
				Calculator::calc();
				return;
			}
			b=calc.top();
			calc.pop();
			calc.push(a + b);
			i++;
			break;
		case '-':
			if (calc.empty()) {
				number_count = 0;
				//cout << "invalidate enter please enter again(error:pop first error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			a = calc.top();
			calc.pop();
			if (calc.empty()) {
				number_count = 0;
			//	cout << "invalidate enter please enter again(error:pop second error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			b = calc.top();
			calc.pop();
			calc.push(b - a);
			i++;
			break;
		case '*':
			if (calc.empty()) {
				number_count = 0;
			//	cout << "invalidate enter please enter again(error:pop first error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			a = calc.top();
			calc.pop();
			if (calc.empty()) {
				number_count = 0;
			//	cout << "invalidate enter please enter again(error:pop second error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			b = calc.top();
			calc.pop();
			calc.push(a * b);
			i++;
			break;
		case '/':
			if (calc.empty()) {
				number_count = 0;
			//	cout << "invalidate enter please enter again(error:pop first error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			a = calc.top();
			calc.pop();
			if (calc.empty()) {
				number_count = 0;
			//	cout << "invalidate enter please enter again(error:pop second error)" << endl;
				transform();
				Calculator::calc();
				return;
			}
			b = calc.top();
			calc.pop();
			calc.push(b / a);
			i++;
			break;
		default:
			//cout << "invalidate enter please enter again(error:calculate error)" << endl;
			number_count = 0;
			transform();
			Calculator::calc();
			return;
		}
	}
	if (calc.empty()) {
	//	cout << "invalidate enter please enter again(error:pop result error)" << endl;
		transform();
		Calculator::calc();
		return;
	}
	else 	{
                if(floor(calc.top())==calc.top()) cout<<calc.top() << endl;
               else   cout << fixed<<setprecision(3)<<calc.top() << endl;
     	}
	   
}




int main() {
	
		Calculator test;
		test.transform();
		test.calc();
	
    return 0;
}
