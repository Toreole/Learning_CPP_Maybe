#pragma once
#include <string>

using namespace std;

class Person
{
public:
	std::string FirstName;
	std::string LastName;

	Person(std::string fName, std::string lName)
	{
		FirstName = fName;
		LastName = lName;
	}

	std::string ToString();
};

