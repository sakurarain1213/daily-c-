#include <bits/stdc++.h>

using namespace std;

char to(char c)
{
    if(c<='Z')
    {
        if(c+13>'Z')return c+13-'Z'+65-1;
        return c+13;
    }
    else
    {
        if(c+13>'z')return c+13-'z'+97-1;
         return c+13;
    }
}

void f(int x)
{
  string s;
getline(cin,s);//scanf本身很强大  
 int n=s.length();
  for (int i=0;i<n;i++)
  {

     if(s[i]==' ') i++;
       s[i]=to(s[i]);
  } 
  
   printf("case #%d:\n",x);
  printf("%s\n",s);

}

int main()
{
  int x;
  cin>>x;

   for (int i=0;i<x;i++)
   {
       f(i);
   }
    return 0;

}

