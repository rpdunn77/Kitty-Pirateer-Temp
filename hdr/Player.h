#ifndef Player_H_
#define Player_H_

//#include "Jukebox.h"
#include <GL/freeglut.h>
#include <time.h>
#include "Obstacle.h"
class Obstacle;

class Player {  
   private:
    int m_x;  
    int m_y; 
    int m_size;
    int m_direction;//0=up,1=right,2=down,3=left
    int m_arraypos;
    float m_speed;
    int m_stepSize;
    int m_lastAttack;
    int m_lastStep;
    int m_health;
    
    
    bool stopup,stopdown,stopright,stopleft;

    GLuint m_PlayerTexture;   

   public:
    bool c_up, c_left, c_down, c_right;
    void left ();
    void right ();
    void up ();
    void down ();
    void attack ();
    void honk ();
    void display ();
    void displayTexture ();
    void update ();
    void collisions(int xpos, int ypos, int width, int height, int cond);
    void init();
    void addHealth(int x);
    int getX(){return m_x;}
    int getY(){return m_y;}
    int getHealth(){return m_health;}
    int getWidth(){return m_size;}
    int getHeight(){return m_size;}
    int getSize(){return m_size;}
    int getDirection(){return m_direction;}
    Player(int x = 500, int y = 500);
};

#endif /* Player_H_ */
