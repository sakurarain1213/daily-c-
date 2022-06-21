#include <bits/stdc++.h>
using namespace std;//string 的处理                 字典序排序 可以直接string数组sort
int  main (){
string s[1001];
string::size_type index;
int n;cin>>n;
for(int i=0;i<n;i++)
{cin>>s[i];}
int x,y;cin>>x>>y;
while(x!=-1||y!=-1){ 
    index=s[y].find(s[x]);//也可以直接int t=s[y].find(s[x]) 找不到就是-1
            if(index==string::npos) cout<<-1<<" ";
            else cout<<index<<" ";
    cin>>x>>y;}
cout<<endl;
sort(s,s+n);
for(int i=0;i<n;i++)
{cout<<s[i]<<" ";}
return 0;}
/* 
6
aaa aaaaaa  aa aaa bab aaaaa
3 5 0 2 0 3 -1 -1
 */



/* string的自己写的类型
以下为String的一种实现参考：
class String {
public: // methods of the string ADT
String( );
~String( );
String (const String &copy); // copy constructor
String (const char copy); // conversion from C-string
String (List &copy); // conversion from List
void operator = (const String &copy);
const char c_str( ) const; // conversion to C-style string
protected:
char *entries;
int length;
};

bool operator == (const String &rst, const String &second);
bool operator > (const String &rst, const String &second);
bool operator < (const String &rst, const String &second);
bool operator >= (const String &rst, const String &second);
bool operator <= (const String &rst, const String &second);
bool operator != (const String &rst, const String &second);

void strncpy(String &to, const String &from, int n);
void strcat(String &add_to, const String &add_on);
int strstr(const String &text, const String &target);

String read_in(istream &input);
void write(String &s); */