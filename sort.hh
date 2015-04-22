#ifndef SORT_HH_INCLUDED
#define SORT_HH_INCLUDED


void sort(int *tab,int prawy,int lewy)
{
  int srodkowy,indeks1,indeks2;
  int dlugosc=0;

for(int i=0; tab[i]!=NULL; i++)
dlugosc++;

      int *tmp=new int[2*dlugosc];

  srodkowy = (prawy + lewy + 1) / 2;


  if(srodkowy-prawy>1) sort(tab,prawy, srodkowy-1);
  if(lewy-srodkowy>0)  sort(tab,srodkowy,lewy);


  indeks1 = prawy;
  indeks2 = srodkowy;

  for(int i=prawy; i<=lewy; i++)
  {
    if((indeks1==srodkowy) || ((indeks2<=lewy) && (tab[indeks1]>tab[indeks2])))
    {
      tmp[i] =tab[indeks2++];
    } else {
      tmp[i]=tab[indeks1++];
    }
  }
  for(int j=prawy; j<=lewy; j++)
    tab[j] = tmp[j];
}

#endif
