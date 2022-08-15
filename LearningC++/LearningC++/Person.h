#pragma once

#include <string>
#include "Workplace.h" //this can safely include Workplace.h

/// <summary>
/// Class that represents a person with a first name and a last name.
/// </summary>
class Person
{
public:
	Workplace* workplace;

	Person(std::string fName, std::string lName);
	Person();

	std::string ToString();

	std::string get_firstName();
	std::string get_lastName();

	void set_firstName(std::string name);
	void set_lastName(std::string name);

private:
	std::string firstName;
	std::string lastName;
};

class Worker : public Person
{
public: 
	std::string jobTitle;
};