#ifndef GRAPH_HH_INCLUDED
#define GRAPH_HH_INCLUDED
#include "benchmark.hh"

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
class CGraph : public CBenchmark {
    int V; /*! ilosc wezlow */
    int E; /*! ilosc krawedzi */
    CNode *ListV;  /*! tablica wezlow */
    CEdge *ListE; /*! tablica krawedzi */
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
    void set_graph(int edge1, int vertice1, int vertice2);

    /*!
     *\brief definicja metody print_maatrix
     *wyswietla macierz sasiedztwa
     */
    void print_matrix()const;

    /*!
     *\brief definicja metody search
     *metoda powinna zwracac liste krawedzi
     *prowadzoca do danego elementu
     *WYMAGA DOPRACOWANIA
     *\param key szukany klucz/element
     *\return lista krawiedzi
     */
    CEdge* search(int key);

    /*!
     *\brief definicja metody DFSing
     *przeszukuje graf algorytmem DFS (przeszukiwanie w glab)
     *zaimplementowana rekuencyjnie
     *wykorzystana w metodzie DFS wyposarzonej w timery
     *\param v element poczatkowy od ktorego algorytm rozpoczyna przeszukiwanie
     */
    void DFSing(int v);

    /*!
     *\brief definicja metody DFS
     *wywoluje metode DFSing
     *posiada timery zapisujace zmierzony czas do pliku
     *\param v element poczatkowy od ktorego algorytm DFS rozpoczyna przeszukiwanie
     */
    void DFS(int v);

    /*!
     *\brief definicja meotdy BFS
     *przeszukuje graf algorytmem BFS (przeszukiwanie w wszerz)
     *posiada timery zapisujace zmierzony czas do pliku
     *nie jest zaimplementowana rekurencyjnie, nie wymaga zewnetrznej metody
     *\param v element poczatkowy od ktorego algorytm DFS rozpoczyna przeszukiwanie
     */
    void BFS(int v);

    /*!
     *\brief definicja metody make_random_graph
     *tworzy graf o losowych wezlach oraz losowych krawedziach
     *przypisuje this na wygenerowanych graf
     *\param sizeV ilosc wierzholkow
     *\param sizeE ilosc krawedzi
     *\return losowy graf
     */
    CGraph* make_random_graph(int sizeV, int sizeE);

    /*!
     *\brief definicja metody benchmarking_DFS
     *metoda posiada petle wywolujace metode DFS
     *w zakresie 1-10 000
     *dzieki timerom do pliku zostaja zapisane dane benchmarku
     */
    void benchmarking_DFS();

    /*!
     *\brief definicja metody benchmarking_BFS
     *metoda posiada petle wywolujace metode BFS
     *w zakresie 1-10 000
     *dzieki timerom do pliku zostaja zapisane dane benchmarku
     */
    void benchmarking_BFS();
};

#endif // GRAPH_HH_INCLUDED
