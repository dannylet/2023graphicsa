#include<stdio.h>
#include<GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;///week13 Step02-1
GLMmodel * body = NULL;///week13 Step02-1
GLMmodel * uparmL = NULL;///week13 Step02-1
GLMmodel * lowarmL = NULL;///week13 Step02-1
int show[4] = {1,1,1,1};
int ID=0;
void keyboard(unsigned char key, int x, int y)
{
    if(key== '0') ID=0;
    if(key== '1') ID=1;
    if(key== '2') ID=2;
    if(key== '3') ID=3;
    ///if(key== '0') show[0] = !show[0];///week13 Step03-1
    ///if(key== '1') show[1] = !show[1];///week13 Step03-1
    ///if(key== '2') show[2] = !show[2];///week13 Step03-1
    ///if(key== '3') show[3] = !show[3];///week13 Step03-1
    glutPostRedisplay();
}
FILE * fout =NULL;
FILE * fin =NULL;
float teapotX=0,teapotY=0;
float angle =0,angle2=0,angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        ///glTranslatef(teapotX,teapotY, 0);
        ///glutSolidTeapot(0.3);
    if(body == NULL){
        head = glmReadOBJ("model/head.obj");
        body = glmReadOBJ("model/body.obj");///week13 Step02-1
        uparmL = glmReadOBJ("model/uparmL.obj");///week13 Step03-1
        lowarmL = glmReadOBJ("model/lowarmL.obj");///week13 Step03-1
        ///glmUnitize(body);
    }
    if(ID==0) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色
    if(show[0])glmDraw(head, GLM_MATERIAL);///week13 Step03-1

    if(ID==1) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色
    if(show[1])glmDraw(body, GLM_MATERIAL);///week13 Step03-1
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        if(ID==2) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[2])glmDraw(uparmL , GLM_MATERIAL);///week13 Step03-1
    glPopMatrix();

    if(ID==3) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色
    if(show[3])glmDraw(lowarmL , GLM_MATERIAL);///week13 Step03-1
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x,int y)
{
    teapotX += (x-oldX)/150.0;
    teapotY -= (y-oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x,int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotX=(x-150)/150.0;
        ///teapotY=(150-y)/150.0;
        ///if(fout==NULL) fout = fopen ("file4.txt","w");
        ///fprintf(fout,"%f %f\n", teapotX, teapotY);
    }
    display();
}
//void keyboard(unsigned char key, int x, int y)
//{
//    if(fin==NULL)
//    {
//        fclose(fout);
//        fin = fopen("file4.txt", "r");
//    }
//    fscanf(fin, "%f %f", &teapotX,&teapotY);
//    display();
//}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
