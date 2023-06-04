///Week15angle[20]


#include <windows.h>
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
#include "CMP3_MCI.h"
CMP3_MCI myMP3;
GLuint tex1,tex2;
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
GLMmodel * Lhand = NULL;
GLMmodel * Rhand = NULL;
int show[8] = {1,1,1,1,1,1,1,1};
int ID=2;
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0;
float angle[20]={};
float angle2[20]={};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};

void timer (int t)
{
    printf("t:%d\n",t);
    if(t<=1410)glutTimerFunc(10, timer, t+1);
    if(t>1410)glutTimerFunc(9, timer, t+1);
    if(t%50==0)
    {
        if(fin==NULL) fin=fopen("motion.txt", "r");
        for(int i=0; i<20; i++)
        {
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );
        }
    }
    float alpha = (t%50) / 50.0;
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        angle2[i] = alpha * NewAngle2[i] + (1-alpha) * OldAngle2[i];
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key== '0') ID=0;///頭
    if(key== '1') ID=1;///身體
    if(key== '2') ID=2;///左手
    if(key== '3') ID=3;///右手
    if(key== '4') ID=4;///左腳
    if(key== '5') ID=5;///右腳
    if(key== '6') ID=6;///左手掌
    if(key== '7') ID=7;///右手掌
    if(key=='s')
    {
        if(fout == NULL)fout =fopen("motion.txt","w");
        for(int i=0; i<20;i++)
        {
            fprintf(fout, "%.2f ",angle[i]);
            fprintf(fout, "%.2f ",angle2[i]);
        }
        fprintf(fout, "\n");
        printf("finish one\n");
    }
    if(key =='r')
    {
        if(fin==NULL)fin = fopen("motion.txt","r");
        for(int i=0;i<20;i++)
        {
            fscanf(fin, "%f", &angle[i]);
            fscanf(fin, "%f", &angle2[i]);
        }
        glutPostRedisplay();
    }
    if(key =='p')
    {
        glutTimerFunc(0, timer, 0);
        myMP3.Play();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, tex1);
        glPushMatrix();
        glScalef(0.08,0.08,0.08);
        glTranslatef(0,-8,-5);


    ///glTranslatef(teapotX,teapotY, 0);
    ///glutSolidTeapot(0.3);








    glPushMatrix();
        glTranslatef(-0.033333, 2.993332, 0);
        glRotatef(angle[1] ,0,1,0);
        glRotatef(angle2[1], 1, 0, 0);
        glTranslatef(0.033333, -2.993332, 0);
        if(show[1])glmDraw(body , GLM_MATERIAL| GLM_TEXTURE);
        glPushMatrix();
            glTranslatef(0.000000, 5.800000, 0);
            glRotatef(angle[0],0,1,0);
            glRotatef(angle2[0],1,0, 0);
            glTranslatef(-0.000000, -5.800000, 0);
            if(show[0])glmDraw(head , GLM_MATERIAL| GLM_TEXTURE);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.300000, 5.000001, 0);
            glRotatef(angle[2] ,0,1,0);
            glRotatef(angle2[2],1,0,0);
            glTranslatef(-1.300000, -5.000001, 0);
            if(show[2])glmDraw(righthand , GLM_MATERIAL| GLM_TEXTURE);
            glPushMatrix();
                glTranslatef(2.600000, 4.100001, 0);
                glRotatef(angle[6] ,0,1,0);
                glRotatef(angle2[6], 1,0,0);
                glTranslatef(-2.600000, -4.100001, 0);
                if(show[6])glmDraw(Rhand , GLM_MATERIAL| GLM_TEXTURE);
            glPopMatrix();
        glPopMatrix();
         glPushMatrix();
            glTranslatef(-1.299999, 5.000000, 0);
            glRotatef(angle[3] ,0,1,0);
            glRotatef(angle2[3] ,1,0,0);
            glTranslatef(1.299999, -5.000000, 0);
            if(show[3])glmDraw(lefthand , GLM_MATERIAL| GLM_TEXTURE);
            glPushMatrix();
                glTranslatef(-2.500000, 4.100000, 0);
                glRotatef(angle[7] ,0,1,0);
                glRotatef(angle2[7], 1,0, 0);
                glTranslatef(2.500000, -4.100000, 0);
                if(show[7])glmDraw(Lhand, GLM_MATERIAL| GLM_TEXTURE);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.900000, 1.600000, 0);
            glRotatef(angle[4] ,0,1,0);
            ///glRotatef(angle[4] ,0,0,1);
            glRotatef(angle2[4], 1, 0, 0);///week15_step03-1
            glTranslatef(-0.900000, -1.600000, 0);
            if(show[4])glmDraw(leftleg , GLM_MATERIAL | GLM_TEXTURE);///week13 Step03-1
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.900000, 1.600001, 0);
            glRotatef(angle[5] ,0,1,0);
            glRotatef(angle2[5] ,1,0,0);
            glTranslatef(0.900000, -1.600001, 0);
            if(show[5])glmDraw(rightleg , GLM_MATERIAL| GLM_TEXTURE);///week13 Step03-1
        glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, tex2);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
    glEnd();
    ///glColor3f(0,1,0);
    ///glutSolidTeapot(0.02);
    glutSwapBuffers();
}
float oldX=0, oldY=0;
void motion(int x,int y)
{
    teapotX += (x -oldX)/10.0;
    teapotY += (oldY - y)/10.0;
    angle[ID] += (x- oldX);
    angle2[ID] += (y- oldY);
    oldX = x;
    oldY = y;
    ///printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
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
    glutInitWindowSize(700,700);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16");
    char filename[]="C:\\Users\\木頭\\Desktop\\2023graphicsa\\Final_Project\\song.mp3";
    myMP3.Load(filename);
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
    Lhand = glmReadOBJ("model/Lhand.obj");
    Rhand = glmReadOBJ("model/Rhand.obj");
    tex1 = myTexture("model/ba.jpg");
    tex2 = myTexture("model/ta.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
