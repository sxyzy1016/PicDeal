// FFTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PicDeal.h"
#include "FFTDlg.h"
#include "afxdialogex.h"


// CFFTDlg 对话框

IMPLEMENT_DYNAMIC(CFFTDlg, CDialogEx)

CFFTDlg::CFFTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FFTDLG, pParent)
{

}

CFFTDlg::~CFFTDlg()
{
}

void CFFTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFFTDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BNSAVE, &CFFTDlg::OnBnClickedBnsave)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDCANCEL, &CFFTDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CFFTDlg::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFFTDlg 消息处理程序


void CFFTDlg::OnBnClickedBnsave()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	CFileDialog dlg(FALSE, NULL, NULL, OFN_FILEMUSTEXIST, TEXT("JPG/JPEG格式图片(*.jpg)|*.jpg|"), this, 0UL, TRUE);
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

void CFFTDlg::ChangeSize(UINT nID, int x, int y)
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

void CFFTDlg::drawpic(IplImage* img, unsigned int id)
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

void CFFTDlg::ChangeWndSize(int Width, int Height) {
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

void CFFTDlg::SetFFTImage(IplImage* FFTImg) {
	if (!FFTImg) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	Img = FFTImg;
	ChangeWndSize(Img->width, Img->height);
	this->SendMessage(WM_PAINT);
}



BOOL CFFTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetClientRect(Init_rect);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CFFTDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	ChangeSize(IDC_FFTSHOW, cx, cy);
	ChangeSize(IDC_BNSAVE, cx, cy);
	ChangeSize(IDOK, cx, cy);
	ChangeSize(IDCANCEL, cx, cy);
}


void CFFTDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CFFTDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	return;
	//CDialogEx::OnOK();
}


void CFFTDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	drawpic(Img, IDC_FFTSHOW);
	//CDialogEx::OnPaint();
}
