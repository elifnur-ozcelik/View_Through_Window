/*
Project Name : View Through a Window
Created by : Elifnur Ozcelik
Description :
-This project is developed using OpenGL and the GLUT library.
- Includes basic geometric drawing(ellipse, rectangle, circle) and simple user interaction through keyboard and mouse events.
- It creates a window scene with a view of the sky and a mysterious UFO.
- Pressing the left mouse button toggles the visibility of a surprise alien character.
- Pressing the spacebar starts/stops the UFO animation.
- The UFO moves continuously across the window from left to right.
- Pressing F1 key also starts the animation if it hasn't started yet.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define TIMER_PERIOD   20
#define TIMER_ON        1
#define PI 3.1415

bool alienVisible = false; 
bool startAnimation = false; 
bool activeTimer = false;
int xB = -100 / 2 - 75; 
int yB = 0; 
int rX = 75, rY = 20; 

void ellipse(int x, int y, int rX, int rY) {
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		angle = 2 * PI * i / 100;
		glVertex2f(x + rX * cos(angle), y + rY * sin(angle));
	}
	glEnd();
}

void circle(int x, int y, int r) {
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		angle = 2 * PI * i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

void rectangle(int x, int y, int width, int height) {
	glBegin(GL_QUADS);
	glVertex2f(x - width / 2, y - height);
	glVertex2f(x + width / 2, y - height);
	glVertex2f(x + width / 2, y + height);
	glVertex2f(x - width / 2, y + height);
	glEnd();
}

void onMouseClick(int button, int stat, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN) {
		alienVisible = !alienVisible;
		glutPostRedisplay();
	}
}

void vprint(int x, int y, void* font, const char* string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, str[i]);
}

void display() {
	
	glClearColor(1, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3ub(96, 96, 96);
	glVertex2f(-400.0, -300.0); glVertex2f(-400.0, 300.0);
	glVertex2f(-240.0, -300.0); glVertex2f(-240.0, 300.0);
	glVertex2f(-160.0, -300.0); glVertex2f(-160.0, 300.0);
	glVertex2f(-80.0, -300.0);  glVertex2f(-80.0, 300.0);
	glVertex2f(0.0, -300.0);    glVertex2f(0.0, 300.0);
	glVertex2f(80.0, -300.0);   glVertex2f(80.0, 300.0);
	glVertex2f(160.0, -300.0);  glVertex2f(160.0, 300.0);
	glVertex2f(240.0, -300.0);  glVertex2f(240.0, 300.0);
	glVertex2f(400.0, -300.0);  glVertex2f(400.0, 300.0);
	glEnd();

	glColor3f(0.678, 0.847, 0.902);
	glBegin(GL_QUADS);
	glVertex2f(-200, 240);
	glVertex2f(200, 240);
	glVertex2f(200, 280);
	glVertex2f(-200, 280);
	glEnd();

	glColor3f(0, 0, 0);
	vprint(-185, 255, GLUT_BITMAP_9_BY_15, "View Through a Window by Elifnur Ozcelik");

	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2f(-280, 170);
	glVertex2f(-280, 190);
	glVertex2f(280, 190);
	glVertex2f(280, 170);
	glEnd();

	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2f(280, -170);
	glVertex2f(280, -190);
	glVertex2f(-280, -190);
	glVertex2f(-280, -170);
	glEnd();

	glColor3ub(0, 0, 139);
	glBegin(GL_POLYGON);
	glVertex2f(-270, -170);
	glVertex2f(-270, 170);
	glVertex2f(270, 170);
	glVertex2f(270, -170);
	glEnd();

	glColor3ub(180, 172, 50);
	ellipse(xB, yB, rX, rY);

	glColor3ub(180, 172, 50);
	ellipse(xB, yB + rY, rX / 2, rY / 2);
	
	glColor3ub(180, 172, 50);
	rectangle(xB, yB + rY + rY / 2, 2, 10);

	glColor3ub(255, 0, 0);
	circle(xB, yB + rY + rY / 2 + 10, 5);

	glColor4f(1.0, 1.0, 1.0, 0.5);
	circle(xB - rX / 6, yB + rY + rY / 6, rX / 10);
	circle(xB + rX / 6, yB + rY + rY / 6, rX / 10);
	circle(xB - rX / 2, yB + rY / 3, rX / 10);
	circle(xB - rX / 6, yB + rY / 3, rX / 10);
	circle(xB + rX / 6, yB + rY / 3, rX / 10);
	circle(xB + rX / 2, yB + rY / 3, rX / 10);

	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2f(-280, -180);
	glVertex2f(-280, 180);
	glVertex2f(-270, 180);
	glVertex2f(-270, -180);
	glEnd();

	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2f(280, -180);
	glVertex2f(280, 180);
	glVertex2f(270, 180);
	glVertex2f(270, -180);
	glEnd();

	glColor3ub(255, 0, 255);
	glBegin(GL_POLYGON);
	glVertex2f(-280, -180);
	glVertex2f(-400, -180);
	glVertex2f(-400, 180);
	glVertex2f(-280, 180);
	glEnd();

	glColor3ub(255, 0, 255);
	glBegin(GL_POLYGON);
	glVertex2f(280, -180);
	glVertex2f(400, -180);
	glVertex2f(400, 180);
	glVertex2f(280, 180);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(96, 96, 96);
	glVertex2f(-320.0, -300.0); glVertex2f(-320.0, 300.0);
	glVertex2f(320.0, -300.0);  glVertex2f(320.0, 300.0);
	glEnd();
		
	glColor3ub(0, 100, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-270, -170); 
	glVertex2f(-270, -60);
	glVertex2f(270, -60);
	glVertex2f(270, -170);
	glEnd();

	if (alienVisible) {

		glColor3ub(144, 238, 144);
		glBegin(GL_TRIANGLES);
		glVertex2f(-210, -170);
		glVertex2f(-150, -170);
		glVertex2f(-170, 20);
		glEnd();

		int centerX = -170;
		int centerY = 10;
		int rX = 30;
		int rY = 60;

		glColor3ub(144, 238, 144);
		ellipse(centerX, centerY, rX, rY);

		int eyeRX = rX / 4;
		int eyeRY = rY / 6;
		int eyeOffsetX = 10;
		int eyeOffsetY = 20;

		glColor3ub(255, 255, 255);
		ellipse(centerX + eyeOffsetX, centerY + eyeOffsetY, eyeRX, eyeRY);

		glColor3ub(255, 255, 255);
		ellipse(centerX - eyeOffsetX, centerY + eyeOffsetY, eyeRX, eyeRY);

		int pupilRX = eyeRX / 2;
		int pupilRY = eyeRY / 2;

		glColor3ub(0, 0, 0);
		ellipse(centerX + eyeOffsetX, centerY + eyeOffsetY, pupilRX, pupilRY);

		glColor3ub(0, 0, 0);
		ellipse(centerX - eyeOffsetX, centerY + eyeOffsetY, pupilRX, pupilRY);
	}
	
	glColor3ub(100, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(270, -170);
	glVertex2f(270, -120);
	glVertex2f(240, -120);
	glVertex2f(240, -170);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(240, -120);
	glVertex2f(240, -170);
	glVertex2f(210, -120);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(255, -120);
	glVertex2f(255, -70);
	glVertex2f(250, -70);
	glVertex2f(250, -120);
	glEnd();
		
	glColor3ub(255, 165, 0);
	glBegin(GL_POLYGON);
	glVertex2f(267, -60);
	glVertex2f(252, -43);
	glVertex2f(237, -60);
	glVertex2f(252, -77);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(260, -70);
	glVertex2f(260, -50);
	glVertex2f(245, -50);
	glVertex2f(245, -70);
	glEnd();

	glColor3ub(144, 238, 144);
	glBegin(GL_POLYGON);
    glVertex2f(250, -100);
    glVertex2f(250, -90);
    glVertex2f(230, -90);
	glEnd();
		
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2f(-10, -180);
	glVertex2f(-10, 180);
	glVertex2f(10, 180);
	glVertex2f(10, -180);
	glEnd();

	glColor3ub(245, 235, 214);
	glLineWidth(1);

	glBegin(GL_LINES);
	glVertex2f(-10, -170);
	glVertex2f(-10, 170);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(10, -170);
	glVertex2f(10, 170);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-6, -20);
	glVertex2f(-6, 20);
	glVertex2f(-2, 20);
	glVertex2f(-2, -20); 
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(2, -20);   
	glVertex2f(2, 20);    
	glVertex2f(6, 20);    
	glVertex2f(6, -20);  
	glEnd();

	glColor3ub(245, 235, 214); 
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0, -180); 
	glVertex2f(0, 180);  
	glEnd();

	glutSwapBuffers();
}

void onResize(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400, 400, -300, 300); 
	glMatrixMode(GL_MODELVIEW);
	printf("Event: RESIZE called, Width: %d Height: %d\n", width, height);
}


#if TIMER_ON == 1
void onTimer(int v) {
	if (activeTimer) {
		glutTimerFunc(TIMER_PERIOD, onTimer, 0);
		xB += 2;
		if (xB > WINDOW_WIDTH / 2 + rX) {
			xB = -WINDOW_WIDTH / 2 - rX;
		}
		glutPostRedisplay();
	}
}
#endif

void onKeyDown(unsigned char key, int x, int y) {
	if (key == ' ') {
		activeTimer = !activeTimer;
		if (activeTimer) {
			glutTimerFunc(TIMER_PERIOD, onTimer, 0);
		}
	}
}

void onSpecialKeyUp(int key, int x, int y) {
	if (key == GLUT_KEY_F1) {
		if (!startAnimation) { 
			startAnimation = true;
			glutTimerFunc(TIMER_PERIOD, onTimer, 0);
		}
	}
	glutPostRedisplay();
}

void init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(" Elifnur_Ozcelik 164 HW_1 ");

	glutDisplayFunc(display);
	glutReshapeFunc(onResize);
	glutKeyboardFunc(onKeyDown);
	glutSpecialUpFunc(onSpecialKeyUp);
	glutMouseFunc(onMouseClick);
	
#if TIMER_ON == 1
	glutTimerFunc(TIMER_PERIOD, onTimer, 0);
#endif

	init();
	glutMainLoop();
	return 0;
}