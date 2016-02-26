#include "Items.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include "ImageLoader.h"
#include "Game.h"

class ImageLoader;

void Items::pickUp()
{
   
}

void Items::display()
{
   if(m_pickedUp == false){
      
   }
}

void Items::update()
{

}

Items::Items(int r, int inv, int id, std::string name,bool pickup)
{
   m_range = r;
   m_invslot = inv;
   m_itemID = id;
   m_name = name;
   m_ammount = 1;
   m_pickedUp = pickup;
}

