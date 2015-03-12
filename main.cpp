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
Program zapisuje dane w pliku o nazwie PomiarCzasu1.txt.

\section wartosci
Program wykonuje obliczenia dla tablic o rozmiarach:
10 50 1e02 5e02 1e03 5e03 1e04 5e04 1e06 2.5e06 5e06 7.5e06 1e07 5e07 1e08 2.5e08
*/

int main()
{
   dane *d1, *d15, *d2, *d25, *d3, *d35, *d4, *d45;
   dane *d5, *d55, *d6, *d65, *d7, *d75, *d8, *d825;
   dane *d625, *d675;

    d1=new dane(10);
    d15=new dane(50);
    d2=new dane(100);
    d25=new dane(500);
    d3=new dane(1000);
    d35=new dane(5000);
    d4=new dane(10000);
    d45=new dane(50000);
    d5=new dane(100000);
    d55=new dane(500000);
    d6=new dane(1000000);
    d65=new dane(5000000);
    d7=new dane(10000000);
    d75=new dane(50000000);
    d8=new dane(100000000);
    d825=new dane(250000000);


    d625=new dane(2500000);
    d675=new dane(7500000);


    int czas=0;
    fstream plik;

    plik.open("Pomiar_czasu1.txt",ios::out);
    if(!plik.good())
    {
        cerr << "Blad otwarcia pliku do zapisu." << endl;
        return -1;
    }

cout << "ilosc element. tab.\t czas wyk. operacji" << endl;
    d1->generuj();
    czas=d1->licz();
    cout << "10 " << "\t\t\t " << czas << endl;
    plik << "10 " << "\t\t\t " << czas << endl;

    d15->generuj();
    czas=d15->licz();
    cout << "50 " << "\t\t\t " << czas << endl;
    plik << "50 " << "\t\t\t " << czas << endl;

    d2->generuj();
    czas=d2->licz();
    cout << "100 " << "\t\t\t " << czas << endl;
    plik << "100 " << "\t\t\t " << czas << endl;

    d25->generuj();
    czas=d25->licz();
    cout << "500 " << "\t\t\t " << czas << endl;
    plik << "500 " << "\t\t\t " << czas << endl;

    d3->generuj();
    czas=d3->licz();
    cout << "1000 " << "\t\t\t " << czas << endl;
    plik << "1000 " << "\t\t\t " << czas << endl;

    d35->generuj();
    czas=d35->licz();
    cout << "5000 " << "\t\t\t " << czas << endl;
    plik << "5000 " << "\t\t\t " << czas << endl;

    d4->generuj();
    czas=d4->licz();
    cout << "10000 " << "\t\t\t " << czas << endl;
    plik << "10000 " << "\t\t\t " << czas << endl;

    d45->generuj();
    czas=d45->licz();
    cout << "50000 " << "\t\t\t " << czas << endl;
    plik << "50000 " << "\t\t\t " << czas << endl;

    d5->generuj();
    czas=d5->licz();
    cout << "100000 " << "\t\t\t " << czas << endl;
    plik << "100000 " << "\t\t\t " << czas << endl;

    d55->generuj();
    czas=d55->licz();
    cout << "500000 " << "\t\t\t " << czas << endl;
    plik << "500000 " << "\t\t\t " << czas << endl;

    d6->generuj();
    czas=d6->licz();
    cout << "1000000 " << "\t\t " << czas << endl;
    plik << "1000000 " << "\t\t " << czas << endl;

    d625->generuj();
    czas=d625->licz();
    cout << "2500000 " << "\t\t " << czas << endl;
    plik << "2500000 " << "\t\t " << czas << endl;

    d65->generuj();
    czas=d65->licz();
    cout << "5000000 " << "\t\t " << czas << endl;
    plik << "5000000 " << "\t\t " << czas << endl;

    d675->generuj();
    czas=d675->licz();
    cout << "7500000 " << "\t\t " << czas << endl;
    plik << "7500000 " << "\t\t " << czas << endl;

    d7->generuj();
    czas=d7->licz();
    cout << "10000000 " << "\t\t " << czas << endl;
    plik << "10000000 " << "\t\t " << czas << endl;

    d75->generuj();
    czas=d75->licz();
    cout << "50000000 " << "\t\t " << czas << endl;
    plik << "50000000 " << "\t\t " << czas << endl;

    d8->generuj();
    czas=d8->licz();
    cout << "100000000 " << "\t\t " << czas << endl;
    plik << "100000000 " << "\t\t " << czas << endl;

    d825->generuj();
    czas=d825->licz();
    cout << "250000000 " << "\t\t " << czas << endl;
    plik << "250000000 " << "\t\t " << czas << endl;

    cout << "\nZapisano." << endl;
    plik.close();
    system("PAUSE");
}

