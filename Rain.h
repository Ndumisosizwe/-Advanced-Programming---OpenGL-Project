#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <MMSystem.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

#ifndef RAIN_H
#define RAIN_H
class Rain{
public:
    Rain();
    void drawRain();
    void initParticles(int); //initialize the rain drops
    void initTializeDrops(int);
};

#endif // RAIN_H
