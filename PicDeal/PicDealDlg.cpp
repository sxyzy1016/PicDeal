
// PicDealDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PicDeal.h"
#include "PicDealDlg.h"
#include "ContrastDlg.h"
#include "HisDlg.h"
#include "SmoothDlg.h"
#include "FilterDlg.h"
#include "ColenhDlg.h"
#include "FFTDlg.h"
#include "CannyDlg.h"
#include "CannyShowDlg.h"
#include "afxdialogex.h"
#include <opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\core.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnBnClickedOk();
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
//ON_WM_SIZE()
ON_WM_SIZE()
END_MESSAGE_MAP()


// CPicDealDlg 对话框



CPicDealDlg::CPicDealDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PICDEAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Img = NULL;
}

void CPicDealDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPicDealDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABORT, &CPicDealDlg::OnAbort)
	ON_COMMAND(ID_OPEN, &CPicDealDlg::OnOpen)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_SAVE, &CPicDealDlg::OnSave)
	ON_WM_CLOSE()
	ON_COMMAND(ID_EXIT, &CPicDealDlg::OnExit)
	ON_COMMAND(ID_CONTRAST, &CPicDealDlg::OnContrast)
	ON_COMMAND(ID_FILTER, &CPicDealDlg::OnFilter)
	ON_COMMAND(ID_AVG, &CPicDealDlg::OnAvg)
	ON_COMMAND(ID_PSECOL, &CPicDealDlg::OnPsecol)
	ON_COMMAND(ID_HISTOGRAM, &CPicDealDlg::OnHistogram)
	ON_COMMAND(ID_FFT, &CPicDealDlg::OnFft)
	ON_COMMAND(ID_RGB2GRAY, &CPicDealDlg::OnRgb2gray)
	ON_COMMAND(ID_LAPLACESHARPNESS, &CPicDealDlg::OnLaplacesharpness)
	ON_COMMAND(ID_EDGEDET, &CPicDealDlg::OnEdgedet)
END_MESSAGE_MAP()


// CPicDealDlg 消息处理程序

BOOL CPicDealDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowText(TEXT("图像处理"));
	GetClientRect(Init_rect);
	ClientToScreen(&Init_rect);
	m_rect = Init_rect;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPicDealDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPicDealDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		if(Img)
			drawpic(Img, IDC_PICSHOW);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPicDealDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPicDealDlg::OnAbort()
{
	// TODO: 在此添加命令处理程序代码
	CDialog* dlg = new CDialog;
	dlg->Create(MAKEINTRESOURCE(IDD_ABOUTBOX));        //红色部分为对应菜单项的ID
	dlg->ShowWindow(1);
}


void CPicDealDlg::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	if (Img) {
		int id = MessageBox(TEXT("是否保存当前文件？"), TEXT("打开新文件"), MB_YESNOCANCEL);
		if (id == IDYES) {
			OnSave();
			cvReleaseImage(&Img);
			Invalidate(1);
			SetWindowText(TEXT("图像处理"));
			MoveWindow(m_rect, TRUE);
		}
		else if (id == IDCANCEL) {
			return;
		}
		else if (id == IDNO) {
			cvReleaseImage(&Img);
			Invalidate(1);
			SetWindowText(TEXT("图像处理"));
			MoveWindow(m_rect);
		}
	}
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, TEXT("JPG/JPEG格式图片(*.jpg)|*.jpg|PNG格式图片(*.png)|*.png|BMP格式图片(*.bmp)|*.bmp|"), this, 0UL, TRUE);
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
	Img = cvLoadImage(pFilePathName);
	if (!Img||!Img->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	ChangeWndSize(Img->width, Img->height);
	drawpic(Img, IDC_PICSHOW);
	SetWindowText(TEXT("图像处理 - " + dlg.GetFileName()));
}

void CPicDealDlg::drawpic(IplImage* img, unsigned int id)
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

void CPicDealDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	ChangeSize(IDC_PICSHOW, cx, cy);
}

BOOL CPicDealDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CPicDealDlg::OnSave()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	CFileDialog dlg(FALSE, NULL, NULL, OFN_FILEMUSTEXIST, TEXT("JPG/JPEG格式图片(*.jpg)|*.jpg|PNG格式图片(*.png)|*.png|BMP格式图片(*.bmp)|*.bmp|"), this, 0UL, TRUE);
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

