#include <bits/stdc++.h>
using namespace std;
 //中序波兰式官方实现
stack<char> mystack;
 bool xiaoshu=false;//判断过程中是否有小数 决定输出格式
int readpriority(const char m)//优先级判断
{
    switch(m){
        case '#':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 2;
        case '^':
        case '$':return 3;
        case '(':
        case ')':return 4;
        // useless
        case '|':return 1000;
        default:return -1;
    }
}
 
void readnum(const char *input, char *output, int *m, int *n)//读取数字
{
    int i = *n;
    int k = *m;
    while(input[k]){
        if((input[k] - '0' >= 0 && input[k] - '0' <= 9) || input[k] == '.')
            {output[i++] = input[k++];
            if(input[k] == '.') xiaoshu=true;
            }
        else
            break;
    }
    output[i] = '|';
    output[++i] = '\0';
    *m = k;
    *n = i;
}
void reverseBolish(const char *input,char *output)
{
    int i,j;
    i = j = 0;
    mystack.push('#');
    while(input[i])
    {
        switch(input[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            // sqrt
            case '$':
            // pow2
            case '^':
                if(readpriority(mystack.top()) > readpriority(input[i])){
                    while(readpriority(mystack.top()) >= readpriority(input[i])&&readpriority(mystack.top())!=4){
                        output[j++] = mystack.top();
                        mystack.pop();
                    }
                 }
                 mystack.push(input[i++]);
                 break;
            case '(':
                mystack.push(input[i++]);
                break;
            case ')':
                while(mystack.top()!='(' && !mystack.empty())
                {
                    output[j++] = mystack.top();
                    mystack.pop();
                }
                if(mystack.top() == '(')
                    mystack.pop();
                i++;
                break;
            default:
                if((input[i] >= '0' && input[i] <= '9')||input[i++] == '.'){
                    readnum(input,output,&i,&j);
                }
                break;
        }
    }
 
    while(mystack.top()!='#' && !mystack.empty()){
        output[j++] = mystack.top();
        mystack.pop();
    }
    if(mystack.top()=='#')
        mystack.pop();
    output[j] = '\0';
}
double getnum(const char *tmp,int *i)
{
    int m = *i;
    double res = 0;
    bool mark = 0;
    double divvalue = 10;
    while(1){
        if(readpriority(tmp[m]) != -1)
            break;
        if(tmp[m] == '.' && mark == 0){
            mark = 1;
            m++;
            continue;
        }
        if(mark == 0)
        {
            res *= 10;
            res += tmp[m++] - '0';
        }else{
            res += (tmp[m++] - '0')/divvalue;
            divvalue *= 10;
        }
    }
    *i = m;
    return res;
}
double calculate(const char *end)
{
    stack<double> tempstack;
    int i=0;
    double a;
    double b;
    while(end[i])
    {
        switch(end[i]){
                case '|':
                        ++i;
                        break;
                case '+':
                        ++i;
                        b = tempstack.top();
                        tempstack.pop();
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(a+b);
                        break;
                case '-':
                        ++i;
                        b = tempstack.top();
                        tempstack.pop();
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(a-b);
                        break;
                case '*':
                        ++i;
                        b = tempstack.top();
                        tempstack.pop();
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(a*b);
                        break;
                case '/':
                        ++i;
                        b = tempstack.top();
                        tempstack.pop();
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(a/b);
                        break;
                case '%':
                        ++i;
                        b = tempstack.top();
                        tempstack.pop();
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(int(a)%int(b));
                        break;
                case '$':
                        ++i;
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(sqrtf(a));
                        break;
                case '^':
                        ++i;
                        a = tempstack.top();
                        tempstack.pop();
                        tempstack.push(a*a);
                        break;
                default:
                        tempstack.push(getnum(end,&i));
        }
    }
    return tempstack.top();
}
int main()
{
    // $
   // char *vv = "234-20^+200-500/2^";
   char vv[1000 ];
  
   cin>>vv;
    char m[100];
    int i=5,j=0;
  // cout<<vv<<endl;
    reverseBolish(vv,m);
  //  cout<<m<<endl; 
    double test = calculate(m);
 //   cout<<test;
   if(xiaoshu||floor(test)!=test) cout << fixed<<setprecision(3)<<test << endl;
     else   cout<<test << endl;
    return 0;
}