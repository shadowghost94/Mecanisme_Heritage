#include <iostream>
#include <cstring>
using namespace std;

//const NbMaxCarac=25;

class Produit
{
    char nom[26];
    float prix;
    void fixeNom(const char*);

public:
    Produit(const char* nom, float prix)
    {
        fixeNom(nom);
        prix= prix;
    }

};

int main()
{
    return 0;
}

void Produit::fixeNom(const char *texte)
{
    strncpy(nom, texte, 26);
    nom[26]='\0';
}
