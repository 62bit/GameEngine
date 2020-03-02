#include <iostream>
#include "src\graphics\window.h"
int main() {
	
	using namespace engine;
	using namespace graphics;
	window win("Shigi242", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f,1.0f);
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	while (!win.closed())
	{
		win.clear();
		double x, y;
		win.isMouseButtonPressed(GLFW_KEY_A);
		win.getMousePosition(x, y);
		std::cout << "x " << x << " y " << y << std::endl;
		
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		
		//glDrawArrays(GL_ARRAY_BUFFER, 0, 8);
		win.update();
	}
	//newcommits
	
	return 0;
}