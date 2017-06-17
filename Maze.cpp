#include "Maze.h"
#include <iostream>
using namespace std;
Maze::Maze(){
    textur = loadTexture(loadBMP("images\\bricks.bmp"));
}
Maze::~Maze(){
}

void Maze::render(){
    extendMaize();
    boundWalls();
    wallsAlongX();
    wallsAlongZ();
    SideWalls();
}

void Maze::extendMaize(){
    glPushMatrix(); // +X Center
        glTranslated(+180,0,-180);
        glRotated(-180,0,1,0);
        wallsAlongX();
        wallsAlongZ();
    glPopMatrix();

    glPushMatrix(); //Center
        glTranslated(0,0,-180);
        wallsAlongX();
        wallsAlongZ();
    glPopMatrix();

  glPushMatrix(); //-X
        glTranslated(-180,0,-180);
        wallsAlongX();
        wallsAlongZ();
    glPopMatrix();
}

void Maze::SideWalls(){ //Walls OUTSIDE the maze
    //RIGHT
   glPushMatrix();
   glColor3ub(255,255,255);
        glTranslated(+500, 7.5, -180);
           glRotated(90,0,1,0);
            glScalef(1, 15, 219);
            drawWallZ(2);
       // glutSolidCube(2);
    glPopMatrix();

//LEFT
    glPushMatrix();
        glTranslated(-500, 7.5, -180);
        glRotated(90,0,1,0);
        glScalef(1, 15, 219);
        drawWallZ(2);
    glPopMatrix();
}

