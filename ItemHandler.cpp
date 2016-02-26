#include "ItemHandler.h"
#include "Game.h"
#include "Items.h"
#include <iostream>

#include <string>

void ItemHandler::display()
{
   for(int i = 0; i <= m_lastItem; i++){
      m_itemList[i]->display();
   }
   
}

void ItemHandler::iSwitch()
{
   if(m_currItem == m_lastItem){
      m_currItem = 0;
   }else{
      m_currItem = m_currItem +1;   
   }
   
   std::string name = m_itemInv[m_currItem]->getName();
   std::cout << name << std::endl;
   
}

void ItemHandler::wSwitch()
{
   if(m_currWeapon == m_lastWeapon){
      m_currWeapon == 0;
   }else{
      m_currWeapon++;
   }
}

void ItemHandler::iUse()
{
   
}



