#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class tablica {
    int *tab;
    int rozmiar;
    public:

tablica(int x) { tab=new int[x]; rozmiar=x;}
~tablica() { delete [] tab; }
void losuj() { for(int i=0; i<rozmiar; i++) tab[i]=rand()%10; }
int& operator[](int i) { return tab[i]; }
int operator[](int i)const { return tab[i]; }


int* scal(int indeks1, int indeks2, int indeks_ostatni)
{
    int i1=indeks1;
    int i2=indeks2;
    int i=indeks1;


    int tmp[indeks_ostatni];

    do
    {
     if(i1==indeks2 || (i2<indeks_ostatni && tab[i1]>tab[i2]))
     {
         tmp[i]=tab[i2];
         i2++;
     } else

/*
     if(i2>indeks_ostatni)
     {
         tmp[i]=tab[i1];
         i1++;
     } else
*/
        {
        tmp[i]=tab[i1];
        i1++;
        }
    i++;
 }while(i<indeks_ostatni);


 for(int k=indeks1; k<indeks_ostatni; k++)
 {
     tab[k]=tmp[k];
 }
 delete [] tmp;
 return tab;
}

void sortowanie_scalanie(int indeks1, int indeks_ostatni)
{
    int *tmp=new int[indeks_ostatni];
    int i=(indeks1+indeks_ostatni)/2;
    if(i-indeks1>1)
    {
        sortowanie_scalanie(indeks1, i-1);
    } else
    if(indeks_ostatni-i>0)
    {
        sortowanie_scalanie(i,indeks_ostatni-1);
    } else
    scal(indeks1,i,indeks_ostatni);

/*
  for(int k=indeks1; k<indeks_ostatni; k++)
  {
        int i1=indeks1;
        int i2=i;

      if(i1==i || (i2<=indeks_ostatni && tab[i2]>tab[i2]))
         {
            tmp[k]=tab[i2++];
         } else
            tmp[k]=tab[i1++];
            for(int k=indeks1; k<indeks_ostatni; k++)
            {
                tab[k]=tmp[k];
            }
  }
  */
}
};

int main()
{
    srand(time(NULL));

    tablica t(10);
    t.losuj();

    for(int i=0;  i<10; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;

    t.sortowanie_scalanie(0,10);

    for(int i=0; i<10; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
    return 0;
}
