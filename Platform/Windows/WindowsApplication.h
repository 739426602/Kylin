#pragma once
#include <windows.h>
#include <tchar.h>
#include "stdafx.h"
#include "BaseApplication.h"

namespace kylin
{
	class WindowsApplication : public BaseApplication
	{
	public:
		WindowsApplication() :BaseApplication() {};
		virtual int Initialize();
		virtual void Finalize();

		virtual void Tick();
		
		virtual void CreateMainWindow();
		
		inline HWND GetMainWindowHandler() { return m_hwnd; }

		static LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);
			
	protected:
		HWND m_hwnd;

	public:
		UINT width = 1280;
		UINT height = 720;
		std::wstring name = L"Kylin";

	};
}