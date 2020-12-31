//InsertDialog.h

#pragma once

#include "LinkList.h"//??

// InsertDialog 对话框

class InsertDialog : public CDialogEx
{
	DECLARE_DYNAMIC(InsertDialog)

public:
	InsertDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InsertDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 选中的listctrl的行值
	int listrow;
	LinkList pnode, head;
	virtual BOOL OnInitDialog();
	//afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadioHere();
	afx_msg void OnBnClickedRadioNext();
	afx_msg void OnBnClickedButtonInsertok();
	CListCtrl *m_mainlist;
	// 插入类自己的show函数，但是调用的是主窗口的listctrl
	void ShowOnMainList(LinkList head);
	CDateTimeCtrl m_databirthday;
	afx_msg void OnDtnDatetimechangeDatetimepickerBirthday(NMHDR* pNMHDR, LRESULT* pResult);
};
