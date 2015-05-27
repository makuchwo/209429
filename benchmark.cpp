#include "benchmark.hh"
#include <windows.h>
#include <fstream>
#include <iostream>

/*!
 *\file benchmark.cpp
 *\brief implmentuje zdefiniowana klase benchmarka
 */
LARGE_INTEGER CBenchmark::startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return start;
}

LARGE_INTEGER CBenchmark::endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}

void CBenchmark::start_timer()
{
    performanceCountStart = startTimer();
}

void CBenchmark::stop_timer()
{
    performanceCountEnd = endTimer();
}

int CBenchmark::put_time_to_file(int size_of_list)
{
    std::fstream file;
    file.open("timing.txt",std::ios::out | std::ios::app | std::ios::ate );
    if(!file.good())
    {
        std::cout << "Error open file." << std::endl;
        return -1;
    }
    double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    file << size_of_list << "\t\t\t" << tm << std::endl;
    file.close();
    return tm;
}
