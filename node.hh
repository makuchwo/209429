#ifndef NODE_HH_INCLUDED
#define NODE_HH_INCLUDED
#include "benchmark.hh"

/*!
 *\brief definicja klasy CNode
 *Definijue pojedynczy wezel drzewa binarnego.
 *Jest zaprzyjazniona z klasa CTree.
 */
class CNode {
friend class CTree;
  int value; /*! przechowywane dane */
  CNode *up; /*! wskaznik na rodzica */
  CNode *left; /*! wskaznik na lewego syna */
  CNode *right; /*! wskaznik na prawego syna */
public:
    /*!
     *\brief definicja konstruktora bezparametrycznego
     *Ustawia wskazniki na NULL.
     */
    CNode() : left(NULL), right(NULL), up(NULL), value(0) {}

    /*!
     *\brief definicja destruktora klasy CNode
     */
    ~CNode();

    /*!
     *\brief definicja metody preorder
     *Definiuje przechodzenie przez drzewo odwiedzajac wszystkielefe galzezie,
     *nastepnie wszystkie prawe galezie.
     *Jest wywolywana w klasie CTree.
     *Metoda nie zmienia stanu obiektu.
     */
    void preorder()const;
};

#endif // NODE_HH_INCLUDED
