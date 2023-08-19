#ifndef MESCLASSES_H
#define MESCLASSES_H
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

    friend class etudiant;
    friend class Enseignant;
    friend class Administratif;
    friend class Technicien;

};

//clases etudiant
class etudiant
{
private:
    string universite;
    string faculte;
    string filiere;
    int anneeEtu;
    int numMat;
    string AddrMail;

public:
    etudiant()
    {
        universite="néant";
        faculte="néant";
        filiere="néant";
        anneeEtu=0;
        numMat=0;
        AddrMail="néant";


    };

    void etudier(){};

    void seFaireEvaluer(){};

};

//classe enseignant
class Enseignant
    {

    };

//classe Administratif
class Administratif
{

};

//classe Technicien

class Technicien
{

};


#endif
