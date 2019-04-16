////用什么来实现栈   顺序表 or 链表
//
//typedef int SDataType;
//typedef struct Stack
//{
//	SDataType* _array;
//	int _capacity;
//	int _top; // 标记栈顶位置 
//}Stack;
//
//// 初始化栈 
//void StackInit(Stack* ps)
//{
//	ps->_capacity = 10;
//	SDataType* _array = (SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
//	
//}
//
//// 入栈 
//void StackPush(Stack* ps, SDataType data)
//{
//
//}
//
//// 出栈 
//void StackPop(Stack* ps);
//
//// 获取栈顶元素 
//SDataType StackTop(Stack* ps);
//
//// 获取栈中有效元素个数 
//int StackSize(Stack* ps);
//
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
//int StackEmpty(Stack* ps);
//
//// 销毁栈 
//void StackDestroy(Stack* ps);
////4. 栈的应用：括号匹配、逆波兰表达式、栈与递归
////5. 熟悉队列的概念以及特性
////6. 熟悉循环队列，并分析循环队列如何判断队列满
////7. 实现队列的以下基本操作
//typedef int * QDataType;
//
//// 链式结构：表示队列 
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}	QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//// 初始化队列 
//void QueueInit(Queue* q)
//{
//	q->_front = q->_rear = NULL;
//}
//
//// 队尾入队列 
//void QueuePush(Queue* q, QDataType data);
//
//// 队头出队列 
//void QueuePop(Queue* q);
//
//// 获取队列头部元素 
//QDataType QueueFront(Queue* q);
//
//// 获取队列队尾元素 
//QDataType QueueBack(Queue* q);
//
//// 获取队列中有效元素个数 
//int QueueSize(Queue* q);
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//int QueueEmpty(Queue* q);
//
//// 销毁队列 
//void QueueDestroy(Queue* q);
//
//
////=====================================================
////静态顺序表
//typedef struct Stack
//{
//	int array[100];
//	int size;
//}	Stack;
//
//void StackInit(Stack* s)
//{
//	s->size = 0;
//}
//
//void StackDestroy()
//{
//	s->szie = 0;
//}
//
////压入
//void StackPush(Stack *s, int v)
//{
//	s->array[s->size++] = v;
//}
//
////弹出
//void StackPop(Stack *s, int v)
//{
//	s->size--;
//}
//
////返回栈顶的元素，不删除
//void StackTop2(Stack *s, int v)
//{
//	return s->array[s->size - 1];
//}
//
////返回栈内数据个数
//int StackSize(Stack *s, int v)
//{
//	return s->size;
//}
//
////返回是否是空栈
//int StackEmpty(Stack *s, int v)
//{
//	return !s->size;
//}
//
//
//
//
