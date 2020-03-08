
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, v_Ssmax(1)
	, v_Ssmin(1)
	, v_L1(1)
	, v_L2(1)
	, v_n1(1)
	, v_n2(1)
	, v_Un1(1)
	, v_Un2(1)
	, v_St(1)
	, v_Uk(1)
	, r_Iopk1(1)
	, r_Iopk2(1)
	, r_Iopk3(1)
{


	CDialogEx::SetBackgroundImage(IDB_BITMAP1, BACKGR_TOPLEFT, TRUE);

	m_DlgRect.SetRect(0, 0, 0, 0);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SSMAX, v_Ssmax);
	DDX_Text(pDX, IDC_EDIT_SSMIN, v_Ssmin);

	DDX_Text(pDX, IDC_EDIT_L1, v_L1);
	DDX_Text(pDX, IDC_EDIT_L2, v_L2);
	DDX_Text(pDX, IDC_EDIT_N1, v_n1);
	DDX_Text(pDX, IDC_EDIT_N2, v_n2);
	DDX_Text(pDX, IDC_EDIT_ST, v_St);
	DDX_Text(pDX, IDC_EDIT_UK, v_Uk);
	DDX_Text(pDX, IDC_EDIT_UN1, v_Un1);
	DDX_Text(pDX, IDC_EDIT_UN2, v_Un2);

}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_EN_CHANGE(IDC_EDIT_SSMAX, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_SSMIN, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_N1, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_N2, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_ST, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UK, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UN1, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UN2, &CMFCApplication1Dlg::OnEnChangeEditDefault)

	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CMFCApplication1Dlg::OnBnClickedButtonResult)
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMFCApplication1Dlg::initCalculateResult2File();
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���


	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// nn_20190728 add
	// ���ñ��� 


	// ���ն˴���

	//TRACE("init console window\n");
	//printf("init console window\n");
	// nn_20190728 add


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}




// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{

		CDialogEx::OnPaint();

}



void CMFCApplication1Dlg::repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height)
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




void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	printf("OnSize cx %d %d\n", cx, cy);
	//TRACE("OnSize cx %d %d\n", cx, cy);

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

void CMFCApplication1Dlg::OnEnChangeEditDefault()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//printf("DSZ OR XSG���벻Ҫ�ҵ㣬���[����]��ť����\n");

}

void CMFCApplication1Dlg::initCalculateResult2File() {
	CString path = _T("d:\\�����������.txt");
	BOOL rec = PathFileExists(path);
	if (rec) {
#ifdef DEBUG
		CFile::Remove("d:\\�����������.txt", NULL);
#else
		CFile::Remove(L"d:\\�����������.txt", NULL);
#endif
	}
}

void printCalculateResult2File(const char* value) {

	// ����CFile����ͬʱ�Դ����Ͷ�д�ķ�ʽ���ļ�E:\1.txt  
	CFile file(_T("d:\\�����������.txt"), CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);

	// ��д�����ݵĻ�����ÿ���ֽڶ���ֵΪ�ַ�c   

	// ������д�뵽�ļ���   
	if (file) {
		file.SeekToEnd();
		file.Write(value, strlen(value));

		// �ر��ļ�   
		file.Close();
	}

	printf(value);
}
CApplication0 ExcelApp;     //Excell ����������Ҫ�ı��� 
CWorkbooks0 wbsMybooks;
CWorkbook0 wbMyBook;
CWorksheets0 wssMySheets;
CWorksheet0 wsMySheet;
CRange0 MyRange;

void ExcelToString(int row, int col, CString& sMsg) 
{ 
	VARIANT vMsg; 
	char cMsg[512];  
	vMsg = MyRange.get_Item(_variant_t((long)row), _variant_t((long)col)); 
	_bstr_t bMsg = (_bstr_t)vMsg;    
	strcpy_s(cMsg, strlen(bMsg) + 1, bMsg);
	sMsg = cMsg; 
}


