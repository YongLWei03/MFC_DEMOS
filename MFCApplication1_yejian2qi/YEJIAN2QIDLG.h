
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// YEJIAN2QIDLG �Ի���
class YEJIAN2QIDLG : public CDialogEx
{
// ����
public:
	YEJIAN2QIDLG(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YEJIAN2QI_DIALOG};
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRect m_DlgRect;
	void repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height);




	DECLARE_MESSAGE_MAP()

public:
	CComboBox sCombo101;
	CComboBox sCombo102;
	CEdit sEditS1MAX;
	CEdit sEditS1M;
	CEdit sEditL11;
	CEdit sEditL12;
	CEdit sEditN11;
};
