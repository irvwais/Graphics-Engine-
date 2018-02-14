#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "MMath.h"
#include "Mesh.h"




namespace GAME {
using namespace MATH;

class PhysicsModel {			
protected:						
	Vec3 pos;				
	Vec3 vel;
	Vec3 orientation;
	Vec3 gravity;
	bool useGravity;
	Sphere bounding;
};


class Model: public PhysicsModel {
protected:
	Matrix4 modelMatrix;
	std::vector<Mesh*> meshes;
public:


	inline void setPos(const Vec3& pos_){ pos = pos_; }
	inline void setVel(const Vec3& vel_){ vel = vel_; }
	inline void setGravity(const Vec3& gravity_) { gravity = gravity_; }
	
	virtual ~Model(){};

	Model(const Model&) = delete;
	Model(Model&&) = delete;
	Model& operator = (const Model&) = delete;
	Model& operator = (Model&&) = delete;

	
 

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Render(const Matrix4& projectionMatrix, const Matrix4& modelViewMatrix, const Matrix3& normalMatrix) const = 0;
	virtual void Update(const float deltaTime) = 0;

};




} /// end of namespace

#endif