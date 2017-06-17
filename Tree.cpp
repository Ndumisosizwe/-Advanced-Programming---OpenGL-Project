#include "Tree.h"
#include <GL/freeglut.h>
Tree::Tree(){
}

Tree::~Tree(){}
void Tree::render(){
    drawTree();
}
void Tree::drawTree(){

	//Draw tree
	glPushMatrix();

	glTranslatef(-41.6,40,-10);
    glRotatef(90,1,0,0);
    glColor3ub(167, 57, 0);
    glutSolidCylinder(2,50,50,50);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0,40,0);
        glTranslatef(-41.6,25,-10);
        glRotatef(-90.0,1,0,0);
        glutSolidCone(10,15,50,45);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0,40,0);
        glTranslatef(-41.6,30,-10);
        glRotatef(-90.0,1,0,0);
        glutSolidCone(8,15,50,45);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0,40,0);
        glTranslatef(-41.6,35,-10);
        glRotatef(-90.0,1,0,0);
        glutSolidCone(6,15,50,45);
	glPopMatrix();

}


