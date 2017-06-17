#include "Wall.h"
#include "imageloader.h"
Wall::Wall(const char* filename){
    texture = loadTexture(loadBMP(filename));
}

void Wall::render(){
    drawWall();
}

void Wall::drawWall(){
    glEnable(GL_TEXTURE_2D);

    // Grass
    glPushMatrix();
    glColor3ub(255,255,255);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTranslatef(0,0,-6);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,70.0,1);  glVertex3f(x, y, z);
        glTexCoord3f(0.0,0.0,-1);  glVertex3f(x, -y, z);
        glTexCoord3f(70.0,0.0,-1);  glVertex3f(-x, -y, z);
        glTexCoord3f(70.0,70.0,1);  glVertex3f(x, y, z);

        glTexCoord3f(0.0,70.0,1);  glVertex3f(x, y, -z);
        glTexCoord3f(0.0,0.0,-1);  glVertex3f(x, -y, -z);
        glTexCoord3f(70.0,0.0,-1);  glVertex3f(-x, -y, -z);
        glTexCoord3f(70.0,70.0,1);  glVertex3f(x, y, -z);




    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
