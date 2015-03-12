#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <ctime>

#include "generuj.hh"

LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}
LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}


void dane::generuj()
{
        for(int i=0;i<rozmiar;i++)
        {
            tablica[i]=rand()%9;
        }
}

double dane::licz()
{
    /*
    time_t start, koniec;
    double roznica;
    start=clock();
    for(int i=0;i<rozmiar;i++)
    {
        tablica[i]=tablica[i]*2;
    }
    koniec=clock();
    roznica=difftime(koniec,start);
    return roznica;
    */
LARGE_INTEGER performanceCountStart,performanceCountEnd;
performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
 for(int i=0;i<rozmiar;i++)
    {
        tablica[i]=tablica[i]*2;
    }
performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}

int dane::ZapiszDoPliku(const char* nazwa)
{
    std::fstream plik;
    plik.open(nazwa,std::ios::out);
    if(!plik.good())
    {
        std::cerr << "blad otwarcia pliku do zpaisu." << std::endl;
        return -1;
    }
    for(int i=0;i<rozmiar;i++)
    {
        plik << tablica[i];
    }
    plik.close();
    return 0;
}


/*
int dane::generuj(const char* nazwa)
{
    char w;
    std::cout << "Czy zapisac do pliku? (y/n)" << std::endl;

do{
    w=getch();
    switch(w)
    {
        case 'y':
        plik.open(nazwa,std::ios::out);
        if(!plik.good())
        {
            std::cerr << "blad otwarcia pliku do zapisu o nazwie " << nazwa << "." << std::endl;
            return -1;
        }
        for(int i=0;i<rozmiar;i++)
        {
            plik << rand()%9;
        }
        std::cout << "Zapisano." << std::endl;
        plik.close();
    break;
        case 'n':
        for(int i=0;i<rozmiar;i++)
        {
        tablica[i]=rand()%9;
        }
        std::cout << "Wygenerowano." << std::endl;
    break;
    default: std::cout << "(y/n)" << std::endl;
    break;
    }
    }while(w!='y' && w!='n');
    return 0;
}
*/
