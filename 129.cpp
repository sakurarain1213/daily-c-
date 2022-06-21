//单链表官方实现
#include <iostream>
using namespace std;
 enum Error_code { underflow, overflow, range_Error, success };
const int max_list = 100;
typedef int List_entry;
typedef int Node_entry;
struct Node
{
    Node_entry entry;
    Node* next;
    Node();
    Node(Node_entry item, Node* add_on = NULL);
};
Node::Node()
{
    next = NULL;
}
Node::Node(Node_entry item, Node* add_on)
{
    entry = item;
    next = add_on;
}
class List
{
public:
    List();
    ~List();
    List(const List& copy);
    void operator=(const List& copy);
    int size()const;
    bool full()const;
    bool empty()const;
    void clear();
    Error_code insert(int position, const List_entry& x);
    Error_code remove(int position, List_entry& x);
    Error_code retrieve(int position, List_entry& x)const;
    Error_code replace(int position, List_entry& x);
    void traverse(void(*visit)(List_entry& x));
protected:
    int count;
    Node* head;
    Node* set_position(int position)const;//返回指定位置的节点的地址；
};
Node* List::set_position(int position)const
{
    Node* q = head;
    for (int i = 0; i < position; i++) q = q->next;
    return q;
}
List::List()
{
    count = 0;
    head = NULL;
}
List::~List()
{
   List_entry x;
    while (!empty()) 
        remove(0, x);
}
List::List(const List& copy)
{
    count = 0;
    head = NULL;
    Node* newptr = copy.head;
    while (newptr) {
        insert(size(), newptr->entry);
        newptr = newptr->next;
    }
}
void List::operator=(const List& copy) {
    List_entry x;
    if (this == &copy) return;//是否为本身
    while (!empty()) remove(0, x);
    Node* newptr = copy.head;
    while (newptr) {
        insert(size(), newptr->entry);
        newptr = newptr->next;
    }
}
int List::size()const
{
    return count;
}
bool List::full()const
{
    Node* newptr = new Node();
    if (newptr == NULL) return true;
    delete newptr;
    return false;
}
bool List::empty()const
{
    if (count == 0) return true;
    return false;
}
void List::clear()
{
    List_entry x;
    remove(0, x);
}
Error_code List::insert(int position, const List_entry& x)
{
    if (position < 0 || position > count) return range_Error;
    Node* newptr, * previous = NULL, * following;
    if (position > 0) {
        previous = set_position(position - 1);
        following = previous->next;
    }
    else following = head;
    newptr = new Node(x, following);
    if (newptr == NULL) return overflow;
    if (position == 0) head = newptr;
    else previous->next = newptr;
    count++;
    return success;
}
Error_code List::remove(int position, List_entry& x)
{
    if (position < 0 || position >= count) return range_Error;
    Node* previous, * following;
    if (position > 0) {
        previous = set_position(position - 1);
        following = previous->next;
        previous->next = following->next;
    }
    else {
        following = head;
        head = head->next;
    }
    x = following->entry;
    delete following;
    count--;
    return success;
}
Error_code List::retrieve(int position, List_entry& x)const
{
    if (position < 0 || position >= count) return range_Error;
    Node* newptr = set_position(position);
    x = newptr->entry;
    return success;
}
Error_code List::replace(int position, List_entry& x)
{
    if (position < 0 || position >= count) return range_Error;
    Node* newptr = set_position(position);
    newptr->entry = x;
    return success;
}
void List::traverse(void(*visit)(List_entry& x))
{
    Node* newptr = head;
    while (newptr) {
        (*visit)(newptr->entry);
        newptr = newptr->next;
    }
}
int main()
{
    int a, c;
    cin >> a;
    List b;
    while (a != -1) {
        b.insert(b.size(), a);
        cin >> a;
    }
    cin >> a >> c;
    while (a != -1 || c != -1) {
        b.insert(a, c);
        cin >> a >> c;
    }
    cin >> a;
    while (a != -1) {
        b.remove(a, c);
        cin >> a;
    }
    cin >> a >> c;
    while (a != -1 || c != -1) {
        b.replace(a, c);
        cin >> a >> c;
    }


    while (b.size() > 0) {
        b.remove(0, a);
        cout << a << ' ';
    }

    return 0;
}

/* 
3 7 8 4 6 -1
1 2 -1 -1
3 -1
4 9 -1 -1
 //3 2 7 8 4 6
  //3 2 7 4 6
 //3 2 7 4 9 */