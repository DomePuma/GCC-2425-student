#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Group.hpp"

int main()
{
    const std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
    const std::shared_ptr<Entity> entity2 = std::make_shared<Entity>();
    const std::shared_ptr<Group> group = std::make_shared<Group>();

    group->add(entity1);
    group->add(entity2);

    group->update();
    
    group->remove(entity1);

    group->update();
    
    return 0;
}