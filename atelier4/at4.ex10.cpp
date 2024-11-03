#include <iostream>
#include <string>

using namespace std;


void Extraire (const string & chaine){
    string jour = chaine.substr(0 ,2);
    string mois = chaine.substr(2 ,2);
    string annee = chaine.substr(4 ,2);
    string heure = chaine.substr(8 ,2);
    string minute = chaine.substr(10 ,2);

    cout << "Jour : "<< jour << endl;
    cout << "Mois : "<< mois << endl;
    cout << "Annee : "<< annee << endl;
    cout << "Heure : "<< heure << endl;
    cout << "Minute : "<< minute << endl;
}


int main (){

   string chaine = "010920091123";
   Extraire (chaine);
   return 0;
}