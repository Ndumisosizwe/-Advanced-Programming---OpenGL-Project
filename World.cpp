#include "World.h"
//#include "texture.h"

using namespace std;
GLfloat angle1 = 90.0;

World::World(){
}
World::~World(){
}

GLuint _textureBrick, _textureForest, _textureGrass, _textureRoof, _textureWindow, _textureDoor, _textureSky, _textureCrate;


void World:: initLighting (void)
{
        glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glShadeModel(GL_SMOOTH);

 glEnable(GL_LIGHTING);
        GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = {0.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPosition0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);

    GLfloat lightColor1[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat lightPosition1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

    GLfloat lightColor2[] = {0.0f, 1.0f, 0.0f, 1.0f};
    GLfloat lightPosition2[] = {1, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);

    GLfloat mat_ambient[]    = { 0.0f, 0.0f, 0.7f, 1.0f };
    GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat high_shininess[] = {120}; // how much the objects should shine.


     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
}

void World::Sky(){
     glEnable(GL_TEXTURE_2D);
   glPushMatrix();
   	glColor3ub(255,255,255);
        glBindTexture(GL_TEXTURE_2D, _textureSky);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,1.0,1);  glVertex3f(600,-2.2,600);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-600,-2.2,600);
            glTexCoord3f(1.0,0.0,-1);  glVertex3f(-600,-2.2,-600);
            glTexCoord3f(1.0,1.0,1);  glVertex3f(600,-2.2,-600);
        glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);

}

void World::initTextures(void){
	_textureGrass = loadTexture(loadBMP("images\\Grass.bmp"));
	_textureForest = loadTexture(loadBMP("images\\jungle.bmp"));
	_textureSky = loadTexture(loadBMP("images\\sky.bmp"));
	_textureBrick = loadTexture(loadBMP("images\\wall.bmp"));
	_textureRoof = loadTexture(loadBMP("images\\tiles.bmp"));
	_textureWindow = loadTexture(loadBMP("images\\window.bmp"));
	_textureDoor = loadTexture(loadBMP("images\\door.bmp"));
	_textureCrate = loadTexture(loadBMP("images\\crate.bmp"));
}


void World::drawGround(){
    glEnable(GL_TEXTURE_2D);
   glPushMatrix();
   	glColor3ub(255,255,255);
        glBindTexture(GL_TEXTURE_2D, _textureGrass);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0,40.0,1);  glVertex3f(600,-2.2,600);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-600,-2.2,600);
            glTexCoord3f(40.0,0.0,-1);  glVertex3f(-600,-2.2,-600);
            glTexCoord3f(40,40.0,1);  glVertex3f(600,-2.2,-600);
        glEnd();
    glPopMatrix();

glDisable(GL_TEXTURE_2D);
}

