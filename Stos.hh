#ifndef STOS_HH_INCLUDED
#define STOS_HH_INCLUDED


/*!
 *\file
 *\brief definicja struktruy danych Stos
 */


/*!
 *\brief definicja klasy Stos
 * zedfiniowany za pomoca tablicy.
 * Klasa zbudowana na szablonie.
 */
template<typename typ>
class Stos {
int rozmiar; /*! rozmiar stosu */
typ *tab;    /*! alokowana pamiec */
public:
    Stos(typ p);
    Stos();
    ~Stos();
    void push(typ element);
    typ pop();
    int size()const;
};


/*!
 *\brief definicja konstruktora z jednym parametrem
 *\param [p] rozmiar ilosci alokowanej pamieci
 *alokuje pamiec o zadanym rozmiarze
 */
template<typename typ>
Stos<typ>::Stos(typ p)
{
    rozmiar=p;
    tab=new typ[rozmiar];
}

/*!
 *\brief definicja konstruktora bezparametrycznego
 *zeruje rozmiar, przypisuje NULL do wskaznikow.
 */
template<typename typ>
Stos<typ>::Stos()
{
    rozmiar=0;
    tab=NULL;
}

/*!
 *\brief definicja destruktora
 * Zwalnia pamiec, zeruje rozmiar.
 */
template<typename typ>
Stos<typ>::~Stos()
{
    delete [] tab;
    rozmiar=0;
}

/*!
 *\brief definicja metody push
 *\param [element] dodany element na koniec stosu
 *zwieksza rozmiar o 1, alokuje nowa tablice, kopiuje zawartosc
 *starej do nowej, kladzie element na ostatniej pozycji,
 *realokuje  i przekopiowuje zawartosc do pierwotenj tablicy,
 *usuwa tablice pomocnicza.
 */
template<typename typ>
void Stos<typ>::push(typ element)
{
    ++rozmiar;
    int *tmp=new typ[rozmiar];
    memcpy(tmp,tab,sizeof(int)*(rozmiar-1));
    tmp[rozmiar-1]=element;
    delete [] tab;
    tab=new typ[rozmiar];
    memcpy(tab,tmp,sizeof(int)*size());
    delete [] tmp;
}

/*!
 *\brief definicja metody pop
 *zmmniejsza rozmiar o 1,
 *\return usuwany element
 *\return 0 i wyswietla komunikat, kiedy stos jest pusty.
 */
template<typename typ>
typ Stos<typ>::pop()
{
    if(rozmiar==0)
    {
        std::cout << "Stos jest pusty." << std::endl;
        return 0;
    } else {
    typ tmp;
    tmp=tab[rozmiar-1];
    rozmiar--;
    return tmp;
    }
}

/*!
 *\brief definicja metody size
 *\return rozmiar stosu
 */
template<typename typ>
int Stos<typ>::size()const
{
    return rozmiar;
}

#endif // STOS_HH_INCLUDED
