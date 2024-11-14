#ifndef _GROUPE_HPP_
#define _GROUPE_HPP_

#include <iostream>
#include <vector>

#include "Component.hpp"
#include <algorithm>

class Group : public Component
{
    public :
        void update() override
        {
            std::cout << "Group updated!\n";
            
            for(auto& child : children)
            {
                child->update();
            }
        }

        void add(const std::shared_ptr<Component>& component) override
        {
            children.push_back(component);
        }

        void remove(const std::shared_ptr<Component>& component) override
        {
            children.erase(std::remove_if(children.begin(), children.end(), [&component](const std::shared_ptr<Component>& c) 
            {
                return c == component;
            }), 
            children.end());
        }

    private :
        std::vector<std::shared_ptr<Component>> children;
};

#endif //_GROUPE_HPP_