void World::drawWalls(){
       glEnable(GL_TEXTURE_2D);
    //Draw the 4 walls of the enclosing cube in different colors
    glPushMatrix();
	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D, _textureForest);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);  glVertex3f(-600.0f,-2.2, -600.0f);
        glTexCoord3f(0.0,0.0,-1); glVertex3f(-600.0f,600, -600.0f);
        glTexCoord3f(1.0,0.0,-1); glVertex3f(600.0f,600, -600.0f);
        glTexCoord3f(1.0,1.0,1);  glVertex3f(600.0f,-2.2, -600.0f);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0,1.0,1);   glVertex3f(-600.0f,-2.2, -600.0f);
    glTexCoord3f(0.0,0.0,-1);  glVertex3f(-600.0f,600, -600.0f);
    glTexCoord3f(1.0,0.0,-1); glVertex3f(-600.0f,600, 600.0f);
    glTexCoord3f(1.0,1.0,1); glVertex3f(-600.0f,-2.2, 600.0f);
    glEnd();


    glBegin(GL_QUADS);
         glTexCoord3f(0.0,1.0,1); glVertex3f(600.0f,-2.2, -600.0f);
        glTexCoord3f(0.0,0.0,-1); glVertex3f(600.0f,600, -600.0f);
        glTexCoord3f(1.0,0.0,-1);glVertex3f(600.0f,600, 600.0f);
        glTexCoord3f(1.0,1.0,1); glVertex3f(600.0,-2.2, 600.0f);
    glEnd();
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1); glVertex3f(-600.0f,-2.2, 600.0f);
        glTexCoord3f(0.0,0.0,-1); glVertex3f(-600.0f,600, 600.0f);
        glTexCoord3f(1.0,0.0,-1); glVertex3f(600.0f,600, 600.0f);
        glTexCoord3f(1.0,1.0,1); glVertex3f(600.0f,-2.2, 600.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void World::house(){
     glEnable(GL_TEXTURE_2D);
     // Front side
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
//        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,0.1);  glVertex3f(-2,0,1);
            glTexCoord3f(4.0,2.0,0.1);  glVertex3f(2,0,1);
            glTexCoord3f(4.0,0.0,0.1);  glVertex3f(2,-1.5,1);
            glTexCoord3f(0.0,0.0,0.1);  glVertex3f(-2,-1.5,1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureRoof);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Roof
            glTexCoord3f(0.0,2.0,0); glVertex3f(-2.2,0.5,0);
            glTexCoord3f(4.0,2.0,0);glVertex3f(2.2,0.5,0);
            glTexCoord3f(4.0,0.0,1.25); glVertex3f(2.2,-0.1,1.25);
            glTexCoord3f(0.0,0.0,1.25); glVertex3f(-2.2,-0.1,1.25);
        glEnd();



         glTranslated(0,0,0.01);
        glBindTexture(GL_TEXTURE_2D, _textureDoor);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Door
            glTexCoord3f(0.0,1.0,1.0001); glVertex3f(-0.3,-0.4,1.0001);
            glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.3,-0.4,1.0001);
            glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.3,-1.5,1.0001);
            glTexCoord3f(0.0,0.0,1.0001); glVertex3f(-0.3,-1.5,1.0001);
        glEnd();
        glTranslated(0,0,0.01);
        glBindTexture(GL_TEXTURE_2D, _textureWindow);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window Left
            glTexCoord3f(0.0,1.0,1.0001); glVertex3f(-1.5,-0.3,1.0001);
            glTexCoord3f(1.0,1.0,1.0001); glVertex3f(-0.75,-0.3,1.0001);
            glTexCoord3f(1.0,0.0,1.0001); glVertex3f(-0.75,-0.8,1.0001);
            glTexCoord3f(0.0,0.0,1.0001); glVertex3f(-1.5,-0.8,1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
            glTexCoord3f(0.0,1.0,1.0001); glVertex3f(1.5,-0.3,1.0001);
            glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.75,-0.3,1.0001);
            glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.75,-0.8,1.0001);
            glTexCoord3f(0.0,0.0,1.0001); glVertex3f(1.5,-0.8,1.0001);
        glEnd();
    glPopMatrix();

    // Back side
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
//        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,-1);  glVertex3f(-2,0,-1);
            glTexCoord3f(4.0,2.0,-1);  glVertex3f(2,0,-1);
            glTexCoord3f(4.0,0.0,-1);  glVertex3f(2,-1.5,-1);
            glTexCoord3f(0.0,0.0,-1);  glVertex3f(-2,-1.5,-1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureRoof);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Roof
            glTexCoord3f(0.0,2.0,0); glVertex3f(-2.2,0.5,0);
            glTexCoord3f(4.0,2.0,0);glVertex3f(2.2,0.5,0);
            glTexCoord3f(4.0,0.0,-1.25); glVertex3f(2.2,-0.1,-1.25);
            glTexCoord3f(0.0,0.0,-1.25); glVertex3f(-2.2,-0.1,-1.25);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, _textureWindow);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);  // Window Left
            glTexCoord3f(0.0,1.0,-1.0001); glVertex3f(-1.5,-0.3,-1.0001);
            glTexCoord3f(1.0,1.0,-1.0001); glVertex3f(-0.75,-0.3,-1.0001);
            glTexCoord3f(1.0,0.0,-1.0001); glVertex3f(-0.75,-0.8,-1.0001);
            glTexCoord3f(0.0,0.0,-1.0001); glVertex3f(-1.5,-0.8,-1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
            glTexCoord3f(0.0,1.0,1.0001); glVertex3f(1.5,-0.3,-1.0001);
            glTexCoord3f(1.0,1.0,1.0001); glVertex3f(0.75,-0.3,-1.0001);
            glTexCoord3f(1.0,0.0,1.0001); glVertex3f(0.75,-0.8,-1.0001);
            glTexCoord3f(0.0,0.0,1.0001); glVertex3f(1.5,-0.8,-1.0001);
        glEnd();
    glPopMatrix();

    // Right side
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
//        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1); glVertex3f(2,0,1);
            glTexCoord3f(2.0,2.0,-1); glVertex3f(2,0,-1);
            glTexCoord3f(2.0,0.0,-1); glVertex3f(2,-1.5,-1);
            glTexCoord3f(0.0,0.0,1); glVertex3f(2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
            glTexCoord3f(0.0,1.0,0); glVertex3f(2,0.5,0);
            glTexCoord3f(1.0,0.0,1); glVertex3f(2,0,1);
            glTexCoord3f(-1.0,0.0,-1); glVertex3f(2,0,-1);
        glEnd();
    glPopMatrix();

    // Left side
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, _textureBrick);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTranslatef(0,0,-6);
//        glRotatef(_angle, 0.0, 1.0, 0.0);
        glBegin(GL_QUADS);  // Wall
            glTexCoord3f(0.0,2.0,1);    glVertex3f(-2,0,1);
            glTexCoord3f(2.0,2.0,-1);    glVertex3f(-2,0,-1);
            glTexCoord3f(2.0,0.0,-1);    glVertex3f(-2,-1.5,-1);
            glTexCoord3f(0.0,0.0,1);    glVertex3f(-2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
            glTexCoord3f(0.0,1.0,0);    glVertex3f(-2,0.5,0);
            glTexCoord3f(1.0,0.0,1);    glVertex3f(-2,0,1);
            glTexCoord3f(-1.0,0.0,-1);    glVertex3f(-2,0,-1);
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

void World::cube(){
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glColor3ub(139,69,19);
     glBindTexture(GL_TEXTURE_2D, _textureCrate);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glScaled(10,10,10);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);    glVertex3f(0.6,0,0);
        glTexCoord3f(0.0,0.0,-1);   glVertex3f(0.6,0,-0.6);
        glTexCoord3f(1.0,0.0,-1);   glVertex3f(0.6,0.6,-0.6);
        glTexCoord3f(1.0,1.0,1);    glVertex3f(0.6,0.6,0);
    glEnd();
    glRotated(-90,0,1,0);
    glTranslated(-0.6,0,0);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);    glVertex3f(0.6,0,0);
        glTexCoord3f(0.0,0.0,-1);   glVertex3f(0.6,0,-0.6);
        glTexCoord3f(1.0,0.0,-1);   glVertex3f(0.6,0.6,-0.6);
        glTexCoord3f(1.0,1.0,1);    glVertex3f(0.6,0.6,0);
    glEnd();

    glTranslated(-0.6,0,0);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);    glVertex3f(0.6,0,0);
        glTexCoord3f(0.0,0.0,-1);   glVertex3f(0.6,0,-0.6);
        glTexCoord3f(1.0,0.0,-1);   glVertex3f(0.6,0.6,-0.6);
        glTexCoord3f(1.0,1.0,1);    glVertex3f(0.6,0.6,0);
    glEnd();
    glRotated(-90,0,1,0);
    glTranslated(-0.6,0,-0.6);
    glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);    glVertex3f(0.6,0,0);
        glTexCoord3f(0.0,0.0,-1);   glVertex3f(0.6,0,-0.6);
        glTexCoord3f(1.0,0.0,-1);   glVertex3f(0.6,0.6,-0.6);
        glTexCoord3f(1.0,1.0,1);    glVertex3f(0.6,0.6,0);
    glEnd();
    glRotated(90,0,0,1);
    glTranslated(0,-0.6,0);
        glBegin(GL_QUADS);
        glTexCoord3f(0.0,1.0,1);    glVertex3f(0.6,0,0);
        glTexCoord3f(0.0,0.0,-1);   glVertex3f(0.6,0,-0.6);
        glTexCoord3f(1.0,0.0,-1);   glVertex3f(0.6,0.6,-0.6);
        glTexCoord3f(1.0,1.0,1);    glVertex3f(0.6,0.6,0);
    glEnd();


glPopMatrix();

glDisable(GL_TEXTURE_2D);
}

void World::render(){
    if (!initialized){
        initLighting();
        initTextures();
        initialized = true;
    }
    drawGround();
    drawWalls();
glPushMatrix();
    glTranslated(0,40,-350);
    glScaled(30,30,30);
    house();
glPopMatrix();
glPushMatrix();
    glTranslated(0,600,0);
    Sky();
glPopMatrix();

for(int i = 1; i <= 2 ; i++){
    glPushMatrix();
    glTranslated(i*30,-2,i*120);
    glRotated(30,0,1,0);
    cube();
glPopMatrix();
}

}
