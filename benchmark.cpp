#include <windows.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include "losowy_lancuch.hh"
#include "dane.hh"
#include "haszowanie.hh"


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



double zliczaj_czas(int N)
{
    tablica t(150000);

LARGE_INTEGER performanceCountStart,performanceCountEnd;
performanceCountStart = startTimer();

for(int i=0; i<N-1; i++)
{
dane d(LosowyLancuch(),rand()+1);
t.Wypelnij(d);
}
performanceCountEnd = endTimer();


double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
return tm;
}


int benchmarkuj(char* nazwa_pliku)
{
        std::fstream plik;
        plik.open(nazwa_pliku,std::ios::out);
        if(!plik.good())
        {
            std::cout << "blad otwarcia pliku do zapisu" << std::endl;
            return -1;
        } else


        for(int i=0; i<=100; i+=10)
        {
            std::cout << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
            plik << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
        }
    for(int i=100; i<=1000; i+=100)
        {
            std::cout << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
            plik << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
        }
    for(int i=1000; i<=10000; i+=1000)
        {
            std::cout << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
            plik << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
        }
           for(int i=10000; i<=100000; i+=10000)
        {
            std::cout << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
            plik << i << "\t\t\t" << zliczaj_czas(i) << std::endl;
        }
        plik.close();
        return 0;
}
