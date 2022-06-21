#include <bits/stdc++.h>
using namespace std;
//链式存储 实现归并排序
/* struct node {
  int data;
  node* next;

  node(int data = 0, node* next = NULL) 
  :data(data), next(next) {}
};
node* merge(node*& head, node*& mid) {
  node tmp;
  node *p = &tmp, *q = head, *t = mid;
  while(q && t) {
    if(q->data <= t->data) {
      p->next = q;
      p = p->next;
      q = q->next;
    }
    else {
      p->next = t;
      p = p->next;
      t = t->next;
    }
  }
  if(q) 
    p->next = q;
  else
    p->next = t;
  return tmp.next;
}

void mergesort(node*& head) {
  if(head->next) {
    node* mid = cut(head);
    mergesort(head);
    mergesort(mid);
    head = merge(head, mid);
  }
}
node* cut(node*& head) {
  node* p = head;
  node* q = head;
  node* second_head;
  while(q && q->next) {
    q = q->next;
    if(q->next) {
      p = p->next;
      q = q->next;
    }
  }
  second_head = p->next;
  p->next = NULL;
  return second_head;
}
 */

int main()
{
    int n;
    cin>>n;
    int a[1001] ; memset(a,0,sizeof(a));
    for( int i=0;i<n;i++)
    {cin>>a[i];}
     sort(a,a+(n+1)/2);sort(a+(n+1)/2,a+n);

    for( int i=0;i<(n+1)/2;i++)
    {cout<<a[i]<<" ";}
    cout<<endl;
        for( int i=(n+1)/2;i<n;i++)
    {cout<<a[i]<<" ";}
    cout<<endl;
    sort(a,a+n);
       for( int i=0;i<n;i++)
    {cout<<a[i]<<" ";}

    return 0;
}
/* 
5
9 3 8 2 5 

10
1 2 7 8 9 3 4 5 6 7



*/