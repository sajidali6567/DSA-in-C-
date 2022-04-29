package main
import "fmt"

// structure of type BstNode
type BstNode struct {
	val int
	left *BstNode
	right *BstNode
}

// We can remove this function
func NewNode(key int) *BstNode {
	return BstNode{key, nil, nil}
}

// This function insert a new node in Binary Search Tree
func insert(root *BstNode, key int) *BstNode {
	if root == nil {
		return NewNode(key)
	} else if root.val < key {
		root.right = insert(root.right, key)
	} else {
		root.left = insert(root.left, key)
	}
	return root
}

// PreOrder traversal of a Binary Search Tree
func (root *BstNode) preorder() {
	if root == nil {
		return
	}
	fmt.Printf("%d ", root.val)
	root.left.inorder()
	root.right.inorder()
}

// InOrder traversal of a Binary Search Tree
func (root *BstNode) inorder() {
	if root == nil {
		return
	}
	root.left.inorder()
	fmt.Printf("%d ", root.val)
	root.right.inorder()
}

// Postorder traversal of a Binary Search Tree
func (root *BstNode) postorder() {
	if root == nil {
		return
	}
	root.left.inorder()
	root.right.inorder()
	fmt.Printf("%d ", root.val)
}

func (root *BstNode) Height() {
	if root == nil {
		return -1
	}
	return 1+max(root.left.Height(), root.right.Height())
}

// driver code
func main() {
	var root *BstNode
	root = insert(root, 50)
	root = insert(root, 40)
	root = insert(root, 60)
	root = insert(root, 30)
	root = insert(root, 45)
	root.inorder();
}