void writeData2Excel() {

	CoUninitialize();
	if (CoInitialize(NULL) != 0)
	{
		//AfxMessageBox("��ʼ��COM֧�ֿ�ʧ�ܣ�");
	} //����Excell 
#ifdef DEBUG
	if (!ExcelApp.CreateDispatch("Excel.Application", NULL))
#else
	if (!ExcelApp.CreateDispatch(L"Excel.Application", NULL))
#endif
	{
		//AfxMessageBox("����Excell����ʧ�ܣ�");
		exit(1);
	}
	ExcelApp.put_Visible(FALSE);     //����ģ���ļ��������ĵ� 
	CString strPath;
	CString strPath1;
	//GetCurrentDirectory(MAX_PATH, strPath.GetBuffer(MAX_PATH));//��ȡ��ǰ·�� 
#ifdef DEBUG
	strPath1.Format("D:\\����������.xls");//Ҫ������excel�������
#else
	strPath1.Format(L"D:\\����������.xls");//Ҫ������excel�������
#endif
	printf("writeData2Excel strPath1 %s\n", strPath1);
	wbsMybooks.AttachDispatch(ExcelApp.get_Workbooks(), TRUE);
	wbMyBook.AttachDispatch(wbsMybooks.Add(_variant_t(strPath1)));
	wssMySheets.AttachDispatch(wbMyBook.get_Worksheets(), true);
	wsMySheet.AttachDispatch(wssMySheets.get_Item(_variant_t("Sheet1")), TRUE);
	MyRange.AttachDispatch(wsMySheet.get_Cells(), true);
	//int row = 1; 
	//CString sMsg;
	//ExcelToString(row, 1, sMsg);  //��ȡrow��1�е�������sMsg��
	//printf("writeData2Excel sMsg %s\n", sMsg);

	wbsMybooks.ReleaseDispatch();
	wbMyBook.ReleaseDispatch();
	wssMySheets.ReleaseDispatch();
	wsMySheet.ReleaseDispatch();
	MyRange.ReleaseDispatch();
	ExcelApp.ReleaseDispatch();
}
#include "BasicExcelVC6.hpp"
using namespace YExcel;
void CMFCApplication1Dlg::createResultExcel() {
	BasicExcel e1;
	e1.New(1);
	BasicExcelWorksheet* sheet1 = e1.GetWorksheet("Sheet1");
	if (sheet1) {
		sheet1->Cell(30, 10);// ->SetDouble(0.0);
	}
	e1.SaveAs("D:\\����������.xls");
}


