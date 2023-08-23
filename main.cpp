#include <iostream>
#include <cassert>
#include <memory>
#include <unordered_map>
#include <mutex>
#include <semaphore>
#include <pthread.h>
#include <thread>

#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <gl\wgl.h>

#include <windows.h>
#include <dwmapi.h>
#include <ws2tcpip.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <winsock2.h>


#include "Unit.h"
#include "Archer.h"
#include "Transport.h"

#define DWMWA_MICA_EFFECT DWORD(1029)

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_QUESTION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            g_szClassName,
            "The title of my window",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
            NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);


    auto car = std::make_unique<unit::Transport>();

    assert(car->getSpeed() >= 0.0);

    auto car2 = dynamic_cast<unit::Unit *> (car.get());

    assert(car2);

    assert(car.get() == car2);

    car2 = std::move(car.get());

    car2->go();

    car2->fly();

    car2->getLevel();


    /*----------------------------------------------------*/
    /*
     * Функция WSAStartup инициирует использование библиотеки DLL Winsock процессом.
     */

    WSADATA wsaData;
    ZeroMemory(&wsaData, sizeof(wsaData));
    int nResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (nResult != 0) {
        printf(TEXT("WSAStartup function failed, value: %d\n"), nResult);
        Sleep(5000);
        return 0001;
    } else
        printf(TEXT("WSAStartup function has succeeded! value: %d\n"), nResult);
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    nResult = getaddrinfo("rootbrains.ru", "http", &hints, &result);

    if (nResult != 0) {
        printf("getaddrinfo did not return 0... failure...");
        WSACleanup();
        return 0002;
    }

    SOCKET ListenSocket = INVALID_SOCKET;
    freeaddrinfo(result);
    /*----------------------------------------------------*/



    // Step 3: The Message Loop
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
