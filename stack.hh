#ifndef STACK_HH_INCLUDED
#define STACK_HH_INCLUDED
#include <iostream>

/*!
 *\file
 *\brief definicja struktury danych Lista
 */

/*!
 *\brief definicja klasy Lista
 *Przechowuje obiekt oraz wskaznik na nastepny i pole rozmiar.
 *Zbudowana na szablonie.
 */
template<typename typ>
class Lista {
    public:
    Lista<typ>* nastepny; /*! wskaznik na nastepny obiekt/element */
    typ dane;               /*! przechowywana informacja/obiekt/element */
    int rozmiar;            /*! ilosc elementow/obiektow */
public:
    Lista();
    ~Lista();
    void push(typ element);
    typ pop();
    int size()const;
    void wyswietl();
};


/*!
 *\brief definicja konstruktora bezparametrycznego
 *Zeruje rozmiar, ustawia wskaznik na NULL.
 */
template<typename typ>
Lista<typ>::Lista()
{
    nastepny=NULL;
    rozmiar=0;
}

/*!
 *\brief definicja metody push
 *\param [element] dodawany element na koniec listy
 *Zwieksza rozmiar, alokuje pamiec, przypisuje element do pola klasy.
 */
template<typename typ>
void Lista<typ>::push(typ element)
{
    rozmiar++;
    Lista<typ> *tmp=new Lista<typ>;
    tmp->dane=element;
    tmp->nastepny=nastepny;
    nastepny=tmp;
}

/*!
 *\brief definicja metody pop
 *\return usuwany element
 *Ustawia wskaznik na poprzedni element
 *zwraca i kasuje ostatni element.
 *\return 0 i wyswietla komunikat gdy lista jest pusta.
 */
template<typename typ>
typ Lista<typ>::pop()
{
    if(nastepny==NULL)
    {
        std::cout << "Lista jest pusta." << std::endl;
        return 0;
    } else {
    rozmiar--;
    Lista<typ> *tmp=nastepny;
    nastepny=tmp->nastepny;
    // nastepny=nastepny->nastepny;
    return tmp->dane;
    delete tmp;
    }
}

/*!
 *\brief deinicja metody size
 *\return ilosc elementow przechowywanych na liscie.
 */
template<typename typ>
int Lista<typ>::size()const
{
    return rozmiar;
}

/*!
 *\brief definicja destruktora
 *Zeruje rozmiar,
 *Kasuje wszystkie obiektry/elementy.
 */
template<typename typ>
Lista<typ>::~Lista()
{
    while(nastepny!=NULL)
    pop();
    rozmiar=0;
}

template<typename typ>
void Lista<typ>::wyswietl()
{
    Lista<typ> *tmp=nastepny;
    while(tmp)
    {
        std::cout << tmp->dane << std::endl;
        tmp=tmp->nastepny;
    }
}

#endif // STACK_HH_INCLUDED
