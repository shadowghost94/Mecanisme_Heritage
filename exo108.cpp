#include <iostream>
using namespace std;

class vect
{
protected:
    int nelem;  //nombre d'éléments courant dans une instance de vect
    int* adr;   //pointeur à initialiser sur le premier élément du tableau dynamique
public:
    vect(int tailleAlloc)
    {
        adr= new int[tailleAlloc];
    };
    ~vect(){}
    int& operator [] (int indice)
    {
        return *(adr+indice);
    }
};

class vectok:public vect
{
public:
    vectok(int tailleAlloc): vect(tailleAlloc){};
    int taille(){ return nelem;}
    vectok& operator = (const vectok& objet0)
    {
            if(this!= &objet0)
            {
                delete adr;
                adr= new int [nelem=objet0.nelem];

                for(int i; i<nelem; i++)adr[i]=objet0.adr[i];
            }
            return *this;

    }

};

void fct(vectok &v)
{
    cout<<"Ici fonction fct. J'ai bien reçu en argument un vecteur. Voici son contenu..."<<endl;
    for(int i=0; i<v.taille(); i++)cout<<v[i]<<" ";
}

int main()
{
    vectok v(6);
    for(int i=0; i<v.taille(); i++)v[i]=i;
    cout<<"Affichage de vecteur..."<<endl;
    fct(v);

    vectok w(3);
    w=v;
    cout<<"Affichage du vecteur w..."<<endl;
    fct(w);


    return 0;
}


