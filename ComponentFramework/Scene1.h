#ifndef Scene1_H
#define Scene1_H

#include "Scene.h"
#include "Mesh.h"



namespace GAME {
	class Window; /// Forward declaration

	class Scene1 : public Scene  {
	protected:
		
	public:
		explicit Scene1(Window& windowRef);
		virtual ~Scene1();


		/// Delete these possible default constructors and operators  
		Scene1(const Scene1&) = delete;
		Scene1(Scene1 &&) = delete;
		Scene1& operator=(const Scene1 &) = delete;
		Scene1& operator=(Scene1 &&) = delete;

		virtual bool OnCreate() ;
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);
	
	private:
		Vec3 lightPos;
		std::vector<Mesh*> meshes;
		class Shader *shader;
	};
}
#endif