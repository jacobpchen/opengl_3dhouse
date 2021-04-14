#include<Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>

float light_angle = 0.0f;

void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
    GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
    GLfloat specularR, GLfloat specularG, GLfloat specularB,
    GLfloat shininess) {

    GLfloat ambient[] = { ambientR, ambientG, ambientB };
    GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
    GLfloat specular[] = { specularR, specularG, specularB };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}


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
    setMaterial(0.05, 0.0, 0.0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, .078125); // red
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    // roof
    setMaterial(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4); // gold
    glTranslatef(0, 1, 0);
    glRotatef(180, 0, 1, 1);
    glutSolidCone(1.5, 1, 16, 8);
    glPopMatrix();

    // chimney
    glPushMatrix();
    setMaterial(0.05, 0.0, 0.0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, .078125); // red
    glScalef(1, 2, 1);
    glTranslatef(2, 1.25, 1);
    glutSolidCube(.25);
    glPopMatrix();

    // car

    glPushMatrix();
    setMaterial(0.1, 0.18725, 0.1745, 0.396, 0.74151, 0.69102, 0.297254, 0.30829, 0.306678, 0.1);
    glTranslatef(-3, -4, .3);
    glScalef(3, 1, 1.5);
    glutSolidCube(.5); // body
    glPopMatrix();


    glPushMatrix();
    setMaterial(0.05, 0.05, 0.05, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7, .078125); // white rubber
    glTranslatef(-3.9, -4.50, .65);
    glScalef(2, 2, 2);
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
    setMaterial(0.329412, 0.223529, 0.027451, 0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843, 0.21794872); // bronze
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(2.4, .15, 0);
    gluCylinder(quadratic, .25, .25, .5, 32, 32);
    glPopMatrix();

    // Tree branches
    // base branch
    glPushMatrix();
    setMaterial(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6); // emerald
    glTranslatef(2.25, 0, 0);
    glRotatef(180, 0, 1, 1);
    glutSolidCone(.50, .50, 16, 8);
    glPopMatrix();

    //top branch
    glPushMatrix();
    setMaterial(0.0215, 0.1745, 0.0215, 0.07568, 0.61424, 0.07568, 0.633, 0.727811, 0.633, 0.6); // emerald
    glTranslatef(2.25, .5, 0);
    glRotatef(180, 0, 1, 1);
    glutSolidCone(.35, .35, 16, 8);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    /* flush drawing routines to the window */
    glFlush();


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);


    //Light Parameters
    GLfloat light0_ambient[] = { 0.6, 0.6, 0.6, 1.0 };
    GLfloat light0_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0 };
    GLfloat light0_specular[] = { 0.8f, 0.8f, 0.8f, 1.0 };
    GLfloat light0_position[] = { 0.8f, 0.8f, 0.5f, 1.0 };

    //Set light Parameters and enable light
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT4, GL_POSITION, light0_position);

    glEnable(GL_LIGHT0);

    //Set material and ambient light
    GLfloat ambientLight[] = { 0.10588, 0.058824, 0.0113725 };
    GLfloat diffuseLight[] = { 0.427451, 0.470588, 0.541176 };
    GLfloat specularLight[] = { 0.3333, 0.333, 0.521569 };
    GLfloat shininessLight[] = { 100.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientLight);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLight);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininessLight);

    glLoadIdentity();
    glPushMatrix();
    glFlush();
    glPopMatrix();


}

//Display lights
void displayWithLights()
{
    glLoadIdentity();
    glPushMatrix();
    glFlush();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (float i = -32; i < +32; i += 32 / 4)
        for (float j = -32; j < +32; j += 32 / 8)
        {
            (i + 20.0f, j + 30.0f, 45.0f);
        }

    light_angle += 80.0;

    glutSwapBuffers();
    glutPostRedisplay();
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
    //glClearColor(0.25f, 0.5f, 0.9f, 0.1f);
    glClearColor(0, 0, 0, 1);
    glViewport(0, 0, 500, 500);
    glutMainLoop();
    return 0;
}