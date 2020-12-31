#pragma once
#include"LinkList.h"


class MenuDataOrder
{
public:
	MenuDataOrder(LinkList head, LinkList tail,int order)//构造函数先把数据复制过来,再调用命令行数进行排序
	{
		this->order = order;//复制命令
		//复制
		{	
			//头节点
			myhead = (LinkList)malloc(sizeof(struct Node));
			if (myhead != NULL)//空间申请成功
			{
				myhead->before = myhead;
				myhead->next = NULL;
				mytail = myhead;			//
				myhead->student.num = 0;
			}
			else//空间申请失败
			{
				//printf("创建头节点时申请空间失败！\n");
				//todo:弹窗！
			}
			//复制身体
			head = head->next;
			while (head != NULL)//用head定位原来的节点
			{
				//【申请一个节点】
				PNode node = new(Node);

				//【指针域修改】
				node->next = NULL;
				node->before = mytail;	//后插法
				mytail->next = node;
				mytail = node;

				//【赋值数据域】
				node->student.num = head->student.num;
				node->student.Chinese = head->student.Chinese;
				node->student.Birthday = head->student.Birthday;
				node->student.Math = head->student.Math;
				node->student.Ehglish = head->student.Ehglish;
				node->student.ID = head->student.ID;
				node->student.P_E_ = head->student.P_E_;
				node->student.Class = head->student.Class;
				node->student.Sex = head->student.Sex;
				node->student.Name = head->student.Name;

				head = head->next;
			}
			myOrder = myhead; 
		}
		//排序
		//quick_sort(myhead, myhead->next, tail, order);
		Commader(order);
	}
	~MenuDataOrder()//析构函数释放空间
	{
	}

public:
	LinkList myOrder;
	LinkList myhead, mytail;
	int order = 0;
	
private:
	void Commader(int order);//还是要传参数是为了加强这个参数的重要性
	void quick_sort(LinkList myhead, LinkList left, LinkList right, int order);
	int getGrade(LinkList p, int order);
	void  swap(LinkList a, LinkList b)
	{
		LinkList flag = new(Node);
		flag->before = NULL; flag->next = NULL;
		__list_add(flag, b->before, b);
		list_del(b);
		__list_add(b, a->before, a);
		list_del(a);
		__list_add(a, flag->before, flag);
		list_del(flag);
	}
	void __list_add(LinkList thenew,LinkList prev,LinkList next)
	{
		next->before = thenew;
		thenew->next = next;
		thenew->before = prev;
		prev->next = thenew;
	}
	void __list_del(LinkList prev, LinkList next)
	{
		if (next==NULL)
		{
			prev->next = NULL;
		}
		else
		{
		next->before = prev;
		prev->next = next;
		}
	}
	void list_del(LinkList entry)
	{
		__list_del(entry->before, entry->next);
	}
};

