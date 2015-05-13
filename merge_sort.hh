#ifndef MERGE_SORT_HH_INCLUDED
#define MERGE_SORT_HH_INCLUDED

#include "list.hh"
#include "csort.hh"

/*!
 *\brief definicja klasy CMergeSort
 * definiuje sortowanie przez scalanie
 *jest przykadem klasy obserwowanej
 *implementuje metode abstakcyjna sort
 */
class CMergeSort : public CSort {
public:

    /*!
     *\brief definicja metody sorting
     *sortuje liste poprzez algorytm sortowania przez scalanie
     *\param list - sortowana lista
     *\param left - indeks na 1-szy element
     *\param right - indeks na ostatni element sortowanej listy
     */
    void sorting(CList* list, int left, int right);

    /*!
     *\brief definicja metody sort
     *implementacja metody czysto abstrakcyjnej
     *korzysta z metody sorting
     *korzysta z timerow
     *\param list - sortowana lista
     *\param left - indeks na 1-szy element
     *\param right - indeks na ostatni element sortowanej listy
     */
    void sort(CList* list, int left, int right);


    /*!
     *\brief feinicja metody benchmarking
     *sortuje listy w zakresie 1- 10 000
     *wykonujac metode sort, zapisuje dane z licznikw czasu do pliku
     *\param list - benchmarkowana lista
     */
    void benchmarking(CList *list);
};

#endif // MERGE_SORT_HH_INCLUDED
