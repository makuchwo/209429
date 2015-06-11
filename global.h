#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include <windows.h>


/*!
 *\file
 *przechowuje zmienne globalne
 */


#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>

#define ID_BUTTON1         101
#define ID_BUTTON2         102
#define ID_BUTTON3         103
#define ID_STATICTEXTBOX1  201
#define ID_STATICTEXTBOX2  202
#define ID_STATICTEXTBOX3  203
#define ID_COMANDLINE      301

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure( HWND, UINT, WPARAM, LPARAM );

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T( "WindowsApp" );

/* Uchwyty do kontrolek */
HWND hCommandLine;
HWND hExecButton;
HWND hStaticDebugBox;
HWND hCommandLine2;
HWND hExecButton2;
HWND hStaticDebugBox2;
HWND hCommandLine3;
HWND hExecButton3;
HWND hStaticDebugBox3;


/* Bufor przechowuje tekst wpisany do textboksa */
LPSTR CommandLineBuf;

using std::cout;
using std::endl;

    fstream plik;
    Lista<int> C;
    int i,j;
    int licznik=0;
    int start_path;
    int end_path;
    CGraph *G;
    LPSTR tmp_string;

    HWND hwnd; /* This is the handle for our window */

#endif // GLOBAL_H_INCLUDED
