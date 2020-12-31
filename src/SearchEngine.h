//SearchEngine.h

#pragma once

#include"LinkList.h"
// SearchEngine 对话框

class SearchEngine : public CDialogEx
{
	DECLARE_DYNAMIC(SearchEngine)

public:
	SearchEngine(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SearchEngine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl searchlistscreen;
	LinkList pnode = NULL;
	short leader = 1;//作为radio button 的选择标志。
	CString tempText = _T("null");//作为收集edit框的临时空间
	afx_msg void OnBnClickedRadioSnum();
	afx_msg void OnBnClickedRadioSid();
	afx_msg void OnBnClickedRadioSname();
	afx_msg void OnBnClickedRadioSclass();
	afx_msg void OnBnClickedButtonBssearch();
	// 通过leader值，查找相应的节点，返回查找到的第一个节点。如果没有查找到返回null
	LinkList GetANode(int num, unsigned long long int id, CString name, CString inclass,LinkList pnode);
	bool FindShow(int num, unsigned long long int id, CString name, CString inclass,LinkList pnode);
	// 把一个pnode内的数据显示在第i行
	void ShowANode(LinkList pnode);
};
