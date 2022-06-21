
#include <bits/stdc++.h>
using namespace std;

/* ①建立一个类来储存 日 月 年
由于月是字符串形式，我们利用string的特性可以用if（string a == string b)来将其转化为数字，然后利用sort函数排序好即可
② 数据中有一个“."数据，getchar（）把他消掉即可 */
string month[] = //常量数组
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", 
    "ceh", "mac", "kankin", "muan", "pax", 
    "koyab", "cumhu","uayet"
};
struct date
{
    int y;
    string m;
    int d;
    int m_num;
    void init()//string 转int   其实map也行
    { for(int i = 0; i < 19; i++)
        { if(this->m == month[i])
                this->m_num = i; } }
};
bool cmp(date a, date b)
{if(a.y == b.y)
    { if(a.m_num == b.m_num)
        {return (a.d < b.d);}
        return(a.m_num < b.m_num);}
    return (a.y < b.y);}
int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        int alld;
        cin >> alld;
        date * D = new date[alld];
        for(int j = 0; j < alld; j++)
        { cin >> D[j].d;
            getchar();
            cin >> D[j].m;
            cin >> D[j].y;
            D[j].init(); }
        sort(D,D+alld,cmp);
        cout << "case #" << i << ":" << endl;
        for(int j = 0; j < alld; j++)
        { cout << D[j].d << ". "<<D[j].m << " " << D[j].y << endl; }
    }
return 0;}

/* 
2
2
8. yoxkin 2012
0. pop 2000
3
8. yoxkin 2012
9. yoxkin 2010
0. uayet 2012

 */