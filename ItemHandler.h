#ifndef ITEMHANDLER_H_
#define ITEMHANDLER_H_
#define MAXITEMS 50
#define MAXINV 10

#include "Items.h"
#include "GameObject.h"
#include "Weapon.h"

/*
Item ID:
   0: sword

   10:lemon
   11:health

*/




class ItemHandler {
   public:
      static ItemHandler& getInstance()
      {
         static ItemHandler instance;
         
         return instance;
      };
   private:
      ItemHandler(){
         m_currWeapon = 0;
         m_currItem = 0;
         m_lastWeapon = 0;
         m_lastItem = 1;
         m_weaponInv[0] = new Weapon(10,3,0,0,"sword", 0,true);
         m_itemInv[0] = new Items(0,0,10, "Lemon",true);
         m_itemInv[1] = new Items(0,0,10, "Lime", true);
      }
      
      ItemHandler(ItemHandler const&);
      void operator=(ItemHandler const&);
   
   private:
         Items *m_itemList[MAXITEMS];
         Items *m_itemInv[MAXINV];
         Items *m_weaponInv[MAXINV];    
         int m_invStack[MAXINV]; //amount of that item you are holding. ie character has
                                 //3 lemons, lemons are in slot 10, so m_invStack[10] = 3; 
         int m_currWeapon;       //current weapon in item array
         int m_currItem;         //current item in item array
         int m_lastWeapon;       //last weapon slot in your inventory
         int m_lastItem;         //last item slot in your inventory
      
   public:
      Items* getWeaponInv() {return *m_weaponInv;}
      Items* getItemInv() {return *m_itemInv;}
      int getWeaponSlot() {return m_currWeapon;}
      int getItemSlot() {return m_currItem;}
      Items* getWeapon() {return m_weaponInv[m_currWeapon];}
      Items* getItem() {return m_itemInv[m_currItem];}
      //void setWeaponSlot(int w){m_currWeapon = w;}
      //void setItemSlot(int i){m_currItem = i;}
      void display();
      void iSwitch();
      void wSwitch();
      void iUse();      

};
#endif
