#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sort.hh"

#define R 10

using namespace std;


int main()
{
   srand(time(NULL));
   int *t=new int[R];

for(int i=0; i<R; i++)
{
    t[i]=rand()%10;
}

for(int i=0; i<R; i++)
    cout << t[i] << " ";
    cout << endl;

 sort(t,0,R);


for(int i=0; i<R; i++)
    cout << t[i] << " ";
    cout << endl;


delete [] t;
return 0;
}
