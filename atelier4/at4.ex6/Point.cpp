#include <iostream>
#include "Point.hpp"

using namespace std;

Point::Point (float x,float y) : x(x),y(y) {}

void Point::deplace (float dx ,float dy){
    x += dx;
    y += dy;
}

void Point::affiche()const {
    cout << "Coordonnées du point :( "<< x <<" ," << y <<")" << endl ;

}