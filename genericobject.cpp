#include "genericobject.h"
#include <iostream>

GenericObject::GenericObject()
{

}

void GenericObject::draw(QPainter *painter)
{
    std::cout << "Hello" << std::endl;
}

