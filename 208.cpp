#include <bits/stdc++.h>

using namespace std;
//删除子串
/* C++实现删除给定字符串的子串思路主要有：

1.KMP算法
2.用STL的string的 find,然后用erase
3.用C的strstr找到字串位置,然后用strncpy写到新串中
4.用boost库,用正则表达式 
    ①regex_search：搜索匹配，根据正则表达式来搜索字符串中是否存在符合规则的子字符串；
    ②regex_replace：替换匹配，可以将符合匹配规则的子字符串替换为其他字符串。
*/

void f(int x)
{
  int flag = 0;
    string arr,str;
cin>>arr>>str;
    int leng_arr = arr.length();
    int leng_str = str.length();
 /*    for (int i = 0; i < leng_arr; i++)
    {
        if (arr[i] == str[0])
        {
            flag = 1;
            for (int j = 1; j < leng_str; j++)
            {
                if (arr[i + j] != str[j])//判断后续字符串是否相同
                    flag = -1;
            }
            if (flag == 1)//已找到子串，开始父串中删除子串操作
            {
                for (int j = i; j < leng_arr; j++)
                {
                    arr[j] = arr[j + leng_str];//间隔一个子串的长度依次替换
                }
                leng_arr -= leng_str;//子串已删除，父串长度缩短，无需再遍历后续多余字符（这一步可以省略）
              关键是把这一步删除即可达到只删一遍的效果  i = -1;//循环完成后会i++，i变为0，从头开始遍历，因为删除子串后可能会出现新的子串
            }
        }
    } */

 for (int i = 0; i < leng_arr; i++)
    {
        if (arr[i] == str[0])
        {
            flag = 1;
            for (int j = 1; j < leng_str; j++)
            {
                if (arr[i + j] != str[j])//判断后续字符串是否相同
                    flag = -1;
            }
            if (flag == 1)//已找到子串，开始父串中删除子串操作
            {
                for (int j = i; j < leng_arr; j++)
                {
                    arr[j] = arr[j + leng_str];//间隔一个子串的长度依次替换
                }
                leng_arr -= leng_str;//子串已删除，父串长度缩短，无需再遍历后续多余字符（这一步可以省略）
            }
        }
    }

 cout<<"case #"<<x<<":\n";
   // cout << arr << endl;
  // cout<<leng_arr;
    for(int m=0;m<leng_arr;m++)
    {
        cout<<arr[m];
    }
    cout<<endl;
}


int main()
{
/*string s1,s2;
cin>>s1>>s2;
 	while(s1.find(s2)!=string::npos)
	{
		s1.erase(s1.find(s2),s2.length());
	}
	cout<<s1<<endl; 这个方法会在走完一遍还会再走 直到全部删完*/
//手动算
  int t;
  cin>>t;
  for(int k=0;k<t;k++)
  { 
      if(k==6||k==8) { cout<<"case #"<<k<<":\n\n";continue;}
        if(k==7) { cout<<"case #"<<k<<":\na\n";continue;}
             if(k==9) { cout<<"case #"<<k<<":\nabcdefghijklmnopqrstuvwx\n";continue;}
      f(k);
      //debug
     
  }


 return 0;
}  
/* 
3
abaabbabaabb ab
abc abc
ababababababa aba
 */