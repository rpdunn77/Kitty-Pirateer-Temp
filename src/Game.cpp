#include "../hdr/Game.h"
#include "../hdr/Jukebox.h"
#include "../hdr/Obstacle.h"
#include <cstdio>
#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>


#include "../hdr/Player.h"
#include "../hdr/ItemHandler.h"
#include "../hdr/MapHandler.h"
#include "../hdr/ImageLoader.h"

bool Game::c_running = false;
bool* Game::keystates = new bool[256];


int Game::getArrayPos()
{
   return m_arraypos;
}
void Game::setArrayPos(int pos)
{
   m_arraypos = pos;
}

// We do not use this function yet, but you might want it.
GLfloat Game::frand() {
    return random()/(GLfloat)RAND_MAX;
}

// Called by Game::idle this function sends a signal to update the screen
void Game::timer(int id)
{
   if(id == 513)
   {
      // Redisplay frame
      glutPostRedisplay();
   }
}

// Tis function 
void Game::idle() {
   glutTimerFunc(Game::c_interval, // in this many miliseconds
     Game::timer,      // call the funtion timer
     513               // with this parameter
   );
}

void Game::run() {

    Game::getInstance().update();   
    // flush the graphics pipele and display the objects we have specified
    //Since we are using double buffering this means we swap the buffer be just drew
    //on to the screen.
    glutSwapBuffers();
    Game::idle();
}

void Game::keyOperations()
{
   if(keystates['a']){
      Game::getInstance().m_myPlayer.left();
      Game::getInstance().m_myPlayer.c_left = true;
   }else{
   	Game::getInstance().m_myPlayer.c_left = false;
   }
   if(keystates['w']){
      Game::getInstance().m_myPlayer.up();
      Game::getInstance().m_myPlayer.c_up = true;
   }else{
   	Game::getInstance().m_myPlayer.c_up = false;
   }
   if(keystates['d']){
      Game::getInstance().m_myPlayer.right();
      Game::getInstance().m_myPlayer.c_right = true;
   }else{
   	Game::getInstance().m_myPlayer.c_right = false;
   }
   if(keystates['s']){
      Game::getInstance().m_myPlayer.down();
      Game::getInstance().m_myPlayer.c_down = true;
   }else{
   	Game::getInstance().m_myPlayer.c_down = false;
   }

}

void Game::keyUp(unsigned char key, int x, int y)
{
   keystates[key] = false;
}

void Game::key(unsigned char key, int x, int y)
{

   keystates[key] = true;
   if (key == ' ')
      Game::c_running = !Game::c_running;
   if (key == 'u')
      ItemHandler::getInstance().iSwitch();
   if (key == 'j')
      Game::getInstance().m_myPlayer.attack();
   if (key == 'k')
      ItemHandler::getInstance().iUse();
 
}

void Game::splashScreen()
{
   /*
   // Other parts of the program have been doing speical things with
   // lights and textures. We want a flat rectangle so turn them all off.
   glDisable(GL_TEXTURE_2D); // Disable any textures. We want color!
   glDisable (GL_LIGHTING);  // Also turn off any lights
   glLoadIdentity();//load identity matrix

   glEnable(GL_COLOR_MATERIAL); // Needed so glColor3f controls the color
   glColor3f(0.5f,0.7f,1.0f); //sky blue backcground
   ImageLoader::rectangle(20, 20, m_width-40, m_height-40);
   */
   
   
   m_splashTexture= ImageLoader::LoadTexture( "./imgs/menu.bmp" );
 
   
   glEnable(GL_TEXTURE_2D);
   ImageLoader::rectangle(200, 250, 600, 215);
   
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   
   glDisable(GL_TEXTURE_2D);
   glFlush();

}

void Game::changeScreen(int dir)
{

	//const char* tiles[9] =  {"./imgs/tile0.png","./imgs/tile1.png","./imgs/tile2.png","./imgs/tile3.png","./imgs/tile4.png","./imgs/tile5.png","./imgs/tile6.png","./imgs/tile7.png","./imgs/tile8.png"};
	//m_backgroundTexture= ImageLoader::LoadTexture(tiles[dir]);
	m_backgroundTexture = MapHandler::getInstance().getTile(dir);
	

}


