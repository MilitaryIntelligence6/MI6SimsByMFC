// SEARCH.cpp: 实现文件
//

#include "pch.h"
#include "Sims.h"
#include "SearchEngine.h"
#include "afxdialogex.h"

int i = 0;//查找listctrl的显示行数

// SEARCH 对话框

IMPLEMENT_DYNAMIC(SearchEngine, CDialogEx)

SearchEngine::SearchEngine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEARCH, pParent)
{

}

SearchEngine::~SearchEngine()
{
}

void SearchEngine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SCREEN, searchlistscreen);
}


BEGIN_MESSAGE_MAP(SearchEngine, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_SNUM, &SearchEngine::OnBnClickedRadioSnum)
	ON_BN_CLICKED(IDC_RADIO_SID, &SearchEngine::OnBnClickedRadioSid)
	ON_BN_CLICKED(IDC_RADIO_SNAME, &SearchEngine::OnBnClickedRadioSname)
	ON_BN_CLICKED(IDC_RADIO_SCLASS, &SearchEngine::OnBnClickedRadioSclass)
	ON_BN_CLICKED(IDC_BUTTON_BSSEARCH, &SearchEngine::OnBnClickedButtonBssearch)
END_MESSAGE_MAP()


// SEARCH 消息处理程序


BOOL SearchEngine::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	searchlistscreen.SetBkColor(RGB(195, 195, 255));//表格的初始化
	searchlistscreen.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); // 整行选择、网格线
	searchlistscreen.InsertColumn(0, _T("序号"), LVCFMT_FILL, 50);
	searchlistscreen.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(2, _T("性别"), LVCFMT_CENTER, 50);
	searchlistscreen.InsertColumn(3, _T("学号"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(4, _T("班级"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(5, _T("数据结构"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(6, _T("计算机网络"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(7, _T("编译原理"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(8, _T("Android开发"), LVCFMT_CENTER, 100);
	searchlistscreen.InsertColumn(9, _T("出生日期"), LVCFMT_CENTER, 100);

	CheckRadioButton(GetDlgItem(IDC_RADIO_SNUM)->GetDlgCtrlID(), GetDlgItem(IDC_RADIO_SNUM)->GetDlgCtrlID(), GetDlgItem(IDC_RADIO_SNUM)->GetDlgCtrlID());//默认选中第一个radio


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SearchEngine::OnBnClickedRadioSnum()
{
	// TODO: 在此添加控件通知处理程序代码
	leader = 1;
}


void SearchEngine::OnBnClickedRadioSid()
{
	// TODO: 在此添加控件通知处理程序代码
	leader = 2;
}


void SearchEngine::OnBnClickedRadioSname()
{
	// TODO: 在此添加控件通知处理程序代码
	leader = 3;
}


void SearchEngine::OnBnClickedRadioSclass()
{
	// TODO: 在此添加控件通知处理程序代码
	leader = 4;
}


void SearchEngine::OnBnClickedButtonBssearch()
{
	// TODO: 在此添加控件通知处理程序代码
	searchlistscreen.DeleteAllItems();
	int innum = 0;
	unsigned long long int inid = 0;
	CString inname ;
	CString inclass ;
	//先读入
	GetDlgItemText(GetDlgItem(IDC_EDIT_SIN)->GetDlgCtrlID(), tempText);
	//再根据leader转换：
	switch (leader)
	{
	case 1:innum = _ttoi(tempText); break;
	case 2:inid = _tcstoull(tempText, 0, 10); break;
	case 3:inname = tempText;
	case 4:inclass = tempText;
	default:
		break;
	}
	//调用getanode函数一个一个找到对应的节点并显示在i行
	//如果一个都没有的话（i==1没变过），设置static文本。
	if (!FindShow(innum,inid,inname,inclass,pnode))
	{
		SetDlgItemText(GetDlgItem(IDC_STATIC_SEARCH)->GetDlgCtrlID(), _T("未找到指定数据！"));
	}
	else
	{
		CString tempText;
		tempText.Format(_T("查找到%d个数据！"), i);
		SetDlgItemText(GetDlgItem(IDC_STATIC_SEARCH)->GetDlgCtrlID(),tempText );
	}
}


// 通过leader值，查找相应的节点，返回查找到的第一个节点。如果没有查找到返回null
LinkList SearchEngine::GetANode(int num, unsigned long long int id, CString name, CString inclass,LinkList pnode)
{
	// TODO: 在此处添加实现代码.
	while (pnode!=NULL)
	{
		switch (leader)
		{
		case 1:if (pnode->student.num==num)
		{
			return pnode;
		}
			  break;
		case 2:if (pnode->student.ID==id)
		{
			return pnode;
		}
			  break;
		case 3:if (pnode->student.Name==name)
		{
			return pnode;
		}
			  break;
		case 4:if (pnode->student.Class==inclass)//有bug
		{
			return pnode;
		}
			  break;
		default:
			break;
		}
		pnode = pnode->next;
	}
	return NULL;
}


bool SearchEngine::FindShow(int innum, unsigned long long int inid, CString inname, CString inclass,LinkList pnode)
{
	// TODO: 在此处添加实现代码.
	bool isfind = 0;
	i = 0;	//显示行数的变量置为零
	while (GetANode(innum, inid, inname, inclass, pnode) != NULL)
	{
		isfind = 1;
		//pnode指向最后一个找到的节点
		pnode = GetANode(innum, inid, inname, inclass, pnode);
		//在listctrl中显示：[旁边复制过来的]
		ShowANode(pnode);
		i++;
		//pnode指向下一个节点以开始下一次查找
		pnode = pnode->next;
		//指向下一行
	}
	return isfind;
}




// 把一个pnode内的数据显示在第i行
void SearchEngine::ShowANode(LinkList pnode)
{
	// TODO: 在此处添加实现代码.
	tempText.Format(_T("%d"), pnode->student.num);
	searchlistscreen.InsertItem(i, tempText);
	tempText = pnode->student.Name;
	searchlistscreen.SetItemText(i, 1, tempText);			//显示姓名
	if (pnode->student.Sex == 1)
	{
		tempText.Format(_T("男"));
	}
	else
	{
		tempText.Format(_T("女"));
	}
	searchlistscreen.SetItemText(i, 2, tempText);			//显示性别
	tempText.Format(_T("%llu"), pnode->student.ID);	
	searchlistscreen.SetItemText(i, 3, tempText);			//显示学号
	searchlistscreen.SetItemText(i, 4, pnode->student.Class);	//显示班级
	tempText.Format(_T("%d"), pnode->student.Chinese);
	searchlistscreen.SetItemText(i, 5, tempText);			//显示数据结构成绩
	tempText.Format(_T("%d"), pnode->student.Math);
	searchlistscreen.SetItemText(i, 6, tempText);			//显示计算机网络成绩
	tempText.Format(_T("%d"), pnode->student.Ehglish);
	searchlistscreen.SetItemText(i, 7, tempText);			//显示英语成绩
	tempText.Format(_T("%d"), pnode->student.P_E_);
	searchlistscreen.SetItemText(i, 8, tempText);			//显示体育成绩
	searchlistscreen.SetItemText(i, 9, pnode->student.Birthday);//显示出生日期

}
