#include <GL/glut.h>
#include "imageloader.h"
#ifndef Maze_H
#define Maze_H
class Maze{
    public:
        Maze();
        ~Maze();
        void render();
        bool checkCollision(GLdouble x, GLdouble z);
    public:
        void boundWalls();
        void extendMaize();
        void wallsAlongX();
        void wallsAlongZ();
        bool boundsCollision(GLdouble x, GLdouble z);
        bool wallsAlongXCollision(GLdouble x, GLdouble z);
        bool wallsAlongZCollision(GLdouble x, GLdouble z);
        void drawWallX(GLdouble siz);
        void drawWallZ(GLdouble siz);
        void SideWalls();
        GLuint textur;
};

#endif
