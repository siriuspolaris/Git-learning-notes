#include <iostream>

#include "singleinstance.h"

SingleInstance::Garbo SingleInstance::gc;
SingleInstance * SingleInstance::pSI = new SingleInstance();

SingleInstance & SingleInstance::getInstance()
{
       	return *pSI;
}

SingleInstance::Garbo::Garbo()
{
	std::cout << "Garbo constructor" << std::endl;
}

SingleInstance::Garbo::~Garbo()
{
	std::cout << "Garbo deconstructor" << std::endl;
	delete pSI; pSI = nullptr;
	std::cout << "gc end" << std::endl;
}

SingleInstance::SingleInstance() : value(0)
{
	std::cout << "single instance constructor" << std::endl;
}

SingleInstance::~SingleInstance()
{
	std::cout << "single instance deconstructor" << std::endl;
}

void SingleInstance::print()
{
	std::cout << "single instance print: " << value << std::endl;
}

void SingleInstance::set(int i)
{
       	value = i;
}

