#include <iostream>
#include "marche.h"

int main()
{
	Marche::getInstance();
	
	std::cout << "Après" << std::endl;

	return 0;
}