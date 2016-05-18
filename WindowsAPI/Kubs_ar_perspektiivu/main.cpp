#include <windows.h>
#include <math.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

HPEN bluePen;
/*
x  y  z
*/
int static_cube[8][3] = {
1, 1, 1,
-1, 1, 1,
-1,-1, 1,
1,-1, 1,
1, 1,-1,
-1, 1,-1,
-1,-1,-1,
1,-1,-1
};
double nobiideX = 0, nobiideY = 0, nobiideZ = 0;
double Xan = 0,Yan = 0,Zan = 0;
double cube2d[8][3], perspective = 100;
int rotateCube(char, double);
int redraw(HWND,HDC,PAINTSTRUCT, HPEN);
template <class t>
t mod(t nr, t md)
{
    int temp = (int)(nr/md);
    return (nr - (md*(int)(nr/md)));
}

//int current_cube[8][3];

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "ZR: 3D Cube, Perspective",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           660,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    ShowWindow (hwnd, nFunsterStil);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 
    PAINTSTRUCT ps;
    
    switch (message)
    {
        case WM_CREATE:
            hdc = BeginPaint(hwnd, &ps);
            bluePen = CreatePen(PS_SOLID,1,RGB(0,0,200));  // create blue pen
            rotateCube('x', 0);
            redraw(hwnd,hdc,ps,bluePen);
            break;
        case WM_DESTROY:
            DeleteObject(bluePen);
            ReleaseDC(hwnd,hdc);
            PostQuitMessage(0); /* send a WM_QUIT to the message queue */
            break;
        case WM_PAINT:
            redraw(hwnd,hdc,ps,bluePen);
            break;
        case WM_CHAR:
            switch (wParam)
            {
                case ('a'):
                case ('A'):
                    rotateCube('z', -0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('s'):
                case ('S'):
                    rotateCube('z', 0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('-'):
                    if(perspective < 100)
                        perspective *=1.3;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('+'):
                    if(perspective > 2)
                        perspective /=1.3;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('u'):
                    nobiideZ+=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('g'):
                    nobiideY+=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('h'):
                    nobiideX+=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('j'):
                    nobiideZ-=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('f'):
                    nobiideX-=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('t'):
                    nobiideY-=0.5;
                    rotateCube('z', 0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
            }
            break;
        case WM_KEYDOWN:
            switch (wParam)
            {
                case VK_LEFT:
                    rotateCube('y', -0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case VK_RIGHT:
                    rotateCube('y', 0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case VK_UP:
                    rotateCube('x', 0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case VK_DOWN:
                    rotateCube('x', -0.1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
            }
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

int rotateCube(char axis, double angle)
{
    switch(axis)
    {
    case 'x':
    case 'X':
        Xan = (Xan+angle);//%(2*(3.14159));
        break;
    case 'y':
    case 'Y':
        Yan = (Yan+angle);//%(2*(Math::PI));
        break;
    case 'z':
    case 'Z':
        Zan = (Zan+angle);//%(2*(Math::PI));
        break;
    default:
        break;
    }
    double Xt,Yt,Zt,X,Y,Z;
    for(int i=0;i<8;i++)
    {
        X = static_cube[i][0] + nobiideX;
        Y = static_cube[i][1] + nobiideY;
        Z = static_cube[i][2] + nobiideZ;
        
        Yt = Y*cos(Xan) - Z*sin(Xan);
        Zt = Y*sin(Xan) + Z*cos(Xan);
        Y = Yt;
        Z = Zt;
        Xt = X*cos(Yan) - Z*sin(Yan);
        Zt = X*sin(Yan) + Z*cos(Yan);
        X = Xt;
        Z = Zt;
        cube2d[i][0] = perspective*(X*cos(Zan) - Y*sin(Zan))/(Z+perspective);
        cube2d[i][1] = perspective*(X*sin(Zan) + Y*cos(Zan))/(Z+perspective);
    }
    return 1;
}

int redraw(HWND hwnd, HDC hdc, PAINTSTRUCT ps, HPEN bluePen)
{
    hdc = BeginPaint(hwnd, &ps);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i==j)
                continue;
            if(static_cube[i][0]==static_cube[j][0] && static_cube[i][1]==static_cube[j][1] || static_cube[i][2]==static_cube[j][2] && static_cube[i][0]==static_cube[j][0] || static_cube[i][2]==static_cube[j][2] && static_cube[i][1]==static_cube[j][1])
            {
                SelectObject(hdc, bluePen);
                MoveToEx(hdc,(int)(90*cube2d[i][0]+320),(int)(90*cube2d[i][1]+240),NULL);// draw blue line (40,50)-(100,100)
                LineTo(hdc,(int)(90*cube2d[j][0]+320),(int)(90*cube2d[j][1]+240));
            }
        }
    }
}
