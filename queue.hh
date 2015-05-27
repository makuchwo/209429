#ifndef QUEUE_HH_INCLUDED
#define QUEUE_HH_INCLUDED
#include <iostream>

/*!
 *\file queue.hh
 *\brief zawiera definicje klas queue_node, queue
 *queue_node -  wezel kolejki
 *queue - kolejka
 */

/*!
 *\brief definicja klasy queue_node
 *definicja wezla dla kolejki
 *definiuje pojedynczy element bedacy w kolejkce
 */
class queue_node {
public:
  queue_node *next; /*! wskaznik na nastepny */
  int data; /*! dane */
};

/*!
 *\brief definicja klasy queue
 *definicja kolejki
 *ADT, kolejka typu FIFO
 *zimplementowaa na liscie
 */
class queue {
public:
    queue_node *first; /*! wskaznik na pierwszy element */
    queue_node *last; /*! wskaznik na ostatni element */
public:

    /*!
     *\brief definicja metody push
     *dodaje element na koniec kolejki
     *\param element dodawany element
     */
    void push(int element);

    /*!
     *\brief definicja metody pop
     *usuwa element z poczatku kolejki
     */
    void pop();

    /*!
     *\brief definicja destruktora
     */
    ~queue();

    /*!
     *\brief desfinicja konstruktora bezparametrycznego
     *ustawia wskazniki na NULL
     */
    queue() : first(NULL), last(NULL) {}

    /*!
     *\brief definicja metody print
     *wyswietla zawartosc kolejki
     */
    void print()const;
};

#endif // QUEUE_HH_INCLUDED
