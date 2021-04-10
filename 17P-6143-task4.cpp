#include <GL/glut.h>
using namespace std;

GLfloat angleCube = 0.0f;
GLfloat angleCube2 = 0.0f;

float move_x = 0.5;
float move_nx = 0.5;
float move_y = 0.5;
float move_ny = 0.5;
void display()
{
	glClearColor(1, 1, 1, 0.0); // Background (R, G, B, alpha), all b/w 0 and 1
	glClear(GL_COLOR_BUFFER_BIT); // Clear output buffer to window color
	glColor3f(1,0, 0);
	//glLoadIdentity();
	glRotatef(angleCube2, 1.0f, 0.0f, 0.0f);
	glRotatef(angleCube, 0.0f, 1.0f, 0.0f);// Drawing color (R, G, B), all b/w 0 and 1
	glBegin(GL_TRIANGLES);// begin drawing a polyg
	glVertex3f(-0.2, -0.2, 0.5);
	glVertex3f(0.2,-0.2, 0.5);
	glVertex3f(0, 0.2, 0.3);

	glColor3f(0, 1, 0);
	
	glVertex3f(-0.2, -0.2, 0.1);
	glVertex3f(-0.2, -0.2, 0.5);
	glVertex3f(0, 0.2, 0.3);

	glColor3f(0, 0, 1);
	glVertex3f(0.2, -0.2, 0.5);
	glVertex3f(0.2, -0.2, 0.1);
	glVertex3f(0, 0.2, 0.3);

	glColor3f(1,1, 0);

	glVertex3f(0.2, -0.2, 0.1);
	glVertex3f(-0.2, -0.2, 0.1);
	glVertex3f(0, 0.2, 0.3);

	glColor3f(0, 1,1);
	glVertex3f(-0.2, -0.2, 0.5);
	glVertex3f(0.2, -0.2, 0.5);
	glVertex3f(0.2, -0.2, 0.1);

	glColor3f(1, 0, 1);
	glVertex3f(-0.2, -0.2, 0.5);
	glVertex3f(-0.2, -0.2, 0.1);
	glVertex3f(0.2, -0.2, 0.1);

	
	glEnd(); // end drawing the polygon
	glFlush(); // force OpenGL to empty the buffer and render
}
void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT: {
		angleCube += 0.3f;
		break;
	}
	case GLUT_KEY_LEFT: {
		angleCube -= 0.3f;
		break;
	}
	case GLUT_KEY_UP: {
		angleCube2 += 0.3f;
		break;
	}
	case GLUT_KEY_DOWN: {
		angleCube2 -= 0.3f;
		break;
	}
	}
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Initializes GLUT Toolkit
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("task 4");
	glutDisplayFunc(display);// Register call back routine for window updates
	glutSpecialFunc(keyboard);
	//keyboard();
	glutMainLoop(); // Starts the toolkit loop (infinite)
}