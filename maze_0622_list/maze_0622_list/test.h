//#pragma once
//#include <iostream>
//#include <stdlib.h>
//#include <assert.h>
//using namespace std;
//
////对一个结点进行封装
//class Node<T> {
//public:
//	Node<T>* _next;
//	Node<T>* _pre;
//	int _data;
//};
//
////双向非循环链表
//class SList {
//public:
//	SList(){
//		_head = new Node<T>;
//		
//		_head->_pre = nullptr;
//		_head->_next = nullptr;
//		_head->_data = 0;
//	}
//	~SList() {
//		delete _head;
//		_head = nullptr;
//	}
//	//尾插
//	void SListPushBack(int data) {
//		Node<T>* node = new Node<T>;
//		node->_data = data;
//
//		//只存在头结点
//		if (_head->_next == nullptr) {
//			node->_pre = _head;
//			node->_next = nullptr;
//			_head->_next = node;
//		}
//		else {
//
//			//找到最后一个结点
//			Node<T>* cur = _head->_next;
//			while (cur->_next != nullptr) {
//				cur = cur->_next;
//			}
//			//进行插入
//			node->_next = nullptr;
//			node->_pre = cur;
//			cur->_next = node;
//		}
//	}
//	//尾删
//	void SListPopBack() {
//		if (_head->_next == nullptr) {
//			return;
//		}
//
//		//找到倒数第二个结点
//		Node<T>* cur = _head->_next;
//		while (cur->_next->_next != nullptr) {
//			cur = cur->_next;
//		}
//		Node<T>* node = cur->_next;
//		node->_pre = nullptr;
//		delete node;
//		cur->_next = nullptr;
//	}
//	//头插
//	void SListPushFront(int data) {
//		Node<T>* node = new Node<T>;
//		node->_data = data;
//	
//		//如果只有头结点 
//		if (_head->_next == nullptr) {
//			node->_next = nullptr;
//			node->_pre = _head;
//			_head->_next = node;
//		}
//		//至少有一个结点
//		node->_next = _head->_next;
//		node->_pre = _head;
//		_head->_next->_pre = node;
//		_head->_next = node;
//	}
//	//头删
//	void SListPopFront() {
//		if (_head->_next == nullptr) {
//			return;
//		}
//		if (_head->_next->_next == nullptr) {
//			Node<T>* cur = _head->_next;
//			cur->_pre = nullptr;
//			delete cur;
//			_head->_next = nullptr;
//		}
//
//		//至少有两个结点
//		Node<T>* node = _head->_next->_next;
//		Node<T>* cur = _head->_next;
//		_head->_next = node;
//		node->_pre = _head;
//		cur->_next = cur->_pre = nullptr;
//		delete cur;
//	}
//
//	//在 pos 结点前面插入
//	void SListInsertFront(Node<T>* pos,int data) {
//		Node<T>* node;
//		node->_data = data;
//		
//		node->_next = pos;
//		node->_pre = pos->_pre;
//		pos->_pre->_next = node;
//		pos->_pre = node;
//	}
//	//在 pos 结点后面插入
//	void SListInsertAfter(Node<T>* pos, int data) {
//		Node<T>* node;
//		node->_data = data;
//
//		node->_pre = pos;
//		node->_next = pos->_next;
//		pos->_next->_pre = node;
//		pos->_next = node;
//	}
//
//	//删除 pos 结点
//	void SListErase(Node<T>* pos) {
//		//只有头结点或只剩下最后一个结点
//		if (pos->_next == nullptr) {
//			Node<T>* pre = pos->_pre;
//			pre->_next = nullptr;
//			pos->_pre = nullptr;
//			delete pos;
//		}else{
//			Node<T>* pre = pos->_pre;
//			pre->_next = pos->_next;
//			pos->_next->_pre = pre;
//			pos->_next = pos->_pre = nullptr;
//			delete pos;
//		}
//	}
//
//	//查找结点
//	int SListFind(int data) {
//		Node<T>* node = _head->_next;
//		while (node != nullptr) {
//			if (node->_data == data) {
//				return 1;
//			}
//			node = node->_next;
//		}
//		return 0;
//	}
//	//删除v所对应的结点
//	void SListEraseV(int data) {
//		Node<T>* node = _head->_next;
//		while (node != nullptr) {
//			if (node->_data == data) {
//				Node<T>* next = node->_next;
//				SListErase(node);
//				node = next;
//			}else {
//				node = node->_next;
//			}
//		}
//	}
//
//	void Print() {
//		Node<T>* node = _head->_next;
//		while (node != nullptr) {
//			cout << node->_data<<" ";
//			node = node->_next;
//		}
//		cout << endl;
//	}
//private:
//	Node<T>* _head;
//};
//

