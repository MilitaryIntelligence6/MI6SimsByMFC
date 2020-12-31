//SimsDialog.h


// SimsDialog.h: 头文件
//

#pragma once
#include"LinkList.h"

// SimsDialog 对话框
class SimsDialog : public CDialogEx
{
// 构造
public:
	SimsDialog(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSGM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:

	HICON m_hIcon;

	bool TimerOn = 0;
	int timedigit = 0;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonSave();
	CListCtrl m_stlistct;
	bool ShowOnScreen(LinkList head,LinkList orderhead);
	//afx_msg void OnLvnItemchangedListScreen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonChange();
	// 封装：从对话框的edit框填入的内容获取cstring，填入p指向的空间
	void FillANodeFromDlg(LinkList node);
	afx_msg void OnClickListScreen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonInsert();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonSerach();
	afx_msg void OnBnClickedButtonDelete();
	CDateTimeCtrl m_databirthday;
	afx_msg void OnMenuSaveTheFile();
	// 将整个链表的数据输出到strFile路径/文件名下
	bool FileSave(LinkList head, CString strFilePath);
	afx_msg void OnMenuOpenOneFile();
	/**
	 * 打开传入的文件;
	 */
	void OnMenuOpenOneFile(CString filePath);
	// 打开窗口，另存为窗口。返回选中文件路径
	CString getFilePath(bool isRead);
	// 将strData填入node的第iWitchData个数据内
	void fillANodeFromTXT(LinkList node, CString strData, int iWhichData);
	// 保留头指针和尾指针，将整个链表释放掉
	void freeAList(LinkList head);
	afx_msg void OnMenuCreateNewFile();
	afx_msg void OnMenuSaveSelfFile();
	afx_msg void OnShowMI6();
	// 是否打开数据文件，是则指向此文件，否则指向null。
	CStdioFile* TheOpenedFile = NULL;
	// 是否打开外部数据文件，是则1，否则0.
	bool bIsOpenFile = 0;
	// 保存是否改变打开的数据文件状态
	bool isChangeFile = 0;
	// 保存是否保存文件的状态，与isChangeFile状态一起用
	bool isSaveFile = 0;
	afx_msg void MenuOrderShowData();
	afx_msg void MenuInOrderChinese();
	afx_msg void OnChineseUnorder();
	afx_msg void OnMathInOrder();
	afx_msg void OnMathUnorder();
	afx_msg void OnEnglishInOrder();
	afx_msg void OnEnglishUnorder();
	afx_msg void OnPEInOrder();
	afx_msg void OnPEUnorder();
	afx_msg void OnSumData();
	afx_msg void OnAverageData();
	afx_msg void OnStandardData();
	void MakeOrderList();

private:
	LinkList head, tail, ptempfromlistctl;
	int Order;
	LinkList orderhead, ordertail;//todo
	bool isOrdered = 0;
	int timer = 1;

public:

	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticEnglish();
	afx_msg void OnEnChangeEditId();
	afx_msg void OnEnChangeEditMath();
	afx_msg void OnLvnItemchangedListScreen(NMHDR* pNMHDR, LRESULT* pResult);
};
