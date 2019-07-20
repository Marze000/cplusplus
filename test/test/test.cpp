#pragma once
#include "UIlib.h"
using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "F:\\c_exercise\\xiaomaze\\test\\test\\lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetText(_T("Hello World"));   // 设置文字
			pWnd->SetBkColor(0xFF00FF00);       // 设置背景色

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};
#endif
//================================================

#if 0
class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { 
		return _T("DUIMainFrame");
	}
	virtual void    Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;

		if (uMsg == WM_CREATE)
		{
			m_PaintManager.Init(m_hWnd);

			CDialogBuilder builder;
			CControlUI* pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager);   
			// duilib.xml需要放到exe目录下
			ASSERT(pRoot && "Failed to parse XML");

			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this); 
			// 添加控件等消息响应，这样消息就会传达到duilib的消息循环，
			//我们可以在Notify函数里做消息处理
			return lRes;

#if 0
			CControlUI *pWnd = new CButtonUI;
			// 设置控件的名称，这个名称用于标识每一个控件，
			//必须唯一，相当于MFC里面的控件ID	
			pWnd->SetName(_T("btnHello"));      

			pWnd->SetText(_T("Hello World"));   // 设置文字
			pWnd->SetBkColor(0xFF00FF00);       // 设置背景色
			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);

			m_PaintManager.AddNotifier(this); 
			// 添加控件等消息响应，这样消息就会传达到duilib的消息循环，
			//我们可以在Notify函数里做消息处理
			return lRes;
#endif
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   
	// 设置资源的默认路径（此处设置为和exe在同一目录）

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();//居中显示
	duiFrame.ShowModal();
	return 0;
}
#endif	

#if 0
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { 
		return _T("DUIMainFrame_Maze");
	}
	virtual CDuiString GetSkinFile(){ 
		return _T("duilib.xml"); 
	}

	virtual CDuiString GetSkinFolder(){ 
		return _T("");
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}
#endif

#if 0
class CDuiFramWnd : public CWindowWnd , public INotifyUI
{
public:
	// CWindowWnd类的纯虚函数，在该函数中必须返回用户所定义窗口的类名称，
	//注册窗口时需要用到
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}

	//创建一个按钮
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			// 创建一个按钮
			CControlUI *pWnd = new CButtonUI;
			// 设置按钮上的显示文本
			pWnd->SetText(_T("Hello World"));
			// 按钮的背景颜色
			pWnd->SetBkColor(0xFF00FF00);

			// 初始化m_PaintManager对象的窗口句柄，发送消息时需要用到	
			m_PaintManager.Init(m_hWnd);
			// 将按钮关联到绘制管理器上
			m_PaintManager.AttachDialog(pWnd);

			// 添加控件等消息响应，这样消息就会传达到duilib的消息循环，
			// 就可以在Notify函数里做消息处理
			m_PaintManager.AddNotifier(this);

			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
		// 注意：__super为vs扩展的一个关键字，意思是调用基类的成员
		// 用户将WM_CREATE消息处理后，其他消息交给其基类HandleMessage
		//方法进行处理
		return __super::HandleMessage(uMsg, wParam, lParam);
	}

	// 对基类 Notify 虚函数进行重写
	virtual void Notify(TNotifyUI& msg){
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("Hello Maze"), _T("DuiFramWnd"), IDOK);
		}
	}

private:
	CPaintManagerUI m_PaintManager;
};
#endif
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("Cashier.xml"); }
	virtual CDuiString GetSkinFolder() { return _T(""); }
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("Hello World"), _T("DuiFramWnd"), IDOK);
		}
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CDuiFramWnd framWnd;
	// Cashier即在窗口右上角显式的名字
	// UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，
	//具有标题栏，最大化最小化，关闭功能等
	// WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("Cashier"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);//显示窗口，激活消息循环
	framWnd.ShowModal();

	return 0;
}