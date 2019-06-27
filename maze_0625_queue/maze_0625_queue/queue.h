#pragma once

template<class T>
class Node {
public:
	Node<T>* _next;
	T _data;
};

template<class T>
class Queue {
public:
	Queue() {
		_front = new Node<T>;
		_rear = new	Node<T>;
		_front = nullptr;
		_rear = nullptr;
	}

	void QueuePush(T data) {
		Node<T>* node = new Node<T>;
		node->_data = data;
		node->_next = nullptr;
		//没有结点的情况
		if (_front == nullptr) {
			_front = node;
			_rear = node;
		}else {
			//有节点的情况
			_rear->_next = node; 
			_rear = node;
		}
	}

	void QueuePop() {
		Node<T>* node = _front->_next;
		_front = node;

		//更新尾指针
		if (_front == nullptr) {
			_rear = nullptr;
		}
	}

	T QueueFront() {
		if (_front == nullptr) {
			return 0;
		}
		return _front->_data;
	}

	T QueueBack() {
		return _rear->_data;
	}

	T QueueSize() {
		if (_front == nullptr) {
			return 0;
		}

		static T size = 0;
		Node<T>* cur = _front;
		while (cur->_next != nullptr) {
			cur = cur->_next;
			++size;
		}
		return size;
	}
	bool QueueEmpty() {
		if (_front == nullptr) {
			return true;
		}
		return false;
	}

	~Queue() {
		Node<T>* cut = _front->_next;
		while (cut != nullptr) {
			delete _front;
			_front = cut;
			cut = cut->_next;
		}
		delete _front;
		_front = nullptr;
	}
private:
	Node<T>* _front;
	Node<T>* _rear;
};

