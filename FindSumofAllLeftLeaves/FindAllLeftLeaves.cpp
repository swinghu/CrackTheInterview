///
///Find sum of all left leaves in a given Binary Tree
///

///思考，怎么样在面试的时候，最快的速度构造一个二叉树？

#include<iostream>
using namespace std;
struct Node
{
	int key;
	struct Node* left, *right;
};


Node *newNode(char k)
{
	Node * node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}


bool isLeaf(Node *node)
{
	if (node == NULL)
		return false;
	if (node->left == NULL && node->right == NULL)
		return true;
	return false;
}

int leftLeavesSum(Node *root)
{
	int res = 0;

	if (root != NULL)
	{
			if (isLeaf(root->left))
				res += root->left->key;
			else // 递归遍历左子树
				res += leftLeavesSum(root->left);
			// 递归调用，遍历右子树
			res += leftLeavesSum(root->right);
	}

	return res;
}


int main()
{
	struct Node *root = newNode(20);
	root->left = newNode(9);
	root->right = newNode(49);
	root->right->left = newNode(23);
	root->right->right = newNode(52);
	root->right->right->left = newNode(50);
	root->left->left = newNode(5);
	root->left->right = newNode(12);
	root->left->right->right = newNode(12);
	cout << "Sum of left leaves is "
		<< leftLeavesSum(root);
	return 0;
}


