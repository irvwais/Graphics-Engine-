#pragma once
#include "VMath.h"
#include "Matrix.h"

namespace  MATH {

	struct Quaternion : public Vec3 { 
		float w;

		inline void load( float _w, float _x, float _y, float _z ) {
			w = _w; x = _x; y = _y; z = _z; 
		}

		inline Quaternion(){
			load(1.0f,0.0f,0.0f,0.0f);
		}


		inline Quaternion(float _w, float _x,  float _y, float _z){
			load(_w,_x,_y,_z);
		}

 
		inline Quaternion( float angle, const Vec3& n){
			angle *= DEGREES_TO_RADIANS; ///
			load(cos(angle/2.0f), sin(angle/2.0f)*n.x, sin(angle/2.0f)*n.y, sin(angle/2.0f)*n.z );
		}

		
		inline Quaternion( const Quaternion& q ) { 
			load(q.w, q.x, q.y, q.z); 
		}

		inline Quaternion& operator = (const Quaternion& q){
			load(q.w, q.x, q.y, q.z); 
			return *this;
		}

		inline const Quaternion operator - () const  { 
			return Quaternion(-w, -x, -y, -z ); 
		}  

		inline const Quaternion operator * (const Quaternion& q) const {
			Vec3 ijk(w*q + q.w * (*this) + VMath::cross(*this, q));
			return Quaternion(w * q.w - VMath::dot(*this, q), ijk.x, ijk.y, ijk.z);
		}

		inline const Quaternion operator * (const Vec4& v) const {
			Vec3 ijk(w*v + v.w * (*this) + VMath::cross(*this, v));
			return Quaternion(w * v.w - VMath::dot(*this, v), ijk.x, ijk.y, ijk.z);
		}
		

		inline const Quaternion conjugate() const {
			return Quaternion( w, -x, -y, -z ); 
		}

		inline Vec3 rotate(const Vec3& v){
		
			Vec3 v2 = VMath::cross(*this, v);
			return v + v2 * (2.0f * w) + VMath::cross(*this, v2) * 2.0f;
		}


		inline  Matrix4 toMatrix(){
			 return Matrix4((1.0f - 2.0f*y*y - 2.0f*z*z), (2.0f*x*y + 2.0f * z*w),      (2.0f*x*z - 2.0f*y*w),        0.0f,
							(2.0f*x*y - 2.0f*z*w),        (1.0f - 2.0f*x*x - 2.0f*z*z), (2*y*z + 2*x*w),              0.0f,
							(2.0f*x*z + 2.0f*y*w),        (2.0f*y*z - 2*x*w),           (1.0f - 2.0f*x*x - 2.0f*y*y), 0.0f,
							 0.0f,                         0.0f,                         0.0f,                        1.0f);

		}



		inline const Quaternion fromEuler(float _yaw, float _pitch, float _roll){
			float cosYaw = cos(0.5f *_yaw * DEGREES_TO_RADIANS);
			float cosPitch = cos(0.5f * _pitch * DEGREES_TO_RADIANS);
			float cosRoll = cos(0.5f  *_roll * DEGREES_TO_RADIANS);
			float sinYaw = sin(0.5f *_yaw * DEGREES_TO_RADIANS);
			float sinPitch = sin(0.5f * _pitch * DEGREES_TO_RADIANS);
			float sinRoll = sin(0.5f  *_roll * DEGREES_TO_RADIANS);
			return Quaternion(	
				(cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll),
				(cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll),
				(cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll),
				(sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll));
		}

		
		inline void print() { 
			printf("%f %f %f %f\n", w,x,y,z);		  
		}

	};
}
