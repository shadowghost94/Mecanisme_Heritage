#include <string>
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

}
