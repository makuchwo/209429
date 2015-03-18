#include <iostream>
#include <windows.h>
#include <fstream>

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "Stoper.hh"

/*!
 *\mainpage Program framework benchmarkujacy dla struktur danych Stos, Lista i Kolejka
 *\author Wojciech Makuch
 *\date 16.03.2015
 *\version 1.0
 *Program przeprowadza operacje zliczania czasu wypelnienia trzech struktur danych
 *liczbami pseldolosowymi.
 *Dla Stosu: 10-10e05 elementow.
 *Dla Listy 10-10e07 elementow.
 *Dla Kolejki 10-10e04 elementow.
 *Wyliczony czas podawany z dokladnoscia do 10e-03 ms
 *Uzyskane dane program zapisuje do pliku o nazwie "Pomiar_czasu2.txt"
 */

using namespace std;

int main() {

    const char* nazwa_pliku="Pomiar_czasu2.txt";
    fstream plik;
    plik.open(nazwa_pliku,ios::out);
    if(!plik.good())
    {
        cerr << "Blad otwarcia pliku." << endl;
        return -1;
    }
{
    Stos<int> *s=new Stos<int>;

    cout << "Pomiar czasu dla stosu:" << endl;
    plik << "Pomiar 1: Stos:" << endl;
    plik << "ilosc element.\tczas" << endl;
    for(int i=10;i<100001;i*=10)
    {
        cout << i << "\t\t" << licz(s,i) << endl;
        plik << i << "\t\t" << licz(s,i) << endl;
    }
}
{
    Lista<int> *l=new Lista<int>;

    cout << "Pomiar czasu dla lisy:" << endl;
    plik << "Pomiar 2: Lista" << endl;
    plik << "ilosc element.\tczas" << endl;
    for(int i=10;i<10000001;i*=10)
    {
        cout << i << "\t\t" << licz(l,i) << endl;
        plik << i << "\t\t" << licz(l,i) << endl;
    }
}
{
    Kolejka<int> *k=new Kolejka<int>;
    cout << "Pomiar czasu dla kolejki:" << endl;
    plik << "Pomiar 3: Kolejka" << endl;
    plik << "ilosc element.\tczas" << endl;
    for(int i=10;i<10001;i*=10)
    {
        cout << i << "\t\t" << liczKol(k,i) << endl;
        plik << i << "\t\t" << liczKol(k,i) << endl;
    }
}
plik.close();
cout << "Zapisano." << endl;

    system("PAUSE");
    return 0;
}
