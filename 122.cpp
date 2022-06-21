#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string a,b,sum;
    int diff,length;
    int carry = 0;
    while(cin >> a >> b)
    {
        if(a.length() < b.length())
        {
            b.insert(0,"0");
            diff = b.length() - a.length();
            a.insert(0,diff,'0');
            sum = b;
        }
        else if (a.length() > b.length())
        {
            a.insert(0,"0");
            diff = a.length() - b.length();
            b.insert(0,diff,'0');
            sum = a;
        }
        else//为了防止最高位进位，在前面多加一位
        {
            a.insert(0,"0");
            b.insert(0,"0");
            sum = b;
        }
        length = sum.length();
        for(int i = length-1; i >= 0; --i)
        {
            int temp_a = a[i] - '0';
            int temp_b = b[i] - '0';
            int s = temp_a + temp_b;
            if(s + carry > 9)
            {
                sum[i] = s + carry - 10 + '0';
                carry = 1;
            }
            else
            {
                sum[i] = s + carry + '0';
                carry = 0;
            }
        }
        if(sum[0] == '0')//把最高位的0去掉
        {
            sum.erase(0,1);
        }
        cout << sum << endl;
        sum.clear();
    }
    return 0;
}