#ifndef SWORD_HPP
#define SWORD_HPP

#include "IWeapon.hpp"

class Sword : public IWeapon
{
    private :
        int damage = 2;
    
    public :
        int GetDamage() override
        {
            return damage;
        }
};

#endif //SWORD_HPP