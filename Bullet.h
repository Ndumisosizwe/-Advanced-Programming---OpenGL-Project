#include <GL/glut.h>
#include "math.h"
#include "Maze.h"
#ifndef BULLET_H
#define BULLET_H

class Bullet
{
    public:
        Bullet(GLdouble pos_x, GLdouble pos_y, GLdouble pos_z, GLdouble angle);
        ~Bullet();
        void update();
        void render();
        bool hit(GLdouble x, GLdouble z, GLdouble rad);
        GLdouble getAngle();
        bool hitWalls();
        void crosshair();

    private:
        void drawBullet();
        GLdouble pos_x, pos_y, pos_z, angle, radius = 0.1;
        Maze maze;
};
#endif // BULLET_H
