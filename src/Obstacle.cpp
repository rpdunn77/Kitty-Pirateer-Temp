#include "../hdr/Obstacle.h"
#include "../hdr/Player.h"




Obstacle::Obstacle(int x, int y, int w, int h, int cond)
{
   m_x = x;
   m_y = y;
   m_width = w;
   m_height = h;
   m_cond = cond;
}
