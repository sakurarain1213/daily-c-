
#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int maxt = 1000+10;
int main()
{
	int t,kase=0;
	while(cin>>t&&t)
	{
		printf("Scenario #%d\n", ++kase);
		//记录所有人的团队编号
		map<int,int> team; //team[x]表示编号为x的人所在的团队编号
		for(int i=0;i<t;i++)
		{
			int n,x;
			cin>>n; //队员数量
			while(n--)
			{
				cin>>x;
				team[x]=i;
			}  
		}
		
		queue<int> q; //团队整体的队列
		queue<int> q2[maxt];  //团队i的成员的队列 
		for(;;)
		{
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if (cmd[0]=='D')
			{
				int t=q.front();
				cout<<q2[t].front()<<endl;  q2[t].pop();
				
				if(q2[t].empty()) q.pop(); //团体t全体出队列
			}
			
			else if(cmd[0] == 'E') 
			{ 
				scanf("%d", &x); 
				int t = team[x]; 
				if(q2[t].empty()) 
				q.push(t); //团队t进入队列 q2[t].push(x);
			}
			cout<<endl;
		} 
	}
	return 0;
} 
