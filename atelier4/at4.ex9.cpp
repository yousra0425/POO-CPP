#include <iostream>

using namespace std ;

struct Element {
    int value;
    Element* next;

    Element(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Element* head;
public:
    LinkedList() : head(nullptr) {}

    // Méthode pour ajouter un élément au début de la liste
    void addToFront(int val) {
        Element* newElement = new Element(val);
        newElement->next = head;
        head = newElement;
    }
    // Méthode pour supprimer un élément au début de la liste
    void removeFromFront() {
        if (head == nullptr) {
            cout << "La liste est déjà vide." << endl;
            return;
        }
        Element* temp = head;
        head = head->next;
        delete temp;
    }

    // Méthode pour afficher la liste
    void display() const {
        Element* current = head;
        if (current == nullptr) {
           cout << "La liste est vide." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructeur pour libérer la mémoire
    ~LinkedList() {
        while (head != nullptr) {
            removeFromFront();
        }
    }
};

int main() {
    LinkedList list;
    list.addToFront(10);
    list.addToFront(20);
    list.addToFront(30);

    cout << "Liste après ajouts :" << endl;
    list.display();

    list.removeFromFront();
    cout << "Liste après suppression du début :" << endl;
    list.display();

    return 0;
}
