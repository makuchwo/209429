#ifndef HASZOWANIE_HH_INCLUDED
#define HASZOWANIE_HH_INCLUDED

#include "dane.hh"

/*!
 * \file
 * \brief plik przechowyjacy deklaracje klasy tablica oraz deklaracje jej pol i metod.
 */

/*!
 * \brief definicja klasy tablica.
 * Definiuje tablice haszujaca(asocjacyjna z mozliwoscia odwolania sie do jej elementu poprzez klucz).
 * Tablica alokowana jest dynamicznie, rozmiar ustalany jest w konstruktorze.
 * Tablica ma narzucony maksymalny rozmiar, poniewaz metoda haszujaca klucze na nim bazuje.
 * Klasa zawiera 2 pola: tab - tablice danych oraz zmienna rozmiar przechowujaca informacje o dlugosci tablicy.
 */

class tablica {
    dane *tab;
    int rozmiar;
public:

    /*!
     * \brief definicja konstruktra 1-parametrowego
     */

    tablica(int n);
    /*!
     * \brief definicja destruktora
     */
    ~tablica();

    /*!
     * \brief defiicja przeciazenia operatora []
     * \param [i] komorka tablicy
     * pozwala na odwolanie sie do elementu tablicy o indeksie i
     * metoda nie pozwala na zmiane wartosci pol prywatnych
     * \return element tablicy
     */
    dane operator[](int i)const { return tab[i]; }

    /*!
     * \brief definicja przeciazenia operatora []
     * pozwala na odwolanie sie do elementu tablicy za pomoca klucza
     * \param [klucz] zadany klucz
     * \return element tablicy
     */
    dane operator[](char* klucz)const;

    /*!
     * \brief definicja metody Haszowanie
     * pierszy sposob haszowania klucza
     * dodaje elementu klucza zrzutowane na inta, liczy reszte z dzielenia przez maksymalny rozmiar
     * metoda nie zmienia stanu obiektu
     * \param [klucz] zadany klucz
     * \return kod bedacy wnikiem pierwszego haszowania
     */
    int Haszowanie(char* klucz)const;

    /*!
     * \brief definicja metody DrugieHaszowanie
     * drugi sposob haszowania klucza.
     * wykorzystuje wzor q-(dodany wartosci klucza)/q, gdzie q jest polowa maksymalnego rozmiaru i q jest liczba nieparzysta.
     * metoda nie zmienia stanu obiektu.
     * DrugieHaszowanie wykorzystuje sie w celu zminimalizowania ilosci wystapien kolizji.
     * \param [klucz] zadany klucz
     * \return kod bedacy wynikiem drugiego haszowania
     */
    int DrugieHaszowanie(char* klucz)const;

    /*!w
     * \brief definicja metody Wypelnij
     * Ustawia element w tablicy haszowania zgodnie z wartoscia klucza
     * Jezeli dojdzie do 1. kolizji, zostaje wykorzystane drugie haszowanie i sprawdzana jest dostepnosc komorki i+j, gdzie
     * i-wynik pierwszego haszowania, j - wynik drugiego haszowania.
     * Jezeli dochodzi do kolejnych kolizji tablica zostaje wypelniana poprzez przechodzenie z komorki do komorki o 1 dalej.
     * \param [element] dane przekazywane do tablicy
     */
    void Wypelnij(dane element);

    /*!
     * \brief definicja metody Wyswietl
     * metoda pomocna przy tworzeniu programu.
     * Wypisuje na strumien wyjsciowy zawartosc tablicy, przy odwolaniu sie do wartosci elementow(a nie do kluczy).
     * Metoda nie zmienia stanu obiektu.
     */
    void Wyswietl()const;
};

#endif // HASZOWANIE_HH_INCLUDED
