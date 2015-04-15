#include <iostream>
#include <cstdlib>

#include "losowy_lancuch.hh"
#include "haszowanie.hh"
#include "dane.hh"
#include "benchmark.hh"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

/*!
 * \author Wojciech Makuch
 * \date 15.04.2015
 * \version 1.0
 * \mainpage program framework benchmarkujacy dla abstrakcyjnego typu danych: tablica haszujaca.
 * Program realizuje zadanie wyliczenia zlozonosci obliczeniowej dla abstakcyjnego typu danych jakim jest tablica haszujaca
 * Uzyskane wyniki program zapisuje do pliku o nazwie \e pomiar_czasu_5.txt. \e
 * Program zbudownay na klasach: dane - przechowujace klucz oraz wartosci danych, tablica - tworzacy tablice haszujaca(asocjacyjna z mozliwoscia przeszukania)
 * Zlozonosc obliczeniowa liczona na podstawie wartosci lodowych otrzymanych z funkcji rand().
 */

int main()
{
    srand(time(NULL));

    benchmarkuj("pomiar_czasu_5.txt");
}



