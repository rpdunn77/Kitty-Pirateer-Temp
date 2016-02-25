#ifndef ITEMS_H_
#define ITEMS_H_

#include <string>

class Items: public GameObject{
   private:
      int m_range;//range of item 0 if N/A
      sdt::string m_name;
      int m_ammount = 1;
      int m_invslot; //which inventory slot
                     //item is currently in
      int m_itemID;  //item id states which
                     //type of item it is     
      bool m_equip;  //if item is equipped
      


   public:
      int getInvSlot(){return m_invslot};//get current inv slot
      int getItemID(){return m_itemID;}
      int getAmmount(){return m_ammount;}
      std::string getName(){return m_name;}
      int equip();   //equips item
      int pickUp();  //when picked up
      int display(); //display item
      //void iSwitch();      //switch item
      //void iUse();         //use item
      Items(int r, int inv, int id, char name);
      Items (){};
};
#endif
