#include <iostream>
using namespace std;

class point
{
    int x,y;
public:
    point(int abs, int ord)
    {
        cout<<"++ constructeur point "<<abs<<" "<<ord<<endl;
        x=abs;
        y=ord;
    }

    point()
    {
        cout<<"++ constructeur par défaut point "<<endl;
        x=0;
        y=0;
    }

    void affiche()
    {
        cout<<"Coordonnées: "<<x<<" "<<y<<endl;
    }
};

class coul
{
    short couleur;
public:
    coul(short cl)
    {
        cout<<"++ constructeur. short "<<cl<<endl;
        couleur=cl;
    }

    void affiche()
    {
        cout<<"Couleur: "<<couleur<<endl;
    }
};

class masse
{
    int mas;
public:
    masse(int m)
    {
        cout<<"++constr. masse "<<m<<endl;
        mas= m;
    }

    void affiche()
    {
        cout<<"Masse : "<<mas<<endl;
    }
};

class pointcoul: public virtual point, public coul
{
public:
    pointcoul(int abs, int ord, int cl): coul(cl)
    //pas d'info pour point car dérivation virtuelle
    {
        cout<<"++++ Constr. pointcoul "<<abs<<" "<<ord<<" "<<cl<<endl;
    }

    void affiche()
    {
        point::affiche();
        coul::affiche();
    }

};

class pointmasse: public virtual point, public masse
{
public:
    pointmasse(int abs, int ord, int m): masse(m)
    //pas d'info pour point car dérivation virtuelle
    {
        cout<<"++++Constr. pointmasse "<<abs<<" "<<ord<<" "<<m<<endl;
    }

    void affiche()
    {
        point::affiche();
        masse::affiche();
    }
};

class pointCoulMasse: public pointcoul, public pointmasse
{
public:
    pointCoulMasse(int abs, int ord, short c, int m): point(abs, ord), pointcoul(abs, ord,c), pointmasse(abs, ord, m)
    //infos sur abs ord en fait inutiles pour pointcoul et pointmasse
    {
        cout<<"++++Constr. pointCoulMasse "<<abs+" "<<ord<<" "<<c<<" "<<m<<endl;
    }

    void affiche()
    {
        point::affiche();
        coul::affiche();
        masse::affiche();
    }
};

int main()
{
    pointcoul p(3,9,2);
    p.affiche();

    pointmasse pm(12,25,100);
    pm.affiche();

    pointCoulMasse pcm(2,5,10,20);
    pcm.affiche();
    return 0;
}
