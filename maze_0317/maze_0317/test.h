#pragma once


//InitList(&L);//����һ���յ����Ա�

//DestroyList(&L);//��ʼ���������Ա��Ѿ�����
				  //����������������Ա�

//ClearList(&L);//��ʼ���������Ա� L �Ѿ�����
			    //����������� L ����Ϊ�ձ�

//ListEmpty(L);//��ʼ���������Ա� L �Ѿ�����
			   //����������� L ��Ϊ�ձ�����TRUE�����򷵻�FALSE;

//ListLength(L);//��ʼ���������Ա� L �Ѿ�����
			    //������������� L ��Ԫ�صĸ���

//GetElem(L,i,&e);//��ʼ���������Ա�L�Ѿ�����,1 <= i <= ListLength(L)
				  //����������� e ���� L �е� i ������Ԫ�ص�ֵ

//LocateElem(L,e,compare());//��ʼ���������Ա� L �Ѿ����ڣ�compare()������Ԫ���ж�����
						    //������������� L �е�һ���� e �����ϵcompare()������Ԫ��
			 				//			��λ����������Ԫ�ز����ڷ���0
							
//PriorElem(L,cur_e,&pre_e);//��ʼ���������Ա� L �Ѿ����ڣ�
						    //�����������cur_e�� L ������Ԫ�أ��Ҳ��ǵ�һ�������� pre_e
						    //			��������ǰ�����������ʧ�ܣ�pre_e�޶���

//NextElem(L,cur_e,&next_e);//��ʼ���������Ա� L �Ѿ�����
							//����������� cur_e �� L ������Ԫ�أ��Ҳ������һ������
						    //			��next_e�������ĺ������������ʧ�ܣ�next_e�޶���

//ListInsert(&L,i,e);//��ʼ���������Ա��Ѿ����ڣ�1<= i <= ListLength(L)+1
					 //�����������L�е�i��λ��֮ǰ�����µ�����Ԫ�� e ,L�ĳ��ȼ�1

//ListDelete(&L,i,&e);//��ʼ���������Ա� L �Ѿ������ҷǿգ�1<= i <= ListLength(L)
					  //���������ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�һ

//ListTraverse(L,visit());//��ʼ���������Ա�L���Ѿ�����
						  //������������ζ�L��ÿ������Ԫ�ص��ú���visit(),
						  //          ��visit()ʧ�ܣ������ʧ�ܣ�

