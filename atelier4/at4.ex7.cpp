#include <iostream>

using namespace std ;

class Pile {
private:
    int* elements;
    int capacite;
    int sommet;

public:
    Pile(int taille = 10) : capacite(taille), sommet(-1) {
        elements = new int[capacite];
    }

    // Destructeur
    ~Pile() {
        delete[] elements;
    }

    bool estVide() const {
        return sommet == -1;
    }

    // Empile un élément (push)
    void push(int element) {
        if (sommet >= capacite - 1) {
            cout << "Erreur : La pile est pleine !" << endl;
            return;
        }
        elements[++sommet] = element;
    }

    // Dépile un élément (pop)
    int pop() {
        if (estVide()) {
            cout << "Erreur : La pile est vide !" << endl;
            return -1;
        }
        return elements[sommet--];
    }

    void afficher() const {
        if (estVide()) {
            cout << "La pile est vide." << endl;
            return;
        }
        cout << "Contenu de la pile : ";
        for (int i = sommet; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Pile p1;
    Pile p2;

    p1.push(10);
    p1.push(20);
    p1.push(30);

    p2.push(40);
    p2.push(50);
    p2.push(60);


    cout << "P1 : ";
    p1.afficher();
    cout << "P2 : ";
    p2.afficher();

    // Dépiler et afficher les éléments de p1
    cout << "Dépilements de P1 :" << endl;
    while (!p1.estVide()) {
        cout << "Dépile : " << p1.pop() << endl;
    }

     // Dépiler et afficher les éléments de p1
    cout << "Dépilements de P2 :" << endl;
    while (!p2.estVide()) {
       cout << "Dépile : " << p2.pop() << endl;
    }

    return 0;
}
