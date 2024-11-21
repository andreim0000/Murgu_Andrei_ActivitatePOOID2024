#include <iostream>
using namespace std;



class Autobuz
{
private:

    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:

    Autobuz() : idAutobuz(nrAutobuze++)

    {
        capacitate = 30;
        nrPersoaneImbarcate = 25;
        this->producator = new char[100];
        strcpy_s(this->producator, 100, "Mercedes");
    }

    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(nrAutobuze++), capacitate(capacitate), nrPersoaneImbarcate(nrPersoaneImbarcate)
    {
        if (capacitate < nrPersoaneImbarcate)
        {
            throw invalid_argument("Capacitate autobuzului nu poate fi mai mica decat numarul de persoane imbarcate.");
        }
        if (nrPersoaneImbarcate < 0)
        {
            throw invalid_argument("Autobuzul nu poate transporta un numar negativ de persoane.");
        }
        if (capacitate <= 0)
        {
            throw invalid_argument("Autobuzul nu poate avea o capacitate de transport nula sau negativa.");
        }
        if (producator == nullptr || strlen(producator) == 0)
        {
            throw invalid_argument("Autobuzul trebuie sa aiba o marca/marca autobuzului nu a fost gasita.");
        }
        this->producator = new char[strlen(producator) + 1];
        strcpy_s(this->producator, strlen(producator) + 1, producator);
    }

    ~Autobuz()
    { 
        delete[] producator; 
    }

    void check() const {
        cout << "idAutobuz: " << idAutobuz << endl;
        cout << "capacitate: " << capacitate << endl;
        cout << "nrPersoaneImbarcate: " << nrPersoaneImbarcate << endl;
        cout << "producator: " << producator << endl;
        cout << endl;
        cout << endl;
        cout << endl;

    }

    int getterCapacitate() const {
        return capacitate;
    }

    int getterNrPersoaneImbarcate() const {
        return nrPersoaneImbarcate;
    }

    void setterCapacitate(int capaModif)
    {
        capacitate = capaModif;
    }

    void setterNrPersoaneImbarcate(int nrPersModif)
    {
        nrPersoaneImbarcate = nrPersModif;
    }

    int getterNrLocuriLibere() const {
        return (capacitate - nrPersoaneImbarcate);
    }

    friend void swap(Autobuz& unu, Autobuz& doi) noexcept {
        using std::swap;
        swap(unu.capacitate, doi.capacitate);
        swap(unu.nrPersoaneImbarcate, doi.nrPersoaneImbarcate);
        swap(unu.producator, doi.producator);
    }

    Autobuz& operator=(Autobuz atribuire)
    {
        swap(*this, atribuire);
        return *this;
    }

    bool operator>(const Autobuz& maiMare) const {
        return capacitate > maiMare.capacitate;
    }

    operator int() const {
        return nrPersoaneImbarcate;
    }
 
  

    Autobuz(const Autobuz& copiat) : idAutobuz(copiat.idAutobuz), capacitate(copiat.capacitate), nrPersoaneImbarcate(copiat.nrPersoaneImbarcate)
    {
        this->producator = new char[strlen(copiat.producator) + 1];
        strcpy_s(this->producator, strlen(copiat.producator) + 1, copiat.producator);
    }

  
};

int Autobuz::nrAutobuze = 0;


int main()
{
    cout << "constructor fara param" << endl;

    Autobuz faraParam;
    faraParam.check();

    cout << "constructor cu param" << endl;

    Autobuz cuParam(40, 20, "Ferrari");
    cuParam.check();
    cout << endl;

    Autobuz Atribuire1(44, 22, "Lamborghini");
    Autobuz Atribuire2(55, 33, "Dacia");

    
    // cout << "TEST AUTOBUZ CARE ARUNCA EROARE" << endl;
    //Autobuz cuParam(-4, 20, "Ferrari");
    //cuParam.check();
    cout << endl;

    cout << "test get set capacitate autobucuz cuParam" << endl;
    cout << "capacitate before cuParam: " << cuParam.getterCapacitate() << endl;
    cuParam.setterCapacitate(300);
    cout << "capacitate after cuParam: " << cuParam.getterCapacitate() << endl;
    cuParam.check();
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "test get set imbarcati cuParam" << endl;
    cout << "pers before cuParam: " << cuParam.getterNrPersoaneImbarcate() << endl;
    cuParam.setterNrPersoaneImbarcate(200);
    cout << "pers after cuParam: " << cuParam.getterNrPersoaneImbarcate() << endl;
  
    cout << endl;
    cout << endl;
    cout << endl;

    cuParam.check();

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Locuri libere in Autobuz cuParam: " << cuParam.getterNrLocuriLibere() << endl;
    
    cout << endl;
    cout << endl;
    cout << endl;

    Atribuire1.check();
    cout << endl;
    Atribuire2.check();

    Atribuire1 = Atribuire2;
    cout << "ATRIBUIRE" << endl;
    Atribuire1.check();
    Atribuire2.check();

    cout << endl;
    cout << endl;
    cout << endl;
    
    cout << "test overload operator >" << endl;
    if (cuParam > faraParam)
    {
        cout << "Autobuzul cu parametrii e mai mare decat cel fara.";

    }
    else
    {
        cout << "Autobuzul cu parametrii e mai mic decat cel fara.";
    }
    cout << endl;
    cout << endl;
    faraParam.check();
    cuParam.check();
    cout << endl;

    cout << "test overload int" << endl;
    int nrPers = static_cast<int>(faraParam);
    cout << "Persoane in autobuzul fara parametrii: " << nrPers;
    cout << endl;
    cout << endl;
    cout << endl;
    faraParam.check();
    cout << endl;
    cuParam.check();
    cout << endl << "test constructor copiere" << endl;
    Autobuz clona = cuParam;
    cuParam.check();
    cout << endl;
    clona.check();


    return 0;
}


