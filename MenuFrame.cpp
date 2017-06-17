#include "MenuFrame.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <MMSystem.h>

MenuFrame::MenuFrame(){
    texture = loadTexture(loadBMP("images\\Play.bmp"));
    highlightPlay = true;
    state = 0;
}

void MenuFrame::setState(int st){
    switch (st){
    case 0:
        texture = loadTexture(loadBMP("images\\Play.bmp"));
        state = 0;
        highlightPlay = true;
        break;
    case 1:
        texture = loadTexture(loadBMP("images\\Gameover.bmp"));
        state = 1;
        break;
    case 2:
        texture = loadTexture(loadBMP("images\\Gameover.bmp"));
        state = 2;
        break;
    }
}

void MenuFrame::render(){
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glLoadIdentity();
        glOrtho(0, 1, 0, 1, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
            glTexCoord3f(0.0, 0.0, 0.0);  glVertex3f(0.0, 0.0, 0.0);
            glTexCoord3f(1.0, 0.0, 0.0);  glVertex3f(1.0, 0.0, 0.0);
            glTexCoord3f(1.0, 1.0, 0.0);  glVertex3f(1.0, 1.0, 0.0);
            glTexCoord3f(0.0, 1.0, 0.0);  glVertex3f(0.0, 1.0, 0.0);

        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
}

void MenuFrame::update(){
    glutPostRedisplay();
}

int MenuFrame::Keys(unsigned char key, int x, int y){
    if (key == 27)
        exit(0);
    if (state == 2 || state == 1){
        state = 0;
        texture = loadTexture(loadBMP("images\\Play.bmp"));
    }
    else  if (state == 0){//main menu
       if (key == 13){
            if (highlightPlay)
                return 1;
            else
                exit(0);
        }
    }
    return 0;
}

void MenuFrame::SpecialKeys(int key,int x,int y){
    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN){
        if (highlightPlay)
            texture = loadTexture(loadBMP("images\\Exit.bmp"));
        else
            texture = loadTexture(loadBMP("images\\Play.bmp"));
        highlightPlay = !highlightPlay;

    }
}

int MenuFrame::processMouseButtons(int but, int state, int x, int y){
    if (but == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        double relativeX = x * 100 / (double) glutGet(GLUT_WINDOW_WIDTH);
        double relativeY = y * 100 / (double) glutGet(GLUT_WINDOW_HEIGHT);
        if ((relativeX >= 0.7 && relativeX <= 29.5) && (relativeY >= 54.5 && relativeY <= 64.5))
            return 1;
        else if ((relativeX >= 0.7 && relativeX <= 29.5) && (relativeY >= 76.5 && relativeY <= 86.5))
            exit(0);
    }
    return 0;
}

void MenuFrame::processPassiveMotion(int x, int y){
    double relativeX = x * 100 / (double) glutGet(GLUT_WINDOW_WIDTH);
    double relativeY = y * 100 / (double) glutGet(GLUT_WINDOW_HEIGHT);
    //cout << relativeX << "CCCCC" << relativeY << endl;
    if ((relativeX >= 0.7 && relativeX <= 29.5) && (relativeY >= 54.5 && relativeY <= 64.5)){
        if (!highlightPlay){
            texture = loadTexture(loadBMP("images\\Play.bmp"));
            highlightPlay = true;
        }
    }
    else if ((relativeX >= 0.7 && relativeX <= 29.5) && (relativeY >= 76.5 && relativeY <= 86.5)){
        if (highlightPlay){
            texture = loadTexture(loadBMP("images\\Exit.bmp"));
            highlightPlay = false;
        }
    }
    glutPostRedisplay();
}

void MenuFrame::idle(){
    glutPostRedisplay();
}
