//LinkList.h

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <afxstr.h>


//单链表类型定义
typedef struct StuMessage
{
	int num = 0;	//序号
	CString Name = _T("foobar");		//姓名
	bool Sex = 1;			//性别
	unsigned long long int ID = 41800000;	//学号
	CString Class = NULL;		//班级
	CString Birthday = NULL;	//生日
	int Chinese = 0;
	int Math = 0;
	int Ehglish = 0;
	int P_E_ = 0;
}Student;


struct Node
{

	Student student;	//数据域

	struct Node* before = NULL;
	struct Node* next = NULL;	//指针域

};


typedef struct Node* PNode;		//节点类型定义
typedef struct Node* LinkList;