#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//对一个结点进行封装
template<class T>
class Node {
public:
	Node<T>* _next;
	Node<T>* _pre;
	int _data;
};

//双向非循环链表
template<class T>
class SList {
public:
	SList(){
		_head = new Node<T>; 
		_head->_pre = nullptr;
		_head->_next = nullptr;
		_head->_data = 0;
	}
	~SList() {
		delete _head;
		_head = nullptr;
	}
	//尾插
	void SListPushBack(int data) {
		Node<T>* node = new Node<T>;
		node->_data = data;

		//只存在头结点
		if (_head->_next == nullptr) {
			node->_pre = _head;
			node->_next = nullptr;
			_head->_next = node;
		}
		else {

			//找到最后一个结点
			Node<T>* cur = _head->_next;
			while (cur->_next != nullptr) {
				cur = cur->_next;
			}
			//进行插入
			node->_next = nullptr;
			node->_pre = cur;
			cur->_next = node;
		}
	}
	//尾删
	void SListPopBack() {
		if (_head->_next == nullptr) {
			return;
		}

		//找到倒数第二个结点
		Node<T>* cur = _head->_next;
		while (cur->_next->_next != nullptr) {
			cur = cur->_next;
		}
		Node<T>* node = cur->_next;
		node->_pre = nullptr;
		delete node;
		cur->_next = nullptr;
	}
	//头插
	void SListPushFront(int data) {
		Node<T>* node = new Node<T>;
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
		if (_head->_next == nullptr) {
			return;
		}
		if (_head->_next->_next == nullptr) {
			Node<T>* cur = _head->_next;
			cur->_pre = nullptr;
			delete cur;
			_head->_next = nullptr;
		}

		//至少有两个结点
		Node<T>* node = _head->_next->_next;
		Node<T>* cur = _head->_next;
		_head->_next = node;
		node->_pre = _head;
		cur->_next = cur->_pre = nullptr;
		delete cur;
	}

	//在 pos 结点前面插入
	void SListInsertFront(Node<T>* pos,int data) {
		Node<T>* node;
		node->_data = data;
		
		node->_next = pos;
		node->_pre = pos->_pre;
		pos->_pre->_next = node;
		pos->_pre = node;
	}
	//在 pos 结点后面插入
	void SListInsertAfter(Node<T>* pos, int data) {
		Node<T>* node;
		node->_data = data;

		node->_pre = pos;
		node->_next = pos->_next;
		pos->_next->_pre = node;
		pos->_next = node;
	}

	//删除 pos 结点
	void SListErase(Node<T>* pos) {
		//只有头结点或只剩下最后一个结点
		if (pos->_next == nullptr) {
			Node<T>* pre = pos->_pre;
			pre->_next = nullptr;
			pos->_pre = nullptr;
			delete pos;
		}else{
			Node<T>* pre = pos->_pre;
			pre->_next = pos->_next;
			pos->_next->_pre = pre;
			pos->_next = pos->_pre = nullptr;
			delete pos;
		}
	}

	//查找结点
	 T SListFind(int data) {
		Node<T>* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				return 1;
			}
			node = node->_next;
		}
		return 0;
	}
	//删除v所对应的结点
	void SListEraseV(int data) {
		Node<T>* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				Node<T>* next = node->_next;
				SListErase(node);
				node = next;
			}else {
				node = node->_next;
			}
		}
	}

	void Print() {
		Node<T>* node = _head->_next;
		while (node != nullptr) {
			cout << node->_data<<" ";
			node = node->_next;
		}
		cout << endl;
	}
private:
	Node<T>* _head;
};


