#include <iostream>
#include <string>

using namespace std;
class Person{
private:
    string last_name;
    string first_name;
    string date_of_birth;

public:
    Person(string last_name, string first_name, string date_of_birth )
        : last_name(last_name), first_name(first_name), date_of_birth(date_of_birth) {}

      virtual void Afficher() const {
        cout << "Last_name : " << last_name << endl;
        cout << "First_name : " << first_name << endl;
        cout << "date_of_birth : " << date_of_birth << endl;
    } 

};


class Employe : public Person{
private:
    double salary;

public:
Employe(string last_name, string first_name, string date_of_birth, double salary)
        : Person(last_name, first_name, date_of_birth),salary(salary) {}

    
    void Afficher() const override {
        Person::Afficher();
        cout << "Salary : " << salary << " euros" << endl;
    }

};


class Chef : public Employe {
private:
   string service;

  public:
    Chef(string last_name, string first_name, string date_of_birth, double salary, string service)
        : Employe(last_name, first_name, date_of_birth, salary), service(service) {}

    
    void Afficher() const override {
        Employe::Afficher();
        cout << "Service : " << service << endl;
    } 

};


class Director : public Chef {
protected:
    string society;

public:
    
    Director(string last_name, string first_name, string date_of_birth, double salary, string service, string society)
        : Chef(last_name, first_name, date_of_birth, salary,service), society(society) {}

   
    void Afficher() const override {
        Chef::Afficher();
        cout << "Society : " << society << endl;
    }
};

int main (){
   
    Person* person = new Person("Durand", "Pierre", "01/01/1980");
    Employe* employe = new Employe("Martin", "Julie", "15/05/1985", 3000);
    Chef* chef = new Chef("Leclerc", "Jean", "22/10/1975", 5000, "Tech");
    Director* director = new Director("Dupont", "Marie", "30/09/1968", 8000, "Humane Ressources", "TechCorp");

    cout << "Person's Informations :" << endl;
    person->Afficher();
    cout << "\nEmploye's informations :" << endl;
    employe->Afficher();
    cout << "\nChef's Informations :" << endl;
    chef->Afficher();
    cout << "\nDirector's Informations :" << endl;
    director->Afficher();

    delete person;
    delete employe;
    delete chef;
    delete director;

    return 0;

}

