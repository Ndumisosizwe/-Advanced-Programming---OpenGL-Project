#include "GameFrame.h"

GameFrame::GameFrame(){
    initVariables();
    glClearColor(1,1,1,1);
    Title.Load("GameTitle.obj");//Load the Obj file, to render it's Normals,Faces, Verteces
    Shotgun.Load("SMG.obj");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void GameFrame::initVariables(){
    //
    v_ghosts.push_back(Ghost(-6, 70));
    v_ghosts.push_back(Ghost(30, 70));
    //
    v_ghosts.push_back(Ghost(10, 50));
    //
    v_ghosts.push_back(Ghost(-15, 10));
    v_ghosts.push_back(Ghost(-26, 10));
    //
    v_ghosts.push_back(Ghost(-10, 28));
    v_ghosts.push_back(Ghost(10, 28));
    //
    v_ghosts.push_back(Ghost(6, -35));
    //
    v_ghosts.push_back(Ghost(-10, -49));
    v_ghosts.push_back(Ghost(10, -49));
    //
    v_ghosts.push_back(Ghost(-15, -71));
    v_ghosts.push_back(Ghost(10, -71));
    //
    v_ghosts.push_back(Ghost(-50, -89));


    v_points.push_back(Collectibles(53,35,0.35,0.15)); // X,Z,SPEED,ColorChanger
    v_points.push_back(Collectibles(-6.5,-150,0.26,4.15)); // X,Z,SPEED,ColorChanger
    v_points.push_back(Collectibles(-200.5,-150,0.7,3.15)); // X,Z,SPEED,ColorChanger
    v_points.push_back(Collectibles(-70.5,-200,0.28,1.15)); // X,Z,SPEED,ColorChanger
    v_points.push_back(Collectibles(-100,-150,0.63,6.15));
    v_points.push_back(Collectibles(-160,-90,0.23,0.15));
    enemies = v_ghosts.size();
    enemiesLeft = enemies;
    cam_x = -300;
    cam_y = 250;
    cam_z = -500;
    look_x = 0;
    look_y = 0;
    look_z = 0;
    angle = 0;
    originalX = -1;
}

void GameFrame::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(cam_x, cam_y, cam_z, //camera position
            look_x, look_y, look_z, // eye look at
            0, 1, 0); // up position

        for(int i = 0; i < v_points.size(); i++){
            if(cam_y<=10)
        v_points[i].render();
        }

       world.render();
       maze.extendMaize();
       maze.render();
       maze.boundWalls();

        if(LetItRain){
            glPushMatrix();
            glTranslated(0,70,0);
            for(int i = - 20 ; i < 20; i++){
                for(int j = -20 ; j < 20; j++){
                    glPushMatrix();
                        glTranslated(i*40,0,j*40);
                        rain.drawRain();
                    glPopMatrix();
            }

        }
        glPopMatrix();
        }

        for(unsigned int i = 0; i < v_bullets.size() ; i++){
                if(cam_y<=10)
           v_bullets[i].render();
        }
        for (unsigned int i = 0; i < v_ghosts.size() ; i++){
            if(cam_y<=10)
         v_ghosts[i].render();
        }
    if(cam_y <= 10){
         glPushMatrix();
        glColor3ub(0.1,0.1,5);
            glTranslated(cam_x - 5 * sin(angle) + 1 *  sin(angle + M_PI_2)*6.5, 0, cam_z - 5 * cos(angle) + 1 * cos(angle + M_PI_2) *-6.5 );
            glRotated(angle * 180 / M_PI + 180, 0, 1, 0);
            glScaled(3, 3, 5);
            glRotated(angle,0,1,0);
            Shotgun.Draw();
        glPopMatrix();
    }

    if (cam_y <= 10)
        displayState();
}

