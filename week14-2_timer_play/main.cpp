
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)
{
    glutTimerFunc(500,timer,t+1);
    angle +=90;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x, int y)
{
    glutTimerFunc(0, timer , 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///¥Îkeyboard
    ///glutTimerFunc(2000, timer , 0);

    glutMainLoop();
}
