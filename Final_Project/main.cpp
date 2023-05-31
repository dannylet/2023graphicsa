///Week15angle[20]



#include<stdio.h>
#include<GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;///week13 Step02-1
GLMmodel * body = NULL;///week13 Step02-1
GLMmodel * righthand = NULL;///week13 Step02-1
GLMmodel * lefthand = NULL;///week13 Step02-1
int show[4] = {1,0,0,0};
int ID=2;
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0;
float angle[20]={};///week15_step03-1
void keyboard(unsigned char key, int x, int y)
{
    if(key== '0') ID=0;
    if(key== '1') ID=1;
    if(key== '2') ID=2;
    if(key== '3') ID=3;
    if(key=='s')
    {
        if(fout == NULL)fout =fopen("motion.txt","w");
        for(int i=0; i<20;i++)
        {
            fprintf(fout,"%.2f ",angle[i]);
        }
        fprintf(fout, "\n");
    }else if(key =='r')
    {
        if(fin==NULL)fin = fopen("motiom.txt","r");
        for(int i=0;i<20;i++)
        {
            fscanf(fin,"%f", &angle[i]);
        }
    }
    glutPostRedisplay();
    ///if(key== '0') show[0] = !show[0];///week13 Step03-1
    ///if(key== '1') show[1] = !show[1];///week13 Step03-1
    ///if(key== '2') show[2] = !show[2];///week13 Step03-1
    ///if(key== '3') show[3] = !show[3];///week13 Step03-1
    glutPostRedisplay();
}
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
        righthand = glmReadOBJ("model/righthand.obj");///week13 Step03-1
        lefthand = glmReadOBJ("model/lefthand.obj");///week13 Step03-1
        ///glmUnitize(body);
    }
    if(ID==0) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色///week13 Step03-1
    glPushMatrix();
        glTranslatef(-0.040000, 2.419998, 0);
        glRotatef(angle[0] ,0,0,1);
        ///glRotatef(angle[0], 1, 0, 0);///week15_step03-1
        glTranslatef(0.040000, -2.419998, 0);
        if(ID==0) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[0])glmDraw(head , GLM_MATERIAL);///week13 Step03-1
    glPopMatrix();



    if(ID==1) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色



    if(show[1])glmDraw(body, GLM_MATERIAL);///week13 Step03-1
    glPushMatrix();
        glTranslatef(-1.299999, 1.733332, 0);
        glRotatef(angle[2] ,0,0,1);
        ///glRotatef(angle[2], 1, 0, 0);///week15_step03-1
        glTranslatef(1.299999, -1.733332, 0);
        if(ID==2) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[2])glmDraw(righthand , GLM_MATERIAL);///week13 Step03-1
    glPopMatrix();


    glPushMatrix();
        glTranslatef(1.226666, 1.653332, 0);
        glRotatef(angle[3] ,0,0,1);///week15_step03-1
        glTranslatef(-1.226666, -1.653332, 0);
    if(ID==3) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色
    if(show[3])glmDraw(lefthand , GLM_MATERIAL);///week13 Step03-1
    glPopMatrix();
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x,int y)
{
    teapotX += (x -oldX)/150.0;
    teapotY -= (y -oldY)/150.0;
    angle[ID] += (x- oldX);///week15_step03-1
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x,int y)
{
    if(state==GLUT_DOWN)
    {
        angle[ID] += (x - oldX);///week15_step03-1
        oldX = x;
        oldY = y;
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
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
