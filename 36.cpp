#include <bits/stdc++.h>
using namespace std ;

/*  class queue
{
private:
int a[1000];
int count;
int rear;
int max;
int 
public:
queue();
bool empty();
int front(int n);
int back(int n);
void push(int n);
int  pop();
}; */
 
/*  queue::append(const queue &item)

{
   if (rear >= max-1) return overflow;
   count++;
   rear++; 
   a[rear] = item; 
   return success;
}

 */
 



int  main ()
{
queue <int >a;
a.push(1);a.push(2);a.push(3);
int b=a.back();
swap(a.front(),a.back());
cout<<a.back();



return 0;
}