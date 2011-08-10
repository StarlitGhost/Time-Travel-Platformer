#include "Shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <string.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <SFML/Window/OpenGL.hpp>
#include <GL/glext.h>

using namespace FlatWorld;

/*
 * Validates the (compiled) shader supplied to it
 * Outputs any errors to the standard error buffer
 */
static void ValidateShader(const GLuint shader, const char* file = 0)
{
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	GLsizei length = 0;

	glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);
	if (length > 0)
	{
		std::cerr << "Shader " << shader << " (" << (file?file:"") << ") compile error: " << buffer << std::endl;
	}
}

/*
 * Validates the linked vertex and fragment shader programs
 * Outputs any errors to the standard error buffer
 */
static void ValidateProgram(GLuint program)
{
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	GLsizei length = 0;

	glGetShaderInfoLog(program, BUFFER_SIZE, &length, buffer);
	if (length > 0)
	{
		std::cerr << "Program " << program << " link error: " << buffer << std::endl;
	}

	glValidateProgram(program);
	GLint status;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);

	if (status == GL_FALSE)
	{
		std::cerr << "Error validating shader " << program << std::endl;
	}
}

static bool ReadShader(const char* fileName, std::string& outShader)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		std::ostringstream stream;

		stream << file.rdbuf();

		file.close();

		outShader = stream.str();

		return true;
	}
	std::cerr << "Unable to open file '" << fileName << "' for reading." << std::endl;
	return false;
}

Shader::Shader(void)
{
}

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	_id = 0;
	_vertexProgram = 0;
	_fragmentProgram = 0;
	Init(vertexShaderPath, fragmentShaderPath);
}

Shader::~Shader(void)
{
	glDetachShader(_id, _vertexProgram);
	glDetachShader(_id, _fragmentProgram);

	glDeleteShader(_vertexProgram);
	glDeleteShader(_fragmentProgram);
	glDeleteProgram(_id);
}

void Shader::Init(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	_vertexProgram = glCreateShader(GL_VERTEX_SHADER);
	_fragmentProgram = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexShaderText;
	std::string fragmentShaderText;
	if (!ReadShader(vertexShaderPath, vertexShaderText) || !ReadShader(fragmentShaderPath, fragmentShaderText))
	{
		std::cerr << "Either vertex shader or fragment shader file not found." << std::endl;
		return;
	}
	const char* constVST = vertexShaderText.c_str();
	const char* constFST = fragmentShaderText.c_str();

	glShaderSource(_vertexProgram, 1, &constVST, 0);
	glShaderSource(_fragmentProgram, 1, &constFST, 0);

	glCompileShader(_vertexProgram);
	ValidateShader(_vertexProgram, vertexShaderPath);
	glCompileShader(_fragmentProgram);
	ValidateShader(_fragmentProgram, fragmentShaderPath);

	_id = glCreateProgram();
	glAttachShader(_id, _vertexProgram);
	glAttachShader(_id, _fragmentProgram);
	glLinkProgram(_id);
	ValidateProgram(_id);
}

void Shader::Bind() const
{
	glUseProgram(_id);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}
