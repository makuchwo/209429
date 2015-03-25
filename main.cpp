#include <iostream>
#include <windows.h>
#include <fstream>

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "Stoper.hh"

/*!
 *\mainpage Program framework benchmarkujacy dla struktury danych Stos
 *\author Wojciech Makuch
 *\date 16.03.2015
 *\version 1.1
 *Program przeprowadza operacje zliczania czasu wypelnienia struktury danych stos
 *liczbami pseldolosowymi. Program sprawdza dzialanie i szybkosc obliczeniowa struktury
 *danych przy alokacji pamieci zarowno o 1 element i razy 200%.
 *Wyliczony czas podawany z dokladnoscia do us.
 *Uzyskane dane program zapisuje do pliku o nazwie "Pomiar_czasu3.txt"
 */

using namespace std;

int main() {

    const char* nazwa_pliku="Pomiar_czasu3.txt";
    fstream plik;
    plik.open(nazwa_pliku,ios::out);
    if(!plik.good())
    {
        cerr << "Blad otwarcia pliku." << endl;
        return -1;
    }
{
    Stos<int> *s=new Stos<int>;

    cout << "Powiekszanie o 1:" << endl;
    plik << "ilosc element.\tczas" << endl;
    for(int i=10;i<100001;i*=10)
    {
        cout << i << "\t\t" << licz(s,i) << endl;
        plik << i << "\t\t" << licz(s,i) << endl;
    }
}
{
    Stos<int> *s=new Stos<int>;

    cout << "Powiekszanie 2x:" << endl;
    plik << "ilosc element.\tczas" << endl;
    for(int i=10;i<10000001;i*=10)
    {
        cout << i << "\t\t" << licz200(s,i) << endl;
        plik << i << "\t\t" << licz200(s,i) << endl;
    }
}

plik.close();
cout << "Zapisano." << endl;
    system("PAUSE");
    return 0;
}
