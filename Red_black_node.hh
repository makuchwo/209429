#ifndef RED_BLACK_NODE_HH_INCLUDED
#define RED_BLACK_NODE_HH_INCLUDED
#include <iostream>


/*!
 *\brief definicja klasy CRed_Black_Node
 *definicja wezla drzewa czerwono-czarnego.
 *Klasa zaprzyjazniona z klasa CRed_Black_Tree
 */
class CRed_Black_Node {
friend class CRed_Black_Tree;
  CRed_Black_Node* up;  /*! wskaznik na rodzica */
  CRed_Black_Node* left; /*! wskaznik na lewego syna */
  CRed_Black_Node* right; /*! wskaznik na prawego syna */
  int value; /*! [rzechowywana wartosc */
  char color; /*! informacja o kolorze wezla */
public:

    /*!
     *\brief definicja konstruktora bezparametrycznego
     *ustaiwa wskazniki na NULL.
     */
      CRed_Black_Node() : up(NULL), left(NULL), right(NULL) {}

      /*!
       *\brief definicja destruktora klasy
       */
      ~CRed_Black_Node();
};

#endif // RED_BLACK_NODE_HH_INCLUDED
