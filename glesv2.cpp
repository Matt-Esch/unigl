#include <iostream>
#include <windows.h>

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#pragma comment (lib, "user32.lib")
#pragma comment (lib, "bin/debug/windows/x86/libEGL.dll.lib")
#pragma comment (lib, "bin/debug/windows/x86/libGLESv2.dll.lib")

EGLContext eglContext;
EGLDisplay eglDisplay;
EGLSurface eglSurface;

void initGLES2(HWND hwnd);
void renderFrame(void);
void cleanGLES2(void);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    HWND hwnd;
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = L"WindowClass";

    RegisterClassEx(&wc);

    hwnd = CreateWindowEx(
        NULL,
        L"WindowClass",
        L"Our First GLESv2 Program",
        WS_OVERLAPPEDWINDOW,
        300, 300,
        800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);


    initGLES2(hwnd);

    MSG msg;
    bool loop = true;

    while(loop)
    {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT) {
                loop = false;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        renderFrame();
    }

    cleanGLES2();

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            } break;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}


// this function initializes and prepares Direct3D for use
void initGLES2(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);

    // Create EGL display connection
    eglDisplay = eglGetDisplay(hdc);

    // Initialize EGL for this display, returns EGL version
    EGLint eglVersionMajor, eglVersionMinor;
    eglInitialize(eglDisplay, &eglVersionMajor, &eglVersionMinor);

    eglBindAPI(EGL_OPENGL_ES_API);

    EGLint configAttributes[] =
    {
    	EGL_BUFFER_SIZE, 0,
    	EGL_RED_SIZE, 8,
    	EGL_GREEN_SIZE, 8,
    	EGL_BLUE_SIZE, 8,
    	EGL_ALPHA_SIZE, 8,
    	EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
    	EGL_DEPTH_SIZE, 24,
    	EGL_LEVEL, 0,
    	EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
    	EGL_SAMPLE_BUFFERS, 0,
    	EGL_SAMPLES, 0,
    	EGL_STENCIL_SIZE, 0,
    	EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
    	EGL_TRANSPARENT_TYPE, EGL_NONE,
    	EGL_TRANSPARENT_RED_VALUE, EGL_DONT_CARE,
    	EGL_TRANSPARENT_GREEN_VALUE, EGL_DONT_CARE,
    	EGL_TRANSPARENT_BLUE_VALUE, EGL_DONT_CARE,
    	EGL_CONFIG_CAVEAT, EGL_DONT_CARE,
    	EGL_CONFIG_ID, EGL_DONT_CARE,
    	EGL_MAX_SWAP_INTERVAL, EGL_DONT_CARE,
    	EGL_MIN_SWAP_INTERVAL, EGL_DONT_CARE,
    	EGL_NATIVE_RENDERABLE, EGL_DONT_CARE,
    	EGL_NATIVE_VISUAL_TYPE, EGL_DONT_CARE,
    	EGL_NONE
    };

    EGLint numConfigs;
    EGLConfig windowConfig;
    eglChooseConfig(eglDisplay, configAttributes, &windowConfig, 1, &numConfigs);

    EGLint surfaceAttributes[] = { EGL_NONE };
    eglSurface = eglCreateWindowSurface(eglDisplay, windowConfig, hwnd, surfaceAttributes);

    EGLint contextAttributes[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
	eglContext = eglCreateContext(eglDisplay, windowConfig, NULL, contextAttributes);
}

void renderFrame(void)
{
    eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
    glClearColor(1.0, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    eglSwapBuffers(eglDisplay, eglSurface);
}


// this is the function that cleans up Direct3D and COM
void cleanGLES2(void)
{
    eglDestroyContext(eglDisplay, eglContext);
    eglDestroySurface(eglDisplay, eglSurface);
}