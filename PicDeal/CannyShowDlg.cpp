// CannyShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PicDeal.h"
#include "CannyShowDlg.h"
#include "afxdialogex.h"


// CCannyShowDlg �Ի���

IMPLEMENT_DYNAMIC(CCannyShowDlg, CDialogEx)

CCannyShowDlg::CCannyShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CANNYSHOW, pParent)
{

}

CCannyShowDlg::~CCannyShowDlg()
{
}

void CCannyShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCannyShowDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCannyShowDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BNSAVE, &CCannyShowDlg::OnBnClickedBnsave)
	ON_BN_CLICKED(IDCANCEL, &CCannyShowDlg::OnBnClickedCancel)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CCannyShowDlg ��Ϣ�������


void CCannyShowDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	return;
}


void CCannyShowDlg::OnBnClickedBnsave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	CFileDialog dlg(FALSE, NULL, NULL, OFN_FILEMUSTEXIST, TEXT("JPG/JPEG��ʽͼƬ(*.jpg)|*.jpg|"), this, 0UL, TRUE);
	if (dlg.DoModal() == IDOK)
		FilePathName = dlg.GetPathName();
	else
		return;
	SetFocus();
	char* pFilePathName = new char[FilePathName.GetLength() + 1];
	memset(pFilePathName, 0, sizeof(pFilePathName));
	int i;
	for (i = 0;i != FilePathName.GetLength();++i) {
		pFilePathName[i] = FilePathName[i];
	}
	pFilePathName[i] = '\0';
	CString FileExtName = dlg.GetFileExt();
	cvSaveImage(pFilePathName, Img, NULL);
}


void CCannyShowDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CCannyShowDlg::drawpic(IplImage* img, unsigned int id)
{
	BYTE *g_pBits;
	HDC g_hMemDC;
	HBITMAP g_hBmp, g_hOldBmp;
	CDC *pDC;
	CStatic *pic;
	int width, height;
	CRect rect;
	pDC = GetDlgItem(id)->GetDC();
	pic = (CStatic*)GetDlgItem(id);
	pic->GetClientRect(&rect);
	width = rect.Width();
	height = rect.Height();
	g_hMemDC = ::CreateCompatibleDC(pDC->m_hDC);
	BYTE bmibuf[sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD)];
	memset(bmibuf, 0, sizeof(bmibuf));
	BITMAPINFO *pbmi = (BITMAPINFO*)bmibuf;
	pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pbmi->bmiHeader.biWidth = img->width;
	pbmi->bmiHeader.biHeight = img->height;
	pbmi->bmiHeader.biPlanes = 1;
	pbmi->bmiHeader.biBitCount = 24;
	pbmi->bmiHeader.biCompression = BI_RGB;
	g_hBmp = ::CreateDIBSection(g_hMemDC, pbmi, DIB_RGB_COLORS, (void**)&g_pBits, 0, 0);
	g_hOldBmp = (HBITMAP)::SelectObject(g_hMemDC, g_hBmp);
	BitBlt(g_hMemDC, 0, 0, width, height, pDC->m_hDC, 0, 0, SRCCOPY);
	int l_width = WIDTHBYTES(img->width* pbmi->bmiHeader.biBitCount);
	for (int row = 0; row < img->height; row++)
		memcpy(&g_pBits[row*l_width], &img->imageData[(img->height - row - 1)*l_width], l_width);
	TransparentBlt(pDC->m_hDC, 0, 0, width, height, g_hMemDC, 0, 0, img->width, img->height, RGB(0, 0, 0));
	SelectObject(g_hMemDC, g_hOldBmp);
	ReleaseDC(pDC);
	DeleteDC(g_hMemDC);
	DeleteObject(pic);
	DeleteObject(g_hBmp);
	DeleteObject(g_hOldBmp);
}

void CCannyShowDlg::ChangeWndSize(int Width, int Height) {
	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	int xScrn = GetSystemMetrics(SM_CXSCREEN);
	int yScrn = GetSystemMetrics(SM_CYSCREEN);
	int center_x = rect.CenterPoint().x;
	int center_y = rect.CenterPoint().y;
	if (Img->height < yScrn&&Img->width < xScrn) {
		rect.top = center_y - (int)(Img->height / 2);
		rect.bottom = center_y + (int)(Img->height / 2);
		rect.right = center_x + (int)(Img->width / 2);
		rect.left = center_x - (int)(Img->width / 2);
	}
	else if (Img->height >= yScrn&&Img->width >= xScrn) {
		rect.top = 0;
		rect.bottom = yScrn;
		rect.right = xScrn;
		rect.left = 0;
	}
	else if (Img->height < yScrn&&Img->width >= xScrn) {
		rect.top = center_y - (int)(Img->height*(xScrn / Img->width) / 2);
		rect.bottom = center_y + (int)(Img->height*(xScrn / Img->width) / 2);
		rect.right = xScrn;
		rect.left = 0;
	}
	else if (Img->height >= yScrn&&Img->width >= xScrn) {
		rect.top = 0;
		rect.bottom = yScrn;
		rect.right = center_x + (int)(Img->width*(yScrn / Img->height) / 2);
		rect.left = center_x - (int)(Img->width*(yScrn / Img->height) / 2);
	}
	if (rect.top < 0) {
		int delt_top = -1 * rect.top;
		rect.top = 0;
		rect.bottom += delt_top;
	}
	if (rect.left < 0) {
		int delt_left = -1 * rect.left;
		rect.left = 0;
		rect.right += delt_left;
	}
	MoveWindow(rect, TRUE);
}

void CCannyShowDlg::SetCannyImage(IplImage* CanImg) {
	if (!CanImg) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	Img = CanImg;
	ChangeWndSize(Img->width, Img->height);
	//this->SendMessage(WM_PAINT);
	drawpic(Img, IDC_CANNYSHOW);
}

void CCannyShowDlg::ChangeSize(UINT nID, int x, int y)
{
	CWnd *pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL)
	{
		CRect rect;
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.left = rect.left*x / Init_rect.Width();
		rect.top = rect.top*y / Init_rect.Height();
		rect.bottom = rect.bottom*y / Init_rect.Height();
		rect.right = rect.right*x / Init_rect.Width();
		pWnd->MoveWindow(rect);
	}
}


BOOL CCannyShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetClientRect(Init_rect);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CCannyShowDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	drawpic(Img, IDC_CANNYSHOW);
}


void CCannyShowDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	ChangeSize(IDC_CANNYSHOW, cx, cy);
	ChangeSize(IDC_BNSAVE, cx, cy);
	ChangeSize(IDOK, cx, cy);
	ChangeSize(IDCANCEL, cx, cy);
}
