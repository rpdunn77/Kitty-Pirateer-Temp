#include "Items.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include "ImageLoader.h"
#include "Game.h"
#include <iostream>

class ImageLoader;

void Items::setAmmount(int x)
{
   m_ammount = x; 
}

void Items::pickUp(Items* item)
{  int playerX = Game::getInstance().m_myPlayer.getX();
   int playerY = Game::getInstance().m_myPlayer.getY();
   int playerSize = Game::getInstance().m_myPlayer.getSize();
   if(playerX + playerSize > m_x && playerX < m_x + 25 && 
      playerY + playerSize > m_y && playerY < m_y + 25 &&
      Game::getInstance().getArrayPos() == m_tilePos){
      if(m_pickedUp == false){
         m_pickedUp = true;
         switch (m_itemID){
            case 10:
               ItemHandler::getInstance().addItemToInv(item);
               break;
            case 11:
               std::cout << "health Increased" << std::endl;   
               break;
      
         }
      }     
   }
}

void Items::display()
{
   if(Game::getInstance().getArrayPos() == m_tilePos){
      if(m_pickedUp == false){

         glEnable(GL_TEXTURE_2D);
   
         glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
         glBindTexture (GL_TEXTURE_2D, m_itemTexture);
         ImageLoader::rectangle(m_x, m_y, 25, 25);
   
         glDisable(GL_TEXTURE_2D);
         glFlush();
         
      }
   }
}

void Items::update()
{

}

Items::Items(int r, int inv, int id, std::string name,bool pickup,int x, int y, int tile)
{
   m_range = r;
   m_invslot = inv;
   m_itemID = id;
   m_name = name;
   m_ammount = 1;
   m_pickedUp = pickup;
   m_x = x;
   m_y = y;
   m_tilePos = tile;

   //switchcase
   switch (m_itemID){
      case 10:
         m_itemTexture = ImageLoader::LoadTexture("./imgs/lemon.png");
         break;
      case 11:
         m_itemTexture = ImageLoader::LoadTexture("./imgs/heart.png");
         break; 
   }
   
}

