#include <iostream>

#include "SharpeningDecorator.hpp"
#include "Sword.hpp"

int main()
{
    IWeapon* weapon1 = new Sword();
    IWeapon* weapon2 = new SharpeningDecorator(weapon1);

    std::cout << weapon1->GetDamage() << std::endl;
    std::cout << weapon2->GetDamage() << std::endl;

    return 0;
}   