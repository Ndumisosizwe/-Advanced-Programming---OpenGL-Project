#ifndef MENUFRAME_H
#define MENUFRAME_H
#include "imageloader.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;
class MenuFrame{
public:
    MenuFrame();
    void render();
    void update();
    int processMouseButtons(int but, int state, int x, int y);
    int Keys(unsigned char key, int x, int y);
    void SpecialKeys(int key,int x,int y);
    void processPassiveMotion(int x, int y);
    void setState(int st);
    void idle();
private:
    bool highlightPlay;
    GLuint texture;
    int state;
};
#endif // MENUFRAME_H