void Maze::boundWalls(){
    glColor3ub(255, 255, 255);
    //Along y-z plane
    //-x wall LEF SIDE WALL
    glPushMatrix();
        glTranslated(-280, 7.5, -180);
        glScalef(1, 10, 100);
        drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
     glTranslated(100, 7.5, 10);
        glScalef(1, 10, 90);
        drawWallZ(2);
    glPopMatrix();

    //+x wall RIGHT MOST wall
    glPushMatrix();
        glTranslated(+280, 7.5, -180);
        glScalef(1, 10, 100);
        drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-100, 7.5, 10);
        glScalef(1, 10, 90);
        drawWallZ(2);
    glPopMatrix();

    //-z +x wall
  glPushMatrix();
        glTranslated(-189, 7.5, -80);
        glScalef(90, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(+189, 7.5, -80);
        glScalef(90, 10, 1);
        drawWallX(2);
    glPopMatrix();

     glPushMatrix();
        glTranslated(+189, 7.5, -280);
        glScalef(90, 10, 1);
        drawWallX(2);
    glPopMatrix();

       glPushMatrix();
        glTranslated(-189, 7.5, -280);
        glScalef(90, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //+z -x wall
    glPushMatrix();
        glTranslated(-50, 7.5, 100);
        glScalef(51, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //+z +z wall
    glPushMatrix();
        glTranslated(60, 7.5, 100);
        glScalef(40, 10, 1);
        drawWallX(2);

    glPopMatrix();
      glPushMatrix();
        glTranslated(60, 7.5, -280);
        glScalef(40, 10, 1);
        drawWallX(2);
    glPopMatrix();



}

void Maze::wallsAlongX(){

    //-z to +z, -x to +x
    //line 1
    glColor3ub(255,255,255); // brown

    glPushMatrix();
        glTranslated(-70, 7.5, -80);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-10, 7.5, -80);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 2
    glPushMatrix();
        glTranslated(-50, 7.5, -60);
        glScalef(31, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(20.5, 7.5, -60);
        glScalef(20.5, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(70, 7.5, -60);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 3
    glPushMatrix();
        glTranslated(-79, 7.5, -40);
        glScalef(20, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(40, 7.5, -40);
        glScalef(21, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(90, 7.5, -40);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 4
    glPushMatrix();
        glTranslated(-50, 7.5, -20);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(20, 7.5, -20);
        glScalef(41, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 5
    glPushMatrix();
        glTranslated(-79, 7.5, 0);
        glScalef(20, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-30, 7.5, 0);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(20.5, 7.5, 0);
        glScalef(20.5, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(70, 7.5, 0);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 6
    glPushMatrix();
        glTranslated(-50, 7.5, 20);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-10, 7.5, 20);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(50, 7.5, 20);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 7
    glPushMatrix();
        glTranslated(-50, 7.5, 40);
        glScalef(31, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(20.5, 7.5, 40);
        glScalef(20.5, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(79, 7.5, 40);
        glScalef(20, 10, 1);
        drawWallX(2);
    glPopMatrix();



    //line 8
    glPushMatrix();
        glTranslated(-89, 7.5, 60);
        glScalef(10, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-10, 7.5, 60);
        glScalef(31, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(60, 7.5, 60);
        glScalef(21, 10, 1);
        drawWallX(2);
    glPopMatrix();

    //line 9
    glPushMatrix();
        glTranslated(-70, 7.5, 80);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-30, 7.5, 80);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(70, 7.5, 80);
        glScalef(11, 10, 1);
        drawWallX(2);
    glPopMatrix();

}

void Maze::wallsAlongZ(){
    //from -x to +x and from +z to -z
    //wall 1
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslated(-80, 7.5, 30);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-80, 7.5, -30);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-80, 7.5, -70);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    //wall 2
    glPushMatrix();
    glTranslated(-60, 7.5, 60);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-60, 7.5, 0);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    //wall 3
    glPushMatrix();
    glTranslated(-40, 7.5, -30);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    //wall 4
    glPushMatrix();
    glTranslated(-20, 7.5, 70);
    glScaled(1, 10, 9);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20, 7.5, 20);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20, 7.5, -30);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-20, 7.5, -90);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    //wall 5
    glPushMatrix();
    glTranslated(0, 7.5, 89);
    glScaled(1, 10, 10);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 7.5, 40);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 7.5, -40);
    glScaled(1, 10, 41);
    drawWallZ(2);
    glPopMatrix();

    //wall 6
    glPushMatrix();
    glTranslated(20, 7.5, 70);
    glScaled(1, 10, 9);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(20, 7.5, 10);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(20, 7.5, -90);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    //wall 7
    glPushMatrix();
    glTranslated(40, 7.5, 89);
    glScaled(1, 10, 10);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(40, 7.5, 40);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    //wall 8
    glPushMatrix();
    glTranslated(60, 7.5, 0);
    glScaled(1, 10, 20);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, 7.5, -70);
    glScaled(1, 10, 31);
    drawWallZ(2);
    glPopMatrix();

    //wall 9
    glPushMatrix();
    glTranslated(80, 7.5, 70);
    glScaled(1, 10, 9);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(80, 7.5, 10);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(80, 7.5, -30);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(80, 7.5, -70);
    glScaled(1, 10, 11);
    drawWallZ(2);
    glPopMatrix();
}

bool Maze::checkCollision(GLdouble x, GLdouble z){//returns true if theres a collision on one of the maze walls
    if (boundsCollision(x, z) || wallsAlongXCollision(x, z) || wallsAlongZCollision(x, z)){
        return true;
    }
    return false;
}

bool Maze::boundsCollision(GLdouble x, GLdouble z){//returns true if there's a collision on bounds
   if((z>=97&&z<=102)&&(x>=-101&&x<=1.3))
        return true;
    else if((z>=97&&z<=102)&&(x>=20&&x<=104))
        return true;
    else if((z>=-79&&z<=101) && (x>=-105&&x<=-101))
        return true;
    else if((x>=-280 && x <= -105) && ( z >= -79 && z<=-77) )
       return true;
   else if((x>=-600&&x<=-287) && ( z>=-182&&z<=-180) )
        return true;
    else if((x>=96&&x<=102) && ( z>=-77&&z<=108) )
        return true;
    else if((x>=96&&x<=278) && ( z>=-83&&z<=-78) )
        return true;
    else if((x>=278&&x<=283) && ( z>=-175&&z<=-81) )
        return true;
    else if((x>=283&&x<=600) && ( z>=-182&&z<=-177) )
        return true;
        else if (((x >= -280 && x <= -98) || (x >= 20 && x <= 279)) && (z >= -280 && z <= -278))
        return true;
    else if ((x >= 279 && x <= 281) && (z >= -280 && z <= -180))
        return true;
    return false;
}

