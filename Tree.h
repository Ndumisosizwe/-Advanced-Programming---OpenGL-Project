#include <GL/glut.h>
#include <iostream>

#ifndef TREE_H
#define TREE_H

class Tree{
public :
    Tree();
    ~Tree();
    void render();
private:
    void drawTree();
};

#endif // TREE_H
