//Mehraj,Ali
//11-19958-3
#include<iostream>
#include<gl\glut.h>
#include<math.h>

using namespace std;

//void DrawCircle(float cx, float cy, float r, int num_segments) 
//{ 
//	glBegin(GL_TRIANGLE_FAN); 
//	for(int ii = 0; ii < num_segments; ii++) 
//	{ 
//		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
//
//		float x = r * cosf(theta);//calculate the x component 
//		float y = r * sinf(theta);//calculate the y component 
//
//		glVertex2f(x + cx, y + cy);//output vertex 
//
//	} 
//	glEnd(); 
//}
 
void myDisplay()
{
	int c;

glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);   //rectangle
glVertex2i(100,100);
glVertex2i(150, 100);
glVertex2i(150, 150);
glVertex2i(100, 150);
glEnd();
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_LINES);   //axes
glVertex2i(-1024, 0);
glVertex2i(1024, 0);

glVertex2i(0, 768);
glVertex2i(0, -768);
glEnd();

cout<<"what do you want to do?"<<endl;
cout<<"1:) Reflection"<<endl;
cout<<"2:) Shearing"<<endl;
cout<<"3:) Rotation about an arbitary point"<<endl;

cin>>c;
if(c==1)
{
	int d;
	cout<<"Input reflection along which axis"<<endl;
	cout<<"1:) X-axis"<<endl;
	cout<<"2:) Y-axis"<<endl;
    cin>>d;
		if(d==1)
		{
		glColor3f (0.0, 0.0, 1.0);
		glBegin(GL_LINE_LOOP);   //reflected rectangle
		glVertex2i(100, -100);
		glVertex2i(150, -100);
		glVertex2i(150, -150);
		glVertex2i(100, -150);
		glEnd();
		}
			 else if(d==2)
			{
				glColor3f (0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);   //reflected rectangle
			glVertex2i(-100, 100);
			glVertex2i(-150, 100);
			glVertex2i(-150, 150);
			glVertex2i(-100, 150);
			glEnd();
		}
}
else if(c==2)
{
	int e,j,t;
	cout<<"Input by how much you want to shear x and y by:"<<endl;
	cout<<"1:) input for x:"<<endl;
	cin>>j;
	cout<<"2:) input for y:"<<endl;
	cin>>t;

	cout<<"Input which point you want to keep fixed"<<endl;
	cout<<"1:) bottom left"<<endl;
	cout<<"2:) bottom right"<<endl;
	cout<<"3:) upper right"<<endl;
	cout<<"4:) upper left"<<endl;
    cin>>e;
		if(e==1)
		{
			glColor3f (0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);   // sheared rectangle
			glVertex2i(100,100);
			glVertex2i(150+j, 100+t);
			glVertex2i(150+j, 150+t);
			glVertex2i(100+j, 150+t);
			glEnd();

		}
		if(e==2)
		{
			glColor3f (0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);   // sheared rectangle
			glVertex2i(100+j,100+t);
			glVertex2i(150, 100);
			glVertex2i(150+j, 150+t);
			glVertex2i(100+j, 150+t);
			glEnd();
		}
		if(e==3)
		{
			glColor3f (0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);   // sheared rectangle
			glVertex2i(100+j,100+t);
			glVertex2i(150+j, 100+t);
			glVertex2i(150, 150);
			glVertex2i(100+j, 150+t);
			glEnd();

		}
		if(e==4)
		{
			glColor3f (0.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);   // sheared rectangle
			glVertex2i(100+j,100+t);
			glVertex2i(150+j, 100+t);
			glVertex2i(150+j, 150+t);
			glVertex2i(100, 150);
			glEnd();

		}	
}
else if(c==3)
{
	int x,y,theta;
	cout<<"input arbitary point:"<<endl;
	cout<<"input x:"<<endl;
	cin>>x;
	cout<<"input y:"<<endl;
	cin>>y;
	cout<<"input new angle:"<<endl;
	cin>>theta;
	
	glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);  
	glVertex2i(((100 + x)*cosf(theta))-((100 + y)*sinf(theta)),  ((100 + x)*sinf(theta))+((100 + y)*cosf(theta)));
	glVertex2i(((150 + x)*cosf(theta))-((100 + y)*sinf(theta)), ((150 + x)*sinf(theta))+((100 + y)*cosf(theta)));
	glVertex2i(((150 + x)*cosf(theta))-((150 + y)*sinf(theta)), ((150 + x)*sinf(theta))+((150 + y)*cosf(theta)));
	glVertex2i(((100 + x)*cosf(theta))-((150 + y)*sinf(theta)),   ((100 + x)*sinf(theta))+((150 + y)*cosf(theta)));
	glEnd();

}
		glFlush ();
}



void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1024.0, 1024.0, -768.0, 768.0);
}



void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1024, 768);
glutInitWindowPosition (100, 150);
glutCreateWindow ("new");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
