#include <bits/stdc++.h>
using namespace std;

//多项式的链表 官方实现
class PolyNode
{
public:
double xishu;//系数
int zhishu;//指数
public:
PolyNode(void);

~PolyNode(void);
PolyNode(double xishu, int zhishu);//构造函数，为xishu、zhishu赋值
bool operator< (PolyNode b)const;//判断两项是否满足小的关系，指数小者小
bool operator> (PolyNode b)const; //判断两项是否满足大的关系，指数大者大
};

PolyNode::PolyNode(void)
{
}

PolyNode::~PolyNode(void)
{
}

PolyNode::PolyNode(double xishu, int zhishu)
{
	this->xishu=xishu;
	this->zhishu=zhishu;
}

bool PolyNode::operator< (PolyNode b)const
{
	if(zhishu<b.zhishu)
		return true;
	return false;
}

bool PolyNode::operator> (PolyNode b)const
{
	if(zhishu>b.zhishu)
		return true;
	return false;
}
/* 3.2多项式类的实现
在多项式类中，必须有存储多项式各项的线性表，还必须有实现多项式运算的成员函数。
类的定义如下： */
class Polynomial//多项式类，其中实现了多项式的加减乘除。
{
	list<PolyNode> mypoly;//list模板，用来存放指数、系数对。内部用双向链表实现。
public:
	Polynomial(void);//构造函数
	~Polynomial(void);//析构函数
	Polynomial(string mystr);//构造函数，根据字符串解析出指数系数对
	int insert_item(double xishu, int zhishu);//在多项式中插入一项
	Polynomial add(Polynomial pa, Polynomial pb);//多项式相加
	Polynomial sub(Polynomial pa, Polynomial pb); //多项式相减
	void sort(void);//对list中的各项排序，指数大的项在后面
	void print(void);//格式化打印多项式
	PolyNode getfirst(void);//从list中得到第一项，并不删除
	void delfirst(void);//从list中删除第一项
	int getitemnum(void);//得到list中的项数
	Polynomial operator+(Polynomial pb);//重载运算符+，实现多项式加法
	Polynomial operator-(Polynomial pb); //重载运算符-，实现多项式减法


	Polynomial multiple(int num); //多项式相乘，乘以整数因子
	Polynomial multiple(PolyNode pnode); //多项式相乘，乘以一项
	Polynomial multiple(Polynomial pa, Polynomial pb); //多项式相乘
	Polynomial operator*(Polynomial pb); //重载运算符*，实现多项式乘法
	
	Polynomial div(Polynomial pa,Polynomial pb);//多项式相除
	Polynomial operator/(Polynomial pb); //重载运算符/，实现多项式除法
};
/* 具体的实现如下： */

Polynomial::Polynomial(void)
{
}

Polynomial::~Polynomial(void)
{
}

Polynomial::Polynomial(string mystr)
{
	//首先从mystr中解析出系数和指数。
}

int Polynomial::insert_item(double xishu, int zhishu)
{
	mypoly.push_back(PolyNode(xishu,zhishu));
	return 0;
}

Polynomial Polynomial::add(Polynomial pa, Polynomial pb)
{
	pa.sort();pb.sort();
	Polynomial pc;
	PolyNode a,b;
	while(pa.getitemnum() && pb.getitemnum())
	{
		
		a=pa.getfirst();b=pb.getfirst();
		if(a.zhishu<b.zhishu)
		{
			pc.insert_item(a.xishu,a.zhishu);
			pa.delfirst();
		}
		else if(a.zhishu>b.zhishu)
		{
			pc.insert_item(b.xishu,b.zhishu);
			pb.delfirst();
		}
		else
		{
			if(a.xishu+b.xishu )
			{
				pc.insert_item(a.xishu+b.xishu,a.zhishu);
			}
			pa.delfirst();pb.delfirst();
		}
	
	}
	while(pa.getitemnum())
	{
		a=pa.getfirst();
		pc.insert_item(a.xishu,a.zhishu);
		pa.delfirst();
		
	}
	while(pb.getitemnum())
	{
		b=pb.getfirst();
		pc.insert_item(b.xishu,b.zhishu);
		pb.delfirst();
	}


	return pc;
}

Polynomial Polynomial::sub(Polynomial pa, Polynomial pb)
{
	Polynomial pc;
	pb=pb.multiple(-1);
	pc=add(pa,pb);
	return pc;
}

