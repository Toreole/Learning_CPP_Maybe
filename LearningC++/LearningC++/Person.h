#pragma once

#include <string>

/// <summary>
/// Class that represents a person with a first name and a last name.
/// </summary>
class Person
{
public:
	Person(std::string fName, std::string lName);
	Person();

	std::string ToString();

	std::string get_firstName();
	std::string get_lastName();

	void set_firstName(std::string name);
	void set_lastName(std::string name);
};

