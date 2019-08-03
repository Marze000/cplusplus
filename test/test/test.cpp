#pragma once
#include "UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

class CDuiFrameWnd : public WindowImplBase{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString GetSkinFile() { 
		return _T("giff.xml");
	}
	//调出指定文件夹 里面放的是皮肤图片
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
	virtual void Notify(TNotifyUI& msg) {
		//鼠标点击的消息
		if (msg.sType == _T("click")) {
			CDuiString strControlName = msg.pSender->GetName();
			if (strControlName == _T("关闭窗口")) {
				Close();
			}
			else if (strControlName == _T("最小化窗口")) {
				SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
			}
			else if (strControlName== _T("加载文件")) {
				LoadFile();
			}
			else if (strControlName == _T("截取视频")) {
				CutView();
			}
			else if (strControlName == _T("BTN_GENERATE")) {
				//GenerateAssFile();
			}
			else if (strControlName == _T("BTN_LOADA_ASS")) {
				//LoadAss();
			}
			else if (strControlName == _T("生成gif")) {
				GenerateGifWithPic();
				//根据选择方式 图片 或 视频
				/*CComboBoxUI* pCombBox = (CComboBoxUI*)
				if (pCombBox->GetCurSel()) {
					GenerateGifWithPic();
				}
				else {
					GenerateGifWithView();
				}*/
			}
		}
		//窗口的初始化
		else if (msg.sType == _T("windowinit")) {
			m_pEditStart = (CEditUI*)m_PaintManager.FindControl(_T("起始时间"));//。。。
			m_pEditStart->SetMaxChar(8);
			m_pEditFinish = (CEditUI*)m_PaintManager.FindControl(_T("结束时间"));
			m_pEditFinish->SetMaxChar(8);

			//m_pRichEditUI = (CRichEditUI*)m_PaintManager.FindControl(_T("RICH_EDIT_WORD"));
		}
		//else if (msg.sType == _T("itemselect")) {
		//	if (strControlName == _T("List_Time_word")) {
		//		//将list 中选中的文本添加到 RichEdit
		//		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("LIST_TIME_WORD;"));
		//		CListTextElementUI* pItem = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel);
		//		CDuiString strWord = pItem->GetText(1);

		//		m_pRichEditUI->SetText(strWord);
		//	}
		//}
	}

	//加载文件的路径
	void LoadFile() {
		OPENFILENAME ofn;
		TCHAR FileName[MAX_PATH];
		memset(&ofn, 0, sizeof(OPENFILENAME));
		memset(FileName, 0, sizeof(char)*MAX_PATH);
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = _T("所有文件(*.*)\0*.bmp;*.tga;*.pcx;*.mp4;*.jpg;*.jpeg;*.gif\0");
		//ofn.lpstrFilter = _T("文本文档\0*.TXT");
		ofn.lpstrFile = FileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_FILEMUSTEXIST;
		//FileName得到用户所选择文件的路径 
		if (GetOpenFileName(&ofn)){
			MessageBox(NULL, FileName, NULL, NULL);
		}
	}
	//截取视频资源
	void CutView() {
		CDuiString strStartTime = m_pEditStart->GetText();
		if (!IsValidTime(strStartTime)) {
			MessageBox(m_hWnd,_T("起始时间有误"),_T("GIFF"),IDOK);
			return;
		}
		CDuiString strFinishTime = m_pEditFinish->GetText();
		if (!IsValidTime(strFinishTime)) {
			MessageBox(m_hWnd,_T("截止时间有误"),_T("GIFF"),IDOK);
			return;
		}

		//构造视频的命令
		CDuiString strCMD;
		strCMD += _T("ffmpeg -ss");
		strCMD += strStartTime;
		strCMD += _T(" -t ");
		strCMD += strFinishTime;
		strCMD += _T(" -i "); 

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("EDIF_PATH")))->GetText();
		strCMD += strViewPath;
		strCMD += _T("-vcodec copy - acodec copy output.avi");
		
		SendCMD(strCMD);
	}

	//调用 cmd 发送命令
	void SendCMD(const CDuiString& strCMD) {

		//1. 初始化结构体
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd.exe");

		// IpParameters 响应的是用户的命令
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE; //隐藏 cmd 窗口

		//2. 发送cmd命令
		ShellExecuteEx(&strSEInfo);
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
	}
	//获取当前工程路径
	void GenerateGifWithPic() {
		//获取到debug目录
		CDuiString strFFmpegPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD(_T("/c"));
		strCMD += strFFmpegPath;
		strCMD += _T("ffmprg\\ffmpeg -r 1 -i ");
		strCMD += strFFmpegPath;
		strCMD +=_T("ffmpeg\\Picture\\%d.jpg .\..\output.gif");

		//发送命令
		SendCMD(strCMD);
	}

	//构造视频生成的路径
	void GenerateGifWithView() {
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		CDuiString strCMD;
		strCMD += _T("/c");
		strCMD += _T("ffmpeg\\output.avi .\\..\\debug\\ffmpeg\\viewgif.gif");
		SendCMD(strCMD);
	}

	//检测输入时间的正确
	bool IsValidTime(const CDuiString& strTime) {
		if (8 != strTime.GetLength()) {
			return false;
		}
		for (int i = 0; i < 8; ++i) {
			if (':' == strTime[i]) {
				continue;
			}else if (isdigit(strTime[i])) {
				continue;
			}else {
				return false;
			}
		}
		return true;
	}
private:
	CEditUI* m_pEditStart;
	CEditUI* m_pEditFinish;
	CEditUI* m_pRichEditUI;
	int m_iSelect;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}
