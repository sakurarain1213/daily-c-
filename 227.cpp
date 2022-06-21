
#include <bits/stdc++.h>
using namespace std;

template<class T>
class BSTree;

template<class T>
class BSTNode
{
	friend class BSTree<T>;
public:
	BSTNode() :data(T()), left(nullptr), right(nullptr)
	{}
	BSTNode(T d, BSTNode<T> *left = nullptr, BSTNode<T> *right = nullptr)
		:data(d), left(left), right(right)
	{}
	~BSTNode()
	{}
private:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
};

template<class T>
class BSTree
{
public:
	BSTree() : root(nullptr)
	{}
	BSTree(vector<T> &v) : root(nullptr)
	{
		for (const auto &e : v)
			Insert(e);
	}
    
public:
	T& Min()const
	{
		return Min(root);
	}
	T& Max()const
	{
		return Max(root);
	}
	BSTNode<T>* Search(const T &key)const
	{
		return Search(root, key);
	}
 /*    BSTNode<T>* lowestCommonAncestor(BSTNode<T> * root, BSTNode<T>  p, BSTNode<T>  q)
	{return lowestCommonAncestor(root,p,q);} */

	bool Insert(const T &x)
	{
		return Insert(root, x);
	}
	bool Remove(const T &x)
	{
		return Remove(root, x);
	}
	void Sort()const
	{
		Sort(root);
	}
protected:
	T& Max(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->right != nullptr)
			t = t->right;
		return t->data;
	}
	T& Min(BSTNode<T> *t)const
	{
		assert(t != nullptr);
		while (t->left != nullptr)
			t = t->left;
		return t->data;
	}


	BSTNode<T>* Search(BSTNode<T> *t, const T &key)const
	{
		if (t == nullptr || t->data == key)
			return t;
		if (key < t->data)
			return Search(t->left, key);
		else
			return Search(t->right, key);
	}

	bool Insert(BSTNode<T> *&t, const T &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<T>(x);
			return true;
		}
		if (x < t->data)
			return Insert(t->left, x);
		else if (x > t->data)
			return Insert(t->right, x);
		return false;
	}

	bool Remove(BSTNode<T> *&t, const T &x)
	{
		if (t == nullptr)
			return false;
		if (x < t->data)
			Remove(t->left, x);
		else if (x > t->data)
			Remove(t->right, x);
		else
		{
			BSTNode<T> *q;
			if (t->left == nullptr && t->right == nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if (t->left != nullptr && t->right == nullptr)
			{
				q = t;
				t = t->left;
				delete q;
			}
			else if (t->right != nullptr && t->left == nullptr)
			{
				q = t;
				t = t->right;
				delete q;
			}
			else
			{
				q = t->left;
				while (q->right != nullptr)
					q = q->right;
				t->data = q->data;
				Remove(t->left, q->data);
			}
			return true;
		}
	}

	void Sort(BSTNode<T> *t)const
	{
		if (t != nullptr)
		{
			Sort(t->left);
			cout << t->data << ' ';
			Sort(t->right);
		}
	}

/*     bool getLCA(BSTNode<T>* root, BSTNode<T>* p,BSTNode<T>* q,BSTNode<T>** res){
    if (root == NULL){
        return false;}
    bool l = getLCA(root->left, p, q, res);
    bool r = getLCA(root->right, p, q, res);
    if ((l && r) || 
        ((root == p || root == q) && (l||r))) {
        *res = root;
        return true;
    }
    return root == p || root == q || l || r;
    }

    BSTNode<T>* lowestCommonAncestor(BSTNode<T>* root,
                              BSTNode<T>* p,
                               BSTNode<T>* q)
	 {
    BSTNode<T>* r= NULL;
    getLCA(root, p,q,&r);
    return r;
    } */


//最矮的公共祖先
/* 定义一个函数getLCA()， getLowestCommonAncestor的缩写，
用于返回当前节点root的左子树(root->left)或者右子树(root->right)是否包含了题目中给定的两个节点，
如果getLCA(root->left)和getLCA(root->right)返回的都是true，
那么root就是所要找的最低公共祖先节点。
如果root本身就是给定的其中一个节点，
只要getLCA(root->left)和getLCA(root->right)中的一个返回的是true，
那么root就是所要找的最低公共祖先节点。 */
private:
	BSTNode<T> *root;
};



template<class T>
    BSTNode<T>* lowestCommonAncestor(BSTNode<T> * root, BSTNode<T>  p, BSTNode<T>  q) {
    if (root == NULL || root == p || root == q ) {
        return root;
    } 
   BSTNode<T> * leftCommonAncestor =  lowestCommonAncestor(root.left, p, q); 
   BSTNode<T> *rightCommonAncestor =  lowestCommonAncestor(root.right, p, q); 
    //在左子树中没有找到，那一定在右子树中
    if(leftCommonAncestor == NULL){
        return rightCommonAncestor;
    }
    //在右子树中没有找到，那一定在左子树中
    if(rightCommonAncestor == NULL){
        return leftCommonAncestor;
    }
    //不在左子树，也不在右子树，那说明是根节点
    return root;
    }




int main()
{
	int n,t;cin>>n;vector<int> iv;
	while(n--)
	{
		cin>>t;iv.push_back(t);
	}
	BSTree<int> bst(iv);
int p,q;
cin>>p>>q;
BSTNode<int> *ptr;
//lowestCommonAncestor(bst,bst.Search(p),bst.Search(q));

	return 0;
}
