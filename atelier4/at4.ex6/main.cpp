#include <iostream>
#include "Point.hpp"

using namespace std ;
int main() {
    
    Point p(2.5, 3.5);
    cout << "Point initial : ";
    p.affiche();

    
    p.deplace(1.0, -0.5);

    
    cout << "Point après déplacement : ";
    p.affiche();

    return 0;
}
