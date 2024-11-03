#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x; 
    float y; 

public:
    // Constructeur avec paramètres
    Point(float x, float y);

    void deplace(float dx, float dy);

    void affiche() const;
};

#endif

