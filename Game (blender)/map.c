#include "game.h"

void map()
{
	ground();

	glPushMatrix();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(-1.000000,-0.541540,-1.000000);
	glVertex3f(-1.000000,1.000000,1.000000);
	glVertex3f(-1.000000,-1.000000,1.000000);
	glVertex3f(-1.000000,-1.000000,-1.000000);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(1.000000,0.304840,-1.000000);
	glVertex3f(-1.000000,-0.541540,-1.000000);
	glVertex3f(-1.000000,-1.000000,-1.000000);
	glVertex3f(1.000000,-1.000000,-0.249399);
	glEnd();
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(1.000000,0.304840,-1.000000);
	glVertex3f(1.000000,-1.000000,-0.249399);
	glVertex3f(1.000000,-1.000000,1.000000);
	glVertex3f(1.000000,1.000000,1.000000);
	glEnd();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.000000,-1.000000,-1.000000);
	glVertex3f(-1.000000,-1.000000,1.000000);
	glVertex3f(1.000000,-1.000000,1.000000);
	glVertex3f(1.000000,-1.000000,-0.249399);
	glEnd();
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(1.000000,1.000000,1.000000);
	glVertex3f(1.000000,-1.000000,1.000000);
	glVertex3f(-1.000000,-1.000000,1.000000);
	glVertex3f(-1.000000,1.000000,1.000000);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(1.000000,0.304840,-1.000000);
	glVertex3f(1.000000,1.000000,1.000000);
	glVertex3f(-1.000000,1.000000,1.000000);
	glVertex3f(-1.000000,-0.541540,-1.000000);
	glEnd();

	glPopMatrix();
}