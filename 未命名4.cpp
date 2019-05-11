#define _UNICODE
#define UNICODE
#include <Windows.h>
#include <tchar.h>
#include <Mmsystem.h>
 
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")
 
#pragma comment(linker, "/subsystem:windows,5.1.2600")
 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
 
BOOL WINAPI SetWindowCenter(HWND hwnd)
{
   UINT uFlags;
   RECT stRect = { 0 };
 
   INT x = GetSystemMetrics(SM_CXSCREEN);   
   INT y = GetSystemMetrics(SM_CYSCREEN);
 
   GetWindowRect(hwnd, &stRect); // 获取窗口当前的位置
 
   __asm
   {
      pushad
      mov eax, stRect.right
      sub eax, stRect.left     ; eax保存的是窗口的宽度
      mov ebx, x
      sub ebx, eax
      shr ebx, 1
      mov stRect.left, ebx     ; 窗口左上角x坐际 = (屏幕宽 - 窗口宽) / 2
      mov eax, stRect.bottom
      sub eax, stRect.top      ; eax保存的是窗口的高度
      mov ebx, y
      sub ebx, eax
      shr ebx, 1
      mov stRect.top, ebx      ; 窗口左上角y坐际 = (屏幕高 - 窗口高) / 2
      popad
   }
 
   uFlags = SWP_NOSIZE | SWP_NOZORDER | SWP_SHOWWINDOW;
   // 宽度和高度参数为零时则保持原样不变
   return SetWindowPos(hwnd, NULL, stRect.left, stRect.top, 0, 0, uFlags); // 重新设置窗口的位置
}
 
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR szCmdLine, int iCmdShow)
{
   static TCHAR szAppName[] = TEXT("HelloWin");
   HWND         hwnd;
   MSG          msg;
   WNDCLASS     wndclass;
    
   RtlZeroMemory(&wndclass, sizeof(wndclass));
   wndclass.style         = CS_HREDRAW | CS_VREDRAW;
   wndclass.lpfnWndProc   = WndProc;
   //wndclass.cbClsExtra    = 0;
   //wndclass.cbWndExtra    = 0;
   wndclass.hInstance     = hInstance;
   //wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION); //#define IDI_APPLICATION MAKEINTRESOURCE(32512)
   //wndclass.hIcon         = LoadIcon(NULL, MAKEINTRESOURCE(32512));
   wndclass.hIcon         = LoadIcon(NULL, TEXT("#32512"));
   wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wndclass.lpszMenuName  = NULL;
   wndclass.lpszClassName = szAppName;
    
   if (!RegisterClass(&wndclass))
   {
      MessageBox(NULL, 
                 TEXT("This program requires Windows NT series!"), 
                 szAppName,
                 MB_ICONERROR);
      return 0;
   }
    
    
   hwnd = CreateWindowEx(WS_EX_TOOLWINDOW,         // A tool window does not appear in the task bar or in the window that appears when the user presses ALT+TAB.
                       szAppName,                  // window class name
                       TEXT("The Hello Program"),  // window caption
                       WS_OVERLAPPEDWINDOW,        // window style
                       10,//CW_USEDEFAULT,              // initial x position
                       200,//CW_USEDEFAULT,              // initial y position
                       320,//CW_USEDEFAULT,              // initial x size
                       320,//CW_USEDEFAULT,              // initial y size
                       NULL,                       // parent window handle
                       NULL,                       // window menu handle
                       hInstance,                  // program instance handle
                       NULL);                      // creation parameters
 
   SetWindowCenter(hwnd);
   ShowWindow(hwnd, SW_SHOW);
   UpdateWindow(hwnd);
      
   {
      BOOL bRet;
      while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
      {
         if (bRet == -1)
          {
            MessageBox(NULL, 
                       TEXT("GetMessage Error."), 
                       szAppName,
                       MB_ICONERROR);
            return -1;
          }
          else
          {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
          }
      }
   }
    
   return msg.wParam;
}
 
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   HDC         hdc;
   PAINTSTRUCT ps;
   RECT        rect;
    
   switch (message)
   {
      case WM_CREATE:
         PlaySound(TEXT("Hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
         return 0L;
       
      case WM_PAINT:
         hdc = BeginPaint(hwnd, &ps);
       
         GetClientRect(hwnd, &rect);
         DrawText(hdc, TEXT("Hello, Windows 98!"), -1, &rect,
                  DT_SINGLELINE | DT_CENTER | DT_VCENTER);
         EndPaint(hwnd, &ps);
         return 0L;
       
      case WM_DESTROY:
         PostQuitMessage(0);
         return 0L;
   }
   return DefWindowProc(hwnd, message, wParam, lParam);
}
