#include "Model_OBJ.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef GUN_H
#define GUN_H
class Gun{
public:
    Gun();
    Gun(float,float,float);
    void render();
    void update(float,float,float);
private:
    float x;
    float y;
    float z;



};
#endif // GUN_H
