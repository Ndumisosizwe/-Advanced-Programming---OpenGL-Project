#include "Gun.h"
#include "Model_OBJ.h"
#include <GL/freeglut.h>
#include <GL/glut.h>

static Model_OBJ Shotgun; //Obj Object
Gun::Gun(){
}

Gun::Gun(float x_pos,float y_pos ,float z_pos){
    this->x = x_pos;
    this->y = y_pos;
    this->z = z_pos;
}

void Gun::render(){
    glPushMatrix();

        glColor3ub(125,125,125);
        //glRotated(185,0,1,0);
        glScaled(20,20,20);
        glTranslated(this->x,this->y,this->z);
        Shotgun.Draw();

    glPopMatrix();

}

void Gun::update(float cam_x,float cam_z,float angle){

}

