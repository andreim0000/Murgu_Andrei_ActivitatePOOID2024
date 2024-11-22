#include <iostream>
#include <string>
using namespace std;

class Car
{
private:

    string company;
    string model;
    int year;

public:

    Car(string company, string model, int year)
    {
        this->company = company;
        this->model = model;
        this->year = year;
    }

    string getterCompany()
    {
        return company;
    }

    string getterModel()
    {
        return model;
    }

    int getterYear()
    {
        return year;
    }

    void setterCompany(string company)
    {
        this->company = company;
    }

    void setterModel(string model)
    {
        this->model = model;
    }

    void setterYear(int year)
    {
        this->year = year;
    }









};





int main()
{
    
    Car car("toyota", "electra", 1999);

    cout << car.getterCompany() << endl;
    cout << car.getterModel() << endl;
    cout << car.getterYear() << endl;
    car.setterCompany("mitsubishi");
    car.setterModel("subaru");
    car.setterYear(1995);
    cout << car.getterCompany() << endl;
    cout << car.getterModel() << endl;
    cout << car.getterYear() << endl;










}

