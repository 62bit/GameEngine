#include <iostream>;
#include "window.h";
namespace engine {
	namespace graphics {
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


		void window_resize(GLFWwindow* window, int widht, int height);

		 bool window::m_Keys[MAX_KEYS];
		 bool window::m_MouseButtons[MAX_BUTTONS];
		 double window::mx;
		 double window::my;

		window::window(const char* title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;
			if (!init())
			{
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}
		window::~window() {
			glfwTerminate();
		}
		bool window::init() {
			if (!glfwInit())
			{
				std::cout << "Failed to init glfw" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window)
			{
				std::cout << "failed to create glfw window" << std::endl;
				return false; 
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Could not initilize GLEW!" << std::endl;
				return false;
			}
			std::cout << "Open Gl " << glGetString(GL_VERSION) << std::endl;
			return true;
		}
		bool window::isKeyPressed(unsigned int keycode) {
			//TODO : LOG THIS
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_Keys[keycode];
		}
		bool window::isMouseButtonPressed(unsigned int button) {
			//TODO : LOG THIS
			if (button >= MAX_BUTTONS) {
				return false;
			}
			return m_MouseButtons[button];
		}
		void window::getMousePosition(double &x, double &y) {
			x = mx;
			y=my;
		}
		void window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void window::update(){
			
			glfwPollEvents();
		
			glfwSwapBuffers(m_window);
		}
		bool window::closed() const{
			return glfwWindowShouldClose(m_window);

		}

		void window_resize(GLFWwindow* window, int widht, int height) {
			glViewport(0, 0, widht, height);//to refresh the images in window
		}
		void mouse_button_callback(GLFWwindow* awindow, int button, int action, int mods) {
			window* win = (window*)glfwGetWindowUserPointer(awindow);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		void key_callback(GLFWwindow* awindow, int key, int scancode, int action, int mods) {
			window* win = (window*)glfwGetWindowUserPointer(awindow);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* awindow, double xpos, double ypos) {
			window* win = (window*)glfwGetWindowUserPointer(awindow);
			win->mx = xpos;
			win->my = ypos;
			

		}

	}
}