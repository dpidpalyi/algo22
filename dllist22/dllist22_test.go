package dllist22

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_NewList(t *testing.T) {
	l := NewList[int]()

	assert.NotNil(t, l)
}

func Test_getNode_0(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")

	node := l.getNode(0)
	assert.Equal(t, "hello", node.val)
}

func Test_getNode_1(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")
	l.Add(1, "world")

	node := l.getNode(0)
	assert.Equal(t, "hello", node.val)

	node = l.getNode(1)
	assert.Equal(t, "world", node.val)
}

func Test_getNode_2(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")
	l.Add(1, " ")
	l.Add(2, "world")
	l.Add(3, "!")

	node := l.getNode(0)
	assert.Equal(t, "hello", node.val)

	node = l.getNode(1)
	assert.Equal(t, " ", node.val)

	node = l.getNode(2)
	assert.Equal(t, "world", node.val)

	node = l.getNode(3)
	assert.Equal(t, "!", node.val)
}

func Test_Get_0(t *testing.T) {
	l := NewList[string]()

	_, ok := l.Get(-1)
	assert.Equal(t, ok, false)
}

func Test_Get_1(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")

	_, ok := l.Get(2)
	assert.Equal(t, ok, false)
}

func Test_Get_2(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")

	v, ok := l.Get(0)
	assert.Equal(t, v, "hello")
	assert.Equal(t, ok, true)
}

func Test_Get_3(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")
	l.Add(1, "world")

	v, ok := l.Get(1)
	assert.Equal(t, v, "world")
	assert.Equal(t, ok, true)

	v, ok = l.Get(0)
	assert.Equal(t, v, "hello")
	assert.Equal(t, ok, true)

	_, ok = l.Get(2)
	assert.Equal(t, ok, false)
}

func Test_Get_4(t *testing.T) {
	l := NewList[string]()
	l.Add(0, "hello")
	l.Add(1, " ")
	l.Add(2, "world")
	l.Add(3, "!")

	v, ok := l.Get(0)
	assert.Equal(t, v, "hello")
	assert.Equal(t, ok, true)

	v, ok = l.Get(1)
	assert.Equal(t, v, " ")
	assert.Equal(t, ok, true)

	v, ok = l.Get(2)
	assert.Equal(t, v, "world")
	assert.Equal(t, ok, true)

	v, ok = l.Get(3)
	assert.Equal(t, v, "!")
	assert.Equal(t, ok, true)
}

func Test_Add_0(t *testing.T) {
	l := NewList[int]()

	ok := l.Add(-1, 10)
	assert.Equal(t, ok, false)
}

func Test_Add_1(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	ok := l.Add(10, 20)
	assert.Equal(t, ok, false)
}

func Test_Add_2(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 20)

	ok := l.Add(0, 10)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 10)
	assert.Equal(t, ok, true)
}

func Test_Add_3(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)
	l.Add(1, 20)
	l.Add(2, 30)

	ok := l.Add(0, 0)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 0)
	assert.Equal(t, ok, true)

	ok = l.Add(4, 40)
	assert.Equal(t, ok, true)

	v, ok = l.Get(4)
	assert.Equal(t, v, 40)
	assert.Equal(t, ok, true)
}

func Test_AddAtHead_0(t *testing.T) {
	l := NewList[int]()

	ok := l.AddAtHead(10)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 10)
	assert.Equal(t, ok, true)
}

func Test_AddAtHead_1(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 20)
	l.Add(1, 30)

	ok := l.AddAtHead(10)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 10)
	assert.Equal(t, ok, true)
}

func Test_AddAtTail_0(t *testing.T) {
	l := NewList[int]()

	ok := l.AddAtTail(10)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 10)
	assert.Equal(t, ok, true)
}

func Test_AddAtTail_1(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)
	l.Add(1, 20)

	ok := l.AddAtTail(30)
	assert.Equal(t, ok, true)

	v, ok := l.Get(2)
	assert.Equal(t, v, 30)
	assert.Equal(t, ok, true)
}

func Test_Remove_0(t *testing.T) {
	l := NewList[int]()

	ok := l.Remove(-1)
	assert.Equal(t, ok, false)
}

func Test_Remove_1(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	ok := l.Remove(1)
	assert.Equal(t, ok, false)
}

func Test_Remove_2(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	ok := l.Remove(0)
	assert.Equal(t, ok, true)

	_, ok = l.Get(0)
	assert.Equal(t, ok, false)
}

func Test_Remove_3(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)
	l.Add(1, 20)
	l.Add(2, 30)

	ok := l.Remove(0)
	assert.Equal(t, ok, true)

	v, ok := l.Get(0)
	assert.Equal(t, v, 20)
	assert.Equal(t, ok, true)
}

func Test_RemoveAtHead(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	ok := l.RemoveAtHead()
	assert.Equal(t, ok, true)

	_, ok = l.Get(0)
	assert.Equal(t, ok, false)
}

func Test_RemoveAtTail(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	ok := l.RemoveAtTail()
	assert.Equal(t, ok, true)

	_, ok = l.Get(0)
	assert.Equal(t, ok, false)
}

func Test_String_0(t *testing.T) {
	l := NewList[int]()

	s := l.String()
	assert.Equal(t, s, "[]")
}

func Test_String_1(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)

	s := l.String()
	assert.Equal(t, s, "[[10]]")
}

func Test_String_2(t *testing.T) {
	l := NewList[int]()
	l.Add(0, 10)
	l.Add(1, 20)
	l.Add(2, 30)

	s := l.String()
	assert.Equal(t, s, "[[10][20][30]]")
}
