#ifndef CSORT_HH_INCLUDED
#define CSORT_HH_INCLUDED

#include "list.hh"
#include "benchmark.hh"

/*!
 *\brief definicja klasy abstrakcyjnej CSort
 * jest klasa bazowa dla konkretnych typow sortowan.
 * jest przykladem klasy obserwowanej.
 */
class CSort : public CBenchmark {
public:
    /*!
     *\brief definicja metody sort
     *sortuje elementy na liscie.
     *\param list - sortowana lista
     *\param left - indeks pierwszego elementu listy sortowanej.
     *\param right - indeks ostatniego elementu listy sortowanej.
     */
    virtual void sort(CList*, int, int)=0;

    virtual void benchmarking(CList *list)=0;

};

#endif // CSORT_HH_INCLUDED
