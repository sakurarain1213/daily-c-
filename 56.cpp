#include <bits/stdc++.h>
using namespace std;
void solve()/* Define function solve() to process one case of the problem    */
{
    string ss = "", ans = "";
    getline(cin, ss);
    getline(cin, ans);
    for(auto &i : ss) // 先分别转小写
        i = tolower(i);
    for(auto &i : ans)
        i = tolower(i);
    for(int i = 0; ;) // 对被查找的字符串进行遍历，每次从位置i开始找
    {
        unsigned int pos = 0;
        int len = ss.size();
        if(ans.find(ss, i) == string::npos || i == ans.size()){
            cout << "None" << endl;
            break;
        }
        else{
            pos = ans.find(ss, i);
            if(( pos + len == ans.size()  ||  ans[pos + len] == ' ' )
                    && ( pos == 0  || ans[pos - 1] == ' ' )){
                cout << pos + 1 << endl; // 输出位置即可 题目要求从1开始输
                break;
            }
            i = pos + len; // 重新定位查找位置
        }
    }
    return ;
}

int main()
{
    int T, i;
    (cin >> T).get();
    for(i = 0; i < T; ++i)
    {
        cout << "case #" << i << ":\n";
        solve();
    }
    return 0;
}





/* 3
IN
Find a word within a string in English and in Chinese.
to
    Find a word within a string in English and in Chinese.
In
    Find a word within a string in English and in Chinese. */