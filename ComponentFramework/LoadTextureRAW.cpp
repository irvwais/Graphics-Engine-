#include <stdio.h>
#include <GL/glew.h>
#include "LoadTextureRAW.h"

/// load an RGB Adobe Photoshop .RAW file as a texture
GLuint loadTextureRAW(const char * filename, int width, int height) {
	GLuint texture = NULL;
	GLubyte * data;
	FILE * file;

	/// open texture data file
	fopen_s(&file, filename, "rb");
	if (file == NULL) return 0;

	data = new GLubyte[width * height * 3];

	fread(data, width * height * 3, 1, file);
	fclose(file); /// all done close the file 


	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	/// Wrapping and filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	delete[] data;


	return texture;	/// return the index
}