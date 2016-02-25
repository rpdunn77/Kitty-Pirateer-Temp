#include "Items.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include "ImageLoader.h"
#include "Game.h"

class ImageLoader;

int Items::equip()
{

}

int Items::pickUp()
{

}

Items::int display()
{
   ImageLoader::rectangle
}

/*
void Items::iSwitch()
{
   Item
   if(ItemHandler::getInstance().

}
*/
void Items::iUse()
{

}

Items::Items(int r, int inv, int id, std::string name)
{
   m_range = r;
   m_invslot = inv;
   m_itemID = id;
   m_name = "name";
}

