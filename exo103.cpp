#include <iostream>
using namespace std;

class point
{
    float x,y;
public:
    point (float abs, float ord)
    {
        x=abs;
        y=ord;
    }
    void affiche()
    {
        cout<<"Coordonnées: "<<x<<" "<<y<<endl;
    }
    void deplace(float dx, float dy)
    {
        x=x+dx;
        y=y+dy;
    }
};

class pointcol: public point
{
    int cl;
public:

    pointcol(float=0.0, float=0.0, int=0);

    void affiche()
    {
        cout<<"Couleur: "<<cl<<endl;
        point::affiche();
    }

    void colore(int couleur)
    {
        cl= couleur;
    }
};

int main()
{
    pointcol(2.5, 3.25, 5);
    /**
     L'instruction ci-dessus entraine la création d'un emplacement mémoire
     pour une instance de type pointcol, lequel est initialisé successivement
        *par appel du constructeur point grâce à l'instruction <point(abs, ord)>
        *par appel du constructeur pointcol avec le troisième argument <int couleur>
     */
}

pointcol::pointcol(float abs, float ord, int couleur): point(abs, ord)
{
    cl= couleur;
}
