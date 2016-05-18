#include <windows.h>
#include <math.h>
using namespace std;
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
char szClassName[ ] = "Kubs";
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    HWND hwnd;               
    MSG messages;           
    WNDCLASSEX wincl;   
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      
    wincl.style = CS_DBLCLKS;                 
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 
    wincl.cbClsExtra = 0;                      
    wincl.cbWndExtra = 0;             
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(219,238,225));
    if (!RegisterClassEx (&wincl))
        return 0;
    hwnd = CreateWindowEx (
           0,                   
           szClassName,         
           "Kubs",       
           WS_OVERLAPPEDWINDOW, 
           CW_USEDEFAULT,       
           CW_USEDEFAULT,       
           500,                 
           500,                 
           HWND_DESKTOP,       
           NULL,                
           hThisInstance,       
           NULL                 
           );
    ShowWindow (hwnd, nFunsterStil);
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

/* -------------------------------------------------------------------------------------
   ------------------------------------------------------------------------------------- */
int mKubs[8][3] = { 1,1,1, 
                    -1,1,1, 
                    -1,-1,1,
                    1,-1,1,
                    1,1,-1,
                    -1,1,-1,
                    -1,-1,-1,
                    1,-1,-1};
double temp[8][2] = {1,1,
                    -1,1,
                    -1,-1,
                    1,-1,
                    1,1,
                    -1,1,
                    -1,-1,
                    1,-1};
int mSavienot[8][3] = {1,3,4,
                    0,2,5,
                    1,3,6,
                    0,2,7,
                    5,7,0,
                    4,6,1,
                    5,7,2,
                    4,6,3};
int iKoef = 90;
double Xan = 0.0, Yan = 0.0, Zan = 0.0;

HPEN redCube;
HBRUSH brush;
HDC hdc;
PAINTSTRUCT ps;

void fPagriezt(int iAss = 0, int iPuse = 0) {
    double X,Y,Z;
    double Xt,Yt,Zt;
    double dLenkis;
     if (iPuse == 0)
     {
         dLenkis = 0.05;
     }
     else if (iPuse == 1)
     {
         dLenkis = -0.05;
     }
     
     if (iAss == 1)
     {
         Xan += dLenkis;
     }
     else if (iAss == 2)
     {
         Yan += dLenkis;
     }
     else if (iAss == 3)
     {
         Zan += dLenkis;
     }

   for (int a=0; a<8; a++) {
       X = mKubs[a][0];
       Y = mKubs[a][1];
       Z = mKubs[a][2];
       
        Yt = Y*cos(Xan) - Z*sin(Xan);
        Zt = Y*sin(Xan) + Z*cos(Xan);
        Y = Yt;
        Z = Zt;
        Xt = X*cos(Yan) - Z*sin(Yan);
        Zt = X*sin(Yan) + Z*cos(Yan);
        X = Xt;
        Z = Zt;
        Xt = X*cos(Zan) - Y*sin(Zan);
        Yt = X*sin(Zan) + Y*cos(Zan);
        X = Xt;
        Y = Yt;
              
       temp[a][0] = X;
       temp[a][1] = Y;   
   }
}
   
void draw(HWND hwnd, HDC hdc, PAINTSTRUCT ps, HPEN redCube)
{  
    hdc = BeginPaint(hwnd, &ps);
    SelectObject(hdc, redCube);   
    for (int a=0; a<8; a++) {
        for (int b=0; b<3; b++) {
            MoveToEx(hdc,(int)(temp[a][0]*iKoef+250),(int)(temp[a][1]*iKoef+250),NULL);
            LineTo(hdc,(int)(temp[mSavienot[a][b]][0]*iKoef+250),(int)(temp[mSavienot[a][b]][1]*iKoef+250));
        }
    }
    EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  
    {
        
        case WM_CREATE:
            redCube = CreatePen(PS_SOLID,1,RGB(0,0,0));            
            break;            
        case WM_DESTROY:           
            DeleteObject(redCube);  
            PostQuitMessage (0);      
            break;
        case WM_TIMER: 
            hdc = GetDC(hwnd);                     
            ReleaseDC(hwnd, hdc);
            break;        
        case WM_PAINT:
            draw(hwnd,hdc,ps,redCube);        
            break;
        case WM_KEYDOWN:
            switch (wParam)
            {
            case VK_UP:
                fPagriezt(1);  
                InvalidateRect(hwnd, NULL, TRUE);
                UpdateWindow(hwnd);
                break;
            case VK_DOWN:
                fPagriezt(1,1);
                InvalidateRect(hwnd, NULL, TRUE);
                UpdateWindow(hwnd);
                break;            
            case VK_LEFT:
                fPagriezt(2);
                InvalidateRect(hwnd, NULL, TRUE);
                UpdateWindow(hwnd);
                break;            
            case VK_RIGHT:                
                fPagriezt(2,1);
                InvalidateRect(hwnd, NULL, TRUE);
                UpdateWindow(hwnd);
                break;  
            }          
            break;
        case WM_CHAR:
            switch (wParam)
            {
                case ('a'):
                case ('A'):
                    fPagriezt(3,1);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                case ('s'):
                case ('S'):
                    fPagriezt(3);
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;                 
            }           
        default:                      
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
