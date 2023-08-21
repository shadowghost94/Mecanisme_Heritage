#include <iostream>
#include <cstring>
using namespace std;

const int NbMax=25;
class Produit
{
protected:
    char nom[NbMax+1];
    float Prix;
    void fixeNom(const char*);

public:
    Produit(const char* Nom, float prix)
    {
        fixeNom(Nom);
        Prix= prix;
    }
    float prix()const{ return Prix; } //accesseur de prix. Const pour indiquer la fonction
                                    //ne modifie aucun attribut
    const char* NomAcces(){ return nom; }

    void afficheToi()
    {
        cout<<"Produit: "<<nom<<endl;
        cout<<"Prix: "<<Prix<<endl;
    }

    virtual void AfficheClasse()
    {
        cout<<"Ma classe est Produit"<<endl;
    }

};

class ProduitPerissable: public Produit
{
    int delai;  //durée de conservation
public:
    ProduitPerissable(const char* Nom, int del, float Prix): Produit(nom, Prix)
    {
        delai= del;
    }

    void afficheToi()
    {
        Produit::afficheToi();
        cout<<"Validité: "<<delai<<" jours."<<endl;
    }

    void AfficheClasse()
    {
        cout<<"Ma classe est ProduitPerissable."<<endl;
    }
};

class ProduitSaisonnier: public Produit
{
    const char* saison;
public:
    ProduitSaisonnier(const char* nom, const char* Saison, float prix ):Produit(nom,prix)
    {}

    void AfficheClasse()
    {
        cout<<"Ma classe est ProduitSaisonnier."<<endl;
    }
};

int main()
{
    Produit P1("Chocolat", 4.50);
    P1.AfficheClasse();

    ProduitPerissable P2("Yaourt", 12, 4.50);
    P2.AfficheClasse();

    ProduitSaisonnier P3("Moufles", "Pluvieuse", 4.50);
    P3.AfficheClasse();
    cout<<endl;

    /*Test de la fonction virtuel...*/
    cout<<"1, 2, 3 on test la fonction virtuel en utilisant le mot clé, virtual..."<<endl;
    Produit* Stock[3]= {&P1, &P2, &P3};
    for(int i=0; i<3; i++)Stock[i]->AfficheClasse();

    return 0;
}

void Produit::fixeNom(const char *texte)
{
    strncpy(nom, texte, NbMax);
    nom[NbMax]='\0';
}
