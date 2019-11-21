#include "game.h"

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
