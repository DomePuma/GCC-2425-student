#ifndef WEAPONUPGRADE_HPP
#define WEAPONUPGRADE_HPP

#include "IWeapon.hpp"

class WeaponUpgrade : public IWeapon
{
    protected : 
        IWeapon* weapon;
    public : 
        WeaponUpgrade() = default;
        ~WeaponUpgrade()
        {
            delete weapon;
        }
        int GetDamage() override 
        {
            return this->weapon->GetDamage();
        }
};

#endif //WEAPONUPGRADE_HPP