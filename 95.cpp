//多项式的链表实现
#include <bits/stdc++.h>
using namespace std;

struct T
{
int x;//系数
int y;//指数
};

list <T> a;
list <T> b;
list <T> ::iterator i=a.begin();
list <T> ::iterator j=b.begin();
list <T> ans;
list <T> ::iterator k=ans.begin();
int solve=0;

void read(void)
{
    char s;
scanf("%c",&s);
     if (s=='+') solve=1;
else if (s=='-') solve=2;
else if (s=='*') solve=3;
int x,y;

while(cin>>x>>y)
{
    T temp;temp.x=x;temp.y=y;//
  a.push_back(temp);
    if(cin.get()=='\n') break;
}

while(cin>>x>>y)
{
    T temp;temp.x=x;temp.y=y;
  b.push_back(temp);
    if(cin.get()=='\n') break;
}
//
 /* for(j=b.begin();j!=b.end();j++)
{
	cout<<j->y;
}
   */
}

void add(void)
{

while(!a.empty()&&!b.empty())
{
    if(a.front().y==b.front().y )
        {   
			//cout<<"eeeeee";
            T temp;temp.x=((a.front().x) +(b.front().x));temp.y=a.front().y;
			//
		/* 	cout<<temp.x;  */
            ans.push_back(temp);
			a.pop_front();b.pop_front();
           // i++; j++;
        }
    else if(a.front().y>b.front().y  )
        {
            T temp;temp.x=a.front().x;temp.y=a.front().y;
             ans.push_back(temp);
           a.pop_front();
			//i++;
        }
    else{
           T temp;temp.x=b.front().x;temp.y=j->y;
             ans.push_back(temp);
           b.pop_front();
			//j++;

	    }

}
//此后还有一个非空
while(!a.empty())
{
 T temp;temp.x=a.front().x;temp.y=a.front().y;
             ans.push_back(temp);
           a.pop_front();
}
while(!b.empty())    
{
	T temp; temp.x=b.front().x;temp.y=b.front().y;
             ans.push_back(temp);
           b.pop_front();
}
	



for(k=ans.begin();k!=ans.end();k++)
{
	cout<<k->x<<"  "<<k->y<<endl;
}



}


int  main ()
{
read();
add();


return 0;
}


/* 

typedef struct Node* List;
struct Node
{	
	List next;//指向下一个结点
	int x;//指数
	int z;//系数
};
List Read()
{
	List L = new Node;
	List head = L;
	int n=0;
	cout << "please put the count number" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, z;
		List temp = new Node;
		cout << "put the " << i + 1 << "pow" << endl;
		cin >> x;
		cout << "put the " << i + 1 << "number" << endl;
		cin >> z;
		temp->x = x;
		temp->z = z;
		L->next = temp;
		L = L->next;

	}
	L->next = NULL;
	return head->next;//由头节点！
}


//加法运算
List Add(List L1,List L2)
{
	List add = new Node;
	add->next = NULL;
	List head = add;
	List t1 = L1;
	List t2 = L2;

	List temp;
	while (t1&&t2)//如果两个链表都不是空的时候
	{
		if (t1->x== t2->x)//指数相等
		{
			temp->z = t1->z + t2->z;
			temp->x = t1->x;
			t1 = t1->next;
			t2 = t2->next;
		}
		else if (t1->x > t2->x)
		{
			temp->x = t1->x;
			temp->z = t1->z;
			t1 = t1->next;
		}
		else if(t1->x < t2->x)
		{
			temp->x = t2->x;
			temp->z = t2->z;
			t2 = t2->next;
		}
		add->next = temp;
		add = add->next;
		
	}
	if (t1)
	{
		add->next =t1;
	}
	else if (t2)
	{
		add->next = t2;
	}
	
	return head->next;
}

//乘法运算
List Mul(List L1, List L2)
{
	List mul = new Node;
	mul->next = NULL;
	List head = mul;
	List t1 = L1;
	List t2 = L2;
	for (; t1; t1 = t1->next)
	{
		for (; t2; t2 = t2->next)
		{
			List temp = new Node;
			temp->x = t1->x + t2->x;//指数相加
			temp->z = t1->z * t2->z;//系数相乘
			head = Add(temp, mul);
			mul = head;//重新确定开头
		}
		return head;
	}
}

//遍历
void Show(List L)
{	
	List t = L;
	int falg = 0;
	for (; t; t = t->next)
	{
		if (!falg)
		{
			falg = 1;
		}
		else
		{
			cout << " " ;
			
		}
		cout << t->z << t->x;
	}

}
 */