FIBITMAP* CPicDealDlg::loadfiDIB(char* lpszPathName, int flag) {
	FreeImage_Initialise();
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib;
	fif = FreeImage_GetFileType(lpszPathName);
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(lpszPathName);
	if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif))
	{
		dib = FreeImage_Load(fif, lpszPathName, flag);
	}
	FreeImage_DeInitialise();
	return dib;
}

IplImage* CPicDealDlg::fbp2ipl(FIBITMAP* bitmap) {
	FreeImage_Initialise();
	if (!bitmap) {
		FreeImage_DeInitialise();
		return NULL;
	}
	IplImage* result = NULL;
	unsigned int imageWidth = FreeImage_GetWidth(bitmap);
	unsigned int imageHeight = FreeImage_GetHeight(bitmap);
	unsigned short channels = 1;
	unsigned short depth = FreeImage_GetBPP(bitmap);
	FIBITMAP * bitmap_temp = 0;
	unsigned char * data = 0;
	if (depth < 8) {
		depth = 8;
		if (NULL != (bitmap_temp = FreeImage_ConvertToGreyscale(bitmap))) {
			data = FreeImage_GetBits(bitmap_temp);
		}
	}
	else {
		assert(depth % 8 == 0);
		channels = depth / 8;
		depth = 8;
		data = FreeImage_GetBits(bitmap);
	}
	if (data) {
		CvSize size = cvSize((int)imageWidth, (int)imageHeight);
		result = cvCreateImageHeader(size, depth, channels);
		cvSetData(result, data, result->widthStep); 
		cvFlip(result, NULL, 0);
	}
	if (bitmap_temp) {
		FreeImage_Unload(bitmap_temp);
	}
	FreeImage_DeInitialise();
	return result;
}

void CPicDealDlg::ChangeWndSize(int Width, int Height) {
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
	//SendMessage(WM_SIZE);
}

void CPicDealDlg::ChangeWndSize(CRect rect) {
	MoveWindow(rect, TRUE);
	//SendMessage(WM_SIZE);
}

void CPicDealDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (Img) {
		int id = MessageBox(TEXT("是否保存当前文件？"), TEXT("退出"), MB_YESNOCANCEL);
		if (id == IDYES) {
			OnSave();
			CDialogEx::OnClose();
		}
		else if (id == IDCANCEL) {
			return;
		}
		else if (id == IDNO) {
			Img = NULL;
			CDialogEx::OnClose();
		}
	}
	else
		CDialogEx::OnClose();
}


void CPicDealDlg::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	if (Img) {
		int id = MessageBox(TEXT("是否保存当前文件？"), TEXT("退出"), MB_YESNOCANCEL);
		if (id == IDYES) {
			OnSave();
			SendMessage(WM_CLOSE);
		}
		else if (id == IDCANCEL) {
			return;
		}
		else if (id == IDNO) {
			cvReleaseImage(&Img);
			SendMessage(WM_CLOSE);
		}
	}
	else {
		SendMessage(WM_CLOSE);
	}
}



