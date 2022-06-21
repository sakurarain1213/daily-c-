#include <bits/stdc++.h>
using namespace std;
//avl树
template<class T>
struct AVLNode{
    T data;
    AVLNode<T>*left, *right;
    int bf;
    AVLNode() :left(NULL), right(NULL), bf(0) {}
    AVLNode(T d, AVLNode<T>*l=NULL,AVLNode<T>*r=NULL):data(d),left(l),right(r),bf(0){}
};
template<class T>
class AVLTree {
public:
    AVLTree():root(NULL){}
    ~AVLTree() {};
    AVLTree(T Ref):Refvalue(Ref),root(NULL){}
    bool insert(AVLNode<T>*&ptr, T&e1);
    bool Remove(AVLNode<T>*&ptr, T x);
    void RotateL(AVLNode<T>*&ptr);
    void RotateR(AVLNode<T>*&ptr);
    void PrintBinTree(AVLNode<T>*&t, int level);
    void RotateLR(AVLNode<T>*&ptr);
    void RotateRL(AVLNode<T>*&ptr);
    AVLNode<T>* search(const T x, AVLNode<T>*ptr);
/*     friend istream& operator>>(istream&, AVLTree<T>& Tree);
    friend ostream& operator<<(ostream&, AVLTree<T>&Tree); */
    void Delete(AVLNode<T>*ptr);
    void output(AVLNode<T>*ptr, ostream&out);
    AVLNode<T>*root;
    T Refvalue;
private:
};
template<class T>
void AVLTree<T>::RotateL(AVLNode<T>*&ptr) {
    AVLNode<T>*subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    ptr->bf = subL->bf = 0;
}
template<class T>
void AVLTree<T>::RotateR(AVLNode<T>*&ptr) {
    AVLNode<T>*subR = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    ptr->bf = subR->bf = 0;
}
template<class T>
void AVLTree<T>::RotateLR(AVLNode<T>*&ptr) {
    AVLNode<T>*subR = ptr, *subL = subR->left;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf <= 0)subL->bf = 0;
    else subL->bf = -1;
    subR->left = ptr->right;
    ptr->right = subR;
    if (ptr->bf == -1)subR->bf = 1;
    else subR->bf = 0;
    ptr->bf = 0;
}
template<class T>
void AVLTree<T>::RotateRL(AVLNode<T>*&ptr) {
    AVLNode<T>*subL = ptr, *subR = subL->right;
    ptr = subR->left;
    subR->left = ptr->right;
    ptr->right = subR;
    if (ptr->bf >= 0)subR->bf = 0;
    else subR->bf = 1;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf == 1)subL->bf = -1;
    else subL->bf = 0;
    ptr->bf = 0;
}
template<class T>
bool AVLTree<T>::insert(AVLNode<T>*&ptr, T&e1) {
    AVLNode<T>*pr = NULL, *p = ptr, *q; int d;
    stack<AVLNode<T>*>st;
    while (p!=NULL)
    {
        if (e1 == p->data) {
            cout << "存在，无法插入\n"; return false;
        }
        pr = p; st.push(pr);
        if (e1 < p->data) p = p->left;
        else p = p->right;
    }
    p = new AVLNode<T>(e1);
    if (p == NULL) { cout << "内存不足" << endl; exit(1); }
    if (pr == NULL) { ptr = p; return true; }//空树，根结点插入
    if (e1 < pr->data)pr->left = p;
    else pr->right = p;
    while (st.empty()==false)
    {
        pr = st.top();
        st.pop();
        if (p == pr->left)pr->bf--;
        else pr->bf++;
        if (pr->bf == 0)break;//case 1,平衡退出
        if (abs(pr->bf) == 1) {//case 2
            p = pr;//回溯
        }
        else {//case 3 |bf|==2
            d = (pr->bf < 0) ? -1 : 1;
            if (p->bf == d) {
                if (d == -1)RotateR(pr);
                else RotateL(pr);
            }
            else {
                if (d == -1)RotateLR(pr);
                else RotateRL(pr);
            }
            break;
        }
    }
    if (st.empty() == true)ptr = pr;
    else {
        q = st.top();
        if (q->data > pr->data)q->left = pr;
        else q->right = pr;
    }
    return true;
}
//template<class T>
istream& operator >>(istream& in, AVLTree<int>& Tree) {
    int item;
    in >> item;
    while (item!=Tree.Refvalue)
    {
        
        Tree.insert(Tree.root,item);
        in >> item;
    
    }
    return in;
}
//template<class T>
ostream& operator<<(  ostream&out, AVLTree<int>&Tree) {
    out << "中序遍历输出各个结点数值:" << endl;
    Tree.output(Tree.root,out);
    out << endl;
    return out;
    
}
template<class T>
void AVLTree<T>::output(AVLNode<T>*ptr, ostream&out) {
    if (ptr != NULL) {
        output(ptr->left, out);
        cout << ptr->data << " ";
        output(ptr->right, out);
    }
}
template<class T>//search要自行改变一下
AVLNode<T>* AVLTree<T>::search(const T x, AVLNode<T>*ptr) {
    if (ptr == NULL)return NULL;
    else if (x < ptr->data){cout<< ptr->data<<" ";return search(x, ptr->left);}
    else if (x > ptr->data){cout<< ptr->data<<" ";return search(x, ptr->right);}
    else {cout<< ptr->data<<" ";return ptr;}
}
template<class T>
void AVLTree<T>::Delete(AVLNode<T>*ptr) {
    if (ptr != NULL){
        Delete(ptr->left);
        Delete(ptr->right);
        delete ptr;
    }
}
template <class T>
void AVLTree<T>::PrintBinTree(AVLNode<T>*&t, int level)
{
    if (t == NULL)return;
    PrintBinTree(t->right, level + 1);
   // for (int i = 0; i < 4 * (level - 1); i++)cout << " ";  调试
    cout << t->data << endl;
    PrintBinTree(t->left, level + 1);
}
template<class T>
bool  AVLTree<T>::Remove(AVLNode<T>*&t, T val)
{
    assert(t != nullptr);
    AVLNode<T> *tmp = t;
    AVLNode<T> *pre_tmp = nullptr;
    AVLNode<T> *ppre_tmp = nullptr;
    AVLNode<T> *it_tmp = nullptr;
    stack<AVLNode<T>*> st;
    int sign, lable;    //符号标记
    int flag = 0;       //子树标记，下文具体解释
    while (tmp != nullptr) {
        if (tmp->data == val)       //找到跳出循环
            break;
        pre_tmp = tmp;
        st.push(pre_tmp);
        if (tmp->data > val)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    if (tmp == nullptr)               //未找到，返回
        return false;
    else if (tmp->left!= nullptr && tmp->right != nullptr) {
        pre_tmp = tmp;               //将有两个孩子的节点转化为只有一个孩子的节点，方法是寻找它中序遍历的直接前驱或后继
        st.push(pre_tmp);
        it_tmp = tmp->left;
        while (it_tmp->right!= nullptr) {
            pre_tmp = it_tmp;
            st.push(pre_tmp);
            it_tmp = it_tmp->right;
        }
        tmp->data = it_tmp->data;      //覆盖要删除的节点
        tmp = it_tmp;                      //tmp指向要删除的节点，函数结束前会delete tmp
    }
    if (tmp->left!= nullptr) {        //这样的判断方式会导致删除一个节点下两个没有孩子节点的节点时，由于左孩子均为空，直接跳入else
        it_tmp = tmp->left;
    }
    else {
        it_tmp = tmp->right;
    }
    if (pre_tmp == nullptr)
        t = it_tmp;
    else {
        if (pre_tmp->left== tmp) {   //上面直接跳入else，但我们在此处加上flag，用来识别它到底是pre_tmp的左孩子还是右孩子。
            flag = 0;
            pre_tmp->left= it_tmp;
        }
        else {
            flag = 1;
            pre_tmp->right = it_tmp;
        }
        while (!st.empty()) {
            pre_tmp = st.top();
            st.pop();
            if (pre_tmp->left == it_tmp && flag == 0)//此处flag=0，防止pre_tmp的左孩子为空，右孩子同样为空，直接进入else
                pre_tmp->bf++;
            else
                pre_tmp->bf--;
            if (!st.empty())
            {
                ppre_tmp = st.top();
                if (ppre_tmp->left == pre_tmp)
                {
                    sign = -1;      //sign用来识别是祖父节点的左孩子还是右孩子，下文链接会用上
                    flag = 0;
                }
                else {
                    sign = 1;
                    flag = 1;
                }
            }
            else
                sign = 0;    //栈空，它的祖先节点不存在，pre_tmp即为根节点，但是这里也要写上，否则sign的值会遗留下来
            if (pre_tmp->bf == -1 || pre_tmp->bf == 1)
                break;           //已经平衡，直接跳出
            if (pre_tmp->bf != 0) {      //m_bf为+2/-2
                if (pre_tmp->bf < 0) {
                    lable = -1;          //lable表示父节点符号，下面会用来区分同号异号
                    it_tmp = pre_tmp->left;
                }
                else {
                    lable = 1;
                    it_tmp = pre_tmp->right;
                }
                if (it_tmp->bf == 0) {       //pre_tmp的较高子树的头节点m_bf为0
                    if (lable == -1) {
                        RotateR(pre_tmp);
                        pre_tmp->bf = 1;
                        pre_tmp->right->bf = -1;
                    }
                    else {
                        RotateL(pre_tmp);
                        pre_tmp->bf = -1;
                        pre_tmp->left->bf = 1;
                    }
                    break;           //直接跳出，并没有链接，需要下文写上链接
                }
                if (it_tmp->bf == lable) {       //同号 
                    lable == 1 ? RotateL(pre_tmp) : RotateLR(pre_tmp);
                }
                else {                            //异号
                    lable == -1 ? RotateLR(pre_tmp): RotateRL(pre_tmp);
                }
                //sign == -1 ? ppre_tmp->left_child = pre_tmp                //不能写成这样，因为sign值可能为0，会直接进入后者
                //                      : ppre_tmp->right_child = pre_tmp;   //!!!!! sign maybe 0 ! not only1 or -1 !!! warning!
                if (sign == -1)
                    ppre_tmp->left = pre_tmp;
                else if (sign == 1)            //else if正确方式
                    ppre_tmp->right = pre_tmp;
            }
            it_tmp = pre_tmp;       //回溯
        }
        if (st.empty())              //栈为空，根节点
            t = pre_tmp;
        else {             //这一段else参考书上没有，书是错的，如果不写此处，290break直接跳出while循环，会导致链接不上，数据丢失
            ppre_tmp = st.top();
            if (ppre_tmp->data > pre_tmp->data)
                ppre_tmp->left = pre_tmp;
            else
                ppre_tmp->right = pre_tmp;
        }
    }
    delete tmp;
    tmp = nullptr;
    return true;
}


int main()
{
  AVLTree<string> tree;
  map<string,string> m;
int n1,n2;string s,t;
cin>>n1;
while(n1--)
{ 
    cin>>s>>t;m[s]=t;
  tree.insert(tree.root, s);
}
 //tree.PrintBinTree(tree.root, 1);


cin>>n2;
while(n2--)
{ 
    cin>>s;
tree.Remove(tree.root, s);
}

// tree.PrintBinTree(tree.root, 1);

   cin>>s;
if(tree.search(s, tree.root)!=NULL) cout<<m[s]<<endl;
else cout<<"NULL"<<endl;

   cin>>s;
if(tree.search(s, tree.root)!=NULL) cout<<m[s]<<endl;
else cout<<"NULL"<<endl;

 return 0;
}





/* 6 computer 电脑 eye 眼睛 hello 你好 train 火车 wait 等待 zebra 斑马
1 eye
eye
hello

6 computer 电脑 eye 眼睛 hello 你好 train 火车 wait 等待 zebra 斑马
3 eye computer train
eye
hello


   AVLTree<int> tree;
    cout << "建立AVL树，终止表示设为0" << endl;
    tree.Refvalue = 0;
    cout << "1:建树\n2:插入\n3:搜索\n4:删除\n5:输出\n6:清空\n7:退出\n";
    bool over = false;
    while (!over)
    {
        int c;
        int num;
        
        cin >> c;
        switch (c)
        {
    case 1: {
        cin >> tree;
        cout << "建树完毕\n";
        break;
             }
    case 2: {
        cin >> num; tree.insert(tree.root, num); cout << "插入完毕\n"; break; }
    case 3: {cin >> num; if (tree.search(num, tree.root) != NULL)cout << num << "已经被找到\n"; else cout << num << "不存在\n"; break; }
    case 4: {cin >> num; tree.Remove(tree.root, num); }
    case 5: {cout << tree; cout << " 凹凸打印AVL树\n"; tree.PrintBinTree(tree.root, 1); break; }
    case 6: {
        //tree.Delete(tree.root); 
        tree.root=NULL;
        break; }
    case 7:{  over = true; break; }
        default:cout << "输入有误\n";
            break;
        }
    }

 */