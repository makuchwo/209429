#ifndef DANE_HH_INCLUDED
#define DANE_HH_INCLUDED

/*!
 * \file
 * \brief plik przechowujacy deklaracje klasy dane oraz deklaracje jej pol i metod.

/*!
 *\brief definicja klasy dane.
 * Jest to struktura przechowujaca klucz poddawany haszowaniu oraz wartosc jako przechowywane dane (zmienna typu int).
 * Obiekty typu dane sa wykorzystywane do wypelniania tablicy haszujacej(asocjacyjnej).
 * Pole klucz mozna potraktowac np. jako nazwisko szukanej osoby w bazie danych, a pole wartosc jako jej nr telefonu.
 * Klasa zawiera metody pozwalajace na odwolanie sie do pol prywatnych bez nadpisywania ich oraz konstruktory.
 */

class dane {
    char* klucz;
    int wartosc;
public:

    /*!
     * \brief definicja metody WezKlucz klasy dane
     * metoda nie pozwala na zmiane zawartosci pola.
     * \return pole prywane klucz.
     */
    char* WezKlucz()const {return klucz; }

    /*!
     * \brief definicja metody WezWartosc klasy dane.
     * metoda nie pozwala na zmiane zawartosci pola.
     * \return pole prywatne wartosc
     */
    int WezWartosc()const { return wartosc; }

    /*!
     * \brief definicja konstruktora 2-parametrycznego
     */
    dane(char* k, int w) : klucz(k), wartosc(w) {};

    /*!
     * \brief definicja konstruktora bezparametrycznego
     * zeruje pole wartosc, wskaznik na lancuch ustawia na NULL
     */
    dane() : klucz(NULL), wartosc(0) {};
};

#endif // DANE_HH_INCLUDED
