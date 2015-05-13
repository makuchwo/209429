#ifndef LIST_HH_INCLUDED
#define LIST_HH_INCLUDED


/*!
 *\brief klasa lista - ADT
 * modeluje prost¹ liste jednokierunkowa
 * zwiera metody niezbedne do implementacji sortowania
 */
class CList {
    int value;  /* pojedynczy element listy */
    CList *next; /* wskaznik na nastepny element */
    public:
         CList();
         ~CList();

         /*!
          *\brief definicja funkcji wyswietlajacej
          * wyswietla na strumieniu wyjsciowym ciag elementow zapisanych na liscie
          */
         void print()const;

         /*!
          *\brief definicja metody push
          *dodaje nowy element na liste
          *\param element - dodawana komorka do listy
          */
         void push(int element);

         /*!
          *\brief definicja metody pop
          *usuwa element z lsity
          *\return usuwany element
          */
         int pop();

         /*!
          *\brief definicja metody get_value
          *odowluje sie do wybranego elemntu listy
          *\param i - indeks komórki listy
          *\return element o indeksie i
          */
         int get_value(int i)const;

         /*!
          *\brief definicja przeciazenia get_value
          *\return referencje do elementu na lsicie
          */
         int& get_value(int i);

         /*!
          *\brief definicja metody swap
          * zamienia elementy listy
          *\param i - inkeks do pierwszego elementu
          *\param j - indeks do drugiego elementu
          */
         void swap(int i, int j);

         /*!
          *\brief definicja metody is_empty
          *\return true - gdy lista jest pusta
          *\return false - w przypadku przeciwnym
          */
         bool is_empty();

         /*!
          *\brief definicja metody get_size
          *\return ilosc elementow na liscie
          */
         int get_size();

        /*!
         *\brief definicja metody pull
         *wypelnia liste liczbami pesudolosowymi
         *\param i - ilosc elementow
         */
         void pull(int i);
};

#endif // LIST_HH_INCLUDED
