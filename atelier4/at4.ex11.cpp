#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Traitement {
private:
    vector<int> vecteur;

public:
    void Initialise() {
        int nombre;
        while (vecteur.size() < 15) {
            cout << "Veuillez saisir un entier pair non nul : ";
            cin >> nombre;

            if (cin.fail() || nombre % 2 != 0 || nombre == 0) {
                cout << "Entrée invalide. Veuillez entrer un entier pair non nul.\n";

                // Reset input stream in case of input error
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                vecteur.push_back(nombre);
            }
        }
    }

    // Recursive method to display elements of the vector
    void show(int index = 0) const {
        if (index < vecteur.size()) {
            cout << vecteur[index] << " ";
            show(index + 1);
        } else if (index == 0) {
            cout << "Le vecteur est vide." << endl; // Correct message for empty vector
        } else {
            cout << endl; // End of line after displaying all elements
        }
    }

    // Friend functions to calculate average and median
    friend double moyenne(const Traitement& t);
    friend double median(Traitement& t); // Changed the function name to "median"
};

// Function to calculate the average of vector elements
double moyenne(const Traitement& t) {
    if (t.vecteur.empty()) return 0.0;

    int somme = 0;
    for (int valeur : t.vecteur) {
        somme += valeur;
    }
    return static_cast<double>(somme) / t.vecteur.size();
}

double median(Traitement& t) {
    if (t.vecteur.empty()) return 0.0;

    sort(t.vecteur.begin(), t.vecteur.end());
    int taille = t.vecteur.size();


    if (taille % 2 != 0) {
        return static_cast<double>(t.vecteur[taille / 2]);
    } else {

        return (t.vecteur[taille / 2 - 1] + t.vecteur[taille / 2]) / 2.0;
    }
}

int main() {
    Traitement traitement;

    traitement.Initialise();
    cout << "Contenu du vecteur : ";
    traitement.show();

    cout << "Moyenne des éléments : " << moyenne(traitement) << endl;
    cout << "Médiane des éléments : " << median(traitement) << endl;

    return 0;
}