void CMFCApplication1Dlg::export2Excel() {

	BasicExcel e;   // Load a workbook with one sheet, display its contents and  // save into another file.  
	CString strPath;

#ifdef DEBUG
	CString strPath1 = "D:\\����������.xls";
#else
	CString strPath1 = L"D:\\����������.xls";
#endif
	BOOL rec = PathFileExists(strPath1);

	if (!rec){
		printf("export2Excel ��D:\\����������.xls���ļ�������\n");
		createResultExcel();
		return;
	}

	GetCurrentDirectory(MAX_PATH, strPath.GetBuffer(MAX_PATH));//��ȡ��ǰ·�� 
	printf("export2Excel strPath:%s\n", strPath);

	//strPath1.Format("%s\\1.xls", strPath);//Ҫ������excel�������

	char * pFileName = "D:\\����������.xls";
	e.Load(pFileName);

	// read from excel
	BasicExcelWorksheet* sheet1 = e.GetWorksheet("Sheet1");  
	if (sheet1)  {    
		size_t maxRows = sheet1->GetTotalRows();    
		size_t maxCols = sheet1->GetTotalCols();    
		cout << "Dimension of " << sheet1->GetAnsiSheetName() <<        " (" << maxRows << ", " << maxCols << ")" << endl;     
		printf(" ");    
		for (size_t c=0; c<maxCols; ++c) 
			printf("%10d", c+1);    
		cout << endl;     
		for (size_t r=0; r<maxRows; ++r)    {      
			printf("%10d: ", r+1);   
			for (size_t c=0; c<maxCols; ++c)      {        
				BasicExcelCell* cell = sheet1->Cell(r,c);        
				switch (cell->Type())        {          
				case BasicExcelCell::UNDEFINED:            
					printf(" ");            
					break;           
				case BasicExcelCell::INT:            
					printf("%10d", cell->GetInteger());            
					break;           
				case BasicExcelCell::DOUBLE:            
					printf("%10.6lf", cell->GetDouble());            
					break;           
				case BasicExcelCell::STRING:            
					printf("%10s", cell->GetString());            
					break;           
				case BasicExcelCell::WSTRING:            
					wprintf(L"%10s", cell->GetWString());            
					break;        
				}     
				printf(" ");
			}      
			cout << endl;    
		}  
	}
	else {
#ifdef DEBUG
		AfxMessageBox("��ر����Excel�ļ����ٴε�������㡿��ť������");
#else
		AfxMessageBox(L"��ر����Excel�ļ����ٴε�������㡿��ť������");
#endif
	}
	cout << endl;

	// write to excel
	if (sheet1) {
		//����ctrl+k+c/u
		//sheet1->Cell(1, 0)->SetDouble(2.0);
		//sheet1->Cell(1, 1)->SetDouble(2.1);
		//sheet1->Cell(1, 2)->SetDouble(2.2);

		sheet1->Cell(0, 0)->SetWString(L"");
		sheet1->Cell(0, 1)->SetWString(L"35kV����ֵ");

		sheet1->Cell(1, 0)->SetWString(L"");
		sheet1->Cell(1, 1)->SetWString(L"");
		sheet1->Cell(1, 2)->SetWString(L"�ܵ��");
		sheet1->Cell(1, 3)->SetWString(L"������");

		sheet1->Cell(2, 0)->SetWString(L"");
		sheet1->Cell(2, 1)->SetWString(L"�������");
		sheet1->Cell(2, 2)->SetDouble(v_n1);
		sheet1->Cell(2, 3)->SetDouble(v_n2);

		sheet1->Cell(3, 0)->SetWString(L"һ");
		sheet1->Cell(3, 1)->SetWString(L"�����ٶ�");
		sheet1->Cell(3, 2)->SetWString(L"");
		sheet1->Cell(3, 3)->SetWString(L"");

		sheet1->Cell(4, 0)->SetWString(L"1");
		sheet1->Cell(4, 1)->SetWString(L"�����ٶ�����ֵ");
		sheet1->Cell(4, 2)->SetDouble(r_IopkS2);
		sheet1->Cell(4, 3)->SetDouble(r_Iopk3);
		sheet1->Cell(5, 0)->SetWString(L"2");
		sheet1->Cell(5, 1)->SetWString(L"������ϵ��");
		sheet1->Cell(5, 2)->SetDouble(r_ksenS2);
		sheet1->Cell(5, 3)->SetDouble(r_ksen3);

		sheet1->Cell(6, 0)->SetWString(L"��");
		sheet1->Cell(6, 1)->SetWString(L"������");

		sheet1->Cell(7, 0)->SetWString(L"1");
		sheet1->Cell(7, 1)->SetWString(L"����������ֵ");
		sheet1->Cell(7, 2)->SetDouble(r_IopkS1);
		sheet1->Cell(7, 3)->SetDouble(r_Iopk2);
		
		sheet1->Cell(8, 0)->SetWString(L"2");
		sheet1->Cell(8, 1)->SetWString(L"ʱ������(S)");
		sheet1->Cell(8, 2)->SetDouble(1.00);
		sheet1->Cell(8, 3)->SetDouble(0.50);

		sheet1->Cell(9, 0)->SetWString(L"3");
		sheet1->Cell(9, 1)->SetWString(L"������ϵ��");
		sheet1->Cell(9, 2)->SetDouble(r_ksenS1);
		sheet1->Cell(9, 3)->SetDouble(r_ksen2);


		sheet1->Cell(10, 0)->SetWString(L"��");
		sheet1->Cell(10, 1)->SetWString(L"������");
		sheet1->Cell(11, 0)->SetWString(L"1");
		sheet1->Cell(11, 1)->SetWString(L"����������ֵ");
		sheet1->Cell(11, 2)->SetWString(L"");
		sheet1->Cell(11, 3)->SetDouble(r_Iopk1);
		sheet1->Cell(12, 0)->SetWString(L"2");
		sheet1->Cell(12, 1)->SetWString(L"ʱ������(S)");
		sheet1->Cell(12, 2)->SetWString(L"");
		sheet1->Cell(12, 3)->SetDouble(10.00);

		sheet1->Cell(13, 0)->SetWString(L"��");
		sheet1->Cell(14, 0)->SetWString(L"(һ)");
		sheet1->Cell(15, 0)->SetWString(L"(��)");
		sheet1->Cell(16, 0)->SetWString(L"1");
		sheet1->Cell(17, 0)->SetWString(L"2");
		sheet1->Cell(18, 0)->SetWString(L"3");
		sheet1->Cell(19, 0)->SetWString(L"4");
		sheet1->Cell(20, 0)->SetWString(L"5");
		sheet1->Cell(21, 0)->SetWString(L"��");
		sheet1->Cell(22, 0)->SetWString(L"1");
		sheet1->Cell(23, 0)->SetWString(L"2");
	}
	// save to excel
	e.SaveAs(pFileName);
}

