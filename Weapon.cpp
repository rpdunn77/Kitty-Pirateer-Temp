#include "../hdr/Weapon.h"

void Weapon::display()
{

}

void Weapon::update()
{

}

Weapon::Weapon(int d, int r, int invs, int id, std::string name, int type)
{  
   m_damage = d;
   m_range = r;
   m_invslot = invs;
   m_itemID = id;
   m_name = name, 
   m_type = type;

}
