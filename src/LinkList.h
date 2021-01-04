//LinkList.h

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <afxstr.h>


// 学生信息数据struct节点定义
typedef struct StudentInfo
{
	int num = 0;	//序号
	CString name = _T("foobar");		//姓名
	bool sex = 1;			//性别
	unsigned long long int id = 41800000;	//学号
	CString clazz = NULL;		//班级
	CString birthday = NULL;	//生日
	// 成绩应该用ArrayList之类的可变容器储存, 方便科目的添加;
	int dataStructure = 0;
	int computerNetwork = 0;
	int compilationPrinciple = 0;
	int androidDevelopment = 0;
} Student;


struct Node
{
	Student student;	//数据域

	struct Node* prev = NULL;
	struct Node* next = NULL;	//指针域

};


typedef struct Node* PNode;		//节点类型定义
typedef struct Node* LinkList;
