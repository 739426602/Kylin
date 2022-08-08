#include "WindowsApplication.h"

namespace kylin 
{
	WindowsApplication g_App;
	IApplication* g_pApp = &g_App;
}

int kylin::WindowsApplication:: Initialize()
{
	int result;
	result = BaseApplication::Initialize();

    if (result != 0)
        exit(result);
	
	HINSTANCE hInstance = GetModuleHandle(NULL);
	
	// Register the window class.

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = _T("Hello Kylin");

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        _T("Hello Kylin"),                     // Window class
        _T("Kylin"),    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }
	
	ShowWindow(hwnd, SW_SHOW);

    return result;
}

void kylin::WindowsApplication:: Tick()
{
	// this struct holds Windows event messages
    MSG msg;

    // we use PeekMessage instead of GetMessage here
    // because we should not block the thread at anywhere
    // except the engine execution driver module 
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        // translate keystroke messages into the right format
        TranslateMessage(&msg);

        // send the message to the WindowProc function
        DispatchMessage(&msg); 
    }
}

void kylin::WindowsApplication:: Finalize()
{

}

LRESULT CALLBACK kylin::WindowsApplication:: WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        BaseApplication::m_bQuit = true;
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}