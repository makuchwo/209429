#ifndef LOSOWY_LANCUCH_HH_INCLUDED
#define LOSOWY_LANCUCH_HH_INCLUDED
#include <cstdlib>

/*!
 * \file
 * \brief plik przechowujacy fukncje do zwracania losowych lancuchow
 */

/*!
 *\brief definicja funkcji LosowyZnak
 * Funkcja inline.
 * \return wartosc liczbowa znaku ASCII z przedzialu od A do Z.
 */
inline char LosowyZnak()
{
    return (std::rand() % ('z'-'A')) + 'A';
}

/*!
 * \brief definicja funkcji LosowyLancuch
 * Metoda inline.
 * \return losowy lancuch znakow o dlugosci od 0 do 10.
 */
inline char* LosowyLancuch()
{
    int rozmiar=rand()%10+1;
    char *lancuch=new char[rozmiar];

    for(int i=0; i<rozmiar; i++)
    {
        lancuch[i]=LosowyZnak();
    }
    return lancuch;
}

#endif // LOSOWY_LANCUCH_HH_INCLUDED
