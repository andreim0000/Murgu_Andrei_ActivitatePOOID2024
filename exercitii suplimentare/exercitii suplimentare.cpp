#include <iostream>
#include <string>
using namespace std;


class Person {
private:
	string name;
	int age;
	string country;



public:

	Person(string name, int age, string country)
	{
		this->name = name;
		this->age = age;
		this->country = country;
	}

	void setterName(string nameset)
	{
		name=nameset;
	}

	void setterAge(int ageset)
	{
		age = ageset;
	}
	
	void setterCountry(string countryset)
	{
		country = countryset;
	}

	string getterName() const
	{
		return name;
	}
	int getterAge() const
	{
		return age;
	}

	string getterCountry() const {
		return country;
	}

};






int main()
{
	Person person1("Andrew", 15, "Romania");
    cout << person1.getterName();
	cout << endl;
	person1.setterName("Bob");

	cout << person1.getterName();

	

	



}


