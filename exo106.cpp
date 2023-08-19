#include <iostream>
using namespace std;

class vect
{
    int nelem;
    int *adr;

public:
    vect(int tailleAlloc)
    {
        adr= new int [tailleAlloc];
    }
    ~vect(){ delete adr;};
    int& operator[](int indice)
        {
            return *(adr+indice);
        }
};

class vectb: public vect
{
    int debut, fin;
public:
    vectb(int deb, int end):vect(end-deb+1)
    {
        debut=deb;
        fin=end;
    }

    int& operator [] (int i)
    {
        return vect::operator [] (i-debut);
    }
}

