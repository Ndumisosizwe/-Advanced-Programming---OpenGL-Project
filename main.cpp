#include "GameFrame.h"
#include "MenuFrame.h"
GameFrame* game;
MenuFrame* menu;
bool gameState = false; //game state or menu state

void init()
{
    menu = new MenuFrame();
    PlaySound("MenuMusic.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void render()
{
    if (gameState)
        game->render();
    else
        menu->render();
    glutSwapBuffers();
}

void update(){
    if (gameState){
        if (game->health > 0){
            game->update();
            if (game->enemiesLeft == 0 && (game->cam_x >= 7 && game->cam_x <= 12) && (game->cam_z >= -500 && game->cam_z <= 485)){
                menu->setState(2);
                gameState = false;
                delete game;
            }

        }
        else{
            menu->setState(1);
            gameState = false;
            delete game;
        }
    }

    else
        menu->update();
    glutPostRedisplay();
}

void display()
{
    render();
    update();
}


void reshape(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)	h = 1;
    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(55, ratio, 0.1, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void idle(){
    if (!gameState)
        menu->idle();
}

void Keys(unsigned char key, int x, int y) {
    if (gameState)
        game->Keys(key, x, y);
    else
        if (menu->Keys(key, x, y) == 1){
            gameState = true;
            game = new GameFrame();
        }
    glutPostRedisplay();
}
    //move up and down to see the world from top
void SpecialKeys(int key,int x,int y){
    if (gameState)
        game->SpecialKeys(key, x, y);
    else
        menu->SpecialKeys(key, x, y);
    glutPostRedisplay();
}

void processMouseButtons(int but, int state, int x, int y){
    if (gameState)
        game->processMouseButtons(but, state, x, y);
    else {
        if (menu->processMouseButtons(but, state, x, y) == 1){
                game = new GameFrame();
                gameState = true;
        }
    }
}
void processMouseMotion(int x, int y){
    if (gameState)
        game->processMouseMotion(x, y);
    //else
    //    menu->processMouseMotion(x, y);
    glutPostRedisplay();
}

void processPassiveMotion(int x, int y){
    if (!gameState)
        menu->processPassiveMotion(x, y);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowPosition(200,200);
    glutInitWindowSize(640, 480); //
    glutCreateWindow("MazeRunner");  // Create window with the given title
    glutFullScreen(); //enter FullScreen
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);   // Register callback handler for window re-size event
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutKeyboardFunc(Keys);         // Register callback handler for window re-size event
    glutSpecialFunc(SpecialKeys);
    glutMouseFunc(processMouseButtons); // Register callback handler for Mouse Click event
    glutMotionFunc(processMouseMotion); // Register callback handler for Mouse Motion event
    glutPassiveMotionFunc(processPassiveMotion);

    init();
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
