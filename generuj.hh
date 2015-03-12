#ifndef GENERUJ_HH_INCLUDED
#define GENERUJ_HH_INCLUDED
#include <Windows.h>

/*!
 *Funcja rozpoczyna pomiar czasu.
 *\return start - zmierzony czas.
 */
LARGE_INTEGER startTimer();

/*!
 *Funkcja konczy pomiar czasu
 *\return koniec - zmierzony czas
 */
LARGE_INTEGER endTimer();

/*!
 *
 *Klasa modeluje pojecie zbioru danych.
 *Jej artybutem jest generowanie liczb pseldolosowych z zakresu 0-9
 *oraz pomiar zlozonosci obliczeniowej bazujacej na tych liczbach.
 */
class dane
{
    long int *tablica;
    long int rozmiar;
    public:
/*!
 *
 *\param[in] wielkosc - liczba elementow tablicy, dla ktorej
 *zostanie przydzielona pamiec.
 */
    dane(long int wielkosc) { rozmiar=wielkosc; tablica=new long int[rozmiar]; }
    ~dane() { delete tablica; }

/*!
 *
 *wypelnia tablice liczbami pseldolosowymi z zakresu 0-9.
 */
    void generuj();

/*!
 *\param[in] i - indeks tablicy.
 *\return zwraca element tablicy.
 */
    int Wez(int i)const { return tablica[i]; }

/*!
 *\return Zwraca rozmiar tablicy.
 */
    int WezRozmiar()const { return rozmiar; }

/*!
 *Zapisuje elementy tablicy w pliku o zadanej nazwie.
 *\param[in] nazwa - nazwa pliku do zapisu.
 *\return 0 - Poprawny zapis. -1 - Niepoprawny zapis.
 */
    int ZapiszDoPliku(const char* nazwa);

/*!
 *Wykonuje operacje na tablicy polegajace na wymnozeniu kazdego elementu przez 2.
 *Mierzy czas wykonywanych operacji z dokladnoscia do e-06s.
 *\return tm - zmierzony czas.
 */
    double licz();
};

#endif GENERUJ_HH_INCLUDED
