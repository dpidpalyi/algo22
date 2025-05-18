package dllist22

import (
	"fmt"
	"strings"
)

type Node[T any] struct {
	val  T
	next *Node[T]
	prev *Node[T]
}

type List[T any] struct {
	sentinel *Node[T]
	size     int
}

func NewList[T any]() *List[T] {
	s := Node[T]{}
	s.next, s.prev = &s, &s

	return &List[T]{
		sentinel: &s,
	}
}

func (l *List[T]) getNode(index int) *Node[T] {
	var curr *Node[T]
	if index < l.size/2 {
		curr = l.sentinel.next
		for i := 0; i < index; i++ {
			curr = curr.next
		}
	} else {
		curr = l.sentinel
		for i := l.size; i > index; i-- {
			curr = curr.prev
		}
	}

	return curr
}

func (l *List[T]) Get(index int) (T, bool) {
	if index < 0 || index > l.size-1 {
		var t T
		return t, false
	}

	return l.getNode(index).val, true
}

func (l *List[T]) addBefore(curr *Node[T], val T) {
	node := &Node[T]{
		val:  val,
		next: curr,
		prev: curr.prev,
	}
	curr.prev.next = node
	curr.prev = node
	l.size++
}

func (l *List[T]) Add(index int, val T) bool {
	if index < 0 || index > l.size {
		return false
	}

	l.addBefore(l.getNode(index), val)
	return true
}

func (l *List[T]) AddAtHead(val T) bool {
	return l.Add(0, val)
}

func (l *List[T]) AddAtTail(val T) bool {
	return l.Add(l.size, val)
}

func (l *List[T]) remove(curr *Node[T]) {
	curr.prev.next = curr.next
	curr.next.prev = curr.prev
	l.size--
}

func (l *List[T]) Remove(index int) bool {
	if index < 0 || index >= l.size {
		return false
	}

	l.remove(l.getNode(index))
	return true
}

func (l *List[T]) RemoveAtHead() bool {
	return l.Remove(0)
}

func (l *List[T]) RemoveAtTail() bool {
	return l.Remove(l.size - 1)
}

func (l *List[T]) String() string {
	var b strings.Builder
	fmt.Fprint(&b, "[")
	curr := l.sentinel.next
	for i := 0; i < l.size; i++ {
		fmt.Fprintf(&b, "[%v]", curr.val)
		curr = curr.next
	}
	fmt.Fprint(&b, "]")

	return b.String()
}
