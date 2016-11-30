#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM); //prototype, realization on the bottom

/*  Make the class name into a global variable  */
char szClassName[ ] = "MyWindow";

int WINAPI WinMain (HINSTANCE hThisInstance, //handle to the instance of the program you are writing
                    HINSTANCE hPrevInstance, //used if your program had any previous instance. If not, this argument can be ignored
                    LPSTR lpszArgument, //string that represents all items used on the command line to compile the application
                    int nFunsterStil) //controls how the window you are building will be displayed

{
    HWND hwnd;               /* This is the handle for our window */
    //handle is object/class/process/window identifier
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */ //class for creating the main window
    //To create a window, you must "fill out" this class, which means you must provide a value for each of its members 
    //so the operating system would know what your program is expected to do.
    

    /* The Window structure */
    wincl.hInstance = hThisInstance; //HINSTANCE hThisInstance from WinMain
    //Creating an application is equivalent to creating an instance for it. 
    //To communicate to the  WinMain() function that you want to create an instance for your application, which is, 
    //to make it available as a resource, assign the WinMain()'s  hInstance argument to your  WNDCLASSEX variable
    
    wincl.lpszClassName = szClassName; //char szClassName[ ] = "MyWindow";
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX); //After declaring a WNDCLASSEX variable, you must specify its size. 
    //This is done by  initializing your variable with the sizeof operator applied to the window class

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    //Upon declaring a  WNDCLASSEX variable, the compiler allocates an amount of memory space for it, as it does for all other variables.
    //If you think you will need more memory than allocated, assign the number of extra bytes to the  cbClsExtra member variable. 
    //Otherwise, the compiler initializes this variable to 0. 
    //If you do not need extra memory for your  WNDCLASSEX variable, initialize this member with 0
    wincl.cbWndExtra = 0;                      /* structure or the window instance */    
    //When an application has been launched and is displaying on the screen, which means an instance
    //of the application has been created, the operating system allocates an amount of memory space for that application to use. 
    //If you think that your application's instance will need more memory than that, 
    //you can request that extra memory bytes be allocated to it. 
    //Otherwise, you can let the operating system handle this instance memory issue and initialize the  cbWndExtra member variable to 0
    
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "MyWindow",       /* Title Text */
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

//A computer application is equipped with Windows controls that allow the user to interact with the computer. 
//Each control creates messages and sends them to the operating system. To manage these messages, 
//they are handled by a function pointer called a Windows procedure.

//This function uses a switch control to list all necessary messages and process each one in turn. 
//This processes only the messages that you ask it to. If you have left-over messages, and you will always 
//have un-processed messages, you can call the DefWindowProc() function at the end to take over.

//The most basic message you can process is to make sure a user can close a window after using it. 
//This can be done with a function called PostQuitMessage().
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            //This function takes one argument which is the value of the  LPARAM argument. 
            //To close a window, you can pass the argument as WM_QUIT.
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
