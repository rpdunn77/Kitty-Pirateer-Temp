#ifndef PROJECTILE_H_
#define PROJECTILE_H_

class Projectile: public Weapon{
   private:
      int m_x, m_y;  //X and Y coordinates
                     //of projectile
      int m_speed;   //speed it is moving
      int m_speed_x; //speed in x
      int m_speed_y; //speed in y
      
   public:
      int getX();    //get x position
      int getY();    //get y position
      bool collide();//collide with object
      Projectile();


};



#endif