void CPicDealDlg::OnContrast()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	IplImage* NewImage;
	CContrastDlg ConDlg;
	int contrast, brightness;
	if (IDOK == ConDlg.DoModal()) {
		contrast = ConDlg.m_contrast;
		brightness = ConDlg.m_light;
	}
	if (contrast < 0 || brightness < 0) return;
	NewImage = compare(Img, contrast, brightness);
	cvReleaseImage(&Img);
	Img = NewImage;
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnFilter()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	int model;
	CFilterDlg fldlg;
	if (fldlg.DoModal() == IDOK) {
		model = fldlg.m_model;
	}
	else {
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	Smooth(Img, NewImage, model, model);
	if (!NewImage || !NewImage->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	cvReleaseImage(&Img);
	Img = NewImage;
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnAvg()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	int model;
	CSmoothDlg smdlg;
	if (smdlg.DoModal() == IDOK) {
		model = smdlg.m_model;
	}
	else {
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	Smooth(Img, NewImage, model, model);
	if (!NewImage || !NewImage->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	cvReleaseImage(&Img);
	Img = NewImage;
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnPsecol()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	int model;
	CColenhDlg cedlg;
	if (cedlg.DoModal() == IDOK) {
		model = cedlg.m_enh;
	}
	else {
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	char* enh = new char[4];
	switch (model)
	{
	case 1:
		enh = "rgb";
		break;
	case 2:
		enh = "rbg";
		break;
	case 3:
		enh = "brg";
		break;
	case 4:
		enh = "grb";
		break;
	case 5:
		enh = "gbr";
		break;
	case 6:
		enh = "bgr";
		break;
	default:
		MessageBox(TEXT("ERROR!"));
		return;
	}
	ColorEnhancement(Img, NewImage,enh);
	if (!NewImage || !NewImage->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	cvReleaseImage(&Img);
	Img = NewImage;
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnHistogram()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	IplImage* hist_image = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	//dilib(Img, hist_image);
	IplImage* redImage = cvCreateImage(cvGetSize(Img), Img->depth, 1);
	IplImage* greenImage = cvCreateImage(cvGetSize(Img), Img->depth, 1);
	IplImage* blueImage = cvCreateImage(cvGetSize(Img), Img->depth, 1);

	cvSplit(Img, blueImage, greenImage, redImage, NULL);//用 cvSplit 函数分解图像到单个色彩通道上
															//分别均衡化每个信道
	cvEqualizeHist(redImage, redImage);
	cvEqualizeHist(greenImage, greenImage);
	cvEqualizeHist(blueImage, blueImage);

	//信道合并
	cvMerge(blueImage, greenImage, redImage, NULL, hist_image);
	CHisDlg* hisdlg = new CHisDlg;
	hisdlg->Create(IDD_HISDLG, this);
	hisdlg->ShowWindow(SW_SHOW);
	hisdlg->SetHisImage(hist_image);
}


void CPicDealDlg::OnFft()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	CFFTDlg* fftdlg = new CFFTDlg;
	CFFTDlg* fftdstdlg = new CFFTDlg;
	IplImage *FFTImg, *FFTDstImg;
	FFTImg = cvCreateImage(cvSize(Img->width, Img->height), Img->depth, Img->nChannels);
	FFTDstImg = cvCreateImage(cvSize(Img->width, Img->height), Img->depth, Img->nChannels);
	outfft(Img, FFTImg, FFTDstImg);
	fftdlg->Create(IDD_FFTDLG, this);
	fftdlg->ShowWindow(SW_SHOW);
	fftdlg->SetFFTImage(FFTImg);
	fftdstdlg->Create(IDD_FFTDLG, this);
	fftdstdlg->ShowWindow(SW_SHOW);
	fftdstdlg->SetFFTImage(FFTDstImg);
	cvReleaseImage(&FFTImg);
	cvReleaseImage(&FFTDstImg);
}


void CAboutDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}

void CPicDealDlg::ChangeSize(UINT nID, int x, int y)
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
	GetClientRect(&Init_rect);
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CPicDealDlg::OnRgb2gray()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 1);
	cvCvtColor(Img, NewImage, CV_BGR2GRAY);
	cvCvtColor(NewImage, Img, CV_GRAY2RGB);
	if (!NewImage || !NewImage->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnLaplacesharpness()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	lapulasi(Img, NewImage);
	if (!NewImage || !NewImage->imageData) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	cvReleaseImage(&Img);
	Img = NewImage;
	Invalidate(1);
	drawpic(Img, IDC_PICSHOW);
}


void CPicDealDlg::OnEdgedet()
{
	// TODO: 在此添加命令处理程序代码
	if (!Img) {
		MessageBox(TEXT("ERROR!"));
		return;
	}
	IplImage* NewImage;
	NewImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 3);
	IplImage* tempImage;
	tempImage = cvCreateImage(cvGetSize(Img), IPL_DEPTH_8U, 1);
	double threshold1 = 0, threshold2 = 0;
	int size;
	bool prepro;
	CCannyDlg* candlg = new CCannyDlg;
	if (IDOK == candlg->DoModal()) {
		threshold1 = candlg->m_threshold1;
		threshold2 = candlg->m_threshold2;
		size = candlg->m_size;
		prepro = candlg->m_prepro;
	}
	mcvCanny(Img, tempImage, threshold1, threshold2, size, prepro);
	cvCvtColor(tempImage, NewImage, CV_GRAY2RGB);
	CCannyShowDlg* canshodlg = new CCannyShowDlg;
	canshodlg->Create(IDD_CANNYSHOW, this);
	canshodlg->ShowWindow(SW_SHOW);
	canshodlg->SetCannyImage(NewImage);
}
