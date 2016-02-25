#ifndef SWORD_H_
#define SWORD_H_

class Sword:public Weapon{
   public:
      static Sword& getInstance()
      {
         static Sword instance;
         return instance;
      }
   private:
      Sword(){
         m_damage = 10;
         m_range = 2;

      }



};


#endif
