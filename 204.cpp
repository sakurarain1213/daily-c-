#include<bits/stdc++.h>
using namespace std;
 //字符串替换 要求所有不重叠的重复串全部替换
 //找到字符串中目标子串的方法可以是暴力遍历  也可以kmp 比较复杂
//第一种替换字符串的方法用replace()
void string_replace(string&s1,const string&s2,const string&s3)
{
	string::size_type pos=0;
	string::size_type a=s2.size();
	string::size_type b=s3.size();
	while((pos=s1.find(s2,pos))!=string::npos)
	{
		s1.replace(pos,a,s3);
		pos+=b;
	}
}
//第二种替换字符串的方法用erase()和insert()
void string_replace_2(string&s1,const string&s2,const string&s3)
{
	string::size_type pos=0;
	string::size_type a=s2.size();
	string::size_type b=s3.size();
	while((pos=s1.find(s2,pos))!=string::npos)
	{
		s1.erase(pos,a);
		s1.insert(pos,s3);
		pos+=b;
	}
}
int main()
{
string s1,s2,s3;
cin>>s1>>s2>>s3;
string_replace_2(s1,s2,s3);
cout<<s1;
 return 0;
}  
//iamstupid stupid clever