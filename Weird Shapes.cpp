//Mehraj,Ali
//11-19958-3
#include<stdio.h>
#include<gl\glut.h>
#include<math.h>

void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	glBegin(GL_TRIANGLE_FAN); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 
}
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);   //green big box
glVertex2i(500, 200);
glVertex2i(400, 180);
glVertex2i(400, 300);
glVertex2i(500, 320);
glEnd();
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);   //blue big box
glVertex2i(320, 320);
glVertex2i(400, 300);
glVertex2i(400, 180);
glVertex2i(320, 200);
glEnd();
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);   //big red polygon
glVertex2i(500, 320);
glVertex2i(400, 300);
glVertex2i(320, 320);
glVertex2i(360, 330);
glVertex2i(440, 325);
glVertex2i(460, 335);
glEnd();
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_POLYGON);   //black small box
glVertex2i(385, 260);
glVertex2i(385, 184);
glVertex2i(355, 140);
glVertex2i(355, 250);
glEnd();
glBegin(GL_POLYGON);   //black small box
glVertex2i(385, 184);
glVertex2i(400, 170);
glVertex2i(410, 182);
glVertex2i(410, 174);
glVertex2i(355, 140);
glEnd();
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);   //green small box
glVertex2i(355, 140);
glVertex2i(355, 250);
glVertex2i(330, 260);
glVertex2i(330, 150);
glEnd();
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);   //blue small box
glVertex2i(330, 260);
glVertex2i(330, 150);
glVertex2i(305, 130);
glVertex2i(305, 240);
glEnd();
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);   //green medium box
glVertex2i(305, 130);
glVertex2i(305, 240);
glVertex2i(200, 260);
glVertex2i(200, 150);
glEnd();
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);   //red medium box
glVertex2i(200, 260);
glVertex2i(305, 240);
glVertex2i(330, 260);
glVertex2i(355, 250);
glVertex2i(385, 260);
glEnd();
glBegin(GL_POLYGON);   //red medium box
glVertex2i(200, 260);
glVertex2i(330, 265);
glVertex2i(300, 280);
glVertex2i(340, 276);
glVertex2i(355, 267);
glVertex2i(345, 264);
glVertex2i(365, 262);
glVertex2i(386, 259);
glEnd();
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_LINES);   //white shadow box
glVertex2i(500, 90);
glVertex2i(400, 50);

glVertex2i(400, 50);
glVertex2i(350, 120);

glVertex2i(350, 120);
glVertex2i(440, 150);

glVertex2i(440, 150);
glVertex2i(500, 90);
glEnd();
glColor3f (0.5, 0.5, 0.5);
glBegin(GL_POLYGON);   //grey shadow 
glVertex2i(440, 150);
glVertex2i(450, 140);
glVertex2i(440, 130);
glVertex2i(400, 137);
glEnd();
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_LINES);   //white shadow box 2
glVertex2i(365, 100);
glVertex2i(340, 115);

glVertex2i(340, 115);
glVertex2i(337, 90);

glVertex2i(337, 90);
glVertex2i(237, 91);

glVertex2i(237, 91);
glVertex2i(297, 62);

glVertex2i(297, 62);
glVertex2i(327, 72);

glVertex2i(327, 72);
glVertex2i(367, 42);

glVertex2i(367, 42);
glVertex2i(394, 62);

glVertex2i(378, 82);
glVertex2i(363, 85);

glVertex2i(363, 85);
glVertex2i(373, 90);
glEnd();
glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("SHIP");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
