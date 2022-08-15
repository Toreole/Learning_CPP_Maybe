#include "Person.h"

using namespace std;

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
	return workplace == nullptr ? firstName + " " + lastName : firstName + " " + lastName + ", working at: " + workplace->name;
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