#include <GL/glut.h>
void display()
{
    glColor3f(64/255.0, 129/255.0, 236/255.0);
    glBegin(GL_POLYGON);
        glVertex2f(1,1);
        glVertex2f(-1,1);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");
	glutDisplayFunc(display);
	glutMainLoop();
}
