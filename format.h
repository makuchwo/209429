#ifndef FORMAT_H_INCLUDED
#define FORMAT_H_INCLUDED
#include <string>
#include <windows.h>

using namespace std;

/*!
 *\file
 *przechowuje funkcje konwertujace
 *string
 */

/*!
 *\brief definicja funkcji intToString
 *konwersja ina na string
 *\param n zadany int
 *\return zwracany string
 */
string intToStr(int n)
{
     string tmp, ret;
     if(n < 0) {
      ret = "-";
      n = -n;
     }
     do {
      tmp += n % 10 + 48;
      n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.size()-1; i >= 0; i--)
      ret += tmp[i];
     return ret;
}



/*!
 *\brief definicja funkcji
 *zamienia liste intow(sciezka w grafie) na LPSTR
 *\param *C wskaznik na liste
 *\return sciezka w formacie LPSTR
 */
LPSTR ZamienFormat(Lista<int> *C)
{
    Lista<int> *tmp=C;
    string pom;
    string pom1;
        tmp=tmp->nastepny;

    for(int i=0;tmp;i++)
    {
        pom1 = intToStr(tmp->dane);
        pom=pom+"->";
        pom=pom+pom1;
        tmp=tmp->nastepny;
    }
    LPSTR s = const_cast<char *>(pom.c_str());
    return s;
}

#endif // FORMAT_H_INCLUDED
