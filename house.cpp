// house.cpp
#include <windows.h>
//#include <iostream.h>
#include <GL/glut.h>
void display() {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);
	/* draw scene */
	glPushMatrix();
	
	// house
	glPushMatrix();
	// building
	glutSolidCube(2);
	glPopMatrix();
	glPushMatrix();
	// roof
	glTranslatef(0, 1, 0);
	glRotatef(180, 0, 1, 1);
	glutSolidCone(1.5, 1, 16, 8);
	glPopMatrix();
	// chimney
	glPushMatrix();
	glScalef(1, 2, 1);
	glTranslatef(2, 1.25, 1);
	glutSolidCube(.25);
	glPopMatrix();
			
	// car
	
	glPushMatrix();
	glTranslatef(-3, -4, .3);
	glScalef(3, 1, 1.5);
	glutSolidCube(.5); // body
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-3.9, -4.50, .65);
	glScalef(2,2,2);
	glutSolidTorus(.05, .1, 8, 8); // wheel 1
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -4.25, .7);
	glScalef(2, 2, 2);
	glutSolidTorus(.05, .1, 8, 8); // wheel 2
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -4.5, -.3);
	glScalef(2, 2, 2);
	glutSolidTorus(.05, .1, 8, 8); // wheel 3
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -4.5, -.3);
	glScalef(2, 2, 2);
	glutSolidTorus(.05, .1, 8, 8); // wheel 4
	glPopMatrix();
	

	// Extra Scenery
	
	// Tree trunk
	glPushMatrix();
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(2.4, .15, 0);
	gluCylinder(quadratic, .25, .25, .5, 32, 32);
	glPopMatrix();
	
	// Tree branches
	// base branch
	glPushMatrix();
	glTranslatef(2.25, 0, 0);
	glRotatef(180, 0, 1, 1);
	glutSolidCone(.50, .50, 16, 8);
	glPopMatrix();

	//top branch
	glPushMatrix();
	glTranslatef(2.25, .5, 0);
	glRotatef(180, 0, 1, 1);
	glutSolidCone(.35, .35, 16, 8);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	/* flush drawing routines to the window */
	glFlush();
}
void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}
int main(int argc, char* argv[]) {
	/* initialize GLUT, using any commandline parameters passed to the
	3
	program */
	glutInit(&argc, argv);
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	/* create and set up a window */
	glutCreateWindow("hello, house!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);
	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/* tell GLUT to wait for events */
	glutMainLoop();
	return 0;
}