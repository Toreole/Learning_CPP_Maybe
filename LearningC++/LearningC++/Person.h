#pragma once
#include <string>

using namespace std;

/// <summary>
/// Class that represents a person with a first name and a last name.
/// </summary>
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

	Person()
	{
		FirstName = "";
		LastName = "";
	}

	std::string ToString();
};

