﻿// DeleteDialog.cpp: 实现文件
//

#include "pch.h"
#include "Sims.h"
#include "DeleteDialog.h"
#include "afxdialogex.h"


// DeleteDialog 对话框

IMPLEMENT_DYNAMIC(DeleteDialog, CDialogEx)

DeleteDialog::DeleteDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE, pParent)
{

}

DeleteDialog::~DeleteDialog()
{
}

void DeleteDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DeleteDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DELETEOK, &DeleteDialog::OnBnClickedButtonDeleteok)
	ON_BN_CLICKED(IDCANCEL, &DeleteDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// DeleteDialog 消息处理程序


BOOL DeleteDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString tempText;
	tempText.Format(_T("%d"), pnodedelete->student.num);
	SetDlgItemText(GetDlgItem(IDC_STATIC_DSNUM)->GetDlgCtrlID(), tempText);
	tempText = pnodedelete->student.Name;//姓名
	SetDlgItemText(IDC_STATIC_DSNAME, tempText);
	if (pnodedelete->student.Sex == 1)//性别
	{
		tempText = _T("男");
		SetDlgItemText(GetDlgItem(IDC_STATIC_DSSEX)->GetDlgCtrlID(), tempText);
	}
	else
	{
		tempText = _T("女");
		SetDlgItemText(GetDlgItem(IDC_STATIC_DSSEX)->GetDlgCtrlID(), tempText);
	}
	tempText.Format(_T("%llu"), pnodedelete->student.ID);	//学号
	SetDlgItemText(IDC_STATIC_DSID, tempText);
	SetDlgItemText(IDC_STATIC_DSCLASS, pnodedelete->student.Class);//班级
	SetDlgItemText(IDC_STATIC_DSBIRTHDAY, pnodedelete->student.Birthday);
	tempText.Format(_T("%d"), pnodedelete->student.Chinese);//CHINESE
	SetDlgItemText(IDC_STATIC_DSCHINESE, tempText);
	tempText.Format(_T("%d"), pnodedelete->student.Math);//MATH
	SetDlgItemText(IDC_STATIC_DSMATH, tempText);
	tempText.Format(_T("%d"), pnodedelete->student.Ehglish);//ENGLISH
	SetDlgItemText(IDC_STATIC_DSENGLISH, tempText);
	tempText.Format(_T("%d"), pnodedelete->student.P_E_);//PE
	SetDlgItemText(IDC_STATIC_DSPE, tempText);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DeleteDialog::OnBnClickedButtonDeleteok()
{
	// TODO: 在此添加控件通知处理程序代码
	pnodedelete->before->next = pnodedelete->next;
	if (pnodedelete->next==NULL)
	{
		*thetail = pnodedelete->before;
	}
	else
	{
		pnodedelete->next->before = pnodedelete->before;
		LinkList p = pnodedelete->next;
		delete pnodedelete;
		while (p != NULL)
		{
			p->student.num--;
			p = p->next;
		}
	}
	ShowOnMainList(head);
	CDialogEx::OnOK();
}


void DeleteDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void DeleteDialog::ShowOnMainList(LinkList head)
{
	// TODO: 在此处添加实现代码.
	m_mainlist->DeleteAllItems();
	CString tempText = _T("MI6");//以后的初始化CString就这个啦！
	LinkList p = head;
	p = p->next;
	int i = 0;

	while (p != NULL)
	{

		tempText.Format(_T("%d"), p->student.num);		//自定义的序号
		m_mainlist->InsertItem(i, tempText);				//创建新的行并显示序号
		tempText = p->student.Name;
		m_mainlist->SetItemText(i, 1, tempText); 		//显示姓名
		if (p->student.Sex == 1)
		{
			tempText.Format(_T("男"));
		}
		else
		{
			tempText.Format(_T("女"));
		}
		m_mainlist->SetItemText(i, 2, tempText);			//显示性别
		tempText.Format(_T("%llu"), p->student.ID);	/////////////to
		m_mainlist->SetItemText(i, 3, tempText);			//显示学号
		m_mainlist->SetItemText(i, 4, p->student.Class);	//显示班级
		tempText.Format(_T("%d"), p->student.Chinese);
		m_mainlist->SetItemText(i, 5, tempText);			//显示科目1成绩
		tempText.Format(_T("%d"), p->student.Math);
		m_mainlist->SetItemText(i, 6, tempText);			//显示科目2成绩
		tempText.Format(_T("%d"), p->student.Ehglish);
		m_mainlist->SetItemText(i, 7, tempText);			//显示科目3成绩
		tempText.Format(_T("%d"), p->student.P_E_);
		m_mainlist->SetItemText(i, 8, tempText);			//显示科目4成绩
		m_mainlist->SetItemText(i, 9, p->student.Birthday);//显示生日

		p = p->next;
		i++;

	}
}