#include <iostream>
using namespace std;

class TableauEntier
{
    int *t;                         //pointera sur l'espace alloué au tableau
    int d;                    //dimension du tableau
    void alloue(int Dim);           //fonction d'initialisation de t et d
    int ValideRang(int Index) const;//fonction renvoie index s'il représente un rang d'éléments

    TableauEntier& operator = (const TableauEntier& Source);

public:
    TableauEntier(int Dimension);
    TableauEntier(const TableauEntier& recop);      //constructeur par recopie
    int& operator [] (int R);                       //redefinition de l'operateur []

};

int main()
{
    return 0;
}

void TableauEntier::alloue(int Dim)
{
    t= new int [d=Dim];
}

int TableauEntier::ValideRang(int Index) const
{
    if(Index<0 || Index>=d)
    {
        cerr<<"La valeur d'index entré est incorrecte. Veuillez corriger et réessayer."<<endl;
        exit(1);
    }

    return Index;
}
