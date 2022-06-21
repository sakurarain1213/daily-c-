#include <bits/stdc++.h>
using namespace std ;
//字符串类的官方实现

class String
{
 private:
 char* str;
 int len;
 public:  
 String();
String(const char*);
 String(const String &);
 String operator=(const String &);
String operator=(const char *);
 String operator+(const String & );
 String operator+=(const String &);
 //operator const char*() { return c_str(); }
 ~String();
 int length() const;
 const char* c_str() const { return (const char*) str; };
 };

 String::String() {
 str = new char [1];
 len = 0;
 str[0] = '\0';
 }

 String::String(const char* s) {
 len = strlen(s);
 str = new char [len + 1];
 strcpy(str, s);
 }

 String::String(const String & s) {
 len = s.length();
 str = new char [len + 1];
 strcpy(str, s.str);
 }

 String String::operator=(const String & s) {
 if (this == &s) return *this;
 delete [] str;
 len = strlen(s.str);
 str = new char [len + 1];
 strcpy(str, s.str);
 return *this;
}

 String String::operator=(const char * s) {
 if (this->str == s) return *this;
 delete [] str;
 len = strlen(s);
 str = new char [len + 1];
 strcpy(str, s);
 return *this;
 }

 String::~String() {
delete [] str;
 len = 0;
 }


 String String::operator+(const String & s) {
 char *temp = new char [len + s.len + 1];
strcpy(temp, str);
 strcat(temp, s.str);
 String t = temp;
 delete [] temp;
 return t;
 }

 String String::operator+=(const String & s) {
 String t = *this;
 *this = t + s;
 return *this;
}

 int String::length() const {
 return len;
 }

 bool operator==(const String & s1, const String & s2) {
 return strcmp(s1.c_str(), s2.c_str()) == 0;
 }

bool operator>(const String & s1, const String & s2) {
 return strcmp(s1.c_str(), s2.c_str()) > 0;
 }

bool operator<(const String & s1, const String & s2) {
  return strcmp(s1.c_str(), s2.c_str()) < 0;
 }

 bool operator>=(const String & s1, const String & s2) {
 return strcmp(s1.c_str(), s2.c_str()) >= 0;
 }

 bool operator<=(const String & s1, const String & s2) {
 return strcmp(s1.c_str(), s2.c_str()) <= 0;
 }

 bool operator!=(const String & s1, const String & s2) {
 return strcmp(s1.c_str(), s2.c_str()) != 0;
 }

String strncpy(String & s1, const String & s2, int n) {
 char *t = new char [n + 1];
 strncpy(t, s2.c_str(), n);
 s1 = t;
delete [] t;
 return s1;
 }

 String strcat(String & s1, const String & s2) {
 char *t = new char [s1.length() + s2.length() + 1];
strcpy(t, s1.c_str());
 strcat(t, s2.c_str());
 s1 = t;
 delete [] t;
 return s1;
 }

int strstr(const String &text, const String &target) {
 const char* p = strstr(text.c_str(), target.c_str());
 if (!p) return -1;
 return p - text.c_str();
 }

 ostream & operator<<(ostream & os, const String & s) {
 cout << s.c_str();
 return os;
}

istream & operator>>(istream & is, String & s) {
 const int maxn = 200;
 char *p = new char [maxn];
 cin >> p;
 s = p;
 delete [] p;
 return is;
 }

String getline(String & s) {
 const int maxn = 200;
 char *p = new char [maxn];
cin.getline(p, maxn);
 s = p;
 delete [] p;
 return s;
 }


 const int MAXN = 1000 + 5;
 String Res[MAXN];
 int n;



int main() {
 cin >> n;
 for (int i = 0; i < n; i++)
 cin >> Res[i];
int a, b;
while (cin >> a >> b && !(a == -1 && b == -1)) {
 cout << strstr(Res[b], Res[a]) << ' ';
 }
 cout << endl;
 sort(Res, Res + n);
 for (int i = 0; i < n; i++)
 cout << Res[i] << ' ';
 return 0;
}