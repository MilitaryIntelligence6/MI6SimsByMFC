#include "pch.h"
#include "MenuData.h"



MenuData::MenuData(LinkList head, LinkList tail, int order)
{
    this->order = order;//复制命令
    //复制
    {
        //头节点
        myhead = (LinkList)malloc(sizeof(struct Node));
        if (myhead != NULL)//空间申请成功
        {
            myhead->prev = myhead;
            myhead->next = NULL;
            mytail = myhead;            //
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
            //申请一个节点
            PNode node = new(Node);

            //指针域修改
            node->next = NULL;
            node->prev = mytail;    //后插法
            mytail->next = node;
            mytail = node;

            //赋值数据域
            node->student.num = head->student.num;
            node->student.dataStructure = head->student.dataStructure;
            node->student.birthday = head->student.birthday;
            node->student.computerNetwork = head->student.computerNetwork;
            node->student.compilationPrinciple = head->student.compilationPrinciple;
            node->student.id = head->student.id;
            node->student.androidDevelopment = head->student.androidDevelopment;
            node->student.clazz = head->student.clazz;
            node->student.sex = head->student.sex;
            node->student.name = head->student.name;

            head = head->next;
        }
        myOrder = myhead;
    }
    //排序
    //quick_sort(myhead, myhead->next, tail, order);
    Commader(order);
}


MenuData::~MenuData()//析构函数释放空间
{
}


void MenuData::Commader(int order)
{
    //写一个函数通过order得到相应的数字
    //上百且是奇数，上百且是偶数，没有上百分别冒泡
    //todo
    LinkList p = mytail;
    while (p != myhead->next)
    {
        LinkList q = myhead->next;

        while (q->next != NULL)    //检查一下冒泡结束条件和冒泡算法是否一致
        {
            if ((order > 99 && order % 2 == 1) || (order <= 99))//上百且是奇数或者没有上百
            {
                if (getGrade(q, order) > getGrade(q->next, order))//大的往后冒
                {
                    swap(q, q->next);
                    q = q->prev;
                }
            }
            //上百且是偶数：小的往后冒
            if (order > 99 && order % 2 == 0)//上百且是奇数或者没有上百
            {
                if (getGrade(q, order) < getGrade(q->next, order))//小的往后冒
                {
                    swap(q, q->next);
                    q = q->prev;
                }
            }
            q = q->next;
        }
        p = p->prev;
    }

}


//快速排序
void MenuData::quickSort(LinkList first, LinkList theleft, LinkList theright, int order)
{
    LinkList left = theleft, right = theright;
    if (left->student.num < right->student.num)
    {
        LinkList flag = first;//将第一个数据作为中枢
        while (left != right)
        {
            while (getGrade(flag, order) <= getGrade(right, order) && left != right) // 从右向左找第一个小于x的数
                right = right->prev;
            if (left != right)
            {
                swap(flag, right);
                flag = right;
                left = left->next;
            } else break;

            while (getGrade(left, order) <= getGrade(flag, order) && left != right) // 从左向右找第一个大于等于x的数
                left = left->next;
            if (left != right)
            {
                swap(left, flag);
                flag = left;
                right = right->prev;
            } else break;
        }
        //?s[i] = x;
        quickSort(first, theleft, left->prev, order); // 递归调用
        quickSort(first, left->next, theright, order);
    }
}


int MenuData::getGrade(LinkList p, int order)
{
    if (order > 99)
    {
        order /= 10;
    }

    int x;
    switch (order)
    {
        case 11:
            return p->student.dataStructure;
        case 12:
            return p->student.computerNetwork;
        case 13:
            return p->student.compilationPrinciple;
        case 14:
            return p->student.androidDevelopment;
        case 21:
            //计算这个学生的总分
            return p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                   p->student.androidDevelopment;
        case 22:
            //平均分
            return (p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                    p->student.androidDevelopment) / 4;
        case 23:
            //标准差
            x = (p->student.dataStructure + p->student.computerNetwork + p->student.compilationPrinciple +
                 p->student.androidDevelopment) / 4;
            return (p->student.dataStructure - x) * (p->student.dataStructure - x) +
                   (p->student.computerNetwork) * (p->student.computerNetwork) +
                   (p->student.compilationPrinciple) * (p->student.compilationPrinciple) +
                   (p->student.androidDevelopment) * (p->student.androidDevelopment);
            break;
        default:
            return p->student.num;
            break;
    }
    return 0;
}


void MenuData::swap(LinkList foo, LinkList bar)
{
    LinkList flag = new(Node);
    flag->prev = NULL;
    flag->next = NULL;
    listAdd(flag, bar->prev, bar);
    listDel(bar);
    listAdd(bar, foo->prev, foo);
    listDel(foo);
    listAdd(foo, flag->prev, flag);
    listDel(flag);
}


void MenuData::listAdd(LinkList newData, LinkList prev, LinkList next)
{
    next->prev = newData;
    newData->next = next;
    newData->prev = prev;
    prev->next = newData;
}


void MenuData::listDelete(LinkList prev, LinkList next)
{
    if (next == NULL)
    {
        prev->next = NULL;
    }
    else
    {
        next->prev = prev;
        prev->next = next;
    }
}


void MenuData::listDel(LinkList entry)
{
    listDelete(entry->prev, entry->next);
}
