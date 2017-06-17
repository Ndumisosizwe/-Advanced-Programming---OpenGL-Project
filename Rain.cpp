#define MAX_PARTICLES 1000
#define RAIN	0
#define SNOW	1
#define	HAIL	2
#include "Rain.h"

float slowdown = 2.0;
float velocity = 0.0;
float zoom = -40.0;
float pan = 0.0;
float tilt = 0.0;
float hailsize = 0.1;

int loop;
int fall;

float ground_points[21][21][3];
float ground_colors[21][21][4];
float accum = -10.0;

Rain::Rain(){
     initTializeDrops(loop);
}

typedef struct {
	// Life
	bool alive;	// is the particle alive?
	float life;	// particle lifespan
	float fade; // decay
	// color
	float red;
	float green;
	float blue;
	// Position/direction
	float xpos;
	float ypos;
	float zpos;
	// Velocity/Direction, only goes down in y dir
	float vel;
	// Gravity
	float gravity;
}particles;

// Paticle System
particles par_sys[MAX_PARTICLES]; //defined at TOP

// Initialize/Reset Particles - give them their attributes
void Rain::initParticles(int i) {
		par_sys[i].alive = true;
		par_sys[i].life = 1.0;
		par_sys[i].fade = float(rand()%100)/1000.0f+0.003f;

		par_sys[i].xpos = (float) (rand() % 21) - 10;
		par_sys[i].ypos = 10.0;
		par_sys[i].zpos = (float) (rand() % 21) - 10;

		par_sys[i].red = 0.5;
		par_sys[i].green = 0.5;
		par_sys[i].blue = 1.0;

		par_sys[i].vel = velocity;
		par_sys[i].gravity = -0.8;//-0.8;
}

void Rain::drawRain() {
	float x, y, z;
	glPushMatrix();
	glScaled(2,7,2);
	for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
		if (par_sys[loop].alive == true) {
			x = par_sys[loop].xpos;
			y = par_sys[loop].ypos;
			z = par_sys[loop].zpos + zoom;

			// Draw particles
			glColor3f(255, 255, 255);
			glBegin(GL_LINES);
                glVertex3f(x, y, z);
				glVertex3f(x, (y+0.3), z);
			glEnd();

			// Update values
			//Move
			par_sys[loop].ypos += par_sys[loop].vel / (slowdown*100);//Speed
			par_sys[loop].vel += par_sys[loop].gravity;
			// Decay
			par_sys[loop].life -= par_sys[loop].fade;

			if (par_sys[loop].ypos <= -10) {
				par_sys[loop].life = -1.0;
			}
			//Revive
			if (par_sys[loop].life < 0.0) {
				initParticles(loop);
			}
		}
	}
	glPopMatrix();
}

void Rain::initTializeDrops(int loop){
        // Initialize particles
    for (loop = 0; loop < MAX_PARTICLES; loop++) {
        initParticles(loop);
    }
}



