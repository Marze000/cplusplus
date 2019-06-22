#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//对一个结点进行封装
class Node {
public:
	Node* _next;
	Node* _pre;
	int _data;
};

//双向非循环链表
class SList {
public:
	SList() {
		_head->_pre = nullptr;
		_head->_next = nullptr;
	}
	~SList() {

	}
	//尾插
	void SListPushBack(int data) {
		Node* node;
		node->_data = data;

		//只存在头结点
		if (_head->_next == nullptr) {
			node->_pre = _head;
			node->_next = nullptr;
			_head->_next = node;
		}

		//找到最后一个结点
		Node* cur = _head->_next;
		while (cur->_next != nullptr) {
			cur = cur->_next;
		}
		//进行插入
		cur->_next = nullptr;
		cur->_pre = cur;
		cur->_next = node;
	}
	//尾删
	void SListPopBack() {
		if (_head->_next == nullptr) {
			_head = nullptr;
		}

		//找到倒数第二个结点
		Node* cur = _head->_next;
		while (cur->_next->_next == nullptr) {
			cur = cur->_next;
		}
		Node* node = cur->_next;
		node->_pre = nullptr;
		cur->_next = nullptr;
	}
	//头插
	void SListPushFront(int data) {
		//先构造一个结点
		Node* node;
		node->_data = data;
		//如果只有头结点 
		if (_head->_next == nullptr) {
			node->_next = nullptr;
			node->_pre = _head;
			_head->_next = node;
		}
		//至少有一个结点
		node->_next = _head->_next;
		node->_pre = _head;
		_head->_next->_pre = node;
		_head->_next = node;
	}
	//头删
	void SListPopFront() {
		assert(_head->_next == nullptr);
		if (_head->_next->_next == nullptr) {
			_head->_next->_pre = nullptr;
			_head->_next = nullptr;
		}

		//至少有两个结点
		Node* node = _head->_next->_next;
		Node* cur = _head->_next;
		_head->_next = node;
		node->_pre = _head;
		cur->_next = cur->_pre = nullptr;
	}

	//在 pos 结点前面插入
	void SListInsertFront(Node* pos,int data) {
		Node* node;
		node->_data = data;
		
		node->_next = pos;
		node->_pre = pos->_pre;
		pos->_pre->_next = node;
		pos->_pre = node;
	}
	//在 pos 结点后面插入
	void SListInsertAfter(Node* pos, int data) {
		Node* node;
		node->_data = data;

		node->_pre = pos;
		node->_next = pos->_next;
		pos->_next->_pre = node;
		pos->_next = node;
	}

	//删除 pos 结点
	void SListErase(Node* pos) {
		//只有头结点
		if (pos->_next = nullptr) {
			return;
		}

		pos->_pre->_next = pos->_next;
		pos->_next->_pre = pos->_pre;
		pos->_next = pos->_pre = nullptr;
	}

	//查找结点
	int SListFind(int data) {
		Node* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				return data;
			}
			node = node->_next;
		}
		return 0;
	}
	//删除v所对应的结点
	void SListEraseV(int data) {
		Node* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				SListErase(node);
			}
			node = node->_next;
		}
	}

	void Print() {
		Node* node = _head->_next;
		while (node != nullptr) {
			cout << node->_data;
		}
		cout << endl;
	}
private:
	Node* _head;
};
