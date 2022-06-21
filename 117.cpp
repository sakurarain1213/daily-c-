#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Maze
{
	public:
		Maze();//初始化 
		void createmaze();//创建迷宫 
		void solve(int x,int y,int cnt);//走迷宫 
		int getstep();//获取步数 
		void init();//初始化 
	private:
		int maze[14][14];
		int tempmaze[14][14];
		int step;//步数 
		int ox,oy;//出口坐标 
};

Maze::Maze()
{
	step=10000;
}

void Maze::init()
{
	step=10000;
}

void Maze::createmaze()
{
	char opr;
	for(int i=0;i<14;i++)
	{
		maze[0][i]=maze[i][0]=maze[13][i]=maze[i][13]=1;
	}
	for(int i=1;i<13;i++)
	{
		for(int j=1;j<13;j++)
		{
			cin >> opr;
			if(opr=='W')
				maze[i][j]=1;
			else if(opr=='O')
				maze[i][j]=0;
			else
			{
				maze[i][j]=0;
				ox=i;
				oy=j;
			}
		}
	}
}

void Maze::solve(int x,int y,int cnt)
{
	if(maze[x][y]!=0) //此路不通
		return;
	if(x==ox&&y==oy)//走出迷宫
	{
		step=min(cnt,step);
		return;
	}
	maze[x][y]=1;
	//四个方向探索 
	if(x>=1)
		solve(x-1,y,cnt+1);
	if(y<=12)
		solve(x,y+1,cnt+1);
	if(x<=12)
		solve(x+1,y,cnt+1);
	if(y>=1)
		solve(x,y-1,cnt+1);
	maze[x][y]=0;
	return; 
}

int Maze::getstep()
{
	return step;
}

int main(int argc, char** argv) 
{
	Maze a;
	a.createmaze();
	for(int i=0;i<3;i++)
	{
		a.init();
		int x,y;
		char c;
	 	cin >> c >> x >> c >> y >> c;
	 	a.solve(x+1,y+1,0);
	 	if(a.getstep()==10000)
	 		cout << "-1" << " ";
	 	else
	 		cout << a.getstep()+1 << " ";
	}
	return 0;
}
/*  example



O W O W O W O O W O W O
O W O W W W W O W O O E
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O O O O W W W W
W W W O O O O W W W O O
O W W W W O O O O O W W
W W W O O O O O W W W W
(1,9) (5,7) (7,8)

O W O W O W O O W O W O
O W O W W W W O W O O E
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O O O O W W W W
W W W O O O O W W W O O
O W W W W O O O O O W W
W W W O O O O O W W W W
(0,0) (5,7) (7,8)

O W O W O W O O W O W O
O W O W W W W O W O O O
O W W W O O O O O O O O
W W W O O O O W W W O W
O O O O W W W O O O O O
O O W O W O W O W O W W
O W W O O O W W O O O W
O O W O O W W W O O O O
O O O W O O O O W W W W
W W W W O O O W W W O O
O W W W W O O O O O W W
W W W E O O O O W W W W
(4,1) (5,7) (7,8)


 */