/*Une classe dérivée ProduitFugace qui hérite de deux classe: ProduitSaisonnier et ProduitPerissable
 qui eux aussi sont dérivées d'une classe de base Produit*/

#include <iostream>
#include <cstring>
using namespace std;

enum id{
    Produit,
    ProduitPerissable,
    ProduitSaisonnier,
    ProduitFugace

};

class Produit
{
protected:
    float Prix;
    char* Nom; //le pointeur autorise les les descriptions de longueur variable
    void fixeNom(const char* texte);

public:
    Produit(float prix, char* nom)
    {
        Prix= prix;
        fixeNom(nom);
    }

    ~Produit(){ delete Nom; }

    virtual id idClasse(){ return Produit; }
};

class ProduitPerissable: public Produit
{
    int delai;
public:
    ProduitPerissable(float prix, char* nom, int Delai): Produit(prix, nom), delai(Delai)
    {}

    id idClasse(){  return ProduitPerissable; }
};

int main()
{
    return 0;
}

void Produit::fixeNom(const char* texte)
{
    Nom= new char[strlen(texte)+1];
    strcpy(Nom, texte);
}
