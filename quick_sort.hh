#ifndef QUICK_SORT_HH_INCLUDED
#define QUICK_SORT_HH_INCLUDED

#include "list.hh"
#include "benchmark.hh"
#include "csort.hh"

/*!
 *\brief defnijca klasy CSort
 *definiuje sortowanie szybkie
 *jest przykaladem klasy obserwowanej
 */
class CQuickSort : public CSort {
public:

    /*!
     *\brief defnicja metody sorting
     *implementacja algortymu quicksort bez timerow
     *\param list - sortowana lista
     *\param left - indeks na 1 element sortowanej listy
     *\param right - indeks na prawy element sortowanej listy
     */
    void sorting(CList *list, int left, int right);

    /*!
     *\brief definicja metody sort
     *implementacja algorytmu quicksort z wykorzystaniem timerow
     *\param list - sortowana lista
     *\param left - indeks na 1 element sortowanej listy
     *\param right - indeks na prawy element sortowanej listy
     */
    void sort(CList *list, int left, int right);

    /*!
     *\brief feinicja metody benchmarking
     *sortuje listy w zakresie 1- 10 000
     *wykonujac metode sort, zapisuje dane z licznikw czasu do pliku
     *\param list - benchmarkowana lista
     */
    void benchmarking(CList *list);

    };

#endif // QUICK_SORT_HH_INCLUDED
