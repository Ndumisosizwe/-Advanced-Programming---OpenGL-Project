#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Maze.h"
#include "Bullet.h"
#include "imageloader.h"
#ifndef GHOST_H
#define GHOST_H


class Ghost
{
    public:
       Ghost(float x, float z);
        virtual ~Ghost();
        void render();
        void update();
        bool isShot(Bullet bul);
        float pos_x, pos_y, pos_z, rad = 3;
        void initRendering();

    private:
        void drawGhost();
         float xUpdate = 0.5, yUpdate = 0.5, angle = 90;
         Maze mze;
};

#endif // GHOST_H
