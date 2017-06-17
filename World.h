#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <string>
#include <stdlib.h>
#include "Maze.h"
#include "Tree.h"
#include "Sun.h"
#include "Ghost.h"
#include "Sun.h"
#include "Tree.h"
//#include "texture.h";
#include "imageloader.h"
//#include <SDL_filesystem.h>
//A world bounded by 4 walls.

#ifndef WORLD_H
#define WORLD_H

class World{
public:
    World();
    ~World();
    void render();
    void initTextures (void);
    void initLighting (void);
private:
    void drawGround();
    void drawWalls();
    void Sky();
    void cube();
    Tree tree;
    Sun sun;
    void house();
    bool initialized = false;
};

#endif // WORLD_H
