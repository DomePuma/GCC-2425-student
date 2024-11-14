#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <memory>

class Component
{
    public :  
        virtual ~Component() = default;
        virtual void update() = 0; 
        virtual void add(const std::shared_ptr<Component>& component) {};
        virtual void remove(const std::shared_ptr<Component>& component) {};
};

#endif // _COMPONENT_HPP_