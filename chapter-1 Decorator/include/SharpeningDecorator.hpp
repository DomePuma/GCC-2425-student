#ifndef SHARPENINGDECORATOR_HPP
#define SHARPENINGDECORATOR_HPP

#include "WeaponUpgrade.hpp"

class SharpeningDecorator : public WeaponUpgrade 
{
    public :
        SharpeningDecorator(IWeapon* weapon)
        {
            WeaponUpgrade::weapon = weapon;
        }
        int GetDamage() override 
        {
            return WeaponUpgrade::weapon->GetDamage() + 3;
        }
};

#endif //SHARPENINGDECORATOR_HPP