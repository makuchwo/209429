#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.hh"
#include "queue.hh"
#include "stack.hh"
#include "format.h"
#include "global.h"

using namespace std;


/*!
 *\mainpage program - poznanie osoby x
 *\author W. Makuch, W.Maluszynski
 *\date
 *\version 0.1
 *
 *Program zrealizowany jest z wykorzystaniem funkcji winApi
 *W pierwszym polu nalezy wpisac plik zawieracjacy konfiguracje grafu, nastepnie wczytac
 *W drugim polu nalezy wpisac identyfikator pierwszej osoby, nastepnie wczytac
 *W trzecim polu nalezy wpisac identyfikator drugiej osoby, nastepnie wczytac

 *program wyswietla okineko ze znaleziona sciezka
 *W przypadku blednej nazwy pliku lub nieznalezienia sciezki
 *program zglasza blad
 */



int WINAPI WinMain( HINSTANCE hThisInstance,
HINSTANCE hPrevInstance,
LPSTR lpszArgument,
int nCmdShow )
{
    //HWND hwnd; /* This is the handle for our window */
    MSG messages; /* Here messages to the application are saved */
    WNDCLASSEX wincl; /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS; /* Catch double-clicks */
    wincl.cbSize = sizeof( WNDCLASSEX );

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wincl.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
    wincl.hCursor = LoadCursor( NULL, IDC_ARROW );
    wincl.lpszMenuName = NULL; /* No menu */
    wincl.cbClsExtra = 0; /* No extra bytes after the window class */
    wincl.cbWndExtra = 0; /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground =( HBRUSH ) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if( !RegisterClassEx( & wincl ) )
         return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx(
    0, /* Extended possibilites for variation */
    szClassName, /* Classname */
    _T( "Poznaznie osoby x" ), /* Title Text */
    WS_OVERLAPPEDWINDOW, /* default window */
    CW_USEDEFAULT, /* Windows decides the position */
    CW_USEDEFAULT, /* where the window ends up on the screen */
    800, /* The programs width */
    400, /* and height in pixels */
    HWND_DESKTOP, /* The window is a child-window to desktop */
    NULL, /* No menu */
    hThisInstance, /* Program Instance handler */
    NULL /* No Window Creation data */
    );


    hStaticDebugBox = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT,
    10, 10, 763, 20, hwnd,( HMENU ) ID_STATICTEXTBOX1, hThisInstance, NULL );

    hCommandLine = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
    10, 40, 763, 20, hwnd,( HMENU ) ID_COMANDLINE, hThisInstance, NULL );

    hExecButton = CreateWindowEx( 0, "BUTTON", "Set Graph", WS_CHILD | WS_VISIBLE,
    660, 70, 100, 30, hwnd,( HMENU ) ID_BUTTON1, hThisInstance, NULL );



    hStaticDebugBox2 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT,
    10, 100, 763, 20, hwnd,( HMENU ) ID_STATICTEXTBOX2, hThisInstance, NULL );

    hCommandLine2 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
    10, 140, 763, 20, hwnd,( HMENU ) ID_COMANDLINE, hThisInstance, NULL );

    hExecButton2 = CreateWindowEx( 0, "BUTTON", "User 1", WS_CHILD | WS_VISIBLE,
    660, 170, 100, 30, hwnd,( HMENU ) ID_BUTTON2, hThisInstance, NULL );


    hStaticDebugBox3 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT,
    10, 200, 763, 20, hwnd,( HMENU ) ID_STATICTEXTBOX3, hThisInstance, NULL );

    hCommandLine3 = CreateWindowEx( WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
    10, 240, 763, 20, hwnd,( HMENU ) ID_COMANDLINE, hThisInstance, NULL );

    hExecButton3 = CreateWindowEx( 0, "BUTTON", "User 2", WS_CHILD | WS_VISIBLE,
    660, 270, 100, 30, hwnd,( HMENU ) ID_BUTTON3, hThisInstance, NULL );

    /* Make the window visible on the screen */
    ShowWindow( hwnd, nCmdShow );

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while( GetMessage( & messages, NULL, 0, 0 ) )
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage( & messages );
        /* Send message to WindowProcedure */
        DispatchMessage( & messages );
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch( message ) /* handle the messages */
    {
    case WM_DESTROY:
        PostQuitMessage( 0 ); /* send a WM_QUIT to the message queue */
        break;

    case WM_COMMAND:
        if( wParam == ID_BUTTON1 )
        {
            int bufor = 0;
            CommandLineBuf =( LPSTR )GlobalAlloc( GPTR, GetWindowTextLength( hCommandLine ) + 1 );

            bufor = GetWindowText( hCommandLine, CommandLineBuf, 50 );
           // cout << bufor << endl;
            SetDlgItemText( hwnd, ID_STATICTEXTBOX1, CommandLineBuf );

            plik.open(CommandLineBuf,ios::in);
            if(!plik.good())
            {
                cout << "blad otwarcia pliku." << endl;

            MessageBox(hwnd,"blad otwarcia pliku.","Blad",MB_ICONINFORMATION);
                return -1;
            }
             int i,j;
             int licznik=0;

            while(!plik.eof())
            {
                plik >> i;
                plik >> j;
                licznik++;
            }
            G=new CGraph(j+1,j+1);

            plik.close();
            plik.open(CommandLineBuf,ios::in);

            for(int k=0;k<licznik;k++)
            {
                plik >> i;
                plik >> j;
                G->set_graph(i,j);
            }
            GlobalFree( CommandLineBuf );
        }

        if( wParam == ID_BUTTON2 )
        {
            int bufor = 0;
            CommandLineBuf =( LPSTR )GlobalAlloc( GPTR, GetWindowTextLength( hCommandLine2 ) + 1 );

            bufor = GetWindowText( hCommandLine2, CommandLineBuf, 50 );
            SetDlgItemText( hwnd, ID_STATICTEXTBOX2, CommandLineBuf );

            start_path = strtod(CommandLineBuf, NULL );

            GlobalFree( CommandLineBuf );
        }
           if( wParam == ID_BUTTON3 )
        {
            int bufor = 0;
            CommandLineBuf =( LPSTR )GlobalAlloc( GPTR, GetWindowTextLength( hCommandLine3 ) + 1 );

            bufor = GetWindowText( hCommandLine3, CommandLineBuf, 50 );

            SetDlgItemText( hwnd, ID_STATICTEXTBOX3, CommandLineBuf );

            end_path=strtod(CommandLineBuf,NULL);

            if(!G->BFSPath(start_path,end_path,&C))
            {
                MessageBox(hwnd,"Sciezka do poznania osoby nie zostala odnaleziona.","Blad",MB_ICONINFORMATION);
                C.~Lista<int>();
                break;
            }
            tmp_string=ZamienFormat(&C);

            MessageBox(hwnd,tmp_string,"Najszybsza sciezka do poznania osoby.",MB_ICONINFORMATION);

            C.~Lista<int>();
            GlobalFree( CommandLineBuf );
        }

        default: /* for messages that we don't deal with */
        return DefWindowProc( hwnd, message, wParam, lParam );
    }

    return 0;
}


/*
int main()
{
    fstream plik;
    plik.open("facebook_combined.txt",ios::in);
    if(!plik.good())
    {
        cout << "blad otwarcia pliku." << endl;
        return -1;
    }

    int i,j;
    int licznik=0;

    while(!plik.eof())
    {
        plik >> i;
        plik >> j;
        licznik++;
    }
    CGraph *G=new CGraph(j+1,j+1);

plik.close();
plik.open("facebook_combined.txt",ios::in);

    for(int k=0;k<licznik;k++)
    {
        plik >> i;
        plik >> j;
        G->set_graph(i,j);
    }

    G->BFSPath(0,4038);

    plik.close();

    return 0;
}
*/
