#include <iostream>
#include "haszowanie.hh"

tablica::tablica(int n)
{
    rozmiar=n;
    tab=new dane[rozmiar];
}

tablica::~tablica()
{
    delete [] tab;
}

int tablica::Haszowanie(char* klucz)const
{
    int tmp=0;
    int dlugosc=0;
    char *tmp2=klucz;

    for(;*tmp2;++tmp2)
    dlugosc++;
      int *inty=new int[dlugosc];

    for(int i=0; i<dlugosc;i++)
    {
        inty[i]=klucz[i];
        tmp+=inty[i];
    }
    delete [] inty;
    return tmp%rozmiar;
}

int tablica::DrugieHaszowanie(char* klucz)const
{
    int q=rozmiar/2;
    if(q%2==0)
        q++;

    int tmp=0;
    int dlugosc=0;
    char *tmp2=klucz;

    for(;*tmp2;++tmp2)
    dlugosc++;
      int *inty=new int[dlugosc];

    for(int i=0; i<dlugosc;i++)
    {
        inty[i]=klucz[i];
        tmp+=inty[i];
    }
    delete [] inty;
    return q-tmp%q;
}

void tablica::Wypelnij(dane element)
{
    int i=Haszowanie(element.WezKlucz());
    int j=DrugieHaszowanie(element.WezKlucz());
    int k=0, l=0;

    if(tab[i].WezWartosc()==0)
    tab[i]=element;
    else

    if(tab[i+j].WezWartosc()==0)
    tab[i+j]=element;
    else
    {
        while(tab[i+j+k].WezWartosc()!=0)
        k++;

        if(i+j+k<=rozmiar)
        tab[i+j+k]=element;
        else
          while(tab[l].WezWartosc()!=0)
            l++;

          if(l>=rozmiar)
            std::cout << "przekroczono zakres tablicy" << std::endl;
            else
            tab[l]=element;
    }
}

void tablica::Wyswietl()const
{
    for(int i=0; i<rozmiar; i++)
    {
    std::cout << tab[i].WezWartosc() << " ";
    }
    std::cout << std::endl;
}

dane tablica::operator[](char* klucz)const
{
    int i=Haszowanie(klucz);
    int j=DrugieHaszowanie(klucz);
    int l=0;

    if(tab[i].WezKlucz()==klucz)
        return tab[i];
        else
            if(tab[i+j].WezKlucz()==klucz)
            return tab[i+j];
            else

/*
            while(tab[i+j+k].WezKlucz()!=klucz)
            k++;

            if(i+j+k>=rozmiar && tab[i+j+k].WezKlucz()!=klucz)
                {*/
                while(tab[l].WezKlucz()!=klucz)
                    l++;
                return tab[l];
                }


