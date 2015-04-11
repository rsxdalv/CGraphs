#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

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
    //wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(212,208,200));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Windows App",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           640,                 /* The programs width */
           480,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    
    //ShowWindow(hwnd, SW_SHOW); 
    //UpdateWindow(hwnd);

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


int x1=60,y1=150,x2=110,y2=200;
HPEN bluePen;  // blue pen
HPEN greyPen; // grey pen
HDC hdc;
  //Device Context Handle - object where we can draw (window/file/printer/memory). A handle to the display DC to be used for painting.
  //handle is object/class/process/window identifier
PAINTSTRUCT ps;
  //The PAINTSTRUCT structure contains information for an application. This information can be used to paint the client area of a window owned by that application.
  //http://msdn.microsoft.com/en-us/library/dd162768(v=VS.85).aspx
const UINT idTimer1 = 1;
UINT nTimerDelay = 5;
int step = 1;
HBRUSH brush;


void draw(HPEN pen)
{
    SelectObject(hdc, brush);  // aizpildiisanas krasa
    SelectObject(hdc, pen);  // ziimula krasa
    Ellipse(hdc, x1, y1, x2, y2);
}


void calc()
{
    if (x1<700)
    {
        x1=x1+step;
        x2=x2+step;
    }
    else
    {
        x1=-60;
        x2=-10;
    }        
}



/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        
        case WM_CREATE:
            bluePen = CreatePen(PS_SOLID,3,RGB(0,0,255));  // create blue pen
            greyPen = CreatePen(PS_SOLID,3,RGB(212,208,200));  // create green pen
            brush = CreateSolidBrush(RGB(212,208,200));
            SetTimer(hwnd, idTimer1, nTimerDelay, NULL);
            //If you specify a window handle in the call to SetTimer, the application associates the timer with that window. 
            //Whenever the time-out value for the timer elapses, the system posts a WM_TIMER message to the window associated with the timer.
            break;
            
        case WM_DESTROY:
            DeleteObject(bluePen);
            DeleteObject(greyPen);  // killing pens
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            KillTimer(hwnd, idTimer1);
            break;
            
        case WM_CHAR:
            switch (wParam)
            {
                case ('w'):
                case ('W'):
                    InvalidateRect(hwnd, NULL, TRUE); 
                    //The InvalidateRect function adds a rectangle to the specified window's update region. 
                    //The update region represents the portion of the window's client area that must be redrawn. 
                    //http://msdn.microsoft.com/en-us/library/dd145002(v=VS.85).aspx
                    UpdateWindow(hwnd);
                    //The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message 
                    //to the window if the window's update region is not empty. 
                    //The function sends a WM_PAINT message directly to the window procedure of the specified window, 
                    //bypassing the application queue. If the update region is empty, no message is sent.

                    y1=y1-step;
                    y2=y2-step;
                    draw(bluePen);
                    break;
                case ('s'):
                case ('S'):
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);

                    y1=y1+step;
                    y2=y2+step;
                    draw(bluePen);
                    break;
                
            }    
            break;
            
        case WM_KEYDOWN:
            switch (wParam)
            {
                    //case VK_LEFT:
                    //break;
                    //case VK_RIGHT:
                    //break;
                    case VK_UP:
                        
                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd, NULL, TRUE);

                        y1=y1-step;
                        y2=y2-step;
                        draw(bluePen);
                        break;
                    case VK_DOWN:
                        
                        UpdateWindow(hwnd);
                        InvalidateRect(hwnd, NULL, TRUE);
                        y1=y1+step;
                        y2=y2+step;
                        draw(bluePen);
                        break;
            }
            break;       
            
        case WM_TIMER: //http://msdn.microsoft.com/en-us/library/windows/desktop/ms644900(v=vs.85).aspx
            hdc = GetDC(hwnd); //This function retrieves a handle to a display device context (DC) for the client area of the specified window. 
            //The display device context can be used in subsequent graphics display interface (GDI) functions to draw in the client area of the window.
            draw(greyPen);
            calc();
            draw(bluePen);
            ReleaseDC(hwnd, hdc);
            break; 
        
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps); // get device context  
            //The BeginPaint function prepares the specified window for painting and fills a PAINTSTRUCT structure with information about the painting.
            //http://msdn.microsoft.com/en-us/library/dd183362(v=VS.85).aspx     
            draw(bluePen);        
            EndPaint(hwnd, &ps); //The EndPaint function marks the end of painting in the specified window. 
            //This function is required for each call to the BeginPaint function, but only after painting is complete.    
            break;
            
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
