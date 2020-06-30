#include "game.h"

void ground()
{	
	glPushMatrix();
	
	glBegin(GL_POLYGON);
	glColor3f(0.871, 0.722, 0.529);
	glVertex3f(-MAPSIZE, -1.5, -MAPSIZE);
	glVertex3f( MAPSIZE, -1.5, -MAPSIZE );
	glVertex3f( MAPSIZE, -1.5,  MAPSIZE );
	glVertex3f(-MAPSIZE, -1.5,  MAPSIZE );
	glEnd();

	glPopMatrix();
}