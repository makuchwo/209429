#ifndef GRAPH_HH_INCLUDED
#define GRAPH_HH_INCLUDED
#include <fstream>
#include "stack.hh"

/*!
 *\file graph.hh
 *\brief zwiera definicje klas CNode, CEdge, CGrpah
 *CNode - wezel grafu
 *CEdge - krawedz grafu
 *CGraph - graf
 */

/*!
 *\brief definicja klasy CNode
 *definiuje pojedynczy wezel grafu
 */
class CNode {
friend class CEdge;
friend class CGraph;
    int value; /*! element przechowywany w wezle */
};

/*!
 *\brief definicja klasy CEdge
 *definuje krawedz grafu
 *nie zawiera wag
 */
class CEdge {
friend class CGraph;
    CNode *prev; /*! wskaznik na poprzedni wezel */
    CNode *next; /*! wskaznik na nastepny wezel */
};


/*!
 *\brief definicja klasy CGraph
 *definije graf skierowany
 *bez wagowaych krawedzi
 *dziedzicy po klasie CBenchmark
 */
class CGraph {
    public:
    int V; /*! ilosc wezlow */
    int E; /*! ilosc krawedzi */

    int **matrix; /*! macierz sasiedztwa */
    bool* visited; /*! lista odwiedzonych elementow grafu */

public:

    /*!
     *\brief definicja konstruktora parametrycznego
     *alokuje pamiec dla tablic wezlow krawdzi oraz dla macierzy sasiedztwa
     *\param v ilosc wezlow
     *\param e ilosc krawedzi
     */
    CGraph(int v, int e);

    /*!
     *\brief definicja destruktora
     */
    ~CGraph();

    /*!
     *\brief definicja metody set_graph
     *wiaze wezly wskaznikami
     *krawdziom ustawia odpowiednie wezly
     *wypelnia macierz sasiedztwa
     *\param edge1 krawdz do ktorej przypisujemy poszczegolne wierzcholki
     *\param vertice1 przypisywany pierwszy wierzcholek
     *\param vertice2 przypisywany drugi wierzcholek
     */
    void set_graph(int vertice1, int vertice2);

    /*!
     *\brief definicja metody print_maatrix
     *wyswietla macierz sasiedztwa
     */
    void print_matrix()const;

    /*!
     *\brief definicja metody DFSing
     *przeszukuje graf algorytmem DFS (przeszukiwanie w glab)
     *zaimplementowana rekuencyjnie
     *wykorzystana w metodzie DFS wyposarzonej w timery
     *\param v element poczatkowy od ktorego algorytm rozpoczyna przeszukiwanie
     */
    void DFS(int v);

    /*!
     *\brief definicja metody DFS
     *wywoluje metode DFSing
     *posiada timery zapisujace zmierzony czas do pliku
     *\param v element poczatkowy od ktorego algorytm DFS rozpoczyna przeszukiwanie
     */
    void BFS(int v);


    /*!
     *\brief definicja metody save_matrix
     *zapsiuje macierz saciedztwa do pliku
     *\param file uchwyt do pliku
     */
    void save_matrix(std::fstream& file)const;

    /*!
     *\brief definicja metody BFSPath
     *Oblicza najszybsza sciezke w grafie
     *miedzy punktem startowym, a koncowym
     *i zapisuje ja na stosie
     *\param start punkt startowy
     *\param meta punkt koncowy
     *\param *L wskaznik do stosu,
     *na ktorym sa zapisane elementy
     */
    bool BFSPath(int start, int meta, Lista<int> *L);
};

#endif // GRAPH_HH_INCLUDED
