/*
gcc test_5.c -o test_5 -lGL -lglut -lGLU -lglfw3 -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread
*/

#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define SPEED 0.003
#define SENS 0.03
#define MAPSIZE 256

int forward, left, backward, right;

void ground()
{
	glPushMatrix();
	
	glBegin(GL_POLYGON);
	glColor3f(0.871, 0.722, 0.529);
	glVertex3f(-MAPSIZE, -0.5, -MAPSIZE);
	glVertex3f( MAPSIZE, -0.5, -MAPSIZE );
	glVertex3f( MAPSIZE, -0.5,  MAPSIZE );
	glVertex3f(-MAPSIZE, -0.5,  MAPSIZE );
	glEnd();

	glPopMatrix();
}

void map()
{
	glPushMatrix();
	glTranslated(0, 0, -2);
	
	glBegin(GL_POLYGON);
	glColor3f(   0.8,  0.8, 0.8 );
	glVertex3f(  0.5, -0.5, 0.5 );
	glVertex3f(  0.5,  0.5, 0.5 );
	glVertex3f( -0.5,  0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.7,  0.7, 0.7 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5,  0.5, -0.5 );
	glVertex3f( 0.5,  0.5,  0.5 );
	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.6,  0.6,  0.6 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.5,  0.5,  0.5 );
	glVertex3f(  0.5, 0.5,  0.5 );
	glVertex3f(  0.5, 0.5, -0.5 );
	glVertex3f( -0.5, 0.5, -0.5 );
	glVertex3f( -0.5, 0.5,  0.5 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.4,  0.4,  0.4 );
	glVertex3f(  0.5, -0.5, -0.5 );
	glVertex3f(  0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.3,  0.3,  0.3 );
	glVertex3f(  0.5, -0.5, -0.5 );
	glVertex3f(  0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glPopMatrix();
}

void gun()
{
	glTranslated(0.2, -0.2, -0.5);
	
	glBegin(GL_POLYGON);
	glColor3f(   0.8,  0.8, 0.8 );
	glVertex3f(  0.1, -0.1, 0.1 );
	glVertex3f(  0.1,  0.1, 0.1 );
	glVertex3f( -0.1,  0.1, 0.1 );
	glVertex3f( -0.1, -0.1, 0.1 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.7,  0.7, 0.7 );
	glVertex3f( 0.1, -0.1, -0.1 );
	glVertex3f( 0.1,  0.1, -0.1 );
	glVertex3f( 0.1,  0.1,  0.1 );
	glVertex3f( 0.1, -0.1,  0.1 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.6,  0.6, 0.6 );
	glVertex3f( -0.1, -0.1,  0.1 );
	glVertex3f( -0.1,  0.1,  0.1 );
	glVertex3f( -0.1,  0.1, -0.1 );
	glVertex3f( -0.1, -0.1, -0.1 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.5,  0.5, 0.5 );
	glVertex3f(  0.1, 0.1,  0.1 );
	glVertex3f(  0.1, 0.1, -0.1 );
	glVertex3f( -0.1, 0.1, -0.1 );
	glVertex3f( -0.1, 0.1,  0.1 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.4,  0.4, 0.4 );
	glVertex3f(  0.1, -0.1, -0.1 );
	glVertex3f(  0.1, -0.1,  0.1 );
	glVertex3f( -0.1, -0.1,  0.1 );
	glVertex3f( -0.1, -0.1, -0.1 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(   0.3,  0.3, 0.3 );
	glVertex3f(  0.1, -0.1, -0.1 );
	glVertex3f(  0.1,  0.1, -0.1 );
	glVertex3f( -0.1,  0.1, -0.1 );
	glVertex3f( -0.1, -0.1, -0.1 );
	glEnd();
}

void display(GLFWwindow* window, float* xrot, float* yrot, float* xpos, float* zpos)
{
	glClearColor(0.529, 0.808, 0.980, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(*xrot, 1.0, 0.0, 0.0);
	glRotatef(*yrot, 0.0, 1.0, 0.0);
	glTranslated(-(*xpos)*SPEED, 0, -(*zpos)*SPEED);
	ground();
	map();
	gun();
	glfwSwapBuffers(window);
}

void update(GLFWwindow* window, float* xrotrad, float* yrotrad, float* xrot, float* yrot, float* xpos, float* ypos, float* zpos)
{
	if (forward) {
		*xrotrad = *yrotrad = 0;
		*yrotrad = (*yrot)/180*M_PI;
		*xrotrad = (*xrot)/180*M_PI; 
		*xpos += (float) sin(*yrotrad);
		*zpos -= (float) cos(*yrotrad);
		*ypos -= (float) sin(*xrotrad);
	}

	if (backward) {
		*xrotrad = *yrotrad = 0;
		*yrotrad = (*yrot)/180*M_PI;
		*xrotrad = (*xrot)/180*M_PI; 
		*xpos -= (float) sin(*yrotrad);
		*zpos += (float) cos(*yrotrad);
		*ypos += (float) sin(*xrotrad);
	}

	if (right) {
		*yrotrad = 0;
		*yrotrad = (*yrot)/180*M_PI;
		*xpos += (float) cos(*yrotrad);
		*zpos += (float) sin(*yrotrad);
	}

	if (left) {
		*yrotrad = 0;
		*yrotrad = (*yrot)/180*M_PI;
		*xpos -= (float) cos(*yrotrad);
		*zpos -= (float) sin(*yrotrad);
	}
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_W && action == GLFW_PRESS)   forward = 1;
	if (key == GLFW_KEY_W && action == GLFW_RELEASE) forward = 0;

	if (key == GLFW_KEY_A && action == GLFW_PRESS)   left = 1;
	if (key == GLFW_KEY_A && action == GLFW_RELEASE) left = 0;

	if (key == GLFW_KEY_S && action == GLFW_PRESS)   backward = 1;
	if (key == GLFW_KEY_S && action == GLFW_RELEASE) backward = 0;

	if (key == GLFW_KEY_D && action == GLFW_PRESS)   right = -1;
	if (key == GLFW_KEY_D && action == GLFW_RELEASE) right = 0;
}


void input(GLFWwindow* window, float* diffx, float* diffy, double* mx, double* my, float* lastx, float* lasty, float* xrot, float* yrot)
{
	*diffx = *mx - *lastx;
	*diffy = *my - *lasty;
	*lastx = *mx;
	*lasty = *my;
	glfwGetCursorPos(window, mx, my);
	*xrot += (*diffy)*SENS;
	*yrot += (*diffx)*SENS;

	glfwPollEvents();
}

int main (int argc, char **argv)
{
	int width = 1280, height = 1280;
	float xrotrad = 0, yrotrad = 0, diffx = 0, diffy = 0, px = 0, py = 0, pz = 0, rx = 0, ry = 0, dmx = 0, dmy = 0, xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, lastx = 0, lasty = 0;
	double mx = width/2, my = width/2;

	glfwInit();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	GLFWwindow* window = glfwCreateWindow(width, height, "test", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window, key_callback);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90.0, width/height, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glfwSwapInterval(0);
	glViewport(0, 0, width, height);
	
	while (!glfwWindowShouldClose(window)) {
		input(window, &diffx, &diffy, &mx, &my, &lastx, &lasty, &xrot, &yrot);
		update(window, &xrotrad, &yrotrad, &xrot, &yrot, &xpos, &ypos, &zpos);
		display(window, &xrot, &yrot, &xpos, &zpos);
	}

	glfwTerminate();

	return 0;
}
