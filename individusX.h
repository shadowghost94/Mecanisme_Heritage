#include <string>
class individu
{
protected:
    string nom;
    string prenom;
    int age;
    char sexe;
    string lieuNaissance;
    long int numero;

public:
    individu(){
        nom="néant";
        prenom="néant";
        age=0;
        sexe="M";
        lieuNaissance="néant";
        numero=0;
    };

    ~individu(){cout<<"destruction d'objet..."<<endl;};

    bool manger()
    {};

    void toString()
    {};

    void dormir()
    {};

};
