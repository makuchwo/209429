#include <iostream>
#include <windows.h>
#include <fstream>

#include "generuj.hh"


using namespace std;

/*!
\mainpage Program sluzacy do pomiaru zlozonosci obliczeniowej.
\author Wojcich Makuch
\date 10.03.2015
\version 1.0

Zadaniem programu jest wygenerowanie tablic
liczb pseldoloswych oraz pomiar zlozonosci obliczeniowej polegajacej
na wymnozeniu kazdego z tych elementow przez 2.
Program zapisuje dane w pliku o nazwie Pomiar_czasu1.txt.

\section wartosci
Program wykonuje obliczenia dla tablic o rozmiarach:
10-10000000
*/

int main()
{
    int rozm=100000000;
    int czas=0;
       fstream plik;

    plik.open("Pomiar_czasu1.txt",ios::out);
    if(!plik.good())
    {
        cerr << "Blad otwarcia pliku do zapisu." << endl;
        return -1;
    }

int i,j;
for(i=10,j=50; i<=rozm, j<=rozm; i*=10,j*=10)
{
    dane *d=new dane(i);
    dane *d2=new dane(j);
    d->generuj();
    d2->generuj();
    czas=d->licz();
    cout << i << "\t\t " << czas << endl;
    plik << i << "\t\t " << czas << endl;
    czas=d2->licz();
    cout << j << "\t\t " << czas << endl;
    plik << j << "\t\t " << czas << endl;
}
    plik.close();
    system("PAUSE");
}

