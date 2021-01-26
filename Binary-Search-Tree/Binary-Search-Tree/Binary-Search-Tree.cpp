#include <iostream>
#include<assert.h>
using namespace std;
template<class t>
class binarySearchTree
{
	struct node
	{
		t     info;
		node* left;
		node* right;
	};
	node* root;
public:
	bool isEmpty();
	bool search(t item);
	bool searchRec(t item);
	void insert(t item);
	void remove(t item);
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();
	void clearTree();
	binarySearchTree();
	~binarySearchTree();
private:
	void clear(node*& p);
	void inorder(node* p);
	void preorder(node* p);
	void postorder(node* p);
	int height(node* p);
	int max(t x, t y);
	int nodeCount(node* p);
	int leavesCount(node* p);
	void deleteFromTree(node*& p);
	bool searchRecPriv(node*,t item);
};
template<class t>
binarySearchTree<t>::binarySearchTree():root(NULL)
{
}
template<class t>
bool binarySearchTree<t>::isEmpty()
{
	return (root == NULL);
}
template<class t>
void binarySearchTree<t>::inorderTraversal()
{
	inorder(root);
}
template<class t>
void binarySearchTree<t>::preorderTraversal()
{
	preorder(root);
}
template<class t>
void binarySearchTree<t>::postorderTraversal()
{
	postorder(root);
}
template<class t>
int binarySearchTree<t>::treeHeight()
{
	return height(root);
}
template<class t>
int binarySearchTree<t>::treeNodeCount()
{
	return nodeCount(root);
}
template<class t>
int binarySearchTree<t>::treeLeavesCount()
{
	return leavesCount(root);
}

template<class t>
void binarySearchTree<t>::preorder(node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->left);
		preorder(p->right);
	}
}
template<class t>
void binarySearchTree<t>::postorder(node *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->info << " ";
	}
}
template<class t>
void  binarySearchTree<t>::clear(node* &p)
{
	if (p != NULL)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = NULL;
	}
}
template<class t>
void binarySearchTree<t>::inorder(node *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		cout << p->info << " ";
		inorder(p->right);
	}
}
template<class t>
void  binarySearchTree<t>::clearTree()
{
	clear(root);
}
template<class t>
binarySearchTree<t>::~binarySearchTree()
{
	clear(root);
}
template<class t>
int binarySearchTree<t>::height(node *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->left), height(p->right));
}
template<class t>
int binarySearchTree<t>::max(t x, t y)
{
	if (x >= y)
		return x;
	else
		return y;
}

template<class t>
int binarySearchTree<t>::nodeCount(node *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->left) + nodeCount(p->right);
}

template<class t>
int binarySearchTree<t>::leavesCount(node *p)
{
	if (p == NULL)
		return 0;
	else if ((p->left == NULL) && (p->right == NULL))
		return 1;
	else
		return leavesCount(p->left) + leavesCount(p->right);
}
template<class t>
bool binarySearchTree<t>::search(t item)
{
	node* current = root;
	while (current != NULL)
	{
		if (current->info == item)
			return true;
		else if (current->info > item)
			current = current->left;
		else
			current = current->right;
	}
	return false;
}
template<class t>
bool binarySearchTree<t>::searchRec(t item)
{
	return searchRecPriv(root, item);
}
template<class t>
bool binarySearchTree<t>::searchRecPriv(node* p, t item)
{
	if (p == NULL)
		return false;
	else if (p->info == item)
		return true;
	else if (p->info > item)
		return searchRecPriv(p->left, item);
	else
		return searchRecPriv(p->right, item);
}
template<class t>
void binarySearchTree<t>::insert(t item)
{
	node* current;  
	node* trailCurrent= NULL; 
	node* newNode;  
	newNode = new node;
	assert(newNode != NULL);
	newNode->info = item;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
		root = newNode;
	else
	{
		current = root;
		while (current != NULL)
		{
			trailCurrent = current;

			if (current->info == item)
			{
				cout << "The insert item is already in the list -- ";
				cout << "duplicates are not allowed." << endl;
				return;
			}
			else
				if (current->info > item)
					current = current->left;
				else
					current = current->right;
		}
		if (trailCurrent->info > item)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}
template<class t>
void binarySearchTree<t>::remove(t item)
{
	node* current;  
	node* trailCurrent; 
	if (root == NULL)
	{
		cout << "Cannot delete from the empty tree." << endl;
		return;
	}
	if (root->info == item)
	{
		deleteFromTree(root);
		return;
	}
	trailCurrent = root;
	if (root->info > item)
		current = root->left;
	else
		current = root->right;
	while (current != NULL)
	{
		if (current->info == item)
			break;
		else
		{
			trailCurrent = current;
			if (current->info > item)
				current = current->left;
			else
				current = current->right;
		}
	}
	if (current == NULL)
		cout << "The delete item is not in the tree." << endl;
	else if (trailCurrent->info > item)
		deleteFromTree(trailCurrent->left);
	else
		deleteFromTree(trailCurrent->right);
}

template<class t>
void binarySearchTree<t>::deleteFromTree (node* & p)
{
	node* current;    							
	node* trailCurrent;   
	node* temp;        
	if (p->left == NULL && p->right == NULL)
	{
		delete p;
		p = NULL;
	}
	else if (p->left == NULL)
	{
		temp = p;
		p = p->right;
		delete temp;
	}
	else if (p->right == NULL)
	{
		temp = p;
		p = p->left;
		delete temp;
	}
	else
	{
		current = p->left;
		trailCurrent = NULL;
		while (current->right != NULL)
		{
			trailCurrent = current;
			current = current->right;
		}
		p->info = current->info;
		if (trailCurrent == NULL) 	
			p->left = current->left;
		else
			trailCurrent->right = current->left;
		delete current;
	}
}

int main()
{
	binarySearchTree<int>b;
	b.insert(10);
	b.insert(20);
	b.insert(5);
	b.remove(10);
	b.inorderTraversal();
	b.postorderTraversal();
	b.preorderTraversal();
	return 0;
}