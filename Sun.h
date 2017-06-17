
#include <GL/glut.h>
#include <iostream>

#ifndef SUN_H
#define SUN_H

class Sun{
public :
    Sun();
    Sun(float,float,float);
    ~Sun();
    void render();

private:
    void drawSun();
    float r; //radius
    float s; //slices
    float st; // stacks
};

#endif // SUN_H
