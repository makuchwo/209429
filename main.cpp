#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#include "tree.hh"
#include "benchmark.hh"
#include "node.hh"
#include "Red_black_node.hh"
#include "Red_black_tree.hh"

using namespace std;

int main()
{
    srand(time(NULL));

    CTree *T=new CTree();
    CTree *tmp=new CTree();
    CRed_Black_Tree *TR=new CRed_Black_Tree();
    int k,l;
    char choice;

    cout << "m - menu" << endl;
    cout << "a - dodaj do drzewa binarnego" << endl;
    cout << "f - znajdz wezel drzewa binarnego" << endl;
    cout << "s - dodaj do drzewa binarnego czerwono - czarnego" << endl;
    cout << "x - znajdz wezel drzewa binarnego czerwono - czarnego" << endl;
    cout << "b - banchmarkuj metode dodaj do drzewa binarnego" << endl;
    cout << "c - banchmarkuj metode znajdz wezel drzewa binarnego" << endl;
    cout << "d - banchmarkuj metode dodaj wezel do drzewa czerwono - czarnego" << endl;
    cout << "e - banchmarkuj metode znajdz wezel drzewa czerwono - czarnego" << endl;
    cout << "w - wyjscie" << endl;

    do
    {
        cin >> choice;
        switch(choice)
        {
        case 'm':
                cout << "m - menu" << endl;
                cout << "a - dodaj do drzewa binarnego" << endl;
                cout << "p - preorder" << endl;
                cout << "f - znajdz wezel drzewa binarnego" << endl;
                cout << "s - dodaj do drzewa binarnego czerwono - czarnego" << endl;
                cout << "x - znajdz wezel drzewa binarnego czerwono - czarnego" << endl;
                cout << "b - banchmarkuj metode dodaj do drzewa binarnego" << endl;
                cout << "c - banchmarkuj metode znajdz wezel drzewa binarnego" << endl;
                cout << "d - banchmarkuj metode dodaj wezel do drzewa czerwono - czarnego" << endl;
                cout << "e - banchmarkuj metode znajdz wezel drzewa czerwono - czarnego" << endl;
                cout << "w - wyjscie" << endl;
                break;
        case 'a':
                cout << "Dodaj do drzewa:" << endl;
                cin >> k;
                T->add(k);
                cout << "Dodano." << endl;
                cout << "m - menu." << endl;
                break;
        case 'p':
                T->preorder();
                cout << endl << "m - menu." << endl;
                break;
        case 'f':
                cout << "znajdz wezel:" << endl;
                cin >> l;
                T->find(l);
                cout << "Znaleziono" << endl;
                cout << "m - menu." << endl;
                break;
        case 's':
            cout << "Dodaj do drzewa czerwono_czarnego" << endl;
            cin >> k;
            TR->add(k);
            cout << "Dodano." << endl;
            cout << endl << "m - menu." << endl;
            break;
        case 'x':
             cout << "znajdz wezel:" << endl;
             cin >> l;
             TR->find(l);
             cout << "znaleziono" << endl;
             cout << "m - menu." << endl;
            break;
        case 'b':
            T->benchmark_add();
            cout << "Zapisano wyniki do pliku timing.txt" << endl;
            cout << "m - menu." << endl;
            break;
        case 'c':
            T->benchmark_find();
            cout << "Zapisano wyniki do pliku timing.txt" << endl;
            cout << "m - menu." << endl;
            break;
        case 'd':
            TR->benchmark_add();
            cout << "Zapisano wyniki do pliku timing.txt" << endl;
            cout << "m - menu." << endl;
            break;
        case 'e':
            TR->benchmark_find();
            cout << "Zapisano wyniki do pliku timing.txt" << endl;
            cout << "m - menu." << endl;
            break;
        case 'w':
            break;
       default:
            cout << "nie rozpoznana opcja " << endl;
        }

    }while(choice!='w');
    return 0;
}
