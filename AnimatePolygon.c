"Develop a menu driven program to animate the polygon using 3D geometric
transformations."

#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
GLint T=0,menu_num=0;
void Spin()
{
T=T+0.10;
if (T>360)
T=0;
glutPostRedisplay();
}
void myinit()
{
glClearColor(0,0,0,1);
glColor3f(1,0,0);
glEnable(GL_DEPTH_TEST);
}
void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
glBegin(GL_POLYGON);
glVertex3fv(A);
glVertex3fv(B);
glVertex3fv(C);
glVertex3fv(D);
glEnd();
}
void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat
V5[],GLfloat V6[],GLfloat V7[])

{
glColor3f(1.0,0.0,0.0);
Face(V0,V1,V2,V3);
glColor3f(0.0,1.0,0.0);
Face(V4,V5,V6,V7);
glColor3f(0.0,0.0,1.0);
Face(V0,V3,V7,V4);
glColor3f(1.0,1.0,0.0);
Face(V1,V2,V6,V5);
glColor3f(0.0,1.0,1.0);
Face(V0,V1,V5,V4);
glColor3f(1.0,0.0,1.0);
Face(V3,V2,V6,V7);
}
void Draw()
{
GLfloat V[8][3]={
{-0.5,0.5,0.5},
{0.5,0.5,0.5},
{0.5,-0.5,0.5},
{-0.5,-0.5,0.5},

{-0.5,0.5,-0.5},
{0.5,0.5,-0.5},
{0.5,-0.5,-0.5},
{-0.5,-0.5,-0.5}
};
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
glLoadIdentity();

//printf("%d",menu_num);
if (menu_num==1)
{
glRotatef(45,0,0,1);
}
if (menu_num==2)
{
glScalef(2.0,1.0,1.0);
}
glutSwapBuffers();
glFlush();
}
void menuFcn(GLint option)
{
if (option==0)
menu_num=1;
if (option==1)
menu_num=2;
}
int main(int c,char ** v)
{
glutInit(&c,v);
glutInitWindowPosition(20,20);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutCreateWindow("Menu Driven Program");
myinit();
glutDisplayFunc(Draw);
glutCreateMenu(menuFcn);
glutAddMenuEntry("Rotate",0);
glutAddMenuEntry("Scale",1);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutIdleFunc(Spin);
glutMainLoop();
return 0;
}