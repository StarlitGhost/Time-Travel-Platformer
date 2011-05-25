#pragma once

/****************************************************************************
* 																			*
* Shader																	*
* 																			*
* Handles the loading, compilation, validation, and use of GLSL shaders		*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class Shader
{
public:
	/*
	 * Default constructor
	 * If you use this, you will later have to call Init to actually set up the shader for use
	 */
	Shader(void);
	/*
	 * Parameterized constructor
	 * Takes in the paths to a vertex and fragment shader, and loads, compiles, and validates them
	 */
	Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
	
	/*
	 * Destructor
	 * Unloads the vertex and fragment shaders from the GPU, and deletes them from memory
	 */
	~Shader(void);

	// Takes in the paths to a vertex and fragment shader, and loads, compiles, and validates them
	void Init(const char *vertexShaderPath, const char *fragmentShaderPath);

	// Binds the shader for use with future OpenGL drawing commands.
	void Bind() const;
	// Unbinds the shader, so fixed OpenGL functionality is used.
	void Unbind() const;
	
	// Returns the id of the loaded shader. This is useful for sending data to the shader later on, if required.
	unsigned int Id() const { return _id; };

private:
	unsigned int _id;
	unsigned int _vertexProgram;
	unsigned int _fragmentProgram;

};
