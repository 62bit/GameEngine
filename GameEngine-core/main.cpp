#include <iostream>
#include "src\graphics\window.h"
#include "src\maths\maths.h"
int main() {
	
	using namespace engine;
	using namespace graphics;
	using namespace maths;


	window win("Shigi242", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f,1.0f);


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec4 vector(2.0f, 2.0f,1.0f,1.0f);
	vec4 a(5.0f, 1.0f,1.0f,5.6f);

	vec4 c = a + vector;
	while (!win.closed())
	{
		win.clear();
		std::cout << a<< std::endl;
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