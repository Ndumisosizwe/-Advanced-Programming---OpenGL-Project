#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <MMSystem.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include "World.h"
#include "Bullet.h"
#include "Ghost.h"
#include "Collectibles.h"
#include "imageloader.h"
#include "Model_OBJ.h"
#include "Model_OBJ2.h"
#include "Gun.h"
#include "Rain.h"
#define TEXTID 3

using namespace std;

#ifndef GAMEFRAME_H
#define GAMEFRAME_H
class GameFrame{
public:
    GameFrame();
    void render();
    void update();
    void DrawTextXY(double x,double y,double z,double scale, char *s);
    void drawString (void * font, char *s, float x, float y);
    char* toChar(int num);
    void displayState();
    int isCollected();      //returns which ball has been collected
    bool checkCollissionWithGhost(Ghost ghost);
    bool inBound();
    void walk(GLdouble units);
    void shiftSideways(GLdouble units);               //method to move the player left if units > 0 or right if units < 0
    void Keys(unsigned char key, int x, int y);
    void SpecialKeys(int key,int x,int y);
    void processMouseButtons(int but, int state, int x, int y);
    void processMouseMotion(int x, int y);
    void processPassiveMotion(int x, int y);
    int enemiesLeft;

    //Bullet Vector
    vector<Bullet> v_bullets;
    vector<Ghost> v_ghosts;
    vector<Collectibles> v_points;


    float Y_ = 0.36;
    float Z_ = 1.28;
    float X_ = 0.55;

    GLdouble cam_x;
    GLdouble cam_y;
    GLdouble cam_z;
    GLdouble look_x;
    GLdouble look_y;
    GLdouble look_z;
    GLdouble angle;

    GLdouble enemies;
    GLdouble health = 100;

    GLfloat angle3 = M_PI;
    const GLdouble z_dist = -500;

    Maze maze;
    World world; // World global object
    Model_OBJ Shotgun; //Obj To be Loaded
    Model_OBJ2 Title;
    int x1 = 0;
    int TitleY = 0;
    Rain rain;
    bool LetItRain = false;
    GLdouble originalX;
private:
    void initVariables();
};
#endif // GAMEFRAME_H
