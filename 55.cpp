#include<bits/stdc++.h>
using namespace std;
//学习写法 字符串分割单词 排序
int main()
{
    int t; string str, tmp;
    (cin >> t).get();
    for (int c = 0; c < t; c++)
    {
        getline(cin, str);
        for (auto &i : str)
            if (!isalpha(i))i = ' ';
        stringstream ss(str);
        set<string>ans;
        while (ss >> tmp)ans.insert(tmp);
        auto x = ans.begin();
        cout << "case #" << c << ":\n" << *x;
        while (++x != ans.end())
            cout << ' ' << *x;
        cout << endl;
    }
}
/* 
#include <bits/stdc++.h>
using namespace std;

void f(int x)
{
string s;
getline(cin,s);
istringstream is(s);
string temp;
string a[100];
int i=0;
while(is>>temp)
{
//cout<<temp<<endl;
a[i]=temp;
i++;
}

 int j=i;
 while(j>=0)
{cout<<a[j];j--;} 
 
sort(a,a+i-1);
cout <<"case #"<<x<<":"<<endl;
for(int n=0;n<i;n++)
{
   if(a[n+1]!=a[i]) cout <<a[n]<<" ";
}
cout<<endl;

}

int  main ()
{
//分割字符串为单词的方法  利用string 本身读入就终止   所以第二种是substr
int x;
scanf("%d\n",&x);
for(int k=0;k<x;k++)
{
f(k);
}

return 0;
} */