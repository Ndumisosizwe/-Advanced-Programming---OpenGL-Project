#include "Collectibles.h"
#include <vector>
#include <Windows.h>
#include <MMSystem.h>
using namespace std;

Collectibles::Collectibles(){}

Collectibles::Collectibles(float x_pos,float z_pos,float speed,float ColorChanger){
    x = 5;
    y = 5;
    z = 0;
    offSet[0] = 2;
    offSet[1] = 2;
    offSet[2] = 2;
    offSet[3] = 2;
    this->x_pos = x_pos;
    this->z_pos = z_pos;
    this->ColorChanger = ColorChanger;

    cubeangle = 60.3f;
    Objangle = 70.3f;
    rotateAngle = 3.14;
    unt = speed;
    R=1;
    G=1;
    B=1;
}

Collectibles::~Collectibles(){}

void Collectibles::CheckPoint(){
    if(this->x<=10){
    this->x_pos = 600000;
    this->z_pos = 600000;
    PlaySound("Point.wav", NULL, SND_FILENAME | SND_ASYNC);}
}

void Collectibles::render(){
        //Cover Cube
        glColor3ub(R,G,B);
        glPushMatrix();
        glTranslatef(x_pos,x,z_pos);
        glRotatef(-cubeangle,1,0,0);
        glutWireSphere(3.5,15,15);
        glPopMatrix();

        glColor3ub(R+6,G*2,B+20);
        glPushMatrix();
        glTranslatef(x_pos,x,z_pos);
        glScalef(2,2,2);
        glRotatef(-Objangle*2,Objangle*2,Objangle*2,0);
        glutSolidTorus(0.5,1,20,20);
        glPopMatrix();

}

void drawLives(){
    glPopMatrix();

    glPushMatrix();
}

void Collectibles::update(){
    //update Colors
    if(R >= 220)
        R = 1;if(G >= 100)
                G = 1;
    if(B>= 200)
        B=1;

    int time = glutGet(GLUT_ELAPSED_TIME);
    Objangle = time/5;
    cubeangle = time / 9;

     if(x <= 2.5 ||x >= 50){
        unt = -unt;
    }
    //bouncing Collectables
    x += unt;

    R +=1*ColorChanger;
    G +=10 *ColorChanger;
    B +=3*ColorChanger;
}
