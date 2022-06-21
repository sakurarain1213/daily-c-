#include <bits/stdc++.h>
using namespace std;
//大数四则运算   要考虑负数



int compare(string s1, string s2)
{
    if (s1.size() > s2.size()) return 1;
    else if (s1.size() < s2.size()) return -1;
    return s1.compare(s2);
}

string add(string str1, string str2);
string sub(string str1, string str2);

string add(string str1, string str2)
{
    int sign = 1;
    string str;
    if (str1[0] == '-') {
        if (str2[0] == '-') {
            sign = -1;
            str = add(str1.erase(0, 1), str2.erase(0, 1));}
        else {  str = sub(str2, str1.erase(0, 1)); }
    }
    else {
        if (str2[0] == '-') {
            str = sub(str1, str2.erase(0, 1));}
        else {
            int len1 = str1.size();
            int len2 = str2.size();
            int i;
           
            if (len1 < len2) { //add 0 at begin and end
                for (i = 1; i <= len2 - len1; i++)
                    str1 = "0" + str1;
            }
            else {
                for (i = 1; i <= len1 - len2; i++)
                    str2 = "0" + str2;
            }
            int current = 0, carry = 0;
            for (int i = str1.size() - 1; i >= 0; i--) {
                current = ((int)str1[i] - '0' + (int)str2[i] - '0' + carry) % 10;
                carry = ((int)str1[i] - '0' + (int)str2[i] - '0' + carry) / 10;
                str = (char)(current + '0') + str;
            }
            if (carry != 0) {
                str = (char)(carry + '0') + str;
            }
        }
    }
    if (sign == -1)//mark the -
        str = "-" + str;
    return str;
}

string sub(string str1, string str2)
{
    int sign = 1, i;
    string str;
    if (str2[0] == '-') {
        str = add(str1, str2.erase(0, 1));
    }
    else {
        int flag = compare(str1, str2);
        if (flag == 0) return "0";
        if (flag < 0) {
            sign = -1;//ans <0
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        int len = str1.size() - str2.size();
        int jiewei;
        for (i = str2.size() - 1; i >= 0; i--) {
            if (str1[i + len] < str2[i]) {//according to every bit   sub
                jiewei = 1;
                while (1) {
                    if (str1[i + len - jiewei] == '0') {//borrow a bit
                        str1[i + len - jiewei] = '9';
                        jiewei++;
                    }
                    else {
                        str1[i + len - jiewei] = char(int(str1[i + len - jiewei]) - 1);
                        break;
                    }
                }
                str = char(str1[i + len] - str2[i] + ':') + str;
            }
            else str = char(str1[i + len] - str2[i] + '0') + str;
        }
        for (i = len - 1; i >= 0; i--)
            str = str1[i] + str;
    }
    str.erase(0, str.find_first_not_of('0'));// remarkable method to erease 0 on the front
    if (str.empty()) str = "0";
    if (sign == -1)
        str = "-" + str;
    return str;
}

string multiply(string str1, string str2)
{
    int sign = 1, i, j;
    string str;
    if (str1[0] == '-') {
        sign *= -1;
        str1 = str1.erase(0, 1);
    }
    if (str2[0] == '-') {
        sign *= -1;
        str2 = str2.erase(0, 1);
    }
    int len1 = str1.size();
    int len2 = str2.size();
    for (i = len2 - 1; i >= 0; i--) {
        string tempstr;//store every bit
        int current = 0, carry = 0, str2_cur = int(str2[i]) - '0';
        if (str2_cur != 0) {
            //in case of overflow  add 0 on the front
            for (j = 1; j <= (int)(len2 - 1 - i); j++)
                tempstr = "0" + tempstr;
            for (j = len1 - 1; j >= 0; j--) {
                current = (str2_cur * (int(str1[j]) - '0') + carry) % 10;
                carry = (str2_cur * (int(str1[j]) - '0') + carry) / 10;
                tempstr = char(current + '0') + tempstr;
            }
            if (carry != 0)
                tempstr = char(carry + '0') + tempstr;
        }
        str = add(str, tempstr);
    }
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty())
        str = "0";
    if (sign == -1)
        str = "-" + str;
    return str;
}

//when choose == 1   return ans ; choose == 0, return the mod ans
string divide(string str1, string str2)
{
    int choose = 1;
    string quo, res;//ans and mod ans
    int sign1 = 1, sign2 = 1;
    int i;
    if (str2 == "0") {
        quo = "wrong";
        res = "'wrong";
        if (choose == 1) return quo;//  only return ans
        return res;
    }
    if (str1 == "0") {
        quo = "0";
        res = "0";
    }
    if (str1[0] == '-') {
        str1 = str1.erase(0, 1);
        sign1 *= -1;
        sign2 *= -1;
    }
    if (str2[0] == '-') {
        str2 = str2.erase(0, 1);
        sign1 *= -1;
    }
    int flag = compare(str1, str2);
    if (flag < 0) { //a<b
        quo = "0";
        res = str1;
    }
    else if (flag == 0) {//a==b
        quo = "1";
        res = "0";
    }
    else {
        int len1 = str1.size();
        int len2 = str2.size();
        string tempstr;
        tempstr.append(str1, 0, len2 - 1);//add more 0 in case of wrong
        for (i = len2 - 1; i < len1; i++) {
            tempstr = tempstr + str1[i];
            tempstr.erase(0, tempstr.find_first_not_of('0'));
            if (tempstr.empty())
                tempstr = "0";
            for (char ch = '9'; ch >= '0'; ch--) {
                string str;
                str = str + ch;
                if (compare(multiply(str2, str), tempstr) <= 0) {
                    quo = quo + ch;
                    tempstr = sub(tempstr, multiply(str2, str));
                    break;
                }
            }
        }
        res = tempstr;
    }
    quo.erase(0, quo.find_first_not_of('0'));
    if (quo.empty()) quo = "0";
    if (sign1 == -1) quo = "-" + quo;
    if (sign2 == -1) res = "-" + res;
    if (choose == 1) return quo;
    return res;
}
int main()
{
    char ch;
    string s1, s2, s;
    cin >> s1 >> s2 >> ch;
    switch (ch) {
    case '+':s = add(s1, s2); break;
    case '-':s = sub(s1, s2); break;
    case '*':s = multiply(s1, s2); break;
    case '/':s = divide(s1, s2); break;
    default:break;
    }
    cout << s << endl;
    return 0;
}
/* int compare(string str1, string str2);

string multiply(string str1, string str2);
string divide(string str1, string str2); 


56891237265
32156789215
-



*/