#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
	Node* _next;
	int _data;
};

class List {
public:
	List() {
		_head = new Node;
		_head->_next = nullptr;
		_head->_data = 0;
	}
	~List() {
		delete	_head;
		_head = nullptr;
	}
	//插入
	void PushBack(int data) {
		Node* node = new Node;
		node->_data = data;
		Node* cur = _head->_next;
		while (cur->_next != nullptr) {
			cur = cur->_next;
		}
		cur->_next = node;
		node->_next = nullptr;
	}

	void PushFront(int data) {
		Node* node = new Node;
		node->_data = data;
		node->_next = _head->_next;
		_head->_next = node;
	}
	void Insert(Node* pos, int data) {
		Node* node = new Node;
		node->_data = data;
		node->_next = pos->_next;
		pos->_next = node;
	}

	//删除
	void PopBack() {
		if (_head->_next == nullptr) {
			delete _head;
			_head = nullptr;
		}else {
			Node* node = _head->_next;
			while (node->_next->_next != nullptr) {
				node = node->_next;
			}
			delete node->_next;
			node->_next = nullptr;
		}
	}
	void PopFront() {
		if (_head->_next == nullptr) {
			delete _head;
			_head = nullptr;
		}
		else {
			Node* node = _head->_next->_next;
			delete _head->_next;
			_head->_next = node;
		}
	}
	
	void Pop(Node* pos) {
		Node* node = _head->_next;
		while (node->_next != pos) {
			node = node->_next;
		}
		Node* tmp = pos->_next;
		node->_next = tmp;
		delete pos;
		pos = tmp;
	}

	//删除data值的结点
	void EraseV(int data) {
		Node* node = _head->_next;
		while (node != nullptr) {
			if (node->_data = data) {
				Pop(node);
			}
			node = node->_next;
		}
	}

	//翻转
	void Reserve() {

	}

	//查找
	void Find();

private:
	Node* _head;
};

	