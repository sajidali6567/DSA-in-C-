package main
import "fmt"

type ListNode struct {
	val int
	next *ListNode
}

func newNode(key int) *ListNode {
	var temp ListNode
	temp = ListNode{key, nil}
	return &temp
}

func pushFront(head *ListNode, key int) *ListNode {
	if head == nil {
		return newNode(key)
	}
	temp := newNode(key)
	temp.next = head
	head = temp
	return head
}

func popFront (head *ListNode) *ListNode {
	if head.next == nil {
		return nil
	}
	head = head.next
	return head
}

func printList (head *ListNode) {
	for head != nil {
		fmt.Printf("%d ", head.val)
		head = head.next
	}
	fmt.Printf("\n")
}

/*func addBefore (nodePtr **ListNode, key int) {
	if nodePtr

}*/

func addAfter (nodePtr **ListNode, key int) {
	if *nodePtr == nil {
		return
	}
	temp := newNode(key)
	temp.next = (*nodePtr).next
	(*nodePtr).next = temp;
}

func main () {
	var head *ListNode
	head = pushFront(head, 5)
	head = pushFront(head, 6)
	head = pushFront(head, 7)
	printList(head)
	addAfter(&head, 4)
	//head = popFront(head, tail)
	printList(head)
	
}