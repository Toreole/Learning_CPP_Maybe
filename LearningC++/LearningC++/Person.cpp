#include "Person.h"

using namespace std;

std::string firstName;
std::string lastName;

Person::Person(std::string fName, std::string lName)
{
	firstName = fName;
	lastName = lName;
}

Person::Person()
{
	firstName = "";
	lastName = "";
}

std::string Person::ToString()
{
	return firstName + " " + lastName;
}

std::string Person::get_firstName()
{
	return firstName;
}

std::string Person::get_lastName()
{
	return lastName;
}

void Person::set_firstName(std::string name)
{
	firstName = name;
}

void Person::set_lastName(std::string name)
{
	lastName = name;
}