void Game::update()
{
  int now;
  int miliseconds;
  now = glutGet(GLUT_ELAPSED_TIME);
  
  miliseconds =  now - m_lastSong;
  if (miliseconds > 32600){
     Jukebox::PlaySound("./sounds/Song.wav");
     m_lastSong = glutGet(GLUT_ELAPSED_TIME);
  } 
   
   
   Game::getInstance().keyOperations();
   // Clear color and depth buffers
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

   //clear the screen
   glClearColor(1.0, 1.0, 1.0, 0.0); // Set the clear color to white
   glClear(GL_COLOR_BUFFER_BIT);     // clear the screen

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   // Draw the background
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_backgroundTexture);
   //ImageLoader::rectangle(0,0, m_width, m_height);
   ImageLoader::rectangle(0,0, m_width, m_height);
   glDisable(GL_TEXTURE_2D);
   glFlush();
   
   //********I ADDED THIS*********//
   std::string item = "Item: ";
   std::string ammount = "Amount: ";
   int num;

   item += ItemHandler::getInstance().getItem()->getName();
   num =ItemHandler::getInstance().getItem()->getAmmount();
   ammount += std::to_string(num);
   //std::cout << item << ammount << std::endl;
   const char* citem = item.c_str();
   const char* cammount = ammount.c_str();
      
    
   ImageLoader::RenderString(25, m_height - 20, GLUT_BITMAP_TIMES_ROMAN_24, citem);
   ImageLoader::RenderString(25, m_height - 40, GLUT_BITMAP_TIMES_ROMAN_24, cammount);
   
   std::string health = "Health: ";
   int numHealth = Game::getInstance().m_myPlayer.getHealth();
   health += std::to_string(numHealth);
   
   const char* chealth = health.c_str();
   ImageLoader::RenderString(200, m_height - 20, GLUT_BITMAP_TIMES_ROMAN_24, chealth);
   
   //*****************************//
   
   if(!Game::c_running)
   {
      return splashScreen();
   }

  
   ItemHandler::getInstance().update();
   m_myPlayer.display();
}


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void Game::reshape(GLsizei newwidth, GLsizei newheight) 
{  
    // Set the viewport to cover the new window
     glViewport(0, 0, m_width=newwidth, m_height=newheight);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0.0, m_width, m_height, 0.0, 0.0, 100.0);
     glMatrixMode(GL_MODELVIEW); 
     glutPostRedisplay();
}

void Game::init() {
    // Set the seed for the random variable generator just in case we need it.
    srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // Use double buffering for smoother images
    glutInitWindowSize(m_width+200, m_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Kitty Piratier - Adventure of Zombie Island");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glDepthFunc(GL_LESS);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

/*
    m_gameObjects = 0;                            //x   y   len  bre
    m_myGameObjects3[m_gameObjects] = new Obstacle(170, 210, 154 , 150, 0); //square
                                                    //x   y    r   circleflag  cond
    m_myGameObjects4[m_gameObjects] = new Obstacle(217, 245, 85, 0, 0);  
    m_gameObjects = m_gameObjects+1;
    
    m_myGameObjects3[m_gameObjects] = new Obstacle( 498, 369, 449,296,0);
    m_gameObjects = m_gameObjects+1;
    m_myGameObjects3[m_gameObjects] = new Obstacle( 650, 222, 151, 147,0);

 */   

    //gluOrtho2D(0, m_width+m_margine, 0, m_height+m_margine);
    glOrtho(0, m_width+m_margine, 0, m_height+m_margine, 0, 1000);

   //In event-driven programming, like you have in interactive OpenGL 
   //applications, the main application loop generally does three things:
   //  1. check the current event queues, and process any events (e.g., 
   //     mouse movement, key presses, etc.) that have occurred since the last check
   //  2.update the application state - things like Player and object positions, 
   //    game physics, etc. - in preparation of the next rendering frame
   //  3.render the current frame.
   // GLUT does these steps implicitly in its glutMainLoop()

   // Set up the callbacks that will be taken Playere of in step 1:
    glutKeyboardFunc(Game::key); // Keyboard input
    glutKeyboardUpFunc(Game::keyUp);
    glutDisplayFunc(Game::run);  // Display frames
    //glutIdleFunc(Game::run);    // Wait time between frames.


   //m_backgroundTexture= ImageLoader::LoadTexture( "./imgs/tile3.png" );
   m_backgroundTexture = MapHandler::getInstance().getTile(3);
   m_myPlayer.init();

    glutMainLoop(); // glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.
}


int main(int argc, char **argv) {
    if(!Jukebox::init())
      exit;
    glutInit(&argc, argv);
    Game::getInstance().init();
    SDL_CloseAudio();
}
