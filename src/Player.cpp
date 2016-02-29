#include "../hdr/Player.h"
#include "../hdr/Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>

#include "../hdr/ImageLoader.h" 
#include "../hdr/Game.h"

class ImageLoader;

void Player::left ()
{
  int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 400){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  }   

   if(!stopleft){
      m_arraypos = Game::getInstance().getArrayPos();
    
   	if(m_x-m_stepSize <= 0)
   	{
      	if(Game::getInstance().getArrayPos() != 0 && Game::getInstance().getArrayPos() != 3 && Game::getInstance().getArrayPos() != 6){
      		m_arraypos -= 1;
         	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_x = Game::getInstance().getWidth() - m_size -m_stepSize;
      	}
   	}else{
	   	m_x -= m_stepSize*m_speed;
   	}
   }
   m_direction = 3;
   m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Left.bmp" );
}
void Player::right ()
{
  int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 400){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  }
   if(!stopright){
      m_arraypos = Game::getInstance().getArrayPos();

   	if(m_x+55 >= Game::getInstance().getWidth())
   	{
      	if(Game::getInstance().getArrayPos() != 2 && Game::getInstance().getArrayPos() != 5 && Game::getInstance().getArrayPos() != 8){
      		m_arraypos +=1;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_x = m_stepSize;
      	}
   	}else{
			m_x += m_stepSize*m_speed;
   	}
   }
   m_direction = 1;
   m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Right.bmp" );
}
void Player::up ()
{
  int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 400){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  }
   if(!stopup){
      m_arraypos = Game::getInstance().getArrayPos();

  		if(m_y+60 >= Game::getInstance().getHeight())
  		{
      	if(Game::getInstance().getArrayPos() != 0 && Game::getInstance().getArrayPos() != 1 && Game::getInstance().getArrayPos() != 2){
      		m_arraypos-=3;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_y = m_stepSize;
     		}
  		}else{
			m_y +=m_stepSize*m_speed;
		}
   }
   m_direction = 0;
	m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}
void Player::down ()
{
  int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastStep;
  if (seconds > 400){
   Jukebox::PlaySound("./sounds/Step.wav");
     m_lastStep = glutGet(GLUT_ELAPSED_TIME);
  }
   if(!stopdown){
      m_arraypos = Game::getInstance().getArrayPos();

  		if(m_y-m_stepSize <= 0)
  		{
      	if(Game::getInstance().getArrayPos() != 6 && Game::getInstance().getArrayPos() != 7 && Game::getInstance().getArrayPos() != 8){
      		m_arraypos +=3;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_y = Game::getInstance().getHeight()-m_size -5;
      	}
   	}else{
			m_y -= m_stepSize * m_speed;
  		}
   }
	m_direction = 2;
  	m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Down.bmp" );
}
void Player::attack ()
{
  int now;
  int seconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  seconds =  now - m_lastAttack;
  if (seconds > 100){
     ItemHandler::getInstance().getWeapon()->attack();
     m_lastAttack = glutGet(GLUT_ELAPSED_TIME);
  }   
}
void Player::honk ()
{
  Jukebox::PlaySound("./sounds/AHH.WAV");
}

void Player::display ()
{
   displayTexture ();
}

void Player::displayTexture ()
{
   // Draw the Player
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_PlayerTexture);
   ImageLoader::rectangle(m_x,m_y, m_size, m_size);
   glDisable(GL_TEXTURE_2D);
   glFlush();

}
void Player::update (Obstacle *ob[],int size,int quad)
{
   for(int i=0;i<size;i++){
      int xpos = ob[i]->getX();
      int ypos = ob[i]->getY();
      int width = ob[i]->getW();
      int height = ob[i]->getH();
      int cond = ob[i]->getC();

      collisions(xpos, ypos, width, height, cond,quad);
      if(stopright == true || stopleft == true||stopup==true||stopdown==true)
      	break;   
   }
}

void Player::collisions(int xpos, int ypos, int width, int height, int cond,int quad)
{
	int quadrant = Game::getInstance().getArrayPos();
	if(quadrant == quad && height > 0){
      if(m_x+m_stepSize+m_size > xpos && m_x < xpos + width && m_y+m_size > ypos && m_y < ypos+height){
         stopright = true;
         m_x -=m_stepSize;
      }else if(m_x+m_size > xpos && m_x-m_stepSize < xpos + width && m_y+m_size > ypos && m_y < ypos+height){
         stopleft = true;
         m_x+=m_stepSize;
      }else if(m_y-m_stepSize < ypos+height  && m_y > ypos && m_x +m_size > xpos && m_x < xpos+width){
         stopdown = true;
         m_y+=m_stepSize;
      }else if(m_y+m_size+m_stepSize> ypos && m_y < ypos+height && m_x+m_size > xpos && m_x < xpos+width){
         stopup = true;
         m_y-=m_stepSize;
      }else{
         stopright = false;
         stopleft = false;
         stopup = false;
         stopdown = false;
      }
	}else if(quadrant == quad && height == 0){
		float circledistancex = abs(xpos - (m_x + (m_size/2)));
		float circledistancey = abs(ypos - (m_y + (m_size/2)));
		float corner = pow((circledistancex - m_size/2),2) +
							pow((circledistancey - m_size/2),2);
		if(circledistancex > (m_size/2 + width)){	
			m_speed = 1;
		}else if(circledistancey > (m_size/2 + width)){	
			m_speed = 1;
		}else if(circledistancex <= (m_size/2)){
      	//m_speed = 0.5;
      	if(c_up){
      		m_y -=m_stepSize;
      	}
      	if(c_right){
      		m_x -=m_stepSize;
      	}
      	if(c_down){
      		m_y +=m_stepSize;
      	}
      	if(c_left){
      		m_x +=m_stepSize;
      	}
		}else if(circledistancey <= (m_size/2)){
			//m_speed = 0.5;
			if(c_up){
      		m_y -=m_stepSize;
      	}
      	if(c_right){
      		m_x -=m_stepSize;
      	}
      	if(c_down){
      		m_y +=m_stepSize;
      	}
      	if(c_left){
      		m_x +=m_stepSize;
      	}
		}else if(corner <=pow(width,2)){
			//m_speed = 0.5;
      	if(c_up){
      		m_y -=m_stepSize;
      	}
      	if(c_right){
      		m_x -=m_stepSize;
      	}
      	if(c_down){
      		m_y +=m_stepSize;
      	}
      	if(c_left){
      		m_x +=m_stepSize;
      	}
		}
	}
}

void Player::init()
{
  m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}


Player::Player(int x, int y)
{
	c_up=false;
	c_down=false;
	c_left=false;
	c_right=false;
   m_x=x;
   m_y=y;
   m_direction = 2;
   m_arraypos = 0;
   m_speed = 1;
   m_size = 30;
   m_stepSize = 4;
   stopright=false;
   stopleft=false;
   stopup=false;
   stopdown=false;
   m_lastAttack = glutGet(GLUT_ELAPSED_TIME);
   m_lastStep = glutGet(GLUT_ELAPSED_TIME);
}

