//Mehraj,Ali
//11-19958-3
#include<stdio.h>
#include<gl/glut.h>

static GLfloat spin = 0.0; 
static GLfloat spin_speed = .5; 
float spin_x = 0; 
float spin_y = 1; 
float spin_z = 0; 
 
float translate_x = 0.0; 
float translate_y = 0.0; 
float translate_z = -30.0; 

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	//glPointSize(14.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
 
 
void setSpin(float x, float y, float z) 
{ 
  spin_x = x; 
  spin_y = y; 
  spin_z = z; 
} 
 

void reset() 
{ 
  spin_x = 0; 
  spin_y = 1; 
  spin_z = 0; 
  translate_x = 0.0; 
  translate_y = 0.0; 
  translate_z = -30.0; 
} 
 

 void reshape(int w,int h) 
{ 
  glViewport(0,0, (GLsizei)w,(GLsizei)h); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f); 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
} 

void myDisplay() 
{ 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   

  //-------------Square--------------
	glLoadIdentity(); 
    glTranslatef(translate_x, translate_y, translate_z); 
    glRotatef(spin,spin_x,spin_y,spin_z);
    glColor3f(0.0f, 0.0f, 1.0f);
   

	glBegin(GL_POLYGON);
	glVertex2f(6, 6);
	glVertex2f(6, 18);
    glVertex2f(18, 18);
    glVertex2f(18, 6);
    glEnd();

  glutSwapBuffers();  
} 
 
void spinDisplay(void) 
{ 
  spin=spin+spin_speed; 
  if(spin<=360) 
  { 
    spin=spin-1.0; 
  } 
  glutPostRedisplay(); 
} 
 
void spinDisplayReverse(void) 
{ 
  spin=spin+spin_speed; 
  if(spin>=360) 
  { 
    spin=spin+1.0; 
  } 
  glutPostRedisplay(); 
} 


void mouse(int button,int state,int x,int y) 
{ 
  switch(button) 
  { 
  case GLUT_LEFT_BUTTON:
		      if(state==GLUT_DOWN)
			  {
				spinDisplay();
			  }
    break; 

  case GLUT_MIDDLE_BUTTON: 
      if(state==GLUT_DOWN) 
		glutIdleFunc(NULL); 
    break; 

  case GLUT_RIGHT_BUTTON: 
      if(state==GLUT_DOWN)
			  {
				spinDisplayReverse();
			  }
    break; 
     
    default: 
    break; 
  } 
} 
 
void keyboard(unsigned char key, int x, int y) 
{ 
  //-------- spin -------- 
  if(key=='x') 
  {
     setSpin(1.0,0.0,0.0); 
     glutPostRedisplay();
  } 
  else if(key=='y') 
  {
     setSpin(0.0,1.0,0.0); 
     glutPostRedisplay(); 
  } 
  else if(key=='z') 
  { 
     setSpin(0.0,0.0,1.0); 
     glutPostRedisplay(); 
  } 
  else if(key=='a') 
  { 
     setSpin(1.0,1.0,1.0); 
     glutPostRedisplay(); 
  } 
  //-------- spin --------   
 
  //-------- zoom --------   
  else if(key=='i') 
  { 
    translate_z++; 
    glutPostRedisplay();
  }   
    else if(key=='o') 
  {  
    translate_z--; 
    glutPostRedisplay();
  } 
  //-------- zoom -------- 
 
  //-------- reset ------- 
  else if(key=='r') 
  { 
    reset(); 
    glutPostRedisplay();   
  } 
  //-------- reset ------- 
} 

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("my first attempt");
	glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	myInit();
	glutMainLoop();
}