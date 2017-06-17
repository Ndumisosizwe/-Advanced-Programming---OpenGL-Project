#include "Sun.h"

Sun::Sun(){
    this->r=30;
    this->s = 50;
    this->st=50 ;
}

Sun::Sun(float radius,float slices,float stacks){
     this->r=radius;
    this->s = slices;
    this->st=stacks ;
}

Sun::~Sun(){}

void Sun::drawSun(){
    glPushMatrix();
        glColor3ub(255,255,0);
        glTranslatef(0,600,-300);
        glutSolidSphere(this->r,this->s,this->st);
    glPopMatrix();
}

void Sun::render(){
    drawSun();
}

