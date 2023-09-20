#include <iostream>
using namespace std;

class A
{
    int na;
public:
    A(int nn=1)
    {
        na=nn;
        cout<<"Construction objet A "<<na<<"\n";
    }
};

class B:virtual public A
{
    float xb;
public:
    B(float xx=0.0 )
    {
        xb=xx;
        cout<<"Construction objet B "<<xb<<"\n";
    }
};

class C: virtual public A
{
    int nc;
public:
    C(int nn=2):A(2*nn+1)
    {
        nc=nn;
        cout<<"Construction objet C "<<nc<<"\n";
    }
};

class D:public B,public C
{
    int nd;
public:
    D(int n1,int n2,float x):C(n1),B(x),A(2*n1+1)
    {
        nd=n2;
        cout<<"Construction objet D "<<nd<<"\n";
    }
};
int main()
{
    D d(10,20,5.0);
    return 0;
}
