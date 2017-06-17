#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <stdlib.h>

using namespace std;
class Collectibles{

public:
    Collectibles();
    Collectibles(float,float,float,float);
    ~Collectibles();
    void update();
    void render();
    void CheckPoint(); //Check if the player is at the position of a Collectible/Point


private:
    float x_pos;
    float y_pos;
    float z_pos;
    float x,y,z;
    float cubeangle = 60.3f;
    float Objangle = 70.3f;
    float rotateAngle = 3.14;
    double offSet[3];
    float unt;
    float R; //red
    float G; //Green
    float B; //Blue
    int index; //index of collectible
    float ColorChanger;

};

#endif // COLLECTABLES_H