void GameFrame::update(){
    //update position of Bullets in the vector
    for(unsigned int i = 0; i < v_bullets.size() ; i++){
        if (v_bullets[i].hitWalls()){
            v_bullets.erase(v_bullets.begin() + i);
            i--;
        }
        else{
            v_bullets[i].update();
        }
    }

   bool shot;
    for (unsigned int i = 0; i < v_ghosts.size() ; i++){
        for (unsigned int j = 0; j < v_bullets.size() ; j++){
            shot = v_ghosts[i].isShot(v_bullets[j]);
            if (shot){
                v_bullets.erase(v_bullets.begin() + j);
                v_ghosts.erase(v_ghosts.begin() + i);
                i--;
                enemiesLeft = v_ghosts.size();
                break;
            }
        }
        if (!shot){
            v_ghosts[i].update();
            if (checkCollissionWithGhost(v_ghosts[i])){
                PlaySound("Monster.wav", NULL, SND_FILENAME | SND_ASYNC);
                health -= 25;
                cam_x = 0;              look_x = cam_x + z_dist * sin(angle);
                cam_z = 120;            look_z = cam_z + z_dist * cos(angle);
            }
        }
    }

    //Point Collection
    if(isCollected() >= 0){
            if(cam_y<=10)
        v_points.at(isCollected()).CheckPoint();
    }

    for(int i = 0; i < v_points.size(); i++){
            if(cam_y<=10)
            v_points[i].update();
    }

//Opening Scene Animation
bool wentToPositive =false;
if(cam_y >= 10){
       angle3 -=0.0005;
           cam_y -=Y_;
           cam_x +=X_;

        look_x += sin(angle3)/5;
        look_z += cos(angle3)/5;
       cam_z += Z_;
     }

     if(cam_x>=2 && cam_x<= 17 && (cam_y <=10) && (cam_z<=130 && cam_z>=120))
        PlaySound("Monster.wav", NULL, SND_FILENAME | SND_ASYNC);

}

