
#include <iostream>
#include <string>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
 // Constructeur par défaut
    Voiture() : marque("Inconnue"), modele("Inconnu"), annee(2000), kilometrage(0.0f), vitesse(0.0f) {
        cout << "Constructeur par defaut appele." << endl;
    }
// Constructeur avec paramètres
    Voiture(string m, string mo, int a, float km, float v)
        : marque(m), modele(mo), annee(a), kilometrage(km), vitesse(v) {
        cout << "Constructeur avec parametres appele." << endl;
    }

    void accelerer(float valeur) {
        vitesse += valeur;
        cout << "La voiture accelere de " << valeur << " km/h." << endl;
    }

    void freiner(float valeur) {
        if (vitesse - valeur < 0) {
            vitesse = 0;
        } else {
            vitesse -= valeur;
        }
        cout << "La voiture freine de " << valeur << " km/h." << endl;
    }

    void afficherInfo() const {
        cout << "Marque: " << marque << "\n"
                  << "Modele: " << modele << "\n"
                  << "Annee: " << annee << "\n"
                  << "Kilometrage: " << kilometrage << " km\n"
                  << "Vitesse actuelle: " << vitesse << " km/h" << endl;
    }

    void avancer(float distance) {
        kilometrage += distance;
        cout << "La voiture avance de " << distance << " km. Kilometrage actuel: " << kilometrage << " km." << endl;
    }

    // Destructeur
    ~Voiture() {
        cout << "La voiture est detruite." << endl;
    }
};

