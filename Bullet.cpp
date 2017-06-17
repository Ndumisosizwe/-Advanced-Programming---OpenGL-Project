#include "Bullet.h"
//#include "texture.h"
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

Bullet::Bullet(GLdouble pos_x, GLdouble pos_y, GLdouble pos_z, GLdouble angle){
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->pos_z = pos_z;
    this->angle = angle;
}

void Bullet::render(){
    //crosshair();
    drawBullet();
}

bool Bullet::hit(GLdouble x, GLdouble z, GLdouble rad){
    if (sqrt(pow(pos_x - x, 2) + pow(pos_z - z, 2)) <= radius + rad)
        return true;
    return false;
}
GLdouble Bullet::getAngle(){
    return angle;
}

void Bullet::update(){
    pos_x -= 5 * sin(angle);
    pos_z -= 5 * cos(angle);
}
void Bullet:: crosshair(){

}

bool Bullet::hitWalls(){
    if(pos_z >= 595 || pos_z <= -595 || pos_x >= 595 || pos_x <= -595)
        return true;
    for (int i = 0; i < 5; i++){
        if (maze.checkCollision(pos_x - i * sin(angle), pos_z - i * cos(angle)))
            return true;
    }
    return false;

}

void Bullet::drawBullet(){

    glColor3f(0, 0, 0);
    glPushMatrix();
        glTranslated(pos_x+0.2, pos_y - 0.8, pos_z);
        glutSolidSphere(radius, 60, 60);
    glPopMatrix();
}
Bullet::~Bullet(){
}
