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

    void afficheur()                                  //fonction d'affichage de tableau
    {
        for(int i=0; i<d; i++)cout<<t[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    TableauEntier objet0(5);
    cout<<"Affichage des valeurs juste après création de l'objet histoire d'avoir une idée de son contenu."<<endl;
    objet0.afficheur();

    cout<<"Maintenant nous allons attribuer des valeurs à chaque éléments..."<<endl;
    objet0[0]=0;
    objet0[1]=5;
    objet0[2]=3;
    objet0[3]=1;
    objet0[4]=2;

    cout<<"Affichage de nouveau du contenu après remplissage..."<<endl;
    objet0.afficheur();
    cout<<endl;

    cout<<"création d'un deuxième objet et test du constructeur par recopie "<<endl;
    TableauEntier objet1(objet0);
    cout<<"Affichage du contenu de l'objet crée dernièrement "<<endl;
    objet1.afficheur();

    return 0;
}

TableauEntier::TableauEntier(int Dimension)
{
    alloue(Dimension);
}

TableauEntier::TableauEntier(const TableauEntier& recop)
{

    alloue(d= recop.d);

    for(int i=0; i<d; i++)t[i]=recop.t[i];

}

void TableauEntier::alloue(int Dim)
{
    t= new int [d=Dim];
    for(int i=0; i<d; i++)t[i]=0;
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

inline int& TableauEntier::operator [] (int R)
{
    return t[ValideRang(R)];
}

TableauEntier& TableauEntier::operator = (const TableauEntier& Source)
{
    delete t;
    d= Source.d;

    alloue(d);

    for(int i=0; i<d; i++)t[i]=Source.t[i];

    return *this;
}
