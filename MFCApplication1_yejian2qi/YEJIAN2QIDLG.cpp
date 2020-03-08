
// YEJIAN2QIDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "YEJIAN2QIDLG.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���




// YEJIAN2QIDLG �Ի���



YEJIAN2QIDLG::YEJIAN2QIDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_YEJIAN2QI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_NIUNIU_TOOLS_ICON);//����Ӧ��ͼ��

	CDialogEx::SetBackgroundImage(IDB_YEJIAN2QI_BG, BACKGR_TOPLEFT, true);
	m_DlgRect.SetRect(0, 0, 0, 0);
}

void YEJIAN2QIDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_COMBO101, sCombo101);
	DDX_Control(pDX, IDC_COMBO102, sCombo102);
	DDX_Control(pDX, IDC_EDIT_S1MAX, sEditS1MAX);
	DDX_Control(pDX, IDC_EDIT_S1MIN, sEditS1M);
	DDX_Control(pDX, IDC_EDIT_L11, sEditL11);
	DDX_Control(pDX, IDC_EDIT_L12, sEditL12);
	DDX_Control(pDX, IDC_EDIT_N11, sEditN11);
}

BEGIN_MESSAGE_MAP(YEJIAN2QIDLG, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// nn_20190728 add
void InitConsoleWindowYEJIAN2QI()
{
	// debug start
// DEBUG OPEN
	int nCrt = 0;
	FILE* fp;
	AllocConsole();
	nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nCrt, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
// DEBUG CLOSE
	//FreeConsole();
	// debug stop
}
// nn_20190728 add

// YEJIAN2QIDLG ��Ϣ�������

BOOL YEJIAN2QIDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// nn_20190728 add
	// ���ñ��� 
	CString customTitle;
	customTitle.LoadString(IDS_NIUNIU_TOOLS);
	SetWindowText(customTitle);

	// ���ն˴���
	InitConsoleWindowYEJIAN2QI();
	//TRACE("init console window\n");
	//printf("init console window\n");
	// nn_20190728 add

	CString strTemp;
	CComboBox* comboBox = NULL;
	//1 
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO101));
	comboBox->ResetContent();//����������������
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);
	//2
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO102));
	comboBox->ResetContent();//����������������
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);

	//11
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO211));
	comboBox->ResetContent();//����������������
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);
	//12
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO212));
	comboBox->ResetContent();//����������������
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void YEJIAN2QIDLG::OnPaint()
{
	/*
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	*/
	{
		/*
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�       
		CDC   dcBmp;                                           //���岢����һ���ڴ��豸����
		dcBmp.CreateCompatibleDC(&dc);                         //����������DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);                 //������Դ�е�IDB_BITMAP1ͼƬ
		BITMAP   m_bitmap;                                     //ͼƬ����                
		bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��
		CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����  
																 //���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
		*/
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��



void YEJIAN2QIDLG::repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height)
//���¿ؼ�λ�úʹ�С���������Ը�����Ҫ�����޸�
{
	CRect rect;
	CWnd *wnd = NULL;
	wnd = GetDlgItem(id);
	if (NULL == wnd) {
		MessageBox(_T("��Ӧ�ؼ�������"));
	}
	wnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	double proportion_x = now_Width / (double)last_Width;
	double proportion_y = now_Height / (double)last_Height;
	rect.left = (long)(rect.left*proportion_x + 0.5);
	rect.right = (long)(rect.right*proportion_x + 0.5);
	rect.top = (long)(rect.top *proportion_y + 0.5);
	rect.bottom = (long)(rect.bottom *proportion_y + 0.5);

	//printf("repaint %d %d %d\n", id, last_Width, now_Width);
	//printf("repaint %d %d %d\n", id, rect.Width(), rect.Height());

	wnd->MoveWindow(&rect);
}

void YEJIAN2QIDLG::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	printf("OnSize cx %d %d\n", cx, cy);
	//TRACE("OnSize cx %d %d\n", cx, cy);

	if (m_DlgRect.left >= 0) {
		return;
	}

	//printf("OnSize left %d right %d\n", m_DlgRect.left, m_DlgRect.right);
	if (0 == m_DlgRect.left && 0 == m_DlgRect.right && 0 == m_DlgRect.top && 0 == m_DlgRect.bottom)
		//��һ�������Ի���ʱ�Ĵ�С�仯��������	
	{
		GetClientRect(&m_DlgRect); //save size of dialog
		//printf("OnSize Width %d Height %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	}
	if (0 == cx && 0 == cy)//����ǰ�������С�����򴥷���������ʱ������Ի�������		
	{
		return;
	}
	{
		CRect rectDlgChangeSize;
		GetClientRect(&rectDlgChangeSize);//�洢�Ի����С�ı��Ի����С���� 		
		
		int woc;
		HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		while (hwndChild) {
			woc = ::GetDlgCtrlID(hwndChild);
			repaint(woc,
				m_DlgRect.Width(), 
				rectDlgChangeSize.Width(), 
				m_DlgRect.Height(), 
				rectDlgChangeSize.Height());

			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
		}


		//repaint(IDC_EDIT_UN2, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
		//repaint(IDC_BUTTON_RESULT, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
	}
	GetClientRect(&m_DlgRect); //save size of dialog	
	//printf("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	//TRACE("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	
	Invalidate();//���´���
}
void YEJIAN2QIDLG::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	printf("OnGetMinMaxInfo x:%d y:%d\n", lpMMI->ptMinTrackSize.x, lpMMI->ptMinTrackSize.y);

	int cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);	
	printf("OnGetMinMaxInfo cx:%d cy:%d\n", cx, cy);

	if (cx >= 1570) {
		lpMMI->ptMinTrackSize.x = 1570;
		lpMMI->ptMinTrackSize.y = 990;
	}
	else {
		lpMMI->ptMinTrackSize.x = cx;
		lpMMI->ptMinTrackSize.y = cy;
	}
	lpMMI->ptMaxTrackSize.x = cx;
	lpMMI->ptMaxTrackSize.y = cy;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

