#ifndef TREE_HH_INCLUDED
#define TREE_HH_INCLUDED
#include "benchmark.hh"
#include "node.hh"


/*!
 *\brief definicja klasy drzewo
 *Definiuje binarne drzewo zbudowane z wezlow galezi.
 */
class CTree : public CBenchmark {
    CNode *root; /*! korzen drzewa */
public:

 /*!
  *\brief definicja konstruktora bezparametrycznego
  *Ustawia korzen na NULL.
  */
  CTree();

  /*!
   *\brief definicja destruktora klasy CTree
   *wywoluje rekurencujnie destruktr klasy CNode
   *dopuki nie usunie korzenia.
   *Ustawia korzen na NULL.
   */
   ~CTree();

    /*!
     *\brief definicja metdy add
     *Tworzy nowy wezel, nastepnie dodaje go zgodnie
     *z regula drzewa binarnego.
     *Dodawany element zawsze staje sie lisciem.
     *\param k dodawana wartosc
     */
    void add(int k);

    /*!
     *\brief definicja metody preorder
     *wywoluje metode preorder klasy CNode
     *Wyswietla kolejno lewa galez drzewa, a nastepnie prawa.
     */
    void preorder()const;

    /*!
     *\brief definicja metody find
     *\param k szukany klucz
     *\return wskaznik na wezel o szukanym kluczu.
     */
    CNode* find(int k);

    /*!
     *\brief definicja metody get_min
     *\return wezel o najmniejszym kluczu
     */
    CNode* get_min();

    /*!
     *\brief definicja metody get_max
     *\return wezel o najwiekszym elemencie.
     */
    CNode* get_max();

    /*!
     *\brief definicja metody fill_random
     *Dodaje do drzewa liczby pseudolowe w zakresie 1-10.
     *Metoda obsewowana przez klase CBenchmark
     *Zapisuje do pliku timing.txt czas dodawania elementow.
     *\param x ilosc elementow pseudolosowych
     */
    void fill_random(int x);

    /*!
     *\brief definicja metody benchmark_add
     *Wywoluje metode fill_random
     *zawiera petle benchmarkujace w zakresie 1-10, 10-100, ... , 10 000.
     */
    int benchmark_add();

    /*!
     *\brief definicja metody find_random
     *\param quantity ilosc szukanych elementow
     *Przeszukuje drzewo binarne.
     *Metoda obserwowana przez klase CBenchmark.
     *Zapisuje do pliku timing.txt czas przeszuiwania drzewa.
     */
    void find_random(int quantity);

    /*!
     *\brief definicja metody benchmark_find
     *Wywoluje metode find_random.
     *Zawiera petle benchmarkujace w zakresie 1-10, 10-100, ... , 10 000 000.
     */
    int benchmark_find();
};

#endif // TREE_HH_INCLUDED
