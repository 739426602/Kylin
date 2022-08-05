#pragma once
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
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

		static LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);

	};
}