void GameFrame::DrawTextXY(double x,double y,double z,double scale, char *s){
    int i;

    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(scale,scale,scale);
    for (i=0;i < strlen(s);i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
    glPopMatrix();
}

void GameFrame::drawString(void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (font, s[i]);
}

char* GameFrame::toChar(int num){
    stringstream ss;
    ss<<num;
    string str =ss.str();
    char *char1= new char[str.size() + 1];
    strcpy(char1, str.c_str());
    return char1;
}

void GameFrame::displayState(){
    glLoadName(TEXTID);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        glOrtho(0, 800, 0, 600, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3f(1, 0, 0);
        DrawTextXY(25,550,0,0.2,"Health:  %");
        DrawTextXY(100,550,0,0.2,toChar(health));

        DrawTextXY(550,550,0,0.2, "Enemies Killed: /");
        DrawTextXY(740,550,0,0.2,toChar(enemies - v_ghosts.size()));
        DrawTextXY(770,550,0,0.2,toChar(enemies));
if(cam_y <=10){
        glColor3f(14, 80, 34);
        glBegin(GL_LINES);
            glVertex2d(390, 310);
            glVertex2d(410, 310);
            glVertex2d(400, 300);
            glVertex2d(400, 320);
        glEnd();

}
        glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
}

int GameFrame::isCollected(){
    if((cam_x >=51&&cam_x<=55)&&(cam_z>=33&&cam_z<=37))
        return 0;
    else if((cam_x >=-9.5&&cam_x<=-3.5)&&(cam_z>=-153&&cam_z<=-147))
        return 1;
    else if((cam_x >=-203.5&&cam_x<=-197.5)&&(cam_z>=-153&&cam_z<=-147))
        return 2;
    else if((cam_x >=-73.5&&cam_x<=-67.5)&&(cam_z>=-203&&cam_z<=-197))
        return 3;
    else if((cam_x >=90&&cam_x<=103)&&(cam_z>=-153&&cam_z<=-147))
        return 4;
     else if((cam_x >=-163&&cam_x<=-157)&&(cam_z>=-93&&cam_z<=-87))
        return 6;
    else
        return -1; //No Ball collected
}

bool GameFrame::checkCollissionWithGhost(Ghost ghost){
    double span = sqrt(pow(ghost.pos_x - cam_x, 2) + pow(ghost.pos_z - cam_z, 2));
    if (span <= ghost.rad + 3)
        return true;
    else
        return false;
}

bool GameFrame::inBound(){
    if((cam_z <= 595 && cam_z >= -595) && (cam_x <= 595&& cam_x >= -595))
        return true;
    else
        return false;
}

void GameFrame::walk(GLdouble units){
    cam_x += units * sin(angle); look_x += units * sin(angle);
    cam_z += units * cos(angle); look_z += units * cos(angle);
}

void GameFrame::shiftSideways(GLdouble units){
    cam_x += units * sin(angle + M_PI_2);
    look_x += units * sin(angle + M_PI_2);
    cam_z += units * cos(angle + M_PI_2);
    look_z += units * cos(angle + M_PI_2);
}

void GameFrame::Keys(unsigned char key, int x, int y){
    key = tolower(key); //In case CAPS LOCK is on

    if(key==27)
        exit(0); //Exit the game
        if(key==13){
            cout << "x "<< cam_x << endl;
            cout <<  "z " << cam_z<<endl;}
    switch(key){
    case ' ':  //SPACE BAR
            v_bullets.push_back(Bullet(cam_x,cam_y,cam_z,angle)); //Load the vector with bullets
           PlaySound("shotgun.wav", NULL, SND_FILENAME | SND_ASYNC);

        break;

    case 'w': // MOVE FOWARD
            if(!maze.checkCollision(cam_x,cam_z) && (inBound())){// if there's no collision with the maize
                walk(-1);
            }
            else
                walk(5);

        break;
    case 's': // MOVE BACK
            if(!maze.checkCollision(cam_x,cam_z) && (inBound()))
                walk(1);
            else
                walk(-5);
        break;
    case 'a':
            if(!maze.checkCollision(cam_x,cam_z) && (inBound()))
                shiftSideways(-1);
            else
                shiftSideways(5);
        break;
    case 'd': //ROTATE RIGHT
            if(!maze.checkCollision(cam_x,cam_z) && (inBound()))
                shiftSideways(1);
            else
                shiftSideways(-5);
        break;
        case 'r': //rain sound effect
            if(cam_y <=10){
            LetItRain = !LetItRain; //I make it rain !
           PlaySound("rain.wav", NULL, SND_FILENAME | SND_ASYNC);
            }
               break;
    }
}

void GameFrame::SpecialKeys(int key,int x,int y){
    switch(key){
        case GLUT_KEY_PAGE_DOWN:
           if(cam_y >= 30)
            cam_y -= 20;
            break;
        case GLUT_KEY_PAGE_UP:
           if(cam_y <= 50)
             if(cam_z <= 595)
            cam_y += 20;
            break;
    }
}

void GameFrame::processMouseButtons(int but, int state, int x, int y){
    if (but == GLUT_LEFT_BUTTON){
        switch (state){
            case GLUT_DOWN:
                originalX = x;
                break;
            case GLUT_UP:
                originalX = -1;
                break;
        }
    }
}

void GameFrame::processMouseMotion(int x, int y){
    if (originalX > 0){
        angle += ((originalX - x) / 500);
        look_x = cam_x + z_dist * sin(angle);
        look_z = cam_z + z_dist * cos(angle);
        originalX = x;
    }
    if (angle > 2 * M_PI) x -= 2 * M_PI;
    if (angle < 2 * M_PI) x += 2 * M_PI;
}

void GameFrame::processPassiveMotion(int x, int y){
    if (cam_y <= 10){
        if (originalX > 0){
            angle += ((originalX - x) / 500);
            look_x = cam_x + z_dist * sin(angle);
            look_z = cam_z + z_dist * cos(angle);
            originalX = x;
        }
        if (angle > 2 * M_PI) x -= 2 * M_PI;
        if (angle < 2 * M_PI) x += 2 * M_PI;
        originalX = x;
    }
}
