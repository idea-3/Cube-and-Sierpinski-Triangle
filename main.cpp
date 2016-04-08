#include <windows.h>
#include <gl/gl.h>
#include "Enable.h"
#include "Draw.h"
#include "Disable.h"

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


GLboolean bQuit = GL_FALSE;

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HWND hwnd2;
    HDC hDC;
    HDC hDC2;
    HGLRC hRC;
    HGLRC hRC2;
    MSG msg;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "Hello Triangle Solid",
                          WS_OVERLAPPEDWINDOW,
                          300,
                          0,
                          730,
                          730,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);
    hwnd2 = CreateWindowEx(0,
                          "GLSample",
                          "Hello Triangle Gradient",
                          WS_OVERLAPPEDWINDOW,
                          300,
                          0,
                          730,
                          730,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    ShowWindow(hwnd2, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);
    EnableOpenGL(hwnd2, &hDC2, &hRC2);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
                TranslateMessage(&msg);
                DispatchMessage(&msg);
        }
        wglMakeCurrent(hDC, hRC);
        drawHandleSolid(hDC);
        wglMakeCurrent(hDC2, hRC2);
        drawHandleGradient(hDC2);
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);
    DisableOpenGL(hwnd2, hDC2, hRC2);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);
    DestroyWindow(hwnd2);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    bQuit = GL_TRUE;
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}




