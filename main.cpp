#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "graph.hh"
#include "queue.hh"
#include "benchmark.hh"
using namespace std;


/*!
 *\file main.cpp
 *\brief glowna funkcja programu
 */

/*!
 *\mainpage Projektowanie algorytmów i metod sztucznej inteligencji. Laboratorium  9 - Sprawozdanie
 *\author Wojciech Makuch
 *\date 27.05.2015
 *\version 1.0
 *
 *program testujacy oraz benchmarkujacy zaimplementowane grafy
 *posiada menu uzytkownika
 *do wyboru
 *\section utworz graf
 *\section utworz lsowy graf
 *\section wyswietl macierz sasiedztwa
 *\section DSF
 *\section BFS
 *\section benchmarkuj DFSa
 *\section benchmarkuj BFSa
 *\section graf omawiany na cwiczeniach
 *\section wyjscie
 */

int main()
{
    srand(time(NULL));

    CGraph *G1 = new CGraph(9,12);
    G1->set_graph(0,0,1);
    G1->set_graph(1,0,2);
    G1->set_graph(2,1,3);
    G1->set_graph(3,1,4);
    G1->set_graph(4,3,6);
    G1->set_graph(5,4,6);
    G1->set_graph(6,2,4);
    G1->set_graph(7,2,6);
    G1->set_graph(8,2,5);
    G1->set_graph(9,5,7);
    G1->set_graph(10,7,8);
    G1->set_graph(11,3,3);


CGraph *G;
int choice;

cout << "0 - menu" << endl;
cout << "1 - utworz graf" << endl;
cout << "2 - utworz losowy graf" << endl;
cout << "3 - wyswietl macierz sasiedztwa" << endl;
cout << "4 - DFS" << endl;
cout << "5 - BFS" << endl;
cout << "6 - benchmarkuj DFSa" << endl;
cout << "7 - benchmarkuj BFSa" << endl;
cout << "8 - graf omawany na cwiczeniach" << endl;
cout << "9 - wyjscie" << endl;


do
{
    cin >> choice;
    switch(choice)
    {
        case 0:
            cout << "0 - menu" << endl;
            cout << "1 - utworz graf" << endl;
            cout << "2 - utworz losowy graf" << endl;
            cout << "3 - wyswietl macierz sasiedztwa" << endl;
            cout << "4 - DFS" << endl;
            cout << "5 - BFS" << endl;
            cout << "6 - benchmarkuj DFSa" << endl;
            cout << "7 - benchmarkuj BFSa" << endl;
            cout << "8 - graf omawany na cwiczeniach" << endl;
            cout << "9 - wyjscie" << endl;
            break;
        case 1:
            int v,e;
            int v1,v2;
            cout << "podaj ilosc wierzholkow:" << endl;
            cin >> v;
            cout << "podaj ilosc krawedzi:" << endl;
            cin >> e;
            G = new CGraph(v,e);
            for(int i=0; i<e; i++)
            {
                cout << "podaj wiezcholek pierwszy dla krawiedzi " << i << ":" << endl;
                cin >> v1;
                cout << "podaj wiercholek drugi dla krawedzi " << i << ":" << endl;
                cin >> v2;
                G->set_graph(i,v1,v2);
            }
            cout << "utworzono." << endl;
            cout << "0 - menu" << endl;
            break;
        case 2:
            int a,b;
            cout << "podaj ilosc wiercholkow:" << endl;
            cin >> a;
            cout << "podaj ilosc krawedzi:" << endl;
            cin >> b;
            G=new CGraph(a,b);
            G->make_random_graph(a,b);
            cout << "utworzono." << endl;
            cout << "0 - menu" << endl;
            break;
        case 3:
            G->print_matrix();
            cout << "0 - menu" << endl;
            break;
        case 4:
            G->DFS(0);
            cout << endl;
            cout << "0 - menu" << endl;
            break;
        case 5:
            G->BFS(0);
            cout << "0 - manu" << endl;
            break;
        case 6:
            G=new CGraph(10000,10000);
            G->benchmarking_DFS();
            cout << "gotowe" << endl;
            cout << "0 - menu" << endl;
            break;
        case 7:
            G=new CGraph(10000,10000);
            G->benchmarking_BFS();
            cout << "gotowe" << endl;
            cout << "0 - menu" << endl;
            break;
        case 8:
            G=G1;
            cout << "ustawiono" << endl;
            cout << "0 - menu" << endl;
            break;
    }
}while(choice!=9);

    return 0;
}

