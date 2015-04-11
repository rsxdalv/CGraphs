#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

HPEN bluePen;  // blue pen
HPEN greenPen; // green pen

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    //handle is object/class/process/window identifier
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
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

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


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  HDC hdc; 
  //Device Context Handle - object where we can draw (window/file/printer/memory). A handle to the display DC to be used for painting.
  //handle is object/class/process/window identifier
  PAINTSTRUCT ps; 
  //The PAINTSTRUCT structure contains information for an application. This information can be used to paint the client area of a window owned by that application.
  //http://msdn.microsoft.com/en-us/library/dd162768(v=VS.85).aspx
  
  
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            bluePen = CreatePen(PS_SOLID,1,RGB(0,0,255));  // create blue pen
            greenPen = CreatePen(PS_SOLID,1,RGB(0,255,0));  // create green pen
            break;
        case WM_DESTROY:
            DeleteObject(bluePen);
            DeleteObject(greenPen);  // killing pens
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps); // get device context
            //we need window identifier and paint info
            
            SetPixel(hdc,25,25,RGB(255,0,0)); // draw red pixel
            
            SelectObject(hdc, bluePen);  // select blue pen
            MoveToEx(hdc,10,10,NULL);  // draw blue line (40,50)-(100,100)
            for(int k=0;k<20;k++)
            {
                LineTo(hdc,10+5*k,10+5*k*k);
            }    
            //LineTo(hdc,200,200);
            
            SelectObject(hdc,greenPen); // select green pen
            SelectObject(hdc,GetStockObject(HOLLOW_BRUSH)); // don't fill
            Rectangle(hdc,50,70,190,250); // draw transparent green rectangle
            
            ReleaseDC(hwnd,hdc); //The ReleaseDC function releases a device context (DC), freeing it for use by other applications
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
