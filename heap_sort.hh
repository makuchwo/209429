#ifndef HEAP_SORT_HH_INCLUDED
#define HEAP_SORT_HH_INCLUDED
#include "list.hh"
#include "csort.hh"

/*!
 *\brief definicja klasy CHeapSort
 *definiuje sortowanie przez kopcowanie
 *przyklad klasy obserwowanej
 */
class CHeapSort : public CSort {
public:

    /*!
     *\brief definicja metody sorting
     *sortuje wykorzystujac algorytm heapsort
     *tworzy kopiec
     *zamienia najwiekszy element z najwiekszym(wysyla najwiekszy na koniec listy
     *przywraca wlasciwosc kopca korzystajac z metody up_heap
     *\param list - sortowana lista
     *\param useless - useless
     *\param last - maksymany romziar listy
     */
    void sorting(CList *list,int useless,int last);

    /*!
     *\brief definicja metody sort
     *implemetacja metody abstakcyjnej
     *wykorzystuje heapsort z wykorzystaniem timerow
     *\param list - sortowana lista
     *\param useless - useless
     *\param last - maksymany romziar listy
     */
    void sort(CList *list,int useless,int last);

    /*!
     *\brief definicja metody build_heap
     *tworzy kopiec z listy
     *wykorzystuje metode down_heap
     *\param list - modyfkowana lista
     *\param last - maksymalny rozmiar kopca
     */
    void build_heap(CList *list,int last);

    /*!
     *\brief definicja metody max_heapify
     *przywraca wlasciwosc kopca
     *zakladajac korzen - najwiekszy element
     *\param list - modyfikowana lista
     *\param parent - 'korzen poddrzewa'
     *\param last - maksymalny rozmiar drzewa
     *algorytm przyraca wlasciwosc kopca zaczynajac od korzenia
     */
    void down_heap(CList *list,int parent, int last);

    /*!
     *\brief definicja metody up_heap
     *przywraca wlasciwosc kopca
     *zakladajac korzen - najwiekszy element
     *\param list - modyfikowana lista
     *\param last - maksymalny rozmiar kopca
     */
    void up_heap(CList *list, int last);


    /*!
     *\brief feinicja metody benchmarking
     *sortuje listy w zakresie 1- 10 000
     *wykonujac metode sort, zapisuje dane z licznikw czasu do pliku
     *\param list - benchmarkowana lista
     */
    void benchmarking(CList *list);
};

#endif // HEAP_SORT_HH_INCLUDED
