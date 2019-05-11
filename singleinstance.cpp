#include <iostream>

#include "singleinstance.h"

SingleInstance & SingleInstance::getInstance()
{
       	return *pSI;
}

void SingleInstance::print()
{
	std::cout << "single instance print: " << value << std::endl;
}

void SingleInstance::set(int i)
{
       	value = i;
}

SingleInstance::SingleInstance() : value(0)
{
	std::cout << "single instance constructor" << std::endl;
}

SingleInstance::~SingleInstance()
{
	std::cout << "single instance deconstructor" << std::endl;
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

SingleInstance * SingleInstance::pSI = new SingleInstance();
SingleInstance::Garbo SingleInstance::gc;

