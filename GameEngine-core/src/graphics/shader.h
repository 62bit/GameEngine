#pragma once
#include <GL\glew.h>
#include "../utils/fileutils.h"
#include <vector>
#include <iostream>
#include "../maths/maths.h"
namespace engine {
	namespace graphics {

		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char* m_VertPath, *m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();


			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMath4(const GLchar* name, const maths::mat4& matrix);

			void enable();
			void disable();
			inline GLuint getShaderId() { return m_ShaderID; }
		
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};


	}
}
