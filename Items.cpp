#include "../hdr/Items.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include "../hdr/ImageLoader.h"
#include "../hdr/Game.h"

class ImageLoader;

void Items::pickUp()
{
   
}

void Items::display()
{

}

void Items::update()
{

}

Items::Items(int r, int inv, int id, std::string name)
{
   m_range = r;
   m_invslot = inv;
   m_itemID = id;
   m_name = "name";
   m_ammount = 1;
}

