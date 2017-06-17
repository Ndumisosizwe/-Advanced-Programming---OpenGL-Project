#ifndef WALL_H
#define WALL_H
#include <GL/glut.h>
#include "imageloader.h"
class Wall{
    public:
        Wall(const char* filename);
        void render();
    private:
        void drawWall();
        GLdouble x = 0.5, y = .5, z = .5;
        GLuint texture;
};
#endif // WALL_H
