#include <iostream>
#include <cmath>

using namespace std;

class Vecteur3D {
private:
    float x, y, z;

public:
    Vecteur3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Surcharge de l'opérateur +
    Vecteur3D operator+(const Vecteur3D &v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    float produitScalaire(const Vecteur3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    bool coincide(const Vecteur3D& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Méthode normax pour retourner le vecteur avec la plus grande norme (par valeur)
    static Vecteur3D normax(const Vecteur3D& v1, const Vecteur3D& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }

    // Fonction normax pour retourner un pointeur vers le vecteur avec la plus grande norme
    static Vecteur3D* normax(Vecteur3D* v1, Vecteur3D* v2) {
        return (v1->norme() > v2->norme()) ? v1 : v2;
    }

    // Fonction normax pour retourner une référence vers le vecteur avec la plus grande norme
    static Vecteur3D& normax(Vecteur3D& v1, Vecteur3D& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }
};

int main() {
    Vecteur3D v1(1.0, 2.0, 3.0);
    Vecteur3D v2(4.0, 5.0, 6.0);

    Vecteur3D somme = v1 + v2;
    cout << "La somme des vecteurs est : ";
    somme.afficher();

    float produit = v1.produitScalaire(v2);
    cout << "Le produit scalaire des vecteurs est : " << produit << endl;

    Vecteur3D v3(4.0, 5.0, 6.0);

    if (v1.coincide(v3)) {
        cout << "v1 et v3 ont les mêmes composantes." << endl;
    } else {
        cout << "v1 et v3 n'ont pas les mêmes composantes." << endl;
    }

    Vecteur3D maxNorm = Vecteur3D::normax(v1, v2);
    cout << "Le vecteur avec la plus grande norme est : ";
    maxNorm.afficher();

    Vecteur3D v4(3.0, 4.0, 0.0);
    cout << "Le vecteur est : ";
    v4.afficher();
    cout << "La norme du vecteur est : " << v4.norme() << endl;

    cout << "Le vecteur v1 est : ";
    v1.afficher();
    cout << "Le vecteur v2 est : ";
    v2.afficher();

    const Vecteur3D& v_max_ref = Vecteur3D::normax(v1, v2); // vecteur avec la plus grande norme
    cout << "Le vecteur avec la plus grande norme (référence) est : ";
    v_max_ref.afficher();

    Vecteur3D v_max_copy = Vecteur3D::normax(v1, v2); // copie du vecteur avec la plus grande norme
    cout << "Le vecteur avec la plus grande norme (copie) est : ";
    v_max_copy.afficher();

    Vecteur3D* v_max_ptr = Vecteur3D::normax(&v1, &v2); // pointeur vers le vecteur avec la plus grande norme
    cout << "Le vecteur avec la plus grande norme (pointeur) est : ";
    v_max_ptr->afficher();

    Vecteur3D& v_max_ref2 = Vecteur3D::normax(v1, v2); // référence vers le vecteur avec la plus grande norme
    cout << "Le vecteur avec la plus grande norme (référence) est : ";
    v_max_ref2.afficher();

    return 0;
}




