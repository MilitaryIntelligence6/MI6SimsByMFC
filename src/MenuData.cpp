#include "pch.h"
#include "MenuData.h"

void MenuDataOrder::Commader(int order)
{
	//写一个函数通过order得到相应的数字
	//上百且是奇数，上百且是偶数，没有上百分别冒泡
	//todo
	LinkList p = mytail;
	while (p!=myhead->next)
	{
		LinkList q = myhead->next;
		
		while (q->next != NULL)	//检查一下冒泡结束条件和冒泡算法是否一致
		{
			if ((order > 99 && order % 2 == 1)||(order<=99))//上百且是奇数或者没有上百
			{
				if (getGrade(q,order)>getGrade(q->next,order))//大的往后冒
				{
					swap(q, q->next);
					q = q->before;
				}
			}
			//上百且是偶数：小的往后冒
			if (order > 99 && order % 2 == 0)//上百且是奇数或者没有上百
			{
				if (getGrade(q, order) < getGrade(q->next, order))//小的往后冒
				{
					swap(q, q->next);
					q = q->before;
				}
			}
			q = q->next;
		}
		p = p->before;
	}

}


//快速排序
void MenuDataOrder::quick_sort(LinkList first, LinkList theleft, LinkList theright,int order)
{
	LinkList left = theleft, right = theright;
	if (left->student.num<right->student.num)
	{
		LinkList flag = first;//将第一个数据作为中枢
		while (left!=right)
		{
			while (getGrade(flag, order) <= getGrade(right, order) && left!=right) // 从右向左找第一个小于x的数
				right = right->before;
			if (left != right)
			{
				swap(flag, right);
				flag = right;
				left = left->next;
			}
			else break;

			while (getGrade(left, order) <= getGrade(flag, order) && left != right) // 从左向右找第一个大于等于x的数
				left = left->next;
			if (left != right)
			{
				swap(left, flag);
				flag = left;
				right = right->before;
			}
			else break;
		}
		//?s[i] = x;
		quick_sort(first, theleft, left->before,order); // 递归调用 
		quick_sort(first, left->next, theright,order);
	}
}

int MenuDataOrder::getGrade(LinkList p,int order)
{
	if (order>99)
	{
		order /= 10;
	}

	int x;
	switch (order)
	{
	case 11:
		return p->student.Chinese;
	case 12:
		return p->student.Math;
	case 13:
		return p->student.Ehglish;
	case 14:
		return p->student.P_E_;
	case 21:
		//计算这个学生的总分
		return p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_;
	case 22:
		//平均分
		return (p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_) / 4;
	case 23:
		//标准差
		x = (p->student.Chinese + p->student.Math + p->student.Ehglish + p->student.P_E_) / 4;
		return (p->student.Chinese - x) * (p->student.Chinese - x) + (p->student.Math) * (p->student.Math) + (p->student.Ehglish) * (p->student.Ehglish) + (p->student.P_E_) * (p->student.P_E_);
		break;
	default:return p->student.num;
		break;
	}
	return 0;
}
