#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0;
void display()
{
    glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.212,0.144);
    glVertex2f(-0.052,0.176);
    glVertex2f(0.028,0.172);
    glVertex2f(0.212,0.136);
    glVertex2f(0.280,-0.004);
    glVertex2f(0.280,-0.136);
    glVertex2f(0.200,-0.216);
    glVertex2f(0.060,-0.232);
    glVertex2f(-0.076,-0.228);
    glVertex2f(-0.208,-0.224);
    glVertex2f(-0.300,-0.148);
    glVertex2f(-0.308,-0.092);
    glVertex2f(-0.272,0.064);
    glVertex2f(-0.216,0.156);
    glEnd();
    glutSwapBuffers();
}
void mouse (int button, int state,int x,int y)
{
    X = (x-250)/250.0;
    Y= -(y-250)/250.0;
    if(state==GLUT_DOWN){
        printf(" glVertex2f(%.3f,%.3f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Week03");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

}
