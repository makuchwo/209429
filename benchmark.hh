#ifndef STOPER_HH_INCLUDED
#define STOPER_HH_INCLUDED
#include <windows.h>
#include <ctime>
#include <fstream>
#include "losowy_lancuch.hh"
#include "dane.hh"
#include "haszowanie.hh"


/*!
 *\file
 *\brief definicje funkcji zliczajacych czas operacji wypelnienia tablic haszujacych
 */

/*!
 *\brief definicja funkcji StartTimer
 *Rozpoczyna pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER startTimer();

/*!
 *\brief definicja funkcji endTimer
 *Konczy pomiar czasu
 *Funkcja pobrana ze strony http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/
 */
LARGE_INTEGER endTimer();

/*!
 * \brief definicja funkcji zliczaj_czas
 * funkcja benchmarkujaca zliczajaca czas wypelnienia tablicy haszujacej elementami losowymi.
 * funkcja tworzy obiekt zadajac mu maksymalny rozmiar wynoszacy 150 000.
 * \param [N] ilosc elementow wypelniajacych tablice
 * \return czas wypelniania elementami losowymi
 */
double zliczaj_czas(int N);

/*!
 * \brief definicja funkcji benchmarkuj
 * Tworzy plik o zadanej nazwie.
 * Wykonuje w petlach funkcje zliczaj czas, wyniki wysyla odpowiednio do strumienia wyjsciowego oraz do pliku.
 * Po zakonczeniu dzialania funkcja zamyka plik
 * \param [nazwa_pliku] nazwa pliku otwartego do zapisu
 * \return 0, gdzy funkcja zostanie wyonana poprawie
 * \return -1, w przypadku przeciwnym.
 */
int benchmarkuj(char* nazwa_pliku);

#endif // STOPER_HH_INCLUDED
