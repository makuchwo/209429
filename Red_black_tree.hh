#ifndef RED_BLACK_TREE_HH_INCLUDED
#define RED_BLACK_TREE_HH_INCLUDED
#include "Red_black_node.hh"
#include "benchmark.hh"

/*!
 *\brief definicja klasy CRed_Black_Tree
 *Definiuje Drzewo czerwono - czarne
 *Posiada wartownika na lisciach.
 *Drzewo czerwono-czarne spelnia nastepujace wlasnosci
 *1) Każdy węzeł jest czerwony lub czarny.
 *2) Korzeń jest czarny.
 *3) Każdy liść jest czarny (Można traktować nil jako liść).
 *4) Jeśli węzeł jest czerwony, to jego synowie muszą być czarni.
 *5) Każda ścieżka z ustalonego węzła do liścia liczy tyle samo czarnych węzłów.
 */
class CRed_Black_Tree : public CBenchmark {
    CRed_Black_Node S;  /*! wartownik */
    CRed_Black_Node* root;  /*! wskaznik na korzen drzewa czerwono-czarnego. */
public:

    /*!
     *\brief definicja konstruktora bezparametrycznego
     *Ustawia wszystkie wskazniki wezla drzewa na wartownika
     */
    CRed_Black_Tree();

    /*!
     *\brief definicja destruktora klasy
     */
    ~CRed_Black_Tree();

    /*!
     *\brief definicja metody find
     *\param k szukany klucz
     *\return wskaznik na wezel przechowujacy klucz
     *Przeszukuje drzewo czerwono-czarne.
     */
    CRed_Black_Node * find(int k);

    /*!
     *\brief definicja metody min
     *\return wezel o najmniejszym kluczu
     */
    CRed_Black_Node * min(CRed_Black_Node* tmp);

    /*!
     *\brief definicja metody max
     *\return wezel o najwiekszym kluczu
     */
    CRed_Black_Node* max(CRed_Black_Node *r);

    /*!
     *\brief definicja metody rotate_left
     *Wykonuje rotacje w lewo.
     *zmienia this z prev, ustawiajac this jako lewego syna.
     *Ustawia rodzica (up) na rodzica wezla this.
     *Ustawia lewego syna this jako prawy syn prev.
     *\param prev obracany wezel nadrzedny przy zalozeniu, ze obracanym wezlem podrzednym jest this.
     */
    void rotate_left(CRed_Black_Node* prev);

    /*!
     *\brief definicja metody rotate_right
     *Wykonyje rotacje w prawo.
     *zmienia this z prev, ustawiajac this jako prawego syna.
     *Ustawia rodzica (up) na rodzica wezla this.
     *Utawia prawego syna this jako lewy syn prav.
     *\param prev obracany wezel nadrzedny przy zalozeniu, ze obracanym wezlem podrzednym jest this.
     */
    void rotate_right(CRed_Black_Node* prev);

    /*!
     *\brief definicja metody add
     *Tworzy Wezel drzewa czerwono czarnego o kluczu k i dodaje do go drzewa
     *zgodnie z regulal drzewa binarnego. Koloruje go na czerwono.
     *Przywraca wlasciwosc dzewa czerwno czarnego zgodnie z przypadkami
     *1) Gdy ojciec i wuj sa czerwoni, zmien ich kolory.
     *2) Gdy lewy ojeciec i jego lewy syn sa czeroni, wykonaj obrot w prawo dziadka i ojca oraz zamien ich kolory.
     *3) Gdy lewy ojciec i jego prawy syn sa czerwoni, wykonaj obrot w lewo ojca i syna oraz wykonaj 2).
     *4) Gdy prawy ojciec i jego prawy syn sa czerwoni, wykonaj obrot w lewo  dziadka i ojca, zamien ich kolory
     *5) Gdy prawy ojciec i jego prawy syn sa czerwoni, wykonaj obrot w prawo ojca i syna oraz wykonaj 4)
     *\param k dodawany klucz do drzewa czerwono-czarnego
     */
    void add(int k);

    /*!
     *\brief definicja metody fill_random
     *dziala analogicznie jak metoda klasy CTree
     *\param x - ilosc elementow pseudolosowych
     */
    void fill_random(int x);

    /*!
     *\brief definicja metody benchmark_add
     *Dzia³a analogicznie jak metoda klasy CTree
     */
    int benchmark_add();

    /*!
     *\brief definicja metody find_random
     *Dzia³a analogicznie jak metoda klasy CTree
     */
    void find_random(int quantity);

    /*!
     *\brief definicja metody benchmark_find
     *Dziala analogicznie jak metoda klasy CTree
     */
    int benchmark_find();
};

#endif // RED_BLACK_TREE_HH_INCLUDED
