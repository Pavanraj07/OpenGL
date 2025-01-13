" Create and rotate a triangle about the origin and a fixed point"
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
int x,y;
int WhereToRotate=0;
float RotateAngle=0;
float TranslateX=0,TranslateY=0;
void draw_pixel(float x1, float y1)
{
glPointSize(5);
glBegin(GL_POINTS);
glVertex2f(x1,y1);
glEnd();
}
void triangle(int x, int y)
{
glColor3f(1,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(x,y);
glVertex2f(x+400,y+300);
glVertex2f(x+300,y+0);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glColor3f(1,1,1);
draw_pixel(0,0);
if (WhereToRotate == 1)
{

TranslateX = 0;
TranslateY = 0;
RotateAngle += 1;
}
if (WhereToRotate == 2)
{
TranslateX = x;
TranslateY = y;
RotateAngle += 1;
glColor3f(0,0,1);
draw_pixel(x,y);
}
glTranslatef(TranslateX, TranslateY, 0);
glRotatef(RotateAngle, 0, 0, 1);
glTranslatef(-TranslateX, -TranslateY, 0);
triangle(TranslateX,TranslateY);
glutPostRedisplay();
glutSwapBuffers();
}
void init()
{
glClearColor(0,0,0,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 800, 0, 800);
glMatrixMode(GL_MODELVIEW);
}
void rotateMenu (int option)
{
if(option==1)
WhereToRotate=1;
if(option==2)
WhereToRotate=2;
if(option==3)

WhereToRotate=3;
}
int main(int argc, char **argv)
{
printf( "Enter Fixed Points (x,y) for Rotation: \n");
scanf("%d %d", &x, &y);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(800, 800);
glutInitWindowPosition(800, 800);
glutCreateWindow("Create and Rotate Triangle");
init();
glutDisplayFunc(display);
glutCreateMenu(rotateMenu);
glutAddMenuEntry("Rotate around Origin",1);
glutAddMenuEntry("Rotate around Fixed Point",2);
glutAddMenuEntry("Stop",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}