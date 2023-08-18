#include <iostream>
using namespace std;

class point
{
    float x,y;
public:
    point(float abs=0.0, float ord=0.0)
    {
        x=abs;
        y=ord;
    }

    void affiche()
    {
        cout<<"Coordonnées: x="<<x<<" y="<<y<<endl;
    }
    float abs(){ return x;}
    float ord(){ return y;}
};

class pointb: public point
{
public:
    float rho(){ return (abs());}
};

int main()
{
    pointb object0;
    cout<<object0.rho()<<endl;
    return 0;
}
