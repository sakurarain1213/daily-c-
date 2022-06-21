 #include <bits/stdc++.h>
using namespace std;
 
 //dfs 应用

  string c[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//数字代表的字符
int b[10]={0,0,3,3,3,3,3,4,3,4};  
/* 电话号码对应的字符组合：在电话或者手机上，一个数字如2对应着字母ABC，7对应着PQRS。那么数字串27所对应的字符的可能组合就有3*4=12种（如AP，BR等）。现在输入一个3到11位长的电话号码，请打印出这个电话号码所对应的字符的所有可能组合和组合数。
算法分析：在这里，递归出口是，当输入的是一个数字时，返回这个数字所有可能性的组合，递归体是当输入一串数字，每个数字代表不同的字符串，返回最后一个数字跟前面已产生的字符串进行组合
算法构造：首先建一个数组，用来存放每个数字代表的字符串组合，然后在建一个数组，用来存放每个字符串的长度，在函数中，先进行判断是否是最后一位，然后根据判断执行函数。
算法实现： */


int cnt=1;
int total[10]={0,0,3,3,3,3,3,4,3,4};//数字代表的字符个数
 
void dfs(int *number,int *answer,int index,int n){
    if(index==n)//判断是否为最后一位
	{
	for( int i=0;i<n;i++){
        printf("%c",c[number[i]][answer[i]]);
		printf("%d\n",cnt++);
		return;
	}
    }
	for(answer[index]=0;answer[index]<total[number[index]];answer[index]++)
		dfs(number,answer,index+1,n);
    }
int main()
{
	int number[11];//储存电话号码
	int n,i;
	int answer[11]={0};//数字代表的字符的位置
	printf("length : \n");
	scanf("%d",&n);//输入电话号码位数
	printf("number : such as 3 2 1:\n");
	for(i=0;i<n;i++)
	scanf("%d",number+i);
	dfs(number,answer,0,n);
	return 0;
 
}