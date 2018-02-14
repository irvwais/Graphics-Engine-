#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "MMath.h"
#include "Window.h"
#include "Shader.h"
#include "Scene1.h"

#include "ObjLoader.h"

using namespace GAME;
using namespace MATH;


Scene1::Scene1(Window& windowRef):Scene(windowRef) {
	shader = nullptr;
}


bool Scene1::OnCreate() {
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	OnResize(windowPtr->GetWidth(),windowPtr->GetHeight());
	
	
	/// Load Assets: as needed 
	
	if (ObjLoader::loadOBJ("sphere.obj") == false) {
		return false;
	}
	/// Get the data out of the ObjLoader and into our own mesh
	meshes.push_back(new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords));
	/// Create a shader with attributes
	shader = new Shader("phongVert.glsl", "phongFrag.glsl", 3, 0, "vVertex", 1, "vNormal", 2, "texCoords");
	lightPos = Vec3(0.0f, 3.0f, 7.0f);
	return true;
}


void Scene1::OnResize(int w_, int h_){
	windowPtr->SetWindowSize(w_,h_);
	glViewport(0,0,windowPtr->GetWidth(),windowPtr->GetHeight());
	float aspect = float(windowPtr->GetWidth()) / float(windowPtr->GetHeight());
	
	projectionMatrix = MMath::perspective(45.0f, aspect, 0.75f, 100.0f);

	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 20.0f), 
							   Vec3(0.0f, 0.0f, 0.0f), 
							   Vec3(0.0f, 1.0f, 0.0f));
}



void Scene1::Update(const float deltaTime) {}

void Scene1::Render() const{
	GLint projectionMatrixID = glGetUniformLocation(shader->getProgram(), "projectionMatrix");
	GLint modelViewMatrixID = glGetUniformLocation(shader->getProgram(), "modelViewMatrix");
	GLint normalMatrixID = glGetUniformLocation(shader->getProgram(), "normalMatrix");
	GLint lightPosID = glGetUniformLocation(shader->getProgram(), "lightPos");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	/// Draw scene here
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	glUseProgram(shader->getProgram());
	Matrix3 normalMatrix;
	glUniformMatrix4fv(projectionMatrixID, 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(modelViewMatrixID, 1, GL_FALSE, viewMatrix );
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	glUniform3fv(lightPosID, 1, lightPos);

	for (Mesh* mesh : meshes) {
		mesh->Render();
	}

	
	

	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
	
}

void Scene1::HandleEvents(const SDL_Event& SDLEvent){
	if(SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN){
		
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION && 
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		
	}
		
}

Scene1::~Scene1() {
	OnDestroy();
}
void Scene1::OnDestroy() {
	/// Cleanup Assets
	if (shader) delete shader;
	for (Mesh* mesh : meshes) {
		if (mesh) delete mesh;
	}
}