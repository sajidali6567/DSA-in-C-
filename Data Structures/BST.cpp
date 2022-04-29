#include<bits/stdc++.h>
using namespace std;

struct BstNode {
	int val;
	BstNode *left, *right;
};

class BST {
	public:
		BstNode* NewNode(int key);
		BstNode* Insert(BstNode* root, int Key);
		BstNode* Search(BstNode* root, int Key);
		BstNode* DeleteNode(BstNode* , int Key);
		int FindMin (BstNode* root);
		int FindMax (BstNode* root);
		int Height(BstNode* root);
		void Preorder(BstNode* root);
		void Inorder(BstNode* root);
		void Postorder(BstNode* root);
		void Levelorder(BstNode* root);
		bool IsBinarySearchTree(BstNode* root);
};

BstNode* BST::NewNode(int key) {
	BstNode* temp = new BstNode();
	temp->val = key;
	temp->left = temp->right = NULL;
	return temp;
}

BstNode* BST::Insert(BstNode* root, int Key) {
	if (root == NULL) {
		return NewNode(Key);
	} else if (Key <= root->val) {
		root->left = Insert(root->left, Key);
	}
	else {
		root->right = Insert(root->right, Key);
	}
	return root;
}

BstNode* BST::Search(BstNode* root, int key) {
	if (root == NULL || root->val == key) {
		return root;
	}
	else if (key < root->val) {
		return Search(root->left, key);
	}
	else {
		return Search(root->right, key);
	}
}

int BST::FindMin (BstNode* root) {
	if (root == NULL) {
		cout << "root is empty" << endl;
		return INT_MIN;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->val;
}

// Recursive Find Max
int BST::FindMax (BstNode* root) {
	if (root == NULL) {
		return INT_MAX;
	} else if (root->right == NULL) {
		return root->val;
	}
	return FindMax(root->right);
}

// To Find the height of the tree
int BST::Height(BstNode* root) {
	if (root == NULL) return -1;
	return 1 + max(Height(root->left), Height(root->right));
}

void BST::Preorder(BstNode* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void BST::Inorder(BstNode* root) {
	if (root == NULL) return;
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

void BST::Postorder(BstNode* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << " ";
}

void BST::Levelorder(BstNode* root) {
	if (root == NULL) {
		return;
	}
	queue<BstNode*> q;
	q.push(root);
	while(!q.empty()) {
		BstNode* temp = q.front();
		cout << temp->val << " ";
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
		q.pop();
	}
}

// Need to work on this function
bool BST::IsBinarySearchTree(BstNode* root) {
	if (root == NULL) return true;
	if (root->left != NULL && root->left->val <= root->val) {
		if (root->right != NULL && root->right->val > root->val) {
			return true;
		}
	} else if (root->left == NULL && root->right == NULL) {
		return true;
	} else {
		return false;
	}
	bool isLeft = IsBinarySearchTree(root->left);
	bool isRight = IsBinarySearchTree(root->right); 
	if (isLeft && isRight) {
		return true;
	} else {
		return false;
	}
}

BstNode* BST::DeleteNode(BstNode* root, int Key) {
	if (root == NULL ) return root;
	if (Key < root->val) {
		root->left = DeleteNode(root->left, Key);
	} else if (Key > root->val) {
		root->right = DeleteNode(root->right, Key);
	} else { // we have to delete the root
		// Check if it has 0 child
		if( root->left == NULL && root->right == NULL) {
			return NULL;
		} else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			return root;
		} else if (root->right != NULL && root->left == NULL) {
			root = root->right;
			return root;
		} else { // Two Child Case
			int MaxOfRightSubtree = FindMax(root->right);
			root->val = MaxOfRightSubtree;
			root->right = DeleteNode(root->right, MaxOfRightSubtree);
			return root;
		}
	}
	return root;
}

// Driver code
int main()
{	
    BST b;
	BstNode* root = NULL;
    root = b.Insert(root, 50);
    root = b.Insert(root, 30);
	root = b.Insert(root, 60);
	root = b.Insert(root, 35);	
    root = b.Insert(root, 20);	
	root = b.Insert(root, 25);
    root = b.Insert(root, 10);
    // b.Insert(root, 70);
    // b.Insert(root, 65);
	// b.Insert(root, 55);
	//cout << b.FindMax(root) << endl;
	// cout << b.Height(root) << endl;
	// cout << "Preorder traversal of the tree is: ";
    // b.Preorder(root);
	cout << "\nInorder traversal of the tree is: ";
	b.Inorder(root);
	// cout << "\nPostorder traversal of the tree is: ";
	// b.Postorder(root);
	// cout << "\nLevelorder traversal of the tree is: ";
	// b.Levelorder(root);
	// cout << "\nInput tree is BST " << b.IsBinarySearchTree(root);
	// Deleting a node from the tree
	b.DeleteNode(root, 30);
	cout << "\nInorder traversal of the tree is: ";
	b.Inorder(root);
    return 0;
}