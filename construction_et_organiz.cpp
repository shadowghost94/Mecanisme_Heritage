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
    void Affichage()
    {
        cout<<"Affichage des éléments du tableau..."<<endl;
        for(int i=0; i<d; i++)cout<<t[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    TableauEntier T(50);
    T.Affichage();
    T[49]=8;
    cout<<T[49]<<endl;

    TableauEntier Y(T);
    Y.Affichage();
    return 0;
}

/* fonction membre privée d'initialisation de t et d */
void TableauEntier::alloue(int Dim)
{
    t= new int [d=Dim];

    for(int i=0; i<d; i++)t[i]=0;
}

/* fonction membre privée qui permet de vérifier la validité d'un rang */
int TableauEntier::ValideRang(int Index) const
{
    if(Index<0 || Index>=d)
    {
        cerr<<"La valeur d'index entré est incorrecte. Veuillez corriger et réessayer."<<endl;
        exit(1);
    }

    return Index;
}

/*fonction membre privée de surdéfinition de l'opérateur d'affectation */
TableauEntier& TableauEntier::operator = (const TableauEntier& Source)
{
    /*

     *on supprime l'ancienne espace mémoire sur laquelle pointait le t de l'objet implicite
     *on affecte au d de l'objet implicite la dimension d de l'objet explicite
     * on alloue un nouveau tableau de dimensio d et on fait pointé t sur lui

     */

    delete t;
    d=Source.d;
    t= new int [d];

    for(int i=0; i<d; i++)
    {
        t[i]=Source.t[i];
    }

    return *this;
};

TableauEntier::TableauEntier(int Dimension)
{
    t= new int [d=Dimension];
};

TableauEntier::TableauEntier(const TableauEntier& recop)
{
    t= new int [d= recop.d];

    for(int i=0; i<d; i++)t[i]=recop.t[i];
};

int& TableauEntier::operator [] (int R)
{
    return t[ValideRang(R)];
};