bool Maze::wallsAlongZCollision(GLdouble x, GLdouble z){
    if ((x >= -81 && x <= -79) && ((z >= -81 && z <= -59) || (z >= -41 && z <= -19) || (z >= 19 && z <= 41)))
        return true;
     else if ((x >= -61 && x <= -59) && ((z >= -20 && z <= 20) || (z >= 40 && z <= 80)))
        return true;
    else if ((x >= -41 && x <= -39) && (z >= -41 && z <= -19))
        return true;
    else if ((x >= -21 && x <= -19) && ((z >= -101 && z <= -79) || (z >= -41 && z <= -19) || (z >= 0 && z <= 40) || (z >= 61 && z <= 79)))
        return true;
    else if ((x >= -1 && x <= 1) && ((z >= -81 && z <= 1) || (z >= 20 && z <= 60) || (z >= 79 && z <= 99)))
        return true;
    else if ((x >= 19 && x <= 21) && ((z >= 61 && z <= 79) || (z >= -1 && z <= 21) || (z >= -101 && z <= -89)))
        return true;
    else if ((x >= 39 && x <= 41) && ((z >= 79 && z <= 99) || (z >= 20 && z <= 60)))
        return true;
    else if ((x >= 59 && x <= 61) && ((z >= -20 && z <= 20) || (z >= -101 && z <= -39)))
        return true;
    else if ((x >= 79 && x <= 81) && ((z >= 61 && z <= 79) || (z >= -1 && z <= 21) || (z >= -41 && z <= -19) || (z >= -81 && z <= -59)))
        return true;
    else if ((x >= -280 && x <= -278) && (z >= -280 && z <= -79))
        return true;
    else if ((x >= -21 && x <= -19) && ((z >= -281 && z <= -259) || (z >= -221 && z <= -199) || (z >= -181 && z <= -139) || (z >= -120 && z <= -101)))
        return true;
    else if ((x >= -261 && x <= -259) && ((z >= -260 && z <= -238) || (z >= -220 && z <= -199) || (z >= -160 && z <= -130)))
        return true;
    else if ((x >= -241 && x <= -239) && (z >= -201 && z <= -159))
        return true;
    return false;
}

bool Maze::wallsAlongXCollision(GLdouble x, GLdouble z){
    if ((z >= -81 && z <= -79) && ((x >= -81 && x <= -59) || (x >= -21 && x <= 1)))
            return true;
    else if ((z >= -61 && z <= -59) && ((x >= -81 && x <= -19) || (x >= 0 && x <= 41) || (x >= 59 && x <= 81)))
            return true;
    else if ((z >= -41 && z <= -39) && ((x >= -99 && x <= -59) || (x >= 19 && x <= 61) || (x >= 79 && x <= 101)))
            return true;
    else if ((z >= -21 && z <= -19) && ((x >= -61 && x <= -39) || (x >= -21 && x <= 61)))
            return true;
    else if ((z >= -1 && z <= 1) && ((x >= -99 && x <= -59) || (x >= -41 && x <= -19) || (x >= 0 && x <= 41) || (x >= 59 && x <= 81)))
            return true;
    else if ((z >= 19 && z <= 21) && ((x >= -61 && x <= -39) || (x >= -21 && x <= 1) || (x >= 39 && x <= 61)))
            return true;
    else if ((z >= 39 && z <= 41) && ((x >= -81 && x <= -19) || (x >= 0 && x <= 41) || (x >= 59 && x <= 99)))
            return true;
    else if ((z >= 59 && z <= 61) && ((x >= -99 && x <= -79) || (x >= -41 && x <= 21) || (x >= 39 && x <= 81)))
        return true;
    else if ((z >= 79 && z <= 81) && ((x >= -81 && x <= -59) || (x >= -41 && x <= -19) || (x >= 59 && x <= 81)))
        return true;
    return false;
}

