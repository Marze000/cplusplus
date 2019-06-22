#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;
namespace List
{
	class SeqList {
	public:
		//初始化,构造函数
		SeqList()
			:_array(new int(_last))
		{
			_start = 0;
			_last = 0;
			_end = 20;
		}
		//销毁
		~SeqList() {
			delete[] _array;
			_array = nullptr;
			_end = 0;
			_last = 0;
		}
		//检查
		void SeqListCheck() {
			//需要扩容
			if (_end == _last) {
				int* new_array = new int(_end);
				_end += 10;

				delete[] _array;
				_array = new_array;
			}
		}
		//尾插
		void SeqListPushBack(int data) {
			SeqListCheck();
			++_last = data;
		}
		//尾删
		void SeqListPopBack() {
			--_last;
		}
		//头删
		void SeqListPopFront() {
			for (int i = 0; i < _last + 1; ++i) {
				_array[i] = _array[i + 1];
			}
			--_last;
		}
		//头插
		void SeqListPushFront(int data) {
			for (int i = _last - 1; i >= 0; --i) {
				_array[i + 1] = _array[i];
			}
			_array[0] = data;
		}
		//在 pos 位置前插入
		void SeqListInsert(int pos, int data) {
			for (int i = _last - 1; i >= pos; --i) {
				_array[i + 1] = _array[i];
			}
			_array[pos] = data;
			++_last;
		}
		//任意位置的删除
		void SeqListErase(int pos) {
			for (int i = pos + 1; i < _last; ++i) {
				_array[i - 1] = _array[i];
			}
			--_last;
		}
		//移除指定的元素
		void SeqListRemove(int pos) {
			for (int i = 0; i < _last; ++i) {
				if (_array[i] == pos) {
					SeqListErase(i);
				}
			}
		}
		//检测元素是否在表中
		bool SeqListFind(int data) {
			for (int i = 0; i < _last; ++i) {
				if (_array[i] == data) {
					return true;
				}
			}
			return false;
		}
		//获取元素个数
		int SeqListSize() {
			return _last;
		}
		//获取容量
		int SeqListCapacity() {
			return _end;
		}
		//判断是否是空
		bool SeqListEmpty() {
			if (_start == 0) {
				return true;
			}
			return false;
		}
		//获取第一个元素
		int SeqListFirst() {
			return _start;
		}
		//获取最后一个元素
		int SeqListlast() {
			return _last;
		}
		//打印表中的数据
		void SeqListPrint() {
			for (int i = 0; i < _last; ++i) {
				cout << _array[i] << endl;
			}
			cout << endl;
		}
	private:
		int* _array;
		int _start;
		int _end;
		int _last;
	};
}
