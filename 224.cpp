#include<bits/stdc++.h>
using namespace std; 
typedef unsigned long long ULL; 
enum Error_code{not_present,overflow,duplicate_error,success,underflow};

struct T  //店家结构 
{
	int lx,ly;
	string name,style;
	T(string &sname,int &llx,int &lly,string &sstyle);        
	T(const T &p);
};
bool operator > (const T &x, const T &y);
bool operator < (const T &x, const T &y);
bool operator <= (const T &x, const T &y);
ostream & operator << (ostream &output, T &a);

T::T(const T &p)
{
	lx=p.lx;
	ly=p.ly;
	name=p.name;
	style=p.style;
}

T::T(string &sname,int &llx,int &lly,string &sstyle)
{
	lx=llx;
	ly=lly;
	name=sname;
	style=sstyle;
}

bool operator < (const T &x, const T &y)
{
	return x.name < y.name;
}

bool operator > (const T &x, const T &y)
{
	return x.name>y.name;
}

bool operator <= (const T &x, const T &y)
{
	return x.name<=y.name;
}

ostream & operator << (ostream &output, T &a)
{
	output<< a.lx << " " << a.ly;
	return output;
}



const int hash_size=9999;
class Solution
{
	public:
		Solution();
		void just_do_it_sequential_search();  //顺序
		void just_do_it_binary_search();  //二分
	private:
		string target; 
		ULL use_probe;  //目标对应的hash值
		vector<T> entry[hash_size];  
	protected:
		void sequential_search();
		ULL hash_position(const string &new_entry) const; //求map值
		void init(string s_target);    //获取餐馆信息
		void append(T a);   
		void orded_insert(T a); //顺序插    用来二分查找
		void recursive_binary_search(int bottom, int top, int &position);
		void recursive_binary_search_2(int bottom, int top, int &position);
};

//顺序查
void Solution::just_do_it_sequential_search()
{
	int m,n;
	cin >> m >> n;
	for(int i=0;i<m;i++)
	{
		string name,style;
		int lx,ly;
		cin >> name >> lx >> ly >> style;
		append(T(name,lx,ly,style));
	}
	for(int i=0;i<n;i++)
	{
		string find;
		cin >> find;
		init(find);
		sequential_search();
	}
}

void Solution::sequential_search()
{
	int len_entry;
	len_entry=entry[use_probe].size();
	for(int position=0;position<len_entry;position++)
	{
		if(entry[use_probe][position].name==target)
		{
			cout << entry[use_probe][position] << endl;
			return ;
		}
	}
	cout << "NULL" << endl;
	return ;
}


//二分查
void Solution::orded_insert(T a)
{
	ULL probe=hash_position(a.name);
	if(entry[probe].size()==0)
	{
		entry[probe].push_back(a);
		return ;
	}
	else if(a<entry[probe].front())
	{
		entry[probe].insert(entry[probe].begin(),a);
		return ;
	}
	else if(a>entry[probe].back())
	{
		entry[probe].push_back(a);
	}
	else
	{
        vector<T>::iterator it=entry[probe].begin();
        vector<T>::iterator temp;
        for (it; it!=entry[probe].end(); ++it)
		{    
            temp=(it+1);
            if (*it<a&&a<=*temp)
            {
                entry[probe].insert(it+1,a);
                break;
            }
        }
    	return ;
	}
}

void Solution::just_do_it_binary_search()
{

	int m,n;
	cin >> m >> n;
	for(int i=0;i<m;i++)
	{
		string name,style;
		int lx,ly;
		cin >> name >> lx >> ly >> style;
		orded_insert(T(name,lx,ly,style));
	}
	for(int i=0;i<n;i++)
	{
		string find;
		cin >> find;
		init(find);
		int bottom=0;
		int top=entry[use_probe].size()-1;
		int position=-1;
		recursive_binary_search(bottom,top,position);
	}
}

void Solution::recursive_binary_search(int bottom, int top, int &position)
{ 
	if (bottom<top) 
	{ 
		int mid = (bottom+top)/2;
		if (target>entry[use_probe][mid].name) 
			return recursive_binary_search(mid+1,top,position);
		else 
			return recursive_binary_search(bottom,mid,position);
	}
	else 
	{
		position=bottom; 
		if (entry[use_probe][position].name == target) 
		{
			cout << entry[use_probe][position] << endl;
			return ;
		}
		cout << "NULL" << endl;
		return ;
	}
}

void Solution::recursive_binary_search_2(int bottom, int top, int &position)
{ 
	if (bottom<=top) 
	{ 
		int mid = (bottom+top)/2;
		if(target==entry[use_probe][mid].name)
		{
			position=mid; 
			cout << entry[use_probe][position] << endl;
			return ;
		}
		if (target>entry[use_probe][mid].name) 
			return recursive_binary_search_2(mid+1,top,position);
		else 
			return recursive_binary_search_2(bottom,mid-1,position);
	}
	else 
	{
		cout << "NULL" << endl;
		return ;
	}
}


Solution::Solution()
{}

void Solution::init(string s_target)
{
	target=s_target;
	use_probe=hash_position(target);
}

void Solution::append(T a)
{
	ULL probe=hash_position(a.name);
	entry[probe].push_back(a);
}

ULL Solution::hash_position(const string &str) const
{
	ULL seed = 13;
    ULL hash = 0;
	for(int i=0;i<str.length();i++)
    {
        hash = (hash*seed+(str[i]-'A'))%hash_size;
    }
    return hash; 
}

int main()
{
	std::ios::sync_with_stdio(false);//快速输入输出 但是空间会炸
	Solution s;
	s.just_do_it_sequential_search();
	//s.just_do_it_binary_search();
	return 0;
}
/*

输入n个数据   m个要查的数据
5 3
JEANGEORGES 260036 14362 FRENCH
HAIDILAO 283564 13179 CHAFINGDIS
KFC 84809 46822 FASTFOOD
SAKEMATE 234693 37201 JAPANESE
SUBWAY 78848 96660 FASTFOOD
HAIDILAO
SAKEMATE
SUBWAY
输出
283564 13179 // HAIDILAO
234693 37201 // SAKEMATE
78848 96660 // SUBWAY

*/