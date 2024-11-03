#include <iostream>
#include <string>

using namespace std;

class Animal{
protected:
   string nom;
   int age;

public:
   void set_value (string nom , int age){
     this->nom =nom;
     this->age=age;
   }
   
   virtual void afficher () const=0;
};

class Zebra : public Animal {
public:
   void afficher() const override {
     cout << "Animal : zebra"<< endl;
     cout << "Nom : "<< nom <<  endl;
     cout << "Age : "<< age << "ans"<< endl;
     cout << "Information : Originaire d'Afrique "<< endl << endl;
   }
};

class Dolphin : public Animal {
    public:
    void afficher() const override {
      cout << "Animal : Dolphin"<< endl;
     cout << "Nom : "<< nom <<  endl;
     cout << "Age : "<< age << "ans"<< endl;
     cout << "Information : Originaire des océans tropicaux "<< endl << endl;  

    }
};

int main (){
    Zebra zebra;
    Dolphin dolphin;

    zebra.set_value("Zuri", 2);
    dolphin.set_value("Marina", 5);

    zebra.afficher();
    dolphin.afficher();

    return 0;
}