package main
import "fmt"
import "math"

// utility function to swap two elements
func swap (a, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func Parent(index int) int {
	return int(math.Ceil(float64(index/2.0)) - 1)
}

func  LeftChild(index int) int {
	return 2*index+1
}

func RightChild(index int) int {
	return 2*index+2
}

func PrintSortedArray(arr []int) {
	for _, val := range(arr) {
		fmt.Printf("%d ", val)
	}
}

func MaxHeapify(arr []int, i int, size int) {
	if (i<0) {
		return
	}
	max := i
	leftChildIndex := LeftChild(i)
	if leftChildIndex < size && arr[leftChildIndex] > arr[i] {
		max = leftChildIndex
	}
	rightChildIndex := RightChild(i);
	if rightChildIndex < size && arr[rightChildIndex] > arr[i] {
		max = rightChildIndex
	}
	if i != max {
		swap(&arr[i], &arr[max])
		MaxHeapify(arr, Parent(i))
	}
}

func ExtractMax(arr []) int {
	max := arr[0]
	swap(&arr[0], &arr[size-1])
	MaxHeapify(arr, 0, size-1)
}

func HeapSort(arr []int) {
	//fmt.Println(
	for i := (len(arr)/2) - 1; i>=0; i-- {
		MaxHeapify(arr, i, len(arr)
	}	
	for i 
}

func main() {
	arr := []int{10,8,9,7,6}
	HeapSort(arr)
	PrintSortedArray(arr)
}