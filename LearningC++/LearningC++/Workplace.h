#pragma once
#include <vector>
#include <string>
#include <iostream>

//forward declare Person to allow Workplace to reference them.
class Person;

class Workplace
{
public: 
	std::vector<Person*> workers;
	std::string name;

	Workplace(std::string n)
	{
		name = n;
	}

	void printWorkerNames();

};

