#include <iostream>
#include <cstring>

using namespace std;

class Fichier {
private:
    char* P;
    size_t longueur;

public:
    // Constructeur par défaut
    Fichier() : P(nullptr) , longueur(0) {
        cout << "Fichier cree." << endl ;
    }


    // Destructeur
    ~Fichier(){
        delete[] P;
        cout << "Le Fichier est detruit." << endl;
    }


    // Méthode pour allouer de l'espace mémoire
    void Creation (size_t taille){
        P = new char[taille];
         longueur = taille ;
         cout << "Espace memoire de " << longueur << "octets alloue." << endl ;
    }

    // Méthode pour remplir la mémoire arbitrairement
    void Remplir (char valeur='A'){
        if(P != nullptr && longueur >0){
            memset (P, valeur , longueur);
            cout << "Memoire remplie avec la valeur " << valeur << "." << endl;

        }
    }



    void Affiche () const {
        if( P!= nullptr && longueur > 0){
            cout << "Contenu de la memoire :" ;
            for (size_t i=0;i<longueur;i++ ){
                cout << P[i];
            }
            cout << endl ;
        }
    }
};

int main (){
    Fichier* fichier = new Fichier();

    fichier->Creation( 20);
    fichier->Remplir(20);
    fichier->Affiche();

    delete fichier;

}
