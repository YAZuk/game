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

//#include <gl\glut.h>

//#include <GL\freeglut.h>
//#include <gl>

#include "Unit.h"
#include "Archer.h"
#include "Transport.h"


//static void RenderSceneCB() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glutSwapBuffers();
//}
//
//static void InitializeGlutCallbacks() {
//    glutDisplayFunc(RenderSceneCB);
//}


const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
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

    //Step 1: Registering the Window Class
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

    // Step 2: Creating the Window
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





    // Step 3: The Message Loop
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}


//int main(int argc, char **argv) {
//
////    glGetString(GL_VERSION);
////    glutInit(&argc, argv);
////    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
////    glutInitWindowSize(1024, 768);
////    glutInitWindowPosition(100, 100);
////    glutCreateWindow("Tutorial 01");
////
//////    InitializeGlutCallbacks();
////    glutDisplayFunc(RenderSceneCB);
////
////    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
////
////    glutMainLoop();
//
//    auto car = std::make_unique<unit::Transport>();
//
//    assert(car->getSpeed() >= 0.0);
//
//    auto car2 = dynamic_cast<unit::Unit *> (car.get());
//
//    assert(car2);
//
//    assert(car.get() == car2);
//
//    car2 = std::move(car.get());
//
//    car2->go();
//
//    car2->fly();
//
//    car2->getLevel();
//
//    return 0;
//}


//int main(int argc, char **argv) {
//    // Инициализация GLUT
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowPosition(100,100);
//    glutInitWindowSize(400,400);
//    glutCreateWindow("Урок 1");
//    glutMainLoop();
//
////    auto car = std::make_unique<unit::Transport>();
////
////    assert(car->getSpeed() >= 0.0);
////
////    auto car2 = dynamic_cast<unit::Unit *> (car.get());
////
////    assert(car2);
////
////    assert(car.get() == car2);
////
////    car2 = std::move(car.get());
////
////    car2->go();
////
////    car2->fly();
////
////    car2->getLevel();
//
//    return 0;
//}
