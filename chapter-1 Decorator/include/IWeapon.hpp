#ifndef IWEAPON_HPP
#define IWEAPON_HPP

struct IWeapon
{
    virtual ~IWeapon() = default;
    virtual int GetDamage() = 0;
};

#endif //IWEAPON_HPP