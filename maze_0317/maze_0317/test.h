#pragma once


//InitList(&L);//构造一个空的线性表

//DestroyList(&L);//初始条件：线性表已经存在
				  //操作结果：销毁线性表

//ClearList(&L);//初始条件：线性表 L 已经存在
			    //操作结果：将 L 重置为空表

//ListEmpty(L);//初始条件：线性表 L 已经存在
			   //操作结果：若 L 表为空表返回TRUE，否则返回FALSE;

//ListLength(L);//初始条件：线性表 L 已经存在
			    //操作结果：返回 L 中元素的个数

//GetElem(L,i,&e);//初始条件：线性表L已经存在,1 <= i <= ListLength(L)
				  //操作结果：用 e 返回 L 中第 i 个数据元素的值

//LocateElem(L,e,compare());//初始条件：线性表 L 已经存在，compare()是数据元素判定函数
						    //操作结果：返回 L 中第一个与 e 满足关系compare()的数据元素
			 				//			的位序，若这样的元素不存在返回0
							
//PriorElem(L,cur_e,&pre_e);//初始条件：线性表 L 已经存在；
						    //操作结果：若cur_e是 L 的数据元素，且不是第一个，则用 pre_e
						    //			返回它的前驱，否则操作失败，pre_e无定义

//NextElem(L,cur_e,&next_e);//初始条件：线性表 L 已经存在
							//操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则
						    //			用next_e返回它的后驱，否则操作失败，next_e无定义

//ListInsert(&L,i,e);//初始条件：线性表已经存在，1<= i <= ListLength(L)+1
					 //操作结果：在L中第i个位置之前插入新的数据元素 e ,L的长度加1

//ListDelete(&L,i,&e);//初始条件：线性表 L 已经存在且非空，1<= i <= ListLength(L)
					  //操作结果：删除L中的第i个元素，并用e返回其值，L的长度减一

//ListTraverse(L,visit());//初始条件：线性表L中已经存在
						  //操作结果：依次对L的每个数据元素调用函数visit(),
						  //          若visit()失败，则操作失败；


