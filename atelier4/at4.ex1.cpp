#include <iostream>
#include <stdexcept>

using namespace std;

class Complex {
private:
    double real;
    double imag;
    double v ;
    double iv ;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    bool isEqual(const Complex& other) const {
        return real == v && imag == iv;
    }

    Complex add(const Complex& other) const {
        return Complex(real + v, imag + iv);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - v, imag - iv);
    }

    Complex multiply(const Complex& other) const {
        return Complex(real * v - imag * iv,
                       real * iv + imag * v);
    }

    Complex divide(const Complex& other) const {
        double denominator = v * v + iv * iv;
        if (denominator == 0) {
            throw invalid_argument("Division par zéro");
        }
        return Complex((real * v + imag * iv) / denominator,
                       (imag * v - real * iv) / denominator);
    }

    // Méthode pour afficher un nombre complexe
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

int main() {
    double real1, imag1, real2, imag2;

    cout << "Entrez le premier nombre complexe (partie réelle et imaginaire) : ";
    cin >> real1 >> imag1;
    cout << "Entrez le deuxième nombre complexe (partie réelle et imaginaire) : ";
    cin >> real2 >> imag2;

    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    if (c1.isEqual(c2)) {
        cout << "Les nombres complexes sont égaux." << endl;
    } else {
        cout << "Les nombres complexes ne sont pas égaux." << endl;
    }

    cout << "Résultat de l'addition : ";
    c1.add(c2).display();

    cout << "Résultat de la soustraction : ";
    c1.subtract(c2).display();

    cout << "Résultat de la multiplication : ";
    c1.multiply(c2).display();

    try {
        cout << "Résultat de la division : ";
        c1.divide(c2).display();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}

