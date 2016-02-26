#include "Weapon.h"
#include "Items.h"

void Weapon::display()
{

}

void Weapon::update()
{

}

Weapon::Weapon(int d, int r, int invs, int id, std::string name, int type, bool pickup)
{  
   m_damage = d;
   m_range = r;
   m_invslot = invs;
   m_itemID = id;
   m_name = name, 
   m_type = type;
   m_pickedUp = pickup;

}
