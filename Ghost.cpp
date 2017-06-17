#include <GL/glut.h>
#include "Ghost.h"
#include "imageloader.h"

//Represents a non player char
Ghost::Ghost(float x, float z){
    this->pos_x = x;
    this->pos_y = 5;
    this->pos_z = z;

}

Ghost::~Ghost(){

}

GLuint _textureId; //The id of the texture
GLUquadric *quad;
float rotate;


GLuint  _textureId2;
GLuint _eyeText;
bool Texture = false;
bool g = true;

void Ghost::initRendering() {
    if(g){
	quad = gluNewQuadric();
	_textureId2 = loadTexture(loadBMP("images\\Monster.bmp"));
    _eyeText = loadTexture(loadBMP("images\\eye6.bmp"));

    }
    g = false;
}



void Ghost::drawGhost(){
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glScaled(2,2,2);


    //Draw the body
    glPushMatrix();
     glColor3ub(255, 255, 255);
            glBindTexture(GL_TEXTURE_2D, _textureId2);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    gluQuadricTexture(quad,1);
    gluSphere(quad,2,50,50);
    glPopMatrix();

   //Draw Left Horn
    glPushMatrix();
    glTranslatef(-1.2, 1.4, 0);
    glScalef(1,1.5,1);
    glRotatef(240, 1, 0, 0);
    glRotatef(-30, 0, 1, 0);
    glutSolidCone(0.5, 1, 20, 20);
    glPopMatrix();

    //Draw right Horn
    glPushMatrix();
    glTranslatef(1.2, 1.4, 0);
    glScalef(1,1.5,1);
    glRotatef(240, 1, 0, 0);
    glRotatef(30, 0, 1, 0);
    glutSolidCone(0.5, 1, 20, 20);
    glPopMatrix();

   //Draw Left Eye
    glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, _eyeText);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glColor3ub(192, 192, 246);
    glTranslatef(-0.5, 0.8, 1.7);
   glRotated(45,0,1,0);
     gluQuadricTexture(quad,1);
    gluSphere(quad,0.25,50,50);
    glPopMatrix();

    //Draw Right Eye
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, _eyeText);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glColor3ub(192, 192, 246);
    glTranslatef(0.5, 0.8, 1.7);
    glRotated(45,0,1,0);
     gluQuadricTexture(quad,1);
    gluSphere(quad,0.25,50,50);
    glPopMatrix();

    //Draw Mouth
    glPushMatrix();
    glColor3ub(51, 51, 51);
    glTranslatef(0, -0.5, 1.9);
    glScalef(2.5,1.5,0.5);
    glutSolidSphere(0.25, 32, 32);
    glPopMatrix();

    //Draw Left Tooth
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(-0.3, -0.3, 1.99);
    glScalef(0.3,0.4,0.2);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.5, 1, 20, 20);
    glPopMatrix();

    //Draw Right Tooth
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(0.3, -0.3, 1.99);
    glScalef(0.3,0.4,0.2);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.5, 1, 20, 20);
    glPopMatrix();

    //Draw Middle Tooth
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(0, -0.8, 1.99);
    glScalef(0.3,0.4,0.2);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.5, 1, 20, 20);
    glPopMatrix();
    glPopMatrix();
glDisable(GL_TEXTURE_2D);
}

bool Ghost::isShot(Bullet bul){
    return bul.hit(pos_x, pos_z, rad);
}

void Ghost::render(){
   if(!Texture){
       initRendering();
        Texture = true;
    }

    glPushMatrix();
    glTranslatef(pos_x, pos_y, pos_z);
    glRotatef(angle, 0, 1, 0);
    drawGhost();
    glPopMatrix();
}

void Ghost::update(){
    if (mze.checkCollision(pos_x + xUpdate + rad, pos_z) || mze.checkCollision(pos_x + xUpdate - rad, pos_z)){
        angle *= -1;
        xUpdate *= -1;
    }

    if (pos_y + yUpdate > 10 || pos_y + yUpdate < 5)
        yUpdate *= -1;
    pos_x += xUpdate;
    pos_y += yUpdate;
}
