#include <iostream>
using namespace std;

class point
{
    int x,y;
public:
    point(int abs=0, int ord=0){ x=abs; y=ord;};

    friend int operator == (point a, point b);
};

int operator == (point a, point b)
{
    return (a.x==b.x && a.y==b.y);
};

class pointcol: public point
{
    int cl;
public:
    pointcol(int abs=0, int ord=0, int col=0):point(abs, ord)
    {cl= col;}
};

int main()
{
    pointcol a,b;
    int c= (a==b);
    cout<<c<<endl;
}
