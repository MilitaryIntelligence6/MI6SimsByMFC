#pragma once

#include"LinkList.h"


class MenuData
{

public:

    LinkList myOrder;

    LinkList myhead, mytail;

    int order = 0;


public:

    MenuData(LinkList head, LinkList tail, int order); //构造函数先把数据复制过来,再调用命令行数进行排序
    

    ~MenuData(); //析构函数释放空间


private:

    void Commader(int order); //还是要传参数是为了加强这个参数的重要性；
    
    void quickSort(LinkList myhead, LinkList left, LinkList right, int order);

    int getGrade(LinkList p, int order);

    void swap(LinkList foo, LinkList bar);

    void listAdd(LinkList newData, LinkList prev, LinkList next);

    void listDelete(LinkList prev, LinkList next);

    void listDel(LinkList entry);
};

