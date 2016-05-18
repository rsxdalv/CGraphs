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
// 1 - 5 1 - 2 1 - 4

float ax=0,ay=0,az=0;

HDC hdc;

const float step=0.19634954084936207740391521145497;

void drawStep()
{
int scale=5;
  int  cube[3][8] ={
    -10, 10, 10,
     10, 10,-10,
     10,-10, 10,
     10,-10,-10,
     10, 10, 10,
    -10, 10,-10, // !!!
    -10,-10,-10,
    -10,-10, 10
     };

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
    xp=cube[0][k];//*scale;
    yp=cube[1][k];//*scale;
    zp=cube[2][k];//*scale;
    ty=yp*cos(ax) - zp*sin(ax);
    tz=yp*sin(ax) + zp*cos(ax);
    yp=ty;
    zp=tz;
    tx=xp*cos(ay) - zp*sin(ay);
    tz=xp*sin(ay) + zp*cos(ay);
    xp=tx;
    zp=tz;
    tx=xp*cos(az) - yp*sin(az);
    ty=xp*sin(az) + yp*cos(az);
    cube2[0][k]=tx*scale;
    cube2[1][k]=ty*scale;
}

MoveToEx(hdc,cube2[0][0]+200,cube2[1][0]+150,NULL);
//LineTo(hdc,cube2[0][1]+200,cube2[1][1]+150);
//MoveToEx(hdc,cube2[0][1]+200,cube2[1][1]+150,NULL);
//LineTo(hdc,cube2[0][2]+200,cube2[1][2]+150);


            // Aiziet uz 1. virsotni
            //MoveToEx(hdc,10,10,NULL);
            //savilkt kubu
            //LineTo(hdc,200,200);
for(int i=0;i<8;i++)
{
    //LineTo(hdc,cube2[0][7-i]+200,cube2[1][7-i]+150);
}
int hue[8]={
    RGB(120,0,0),
    RGB(120,120,0),
    RGB(0,120,0),
    RGB(0,120,120),
    RGB(0,0,120),
    RGB(120,0,120),
    RGB(0,0,0),
    RGB(120,120,120)
};

for(int j=0;j<8;j++)
{
    SetPixel(hdc,cube2[0][j]+200,cube2[1][j]+150,hue[j]);
    SetPixel(hdc,cube2[0][j]+199,cube2[1][j]+149,hue[j]);
    SetPixel(hdc,cube2[0][j]+199,cube2[1][j]+151,hue[j]);
    SetPixel(hdc,cube2[0][j]+201,cube2[1][j]+149,hue[j]);
    SetPixel(hdc,cube2[0][j]+201,cube2[1][j]+151,hue[j]);
}


/*for(int j=0;j<8;j++)
{
    SetPixel(hdc,cube[0][j]*scale+200,cube[1][j]*scale+150,RGB(0,0,0));
    SetPixel(hdc,cube[0][j]*scale+199,cube[1][j]*scale+149,RGB(0,0,0));
    SetPixel(hdc,cube[0][j]*scale+199,cube[1][j]*scale+151,RGB(0,0,0));
    SetPixel(hdc,cube[0][j]*scale+201,cube[1][j]*scale+149,RGB(0,0,0));
    SetPixel(hdc,cube[0][j]*scale+201,cube[1][j]*scale+151,RGB(0,0,0));
}*/

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
