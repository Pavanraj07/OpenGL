"Develop a OpenGL program to Spin 3D sierpinski gasket using OpenGL transformation matrices."
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
int n,i;
float d=0;
void Spin()
{
d=d+0.02;
if (d>360)
d=0;
glutPostRedisplay();
}
void init()
{
glClearColor(1,1,1,1);
glEnable(GL_DEPTH_TEST);
}
void Triangle(GLfloat A[],GLfloat B[],GLfloat C[])
{
glBegin(GL_TRIANGLES);
glVertex3fv(A);
glVertex3fv(B);
glVertex3fv(C);
glEnd();
}
void Tetra(GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[])
{
glColor3f(1.0,1.0,1.0);
Triangle(V1,V2,V3);
glColor3f(1.0,0.0,0.0);
Triangle(V1,V3,V4);
glColor3f(0.0,1.0,0.0);
Triangle(V2,V3,V4);
glColor3f(0.0,0.0,1.0);
Triangle(V1,V2,V4);

}
void Div(GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[])
{
Tetra(V1,V2,V3,V4);
}
void Draw()
{
GLfloat P[4][3]={ {-0.5,-0.5,0.5},
{0.5,-0.5,0.5},
{0,0.5,0.5},
{0, -0.05, -0.5}};
GLfloat rP[4][3],r;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
r=d*3.14/180;
if(n==0)
{
for(int i=0;i<4;i++)
{
rP[i][0]=P[i][0];
rP[i][1]=P[i][1];
rP[i][2]=P[i][2];
}
}
if(n==1)
{
for(int i=0;i<4;i++)
{
rP[i][0]=P[i][0]*cos(r)-P[i][1]*sin(r);
rP[i][1]=P[i][0]*sin(r)+P[i][1]*cos(r);
rP[i][2]=P[i][2];
}
}
if(n==2)
{
for(int i=0;i<4;i++)
{
rP[i][0]=P[i][0];

rP[i][1]=P[i][1]*cos(r)-P[i][2]*sin(r);
rP[i][2]=P[i][1]*sin(r)+P[i][2]*cos(r);
}
}
if(n==3)
{
for(int i=0;i<4;i++)
{
rP[i][0]=P[i][0]*cos(r)-P[i][2]*sin(r);
rP[i][1]=P[i][1];
rP[i][2]=P[i][0]*sin(r)+P[i][2]*cos(r);
}
}
//Tetra(P[0],P[1],P[2],P[3]);
Tetra(rP[0],rP[1],rP[2],rP[3]);
glutSwapBuffers();
glFlush();
}
int main(int argc,char ** argv)
{
printf("Enter the Axis of Rotation[0:No Rotation|1:zaxis Rotation|2:yaxis
Rotation|3:xaxis Rotation]\n");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitWindowSize(600,600);
glutInitWindowPosition(100,100);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow(" 3D Sierpinski gasket");
init();
glutDisplayFunc(Draw);
glutIdleFunc(Spin);
glutMainLoop();
return 0;
}