void Polynomial::sort(void)
{//使得各项按照从小到大的顺序排列
	mypoly.sort(greater<PolyNode>());
	mypoly.reverse();
}


void Polynomial::print(void)
{
	if(mypoly.size()==0) return;
	list<PolyNode>::iterator i=mypoly.begin();
			double xishu=(*i).xishu ;
		int zhishu=(*i).zhishu ;

		if(zhishu==0)
		{
			cout<<xishu;

		}
		else if(zhishu==1)
		{
			cout<<xishu<<"X";

		}
		else	
			cout<<xishu<<"X^"<<zhishu;

	for(++i;i!=mypoly.end();i++)
	{

		xishu=(*i).xishu ;
		zhishu=(*i).zhishu ;
		if(xishu!=1)
		{
			if(xishu>0)
				cout<<"+";
			cout<<xishu<<"X^"<<zhishu;;

		}
		else
		   cout<<"+X^"<<zhishu;
	}
	cout<<endl;
}
PolyNode Polynomial::getfirst(void)
{
	return mypoly.front();
}

void Polynomial::delfirst(void)
{
	mypoly.pop_front();
}

int Polynomial::getitemnum(void)
{
	return mypoly.size();
	
}

Polynomial Polynomial::operator+(Polynomial pb)
{
	return add(*this,pb);
}
Polynomial Polynomial::operator-(Polynomial pb)
{
	return sub(*this,pb);
}
Polynomial Polynomial::multiple(int num)
{
	Polynomial pc;
	for(list<PolyNode>::iterator i=mypoly.begin();i!=mypoly.end();i++)
		pc.insert_item((*i).xishu*num,(*i).zhishu);
	return pc;
}

Polynomial Polynomial::multiple(PolyNode pnode)
{
	Polynomial pc;
	for(list<PolyNode>::iterator i=mypoly.begin();i!=mypoly.end();i++)
		pc.insert_item((*i).xishu*pnode.xishu ,(*i).zhishu+pnode.zhishu );
	return pc;
}

Polynomial Polynomial::multiple(Polynomial pa, Polynomial pb)
{
	Polynomial pc,temp;
	while(pb.getitemnum())
	{
		PolyNode b;
		b=pb.getfirst();
		pb.delfirst();
		temp=pa.multiple(b);
		pc=pc+temp;
	}
	return pc;

}

Polynomial Polynomial::operator*(Polynomial pb)
{
	return multiple(*this,pb);
}



Polynomial Polynomial::div(Polynomial pa,Polynomial pb)
{
	Polynomial pc;
	if(pa.getitemnum()==0) 
	{
		pc.insert_item(0,0);
		return pc;
	}

	while(1)
	{
		PolyNode a,b;
		a=pa.getfirst();b=pb.getfirst();
		if(a.zhishu <b.zhishu)
			break;
		else if(a.zhishu >b.zhishu)
		{
			PolyNode c(a.xishu/b.xishu,a.zhishu-b.zhishu);
			pc.insert_item(c.xishu,c.zhishu);
			pa=pa-pb.multiple(c);
		}
		else
		{
			PolyNode c(a.xishu/b.xishu,a.zhishu-b.zhishu);
			pc.insert_item(c.xishu,c.zhishu);
			break;

		}
	}

	return pc;
}

Polynomial Polynomial::operator/(Polynomial pb)
{

	return div(*this,pb);
}


int _tmain()
{
    
	Polynomial pa,pb,pc;
	pa.insert_item(1,1);
	pa.insert_item(1,2);
	//pa.insert_item(1,3);
	pb.insert_item(1,1);
	pb.insert_item(1,2);
	//pb.insert_item(5,3);
	cout<<"the polynomial a is:"<<endl;
	pa.print();
	cout<<"the polynomial b is:"<<endl;
	pb.print();

	cout<<"the sum is"<<endl;
	pc=pa+pb;
	pc.print();
	

	cout<<"the sub is"<<endl;
	pc=pa-pb;

	pc.print();

	

	cout<<"the product is"<<endl;
	pc=pa*pb;
	pc.print();

	cout<<"the div is"<<endl;

	pc=pa/pb;
	pc.print();


   int temp;
   cin>>temp;
  
	return 0;
}
