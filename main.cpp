#include <iostream>
#include <ctime>
#include "list.hh"
#include "benchmark.hh"
#include "csort.hh"
#include "heap_sort.hh"
#include "quick_sort.hh"
#include "merge_sort.hh"

using namespace std;


/*!
 *\mainpage modyfkacja sortowania - benchmark - obserwator
 *\author Wojcich Makuch
 *\date 12.05.2015
 *\version 2.0
 *program wzbogacono o menu, pozwalajace spradzic poprawnosc algorytmow.
 *wszystkie klasy, metody, zmienne itp. zaimplementowano w jezyku angielskim.
 */


int main()
{
    srand(time(NULL));
    CList *L=new CList;
    CSort *S1=new CQuickSort;
    CSort *S2=new CHeapSort;
    CSort *S3=new CMergeSort;

    char choice;
    int size;

    cout << "c - zaladuj liste liczbami pseudolosowymi" << endl;
    cout << "p - wyswietl liste" << endl;
    cout << "q - quick sort" << endl;
    cout << "h - heap sort" << endl;
    cout << "m - merge sort" << endl;
    cout << "x - benchmarkuj qucik sorta" << endl;
    cout << "y - benchmarkuj heap sorta" << endl;
    cout << "z - benchmarkuj merge sorta" << endl;
    cout << "d - usun liste" << endl;
    cout << "e - wyjscie z programu" << endl;
    do
    {
        cout << "o - opcje/menu" << endl;
        if(choice=='o') {
    cout << "c - zaladuj liste liczbami pseudolosowymi" << endl;
    cout << "p - wyswietl liste" << endl;
    cout << "q - quick sort" << endl;
    cout << "h - heap sort" << endl;
    cout << "m - merge sort" << endl;
    cout << "x - benchmarkuj qucik sorta" << endl;
    cout << "y - benchmarkuj heap sorta" << endl;
    cout << "z - benchmarkuj merge sorta" << endl;
    cout << "d - usun liste" << endl;
    cout << "e - wyjscie z programu" << endl;
        }
    cin >> choice;
    switch(choice)
    {
    case 'x':
        S1->benchmarking(L);
        cout << "zapisano" << endl;
        break;
    case 'y':
        S2->benchmarking(L);
        cout << "zapisano." << endl;
        break;
    case 'z':
        S3->benchmarking(L);
        cout << "zapisano." << endl;
        break;
    case 'c':
    cout << "wprowadz ilosc liczb psudolosowych:" << endl;
    cin >> size;
    for(int i=0; i<size; i++)
    {
        L->push(rand()%10);
    }
    cout << "zaladowano" << endl;
    break;
    case 'p':
    L->print();
    break;
    case 'q':
        if(L->is_empty())
        {
            cout << "lista jest pusta." << endl;
            break;
        } else
    S1->sort(L,0,size-1);
    cout << "posortowano." << endl;
    break;
    case 'h':
        if(L->is_empty())
        {
            cout << "lista jest pusta." << endl;
            break;
        } else
    S2->sort(L,0,size-1);
    cout << "posortowano." << endl;
    break;
    case 'm':
        if(L->is_empty())
        {
            cout << "Lista jest pusta" << endl;
            break;
        } else
        S3->sort(L,0,size-1);
        cout << "posortowano." << endl;
        break;
    case 'd':
        L->~CList();
        cout << "usunieto." << endl;
        break;
    }
}while(choice!='e');
    return 0;
}
