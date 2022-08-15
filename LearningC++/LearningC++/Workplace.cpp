#include "Workplace.h"
#include "Person.h"

void Workplace::printWorkerNames()
{
	for (int i = 0; i < workers.size(); ++i)
		std::cout << workers.at(i)->ToString() << std::endl;
	
}
