#include "heroClasses.hpp"

using namespace std;

// warrior class
void Warrior::increaseAttribute(HeroCreation &hero)
{
    hero.strength += 2;
}

// thief class
void Thief::increaseAttribute(HeroCreation &hero)
{
    hero.dexterity += 2;
}

// berserk class
void Berserk::increaseAttribute(HeroCreation &hero)
{
    hero.endurance += 2;
}

// mage class
void Mage::increaseAttribute(HeroCreation &hero)
{
    hero.intelligence += 2;
}
