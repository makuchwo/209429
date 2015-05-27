#ifndef BENCHMARK_HH_INCLUDED
#define BENCHMARK_HH_INCLUDED
#include <windows.h>

/*!
 *\file benchmark.hh
 *\brief definiuje klase CBenchmark
 */

/*!
 * definicja klasy CBenchmark
 * definijue stoper zliczajacy czas wykoania operacji przez inne klasy
 * jest przykladem wzorca obserwatora
 * obserwuje klase CSort i zlicza czas sortowania listy
 */
class CBenchmark {
    LARGE_INTEGER performanceCountStart;
    LARGE_INTEGER performanceCountEnd;
    LARGE_INTEGER startTimer();
    LARGE_INTEGER endTimer();
    public:

    /*!
     *\brief definicja metody start_timer
     *rozpoczyna pomiar czasu
     *zapisuje dane do zmiennej performanceCountStart
     *korzysta z metdoy StartTimer()
     */
    virtual void start_timer();

    /*!
     *\brief definicja metody stop_timer
     *konczy pomiar czasu
     *zapsiuje dane do zmiennej performanceCountEnd
     *korzysta z metody endTimer
     */
    virtual void stop_timer();

     /*!
      *\brief definicja metody put_time_to_file
      *otiwra plik o nazwie 'timing.txt'
      *zapisuje do niego ilosc elementow listy
      *oraz czas przeprowadzenia operacji przez klasy obserwowane
      *zamyka plik.
      *\param size_of_list - rozmiar listy
      *\return czas przeprowadzenia operacji
      *\return -1 w przypadu bledu otwarcia pliku
      */
    virtual int put_time_to_file(int size_of_list);
};

#endif // BENCHMARK_HH_INCLUDED
