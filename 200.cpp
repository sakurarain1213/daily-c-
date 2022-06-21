/*
：*/
#include <bits/stdc++.h>
using namespace std;

int main() {
string s;
cin>>s;
		int  size, i = 0, j, k, max = 0;
		size = s.size();
		for (j = 0; j < size; j++) {
			for (k = i; k < j; k++)
				if (s[k] == s[j]) {
					i = k + 1;	// 使得i一定在与j相同的上一个字符的右边。
					break;		// 巧妙, 只找相邻的
				}
			if (j - i + 1> max)
				max = j - i + 1;
		}
	cout<< max;
    return 0;
}
/* 
【输入】
第一行，长度为n的字符串，字符串中不包含空格，n小于2000。
【输出】
最大非重复子串的长度；

例如：
【输入】
pwwkew
【输出】
3
【输入】
bbbbb
【输出】
1 */