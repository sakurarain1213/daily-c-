#include <bits/stdc++.h>
using namespace std ;

struct st
{
	int a1;
	int b1;
}arr[100];
bool  cmp(const st &x, const st &y)
{
	return x.b1<y.b1;//从小到大排<，若要从大到小排则>
}
int main()
{
	int i;
	for (i=0;i<3;i++)
	  cin>>arr[i].a1>>arr[i].b1;//对结构体进行输入 
	  sort(arr,arr+3,cmp);
	for (i=0;i<3;i++)
	  cout<<arr[i].a1<<" "<<arr[i].b1<<endl;
      return 0;
}