#ifndef ITEMHANDLER_H_
#define ITEMHANDLER_H_
#define MAXITEMS 50
#define MAXINV 10

#include "Items.h"
#include "GameObject.h"

/*
Item ID:
   0: sword

   10:lemon

*/




class ItemHandler: public GameObject{
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
         m_lastItem = 0;
         Items sword = new Weapon(10,3,0,0);
         Items lemon = new Item(0,0,10, "Lemon");
         m_weaponInv[0] =  sword;
         m_itemInv[0] = lemon;
      }
   
   private:
         Items m_itemlist[MAXITEMS];
         Items m_itemInv[MAXINV];
         Items m_weaponInv[MAXINV];    
         int m_invStack[MAXINV]; //amount of that item you are holding. ie character has
                                 //3 lemons, lemons are in slot 10, so m_invStack[10] = 3; 
         int m_currWeapon;       //current weapon in item array
         int m_currItem;         //current item in item array
         int m_lastWeapon;       //last weapon slot in your inventory
         int m_lastItem;         //last item slot in your inventory
      
   public:
      Items getWeaponInv(){return m_weaponInv;}
      Items getItemInv(){return m_itemInv;
      int getWeaponSlot(){return m_currWeapon;}
      int getItemSlot(){return m_currItem;}
      Items getWeapon(){return m_weaponInv[currWeapon];}
      Items getItem(){return m_itemInv[currItem];}
      void setWeaponSlot(int w){m_currWeapon = w;}
      void setItemSlot(int i){m_currItem = i;}
      void display();
      void iSwitch();
      void wSwitch();
      void iUse();
      void wUse();
      









};
#endif
