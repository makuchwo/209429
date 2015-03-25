#ifndef KOLEJKA_HH_INCLUDED
#define KOLEJKA_HH_INCLUDED

/*!
 *\file
 *\brief definicja struktury danych Kolejka
 */

/*!
 *\brief definicja klasy Kolejka
 *Zbudowana na tablicy
 *posiada indeksy pokazujace na poczatek i na koniec kolejki.
 *Zbudowana na szablonie.
 */

template<typename typ>
class Kolejka {
int f; /*! poczatek */
int r; /*! koniec */
typ *tab; /*! przechowywane elementy */
int rozmiar; /*! max rozmiar tablicy */
public:
    Kolejka(int ilosc);
    Kolejka();
    ~Kolejka();
    int size()const;
    void enqueue(typ element);
    typ dequeue();
};

/*!
 *\brief definicja konstruktora z jednym parametrem
 *\param [ilosc] rozmiar alokowanej tablicy
 *Alokuje tablice o zadanym rozmiarze.
 *Ustawia indeksy na 0.
 */
template<typename typ>
Kolejka<typ>::Kolejka(int ilosc)
{
    rozmiar=ilosc;
    tab=new typ[rozmiar];
    f=r=0;
}

/*!
 *\brief definicja konstruktora bezparametrycznego
 *Zeruje rozmiar, ustawia wskaznik tablicy na NULL,
 *zeruje indeksy.
 */
template<typename typ>
Kolejka<typ>::Kolejka()
{
    rozmiar=0;
    f=r=0;
    tab=NULL;
}

/*!
 *\brief definicja destruktora
 *Zwalnia zaalokowana pamiec tablicy.
 *Zeruje indeksy i rozmiar.
 */
template<typename typ>
Kolejka<typ>::~Kolejka()
{
    delete [] tab;
    rozmiar=r=f=0;
}

/*!
 *\brief definicja metody size
 *\return rozmiar ilosci danych przechowywanych w tablicy.
 *\return 0, gdy kolejka jest pusta.
 */
template<typename typ>
int Kolejka<typ>::size()const
{

    if(rozmiar==0) return 0;
    else
    return (rozmiar-f+r) % rozmiar;
}

/*!
 *\brief definicja metody enqueue
 *\param [element] dodawany element
 *Dodaje element na koniec kolejki.
 *Gdy kolejka jest pelna, powieksza tablice o 5 i przekopiowywuje elementy.
 *zmienia polozenie indeksu konca.
 */
template<typename typ>
void Kolejka<typ>::enqueue(typ element)
{
 if(size()==rozmiar-1)
 {
    rozmiar+=5;
    typ *tmp=new typ[rozmiar];
    memcpy(tmp,tab,sizeof(typ)*rozmiar);
    tmp[r]=element;
    r=(r+1)%rozmiar;
    delete [] tab;
     tab=new typ[rozmiar];
     memcpy(tab,tmp,sizeof(typ)*rozmiar);
     delete [] tmp;
} else
 if(rozmiar==0)
 {
     rozmiar+=5;
     ++r;
     tab=new typ[rozmiar];
     tab[r-1]=element;
     r=(r)%rozmiar;
    } else  {
    tab[r]=element;
    r=(r+1)%rozmiar;
 }
}

/*!
 *\brief definicja metody dequeue
 *\return element z poczatku kolejki
 *\return 0 i wyswietla komunikat gdy kolejka jest pusta.
 *zmienia polozenie indeksu poczatku.
 */
template<typename typ>
typ Kolejka<typ>::dequeue()
{
    if(size()<=0)
    {
        std::cout << "Kolejka jest pusta." << std::endl;
        return 0;
    } else {
    typ tmp=tab[f];
    f=(f+1)%rozmiar;
    return tmp;
    }
}

#endif // KOLEJKA_HH_INCLUDED
