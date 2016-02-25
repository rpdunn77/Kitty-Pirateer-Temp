#ifndef WEAPONS_H_
#define WEAPONS_H_
#include <string>
class Weapons: public Items{
   private:
      int m_damage;  //weapon damage

   public:
      int getDamage();//returns current weapon damage
      int setDamage();//set's damage of weapon
                     //if certain items are used.
      //void wUse();   //weapon use
      Weapon(int d, int r, int invs, int id, sdt::string name);
      Weapon(){};
};

#endif
