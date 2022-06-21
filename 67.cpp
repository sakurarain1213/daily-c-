//官方实现
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,Case=0;
	map<int,int>team;//映射关系（编号--->队伍的编号）
	while(cin>>t&&t!=0)
	{
		printf("Scenario #%d\n",++Case);
		for(int i=0;i<t;i++)
		{
			int n,x;
			cin>>n;    //队伍人数 
			while(n--)
			{
				cin>>x;  //输入编号
				team[x] = i; //队伍号都为i 
			}
		}
		
		queue<int> q,q2[1000+10];//q是队伍编号的队列，q2是每个队伍的队列 
		while(true)
		{
			string str;
			cin>>str;
			if(str[0]=='E')
				{
					int num;
					cin>>num;
					int t = team[num]; //编号为num的人的队伍号
					if(q2[t].empty())	
						q.push(t);    //团队t进入到团队队列 
					q2[t].push(num);   //num进入到队伍t的队列中 
				}	
            else if(str[0]=='S')
				{break;}
			else if(str[0]=='D')
				{
					int top = q.front(); //队伍编号 
					printf("%d\n",q2[top].front());//输出该队伍中的第一个人的编号
					q2[top].pop(); //同时把这第一个人弹出队列
					if(q2[top].empty())//如果把这个人弹出队列后，队伍为空，那么需要把这个队伍从团体队列中删除
						q.pop(); 
				}
		
		}
		cout<<endl;
	}
	return 0;
}
