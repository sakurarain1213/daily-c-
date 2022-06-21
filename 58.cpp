#include <bits/stdc++.h>
using namespace std;

int  main ()
{

//分割字符串的方法1；
//char s[]="alskdjlkasjd salkd asd as s";
/* const char *p=" ";
char *t;

string ss;
t=strtok(s,p);

while(t)
{
cout<<t<<endl;
t=strtok(NULL,p);
}
 */
//2
string sss;//分割字符串为单词的方法  利用string 本身读入就终止   所以第二种是substr
getline(cin,sss);
istringstream is(sss);
string temp;
string a[100];
int x=0;
while(is>>temp)
{
//cout<<temp<<endl;
a[x]=temp;
x++;
}


//3
/* string s;
getline(cin,s);
int i=0,p1=0,p2=0;
int n=s.length();
string temp;
while(i<n)
{
if(s[i]==' ') p2=i;
temp=s.substr(p1,p2-p1);
cout<<temp<<endl;
p1=p2+1;
i=p1+1;
} */

//4
/* 

 string str ;//{ "dog cat cat dog" };
 getline(cin,str);
    istringstream input( str );
    vector<string> vec;
	
    // ---------------------------------------------
    string temp;
    while ( input >> temp )
        vec.push_back( temp );
    // ---------------------------------------------
    
    for ( string word : vec )
        cout << word << " ";


 */

return 0;
}