void Maze::drawWallX(GLdouble siz){
    GLdouble x = 0.5 * siz;
    GLdouble y = 0.5 * siz;
    GLdouble z = 0.5 * siz;
    glEnable(GL_TEXTURE_2D);

    // Grass
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textur);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 1.0);  glVertex3f(-x, -y, z);
        glTexCoord3f(1.0, 0.0, 1.0);  glVertex3f(x, -y, z);
        glTexCoord3f(1.0, 1.0, 1.0);  glVertex3f(x, y, z);
        glTexCoord3f(0.0, 1.0, 1.0);  glVertex3f(-x, y, z);

        glTexCoord3f(0.0, 0.0, -1.0);  glVertex3f(-x, -y, -z);
        glTexCoord3f(1.0, 0.0, -1.0);  glVertex3f(x, -y, -z);
        glTexCoord3f(1.0, 1.0, -1.0);  glVertex3f(x, y, -z);
        glTexCoord3f(0.0, 1.0, -1.0);  glVertex3f(-x, y, -z);

        glTexCoord3f(1.0, 0.0, 0.0);  glVertex3f(x, -y, -z);
        glTexCoord3f(1.0, 0.0, 1.0);  glVertex3f(x, -y, z);
        glTexCoord3f(1.0, 1.0, 1.0);  glVertex3f(x, y, z);
        glTexCoord3f(1.0, 1.0, 0.0);  glVertex3f(x, y, -z);

        glTexCoord3f(-1.0, 0.0, 0.0);  glVertex3f(-x, -y, -z);
        glTexCoord3f(-1.0, 0.0, 1.0);  glVertex3f(-x, -y, z);
        glTexCoord3f(-1.0, 1.0, 1.0);  glVertex3f(-x, y, z);
        glTexCoord3f(-1.0, 1.0, 0.0);  glVertex3f(-x, y, -z);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Maze::drawWallZ(GLdouble siz){
    GLdouble x = 0.5 * siz;
    GLdouble y = 0.5 * siz;
    GLdouble z = 0.5 * siz;
    glEnable(GL_TEXTURE_2D);

    // Grass
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textur);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
        glTexCoord3f(1.0, 0.0, 0.0);  glVertex3f(-x, -y, z);
        glTexCoord3f(1.0, 0.0, 1.0);  glVertex3f(x, -y, z);
        glTexCoord3f(1.0, 1.0, 1.0);  glVertex3f(x, y, z);
        glTexCoord3f(1.0, 1.0, 0.0);  glVertex3f(-x, y, z);

        glTexCoord3f(-1.0, 0.0, 0.0);  glVertex3f(-x, -y, -z);
        glTexCoord3f(-1.0, 0.0, 1.0);  glVertex3f(x, -y, -z);
        glTexCoord3f(-1.0, 1.0, 1.0);  glVertex3f(x, y, -z);
        glTexCoord3f(-1.0, 1.0, 0.0);  glVertex3f(-x, y, -z);

        glTexCoord3f(0.0, 0.0, 1.0);  glVertex3f(x, -y, -z);
        glTexCoord3f(1.0, 0.0, 1.0);  glVertex3f(x, -y, z);
        glTexCoord3f(1.0, 1.0, 1.0);  glVertex3f(x, y, z);
        glTexCoord3f(0.0, 1.0, 1.0);  glVertex3f(x, y, -z);

        glTexCoord3f(0.0, 0.0, -1.0);  glVertex3f(-x, -y, -z);
        glTexCoord3f(1.0, 0.0, -1.0);  glVertex3f(-x, -y, z);
        glTexCoord3f(1.0, 1.0, -1.0);  glVertex3f(-x, y, z);
        glTexCoord3f(0.0, 1.0, -1.0);  glVertex3f(-x, y, -z);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
