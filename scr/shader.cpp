#include "shader.h"

Shader::Shader(const std::string& fileName) {
	
	m_shaderProgram = glCreateProgram();
	m_Shaders[0] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_Shaders[1] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for (size_t i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_shaderProgram, m_Shaders[i]);

	glBindAttribLocation(m_shaderProgram, 0, "Position");
	glBindAttribLocation(m_shaderProgram, 1, "texCoord");

	glLinkProgram(m_shaderProgram);
	checkShaderError(m_shaderProgram, GL_LINK_STATUS, true, "Error linking shader programm");

	glValidateProgram(m_shaderProgram);
	checkShaderError(m_shaderProgram, GL_LINK_STATUS, true, "Invalid Shader Program");

	//m_Uniforms[0] = glGetUniformLocation(m_shaderProgram, "gScale");
	//m_Uniforms[1] = glGetUniformLocation(m_shaderProgram, "gSampler");
}

Shader::~Shader() {

	for (size_t i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(m_shaderProgram, m_Shaders[i]);
		glDeleteShader(m_Shaders[i]);
	}

	glDeleteProgram(m_shaderProgram);
}

void Shader::Bind() {
	glUseProgram(m_shaderProgram);
}

std::string Shader::loadShader(const std::string& fileName) {
	
	std::ifstream file;
	file.open(fileName.c_str());

	std::string shaderText;
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error with loading shader: " << fileName << std::endl;
		return shaderText;
	}

	while (file.good()) {

		std::getline(file, line);
		shaderText.append(line + '\n');
	}

	file.close();

	return shaderText;
}

GLuint Shader::createShader(const std::string& text, unsigned int type) {
	
	GLuint shader = glCreateShader(type);

	if (shader == 0) 
		std::cerr << "Error compiling shader type: " << type << std::endl;
	
	const GLchar* p[1];
	p[0] = text.c_str();
	GLint lenghts[1];
	lenghts[0] = text.length();

	glShaderSource(shader, 1, p, lenghts);
	glCompileShader(shader);

	return shader;
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	
	GLint success = 0;
	GLchar error[256] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}	
}