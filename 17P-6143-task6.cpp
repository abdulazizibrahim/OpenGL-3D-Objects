#include <GL/glut.h>
#include<math.h>
using namespace std;

GLfloat angleCube = 0.0f;
GLfloat angleCube2 = 0.0f;

float move_x = 0.5;
float move_nx = 0.5;
float move_y = 0.5;
float move_ny = 0.5;
void drawSphere(double r, int lats, int longs) {
	int i, j;
	for (i = 0; i <= lats; i++) {
		double lat0 = 3.142 * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = 3.142 * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= longs; j++) {
			double lng = 2 * 3.142 * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		glEnd();
	}
}
void display()
{
	glClearColor(1, 1, 1, 0.0); // Background (R, G, B, alpha), all b/w 0 and 1
	glClear(GL_COLOR_BUFFER_BIT); // Clear output buffer to window color
	glRotatef(angleCube2, 1.0f, 0.0f, 0.0f);
	glRotatef(angleCube, 0.0f, 1.0f, 0.0f);// Drawing color (R, G, B), all b/w 0 and 1
	// begin drawing a polyg
	glColor3f(0, 0, 0);
	float x = 0.5 *cos(360);
	float y = 0.5 * sin(360);
	float r = pow(0.5, (pow(2, (x - 0)) + pow(2, (y - 0))));
	drawSphere(r, 360, 360);
	glLoadIdentity();
	glutPostRedisplay();
	glutSwapBuffers();
	glEnd();// end drawing the polygon
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
	glutCreateWindow("task 6");
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);
	glutDisplayFunc(display);// Register call back routine for window updates
	glutSpecialFunc(keyboard);
	//keyboard();
	glutMainLoop(); // Starts the toolkit loop (infinite)
}
