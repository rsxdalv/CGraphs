#include <windows.h>
#include <math.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "3D grafika";

HPEN linePen;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
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
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(212,208,160));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "3D kubs",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

const  int  cube[3][8] ={
    1, 1, 1,
    -1, 1, 1,
    -1,-1, 1,
     1,-1, 1,
     1, 1,-1,
    -1, 1,-1,
    -1,-1,-1,
     1,-1,-1};

float ax=0,ay=0,az=0;

HDC hdc;
int scale=50;

const float step=0.39269908169872415480783042290994;

void drawStep()
{
/*
X(3D)
Y(3D)8
Z(3D)
Yt = Y * COS(Xan) - Z * SIN(Xan)		//Xan, Yan, Zan - radianos
Zt = Y * SIN(Xan) + Z * COS(Xan)
Y = Yt
Z = Zt
Xt = X * COS(Yan) - Z * SIN(Yan)
Zt = X * SIN(Yan) + Z * COS(Yan)
X = Xt
Z = Zt
Xt = X * COS(Zan) - Y * SIN(Zan)
Yt = X * SIN(Zan) + Y * COS(Zan)
X = Xt
Y = Yt
X(2D)
Y(2D)
*/
SelectObject(hdc, linePen);

float tx=0,ty=0,tz=0;
float xp=0,yp=0,zp=0;
int cube2[2][8];
for(int k=0;k<8;k++)
{
    xp=cube[0][k]*scale;
    yp=cube[1][k]*scale;
    zp=cube[2][k]*scale;
    ty=yp*cos(ax) -zp*sin(ax);
    tz=yp*sin(ax) +zp*cos(ax);
    yp=ty;
    zp=tz;
    tx=xp*cos(ay) - zp*sin(ay);
    tz=xp*sin(ay) + zp*cos(ay);
    xp=tx;
    zp=tz;
    tx=xp*cos(az) - yp*sin(az);
    ty=xp*sin(az) + yp*cos(az);
    cube2[0][k]=tx;
    cube2[1][k]=ty;
}

MoveToEx(hdc,cube2[0][7]+150,cube2[1][7]+100   ,NULL);
            // Aiziet uz 1. virsotni
            //MoveToEx(hdc,10,10,NULL);
            //savilkt kubu
            //LineTo(hdc,200,200);
for(int k=0;k<8;k++)
{
    LineTo(hdc,cube2[0][k]+150,cube2[1][k]+100);
}

};

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    PAINTSTRUCT ps;
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            linePen=CreatePen(PS_SOLID,1,RGB(0,0,155));
            break;

        case WM_DESTROY:
            DeleteObject(linePen);
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;


        case WM_CHAR:
            switch (wParam)
            {
                case ('a'):
                case ('A'):
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    az+=step;
                    drawStep();
                    break;
                case ('s'):
                case ('S'):
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    az-=step;
                    drawStep();
                    break;

            }
            break;


        case WM_KEYDOWN:
            switch (wParam)
            {
                    case VK_LEFT:
                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd,NULL,TRUE);
                        ax+=step;
                        drawStep();
                        break;

                    case VK_RIGHT:
                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd,NULL,TRUE);
                        ax-=step;
                        drawStep();
                        break;

                    case VK_UP:

                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd, NULL, TRUE);
                        ay+=step;
                        drawStep();
                        break;
                    case VK_DOWN:

                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd, NULL, TRUE);
                        ay-=step;
                        drawStep();
                        break;
            }
            break;



        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            drawStep();

            ReleaseDC(hwnd,hdc); //The ReleaseDC function releases a device context (DC), freeing it for use by other applications
            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
