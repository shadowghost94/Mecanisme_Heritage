#include <iostream>
using namespace std;

class point
{
    float x,y;
public:
    point(float abs, float ord)
    {
        x=abs;
        y= ord;
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

class pointcol
{
    point p;
    int col;
public:
    pointcol(float=0.0, float=0.0, int=0);
    void affiche()
    {
        cout<<"Color: "<<col<<endl;
        p.affiche();
    }

    void colore(int couleur)
    {
        col=couleur;
    }

};

int main()
{}

pointcol::pointcol(float abs, float ord, int color): p(abs, ord)
{
    col= color;
}