void CMFCApplication1Dlg::OnBnClickedButtonResult()
{
	char value[512] = { 0 };

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	//����
	//double c_Sj = 100;
	//double c_Xdianlan = 0.08;
	//double c_Xjiakong = 0.4;

	//����ֵ
	//double v_Ssmax;
	//double v_Ssmin;
	//double v_L1;
	//double v_L2;
	//double v_n1;
	//double v_n2;
	//double v_Un1;
	//double v_Un2;
	//double v_St;
	//double v_Uk;

	//�м����
	//double t_Xsmax;
	printCalculateResult2File("##################### START #####################\n");
	if (v_Ssmax != 0) {
		t_Xsmax = c_Sj / v_Ssmax;
	}
	sprintf_s(value, "Xsmax = Sj\/Ssmax = 100\/%f = %f\n", v_Ssmax, t_Xsmax);
	printCalculateResult2File(value);
	//double t_Xsmin;
	if (v_Ssmin != 0) {
		t_Xsmin = c_Sj / v_Ssmin;
	}
	sprintf_s(value, "Xsmin = Sj\/Ssmin = 100\/%f = %f\n", v_Ssmin, t_Xsmin);
	printCalculateResult2File(value);
	//double t_XL1;
	if (v_Un1 != 0) {
		t_XL1 = c_Xdianlan * v_L1 * c_Sj / (pow(v_Un1, 2));
	}
	sprintf_s(value, "XL1 = Xxianlan * L1 * Sj \/ Un1^2 = 0.08 * %f * 100 \/  %f^2 = %f\n", v_L1, v_Un1, t_XL1);
	printCalculateResult2File(value);
	//double t_XL2;
	if (v_Un1 != 0) {
		t_XL2 = c_Xjiakong * v_L2 * c_Sj / (pow(v_Un1, 2));
	}
	sprintf_s(value, "XL2 = Xjiakong * L2 * Sj \/ Un1^2 = 0.4 * %f * 100 \/  %f^2 = %f\n", v_L2, v_Un1, t_XL2);
	printCalculateResult2File(value);
	//double t_Xt;
	if (v_St != 0) {
		t_Xt = v_Uk / v_St;
	}
	sprintf_s(value, "Xt = \(Uk\/100\) * \(Sj\/St\) = %f \/ %f  = %f\n", v_Uk, v_St, t_Xt);
	printCalculateResult2File(value);
	//double t_Xmax;
	t_Xmax = t_Xsmax + t_XL1 + t_XL2 + t_Xt;
	sprintf_s(value, "Xmax = Xsmax + XL1 + XL2 + Xt = %f + %f + %f + %f = %f\n", t_Xsmax, t_XL1, t_XL2, t_Xt, t_Xmax);
	printCalculateResult2File(value);
	//double t_Xmin;
	t_Xmin = t_Xsmin + t_XL1 + t_XL2 + t_Xt;
	sprintf_s(value, "Xmin = Xsmin + XL1 + XL2 + Xt = %f + %f + %f + %f = %f\n", t_Xsmin, t_XL1, t_XL2, t_Xt, t_Xmin);
	printCalculateResult2File(value);
	//double t_I1rt;
	t_I1rt = v_St * 1000 / (sqrt(3) * v_Un1);
	sprintf_s(value, "I1rt = St * 1000 \/ \(sqrt(3) * Un1\) = %f * 1000 \/ sqrt\(3\) * %f = %f\n", v_St, v_Un1, t_I1rt);
	printCalculateResult2File(value);
	//double t_I2rt;
	t_I2rt = v_St * 1000 / (sqrt(3) * v_Un2);
	sprintf_s(value, "I2rt = St * 1000 \/ \(sqrt\(3\) * Un2\) = %f * 1000 \/ sqrt\(3\) * %f = %f\n", v_St, v_Un2, t_I2rt);
	printCalculateResult2File(value);
	//double t_I2kmax;
	t_I2kmax = (100 / (sqrt(3) * (1.05 * v_Un1))) * 1000 / t_Xmax;
	sprintf_s(value, "I2kmax = \(100 \/ \(sqrt\(3\) * \(1.05 * Un1\)\)\) * 1000 \/ Xmax = \(100 \/ \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 / %f = %f\n", v_Un1, t_Xmax, t_I2kmax);
	printCalculateResult2File(value);
	//double t_I1k2min;
	t_I1k2min = 0.866 * (100 / (sqrt(3) * (1.05 * v_Un1))) * 1000 / (t_Xsmin + t_XL1 + t_XL2);
	sprintf_s(value, "I1k2min = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * Un1\)\)\) * 1000 \/ \(Xsmin + XL1 + XL2\) = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 \/ \(%f + %f + %f\) = %f\n", v_Un1, t_Xsmin, t_XL1, t_XL2,t_I2kmax);
	printCalculateResult2File(value);
	//double t_I22k2min;
	t_I22k2min = 0.866 * (100 / (sqrt(3) * (1.05 * v_Un2))) * 1000  / t_Xmin;
	sprintf_s(value, "I22k2min = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * Un2\)\)\) * 1000 \/ Xmin = 0.866 * \(100 / \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 \/ %f = %f\n", v_Un2, t_Xmin, t_I22k2min);
	printCalculateResult2File(value);
	//double t_I2k2min;
	t_I2k2min = 2 * t_I22k2min / (3.5 *sqrt(3));
	sprintf_s(value, "I2k2min = 2 * I22k2min \/ \(3.5 *sqrt\(3\)\) = 2 * %f \/ \(3.5 *sqrt\(3\)\) = %f\n", t_I22k2min, t_I2k2min);
	printCalculateResult2File(value);

	//���
	//double r_Iopk1; 
	r_Iopk1 = 1.05 * t_I1rt / (0.9 * v_n2);	
	sprintf_s(value, "Iopk1 = 1.05 * I1rt \/ \(0.9 * n2\) = 1.05 * %f \/ \(0.9 * %f\) = %f\n", t_I1rt, v_n2, r_Iopk1);
	printCalculateResult2File(value);
	//double r_Iopk2;
	r_Iopk2 = 1.2 * 1.4 * t_I1rt / (0.9 * v_n2);
	sprintf_s(value, "Iopk2 = 1.2 * 1.4 * I1rt \/ \(0.9 * vn2\) = 1.2 * 1.4 * %f \/ \(0.9 * %f\) = %f\n", t_I1rt, v_n2, r_Iopk2);
	printCalculateResult2File(value);
	r_ksen2 = t_I2k2min / (r_Iopk2 * v_n2);
	sprintf_s(value, "ksen2 = I2k2min \/ \(Iopk2 * n2\) = %f \/ \(%f * %f\) = %f\n", t_I2k2min, r_Iopk2, v_n2, r_ksen2);
	printCalculateResult2File(value);
	//double r_Iopk3;
	r_Iopk3 = 1.3 * t_I2kmax / v_n2;
	sprintf_s(value, "Iopk3 = 1.3 * I2kmax \/ n2 = 1.3 * %f \/ %f = %f\n", t_I2kmax, v_n2, r_Iopk3);
	printCalculateResult2File(value);

	r_ksen3 = t_I1k2min / (r_Iopk3 * v_n2);
	sprintf_s(value, "ksen3 = I1k2min \/ \(Iopk3 * n2\) = %f \/ \(%f * %f\) = %f\n", t_I1k2min, r_Iopk3, v_n2, r_ksen3);
	printCalculateResult2File(value);

	//double r_IopkS1;
	r_IopkS1 = 1.1 *  (r_Iopk2 * v_n2) / v_n1;
	sprintf_s(value, "IopkS1 = 1.1 *  \(Iopk2 * n2\) \/ n1 = 1.1 *  \(%f * %f\) \/ %f = %f\n", r_Iopk2, v_n2, v_n1, r_IopkS1);
	printCalculateResult2File(value);

	//double r_ksenS1;
	r_ksenS1 = (v_n2 * r_ksen2) / (1.1 * v_n1);
	sprintf_s(value, "ksenS1 = \(n2 * ksen2\) \/ \(1.1 * n1\) = \(%f * %f\) \/ \(1.1 * %f\) = %f\n", v_n2, r_ksen2, v_n1, r_ksenS1);
	printCalculateResult2File(value);

	//double r_IopkS2;
	r_IopkS2 = 1.1 * (r_Iopk3 * v_n2) / v_n1;	
	sprintf_s(value, "IopkS2 = 1.1 * \(r_Iopk3 * v_n2\) \/ v_n1 = 1.1 * \(%f * %f\) \/ %f = %f\n", r_Iopk3, v_n2, v_n1, r_IopkS2);
	printCalculateResult2File(value);

	//double r_ksenS2;
	r_ksenS2 = (v_n2 * r_ksen3) / (1.1 * v_n1);
	sprintf_s(value, "ksenS2 = \(v_n2 * r_ksen3\) \/ \(1.1 * v_n1\) = \(%f * %f\) \/ \(1.1 * %f\) = %f\n", v_n2, r_ksen3, v_n1, r_ksenS2);
	printCalculateResult2File(value);

	printCalculateResult2File("##################### END #####################\n\n");

	//writeData2Excel();
	export2Excel();
}


void CMFCApplication1Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	printf("OnGetMinMaxInfo x:%d y:%d\n", lpMMI->ptMinTrackSize.x, lpMMI->ptMinTrackSize.y);

	int cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);
	printf("OnGetMinMaxInfo cx:%d cy:%d\n", cx, cy);

	if (cx >= 800) {
		lpMMI->ptMinTrackSize.x = 800;
		lpMMI->ptMinTrackSize.y = 800;
	}
	else {
		lpMMI->ptMinTrackSize.x = cx;
		lpMMI->ptMinTrackSize.y = cy;
	}
	lpMMI->ptMaxTrackSize.x = cx;
	lpMMI->ptMaxTrackSize.y = cy;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}




void CMFCApplication1Dlg::OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
