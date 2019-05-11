#include <iostream>

#include "singleinstance.h"

using namespace std;

SingleInstance & SingleInstance::getInstance()
{
       	return *pSI;
}

void SingleInstance::print()
{
       	cout << "single instance print: " << value << endl;
}

void SingleInstance::set(int i)
{
       	value = i;
}

SingleInstance::SingleInstance() : value(0)
{
       	cout << "single instance constructor" << endl;
}

SingleInstance::~SingleInstance()
{
       	cout << "single instance deconstructor" << endl;
}

SingleInstance::Garbo::Garbo()
{
	cout << "Garbo constructor" << endl;
}

SingleInstance::Garbo::~Garbo()
{
	cout << "Garbo deconstructor" << endl;
	delete pSI; pSI = nullptr;
}

SingleInstance * SingleInstance::pSI = new SingleInstance();
SingleInstance::Garbo SingleInstance::gc;

