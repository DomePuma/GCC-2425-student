#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <iostream>

#include "Component.hpp"

class Entity : public Component
{
    public :
        void update() override
        {
            std::cout << "Entity update!\n";
        }
};

#endif //_ENTITY_HPP_
