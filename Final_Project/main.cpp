///Week15angle[20]



#include<stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}



GLMmodel * head = NULL;///week13 Step02-1
GLMmodel * body = NULL;///week13 Step02-1
GLMmodel * righthand = NULL;///week13 Step02-1
GLMmodel * lefthand = NULL;///week13 Step02-1
GLMmodel * leftleg = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * pom = NULL;
int show[7] = {1,1,1,1,1,1,0};
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
    if(key== '4') ID=4;
    if(key== '5') ID=5;
    if(key== '6') ID=6;
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
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.07,0.07,0.07);
        ///glTranslatef(teapotX,teapotY, 0);
        ///glutSolidTeapot(0.3);







    glPushMatrix();
        glTranslatef(-0.040000, 2.419998, 0);
        glRotatef(angle[0] ,0,0,1);
        glRotatef(angle[0], 1, 0, 0);///week15_step03-1
        glTranslatef(0.040000, -2.419998, 0);
        if(ID==0) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[0])glmDraw(head , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-0.033333, 2.993332, 0);
        glRotatef(angle[1] ,0,0,1);
        ///glRotatef(angle[1], 1, 0, 0);///week15_step03-1
        glTranslatef(0.033333, -2.993332, 0);
        if(ID==1) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[1])glmDraw(body , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();



    glPushMatrix();
        glTranslatef(-1.299999, 1.733332, 0);
        glRotatef(angle[2] ,0,0,1);
        glRotatef(angle[2], 1, 0, 0);///week15_step03-1
        glTranslatef(1.299999, -1.733332, 0);
        if(ID==2) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[2])glmDraw(righthand , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();


    glPushMatrix();
        glTranslatef(1.226666, 1.653332, 0);
        glRotatef(angle[3] ,0,0,1);///week15_step03-1
        glTranslatef(-1.226666, -1.653332, 0);
    if(ID==3) glColor3f(1,0,0);///選定的設紅色
    else glColor3f(1,1,1);///沒選設白色
    if(show[3])glmDraw(lefthand , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.666666, 0.533333, 0);
        glRotatef(angle[4] ,0,0,1);
        ///glRotatef(angle[4], 1, 0, 0);///week15_step03-1
        glTranslatef(-0.666666, -0.533333, 0);
        if(ID==4) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[4])glmDraw(leftleg , GLM_MATERIAL | GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-0.706666, 0.546666, 0);
        glRotatef(angle[5] ,0,0,1);
        ///glRotatef(angle[4], 1, 0, 0);///week15_step03-1
        ///glTranslatef(teapotX,teapotY, 0);
        glTranslatef(0.706666, -0.546666, 0);
        if(ID==5) glColor3f(1,0,0);///選定的設紅色
        else glColor3f(1,1,1);///沒選設白色
        if(show[5])glmDraw(rightleg , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
    glPopMatrix();


    ///glPushMatrix();
        ///glTranslatef(-0.706666, 0.546666, 0);
        ///glRotatef(angle[6] ,0,0,1);
        ///glRotatef(angle[4], 1, 0, 0);///week15_step03-1
        ///glTranslatef(teapotX,teapotY, 0);
        ///glTranslatef(teapotX,teapotY, 0);
        ///if(ID==6) glColor3f(1,0,0);///選定的設紅色
        ///else glColor3f(1,1,1);///沒選設白色
        ///if(show[6])glmDraw( , GLM_MATERIAL);///week13 Step03-1
    ///glPopMatrix();




    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void motion(int x,int y)
{
    teapotX += (x -oldX)/10.0;
    teapotY -= (y -oldY)/10.0;
    angle[ID] += (x- oldX);///week15_step03-1
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x,int y)
{
    oldX = x;
    oldY = y;
    ///teapotX=(x-150)/150.0;
    ///teapotY=(150-y)/150.0;
    ///if(fout==NULL) fout = fopen ("file4.txt","w");
    ///fprintf(fout,"%f %f\n", teapotX, teapotY);
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
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);


    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj");
    righthand = glmReadOBJ("model/righthand.obj");
    lefthand = glmReadOBJ("model/lefthand.obj");
    leftleg = glmReadOBJ("model/leftleg.obj");
    rightleg = glmReadOBJ("model/rightleg.obj");
    pom = glmReadOBJ("model/pom.obj");

    myTexture("model/ba.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
