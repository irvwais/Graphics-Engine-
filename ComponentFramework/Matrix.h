#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>	/// Needed for the printf statement, could have used cin and cout but I have issues.  
#include "Vector.h"

namespace  MATH {

	class Matrix4  {
		
	private:
		float  m[16];
	public:
		

		inline const float operator [] (int index) const {  
			return *(m + index); 
		}


		inline float& operator [] ( int index ) { 
			return *(m + index); 
		}

		inline Matrix4& operator = (const Matrix4 &m_){
			this->m[0] = m_[0]; this->m[1] = m_[1]; this->m[2] = m_[2]; this->m[3] = m_[3];
			this->m[4] = m_[4]; this->m[5] = m_[5]; this->m[6] = m_[6]; this->m[7] = m_[7];
			this->m[8] = m_[8]; this->m[9] = m_[9]; this->m[10] = m_[10]; this->m[11] = m_[11];
			this->m[12] = m_[12]; this->m[13] = m_[13]; this->m[14] = m_[14]; this->m[15] = m_[15];
			return *this;
		}
		

		inline Matrix4(float x0, float x1, float x2, float x3,
			       float y0, float y1, float y2, float y3,
			       float z0, float z1, float z2, float z3,
			       float w0, float w1, float w2, float w3) {
			m[0] = x0;   m[4] = y0;   m[8] = z0; m[12] = w0;
			m[1] = x1;   m[5] = y1;   m[9] = z1; m[13] = w1;
			m[2] = x2;   m[6] = y2;   m[10] = z2; m[14] = w2;
			m[3] = x3;   m[7] = y3;   m[11] = z3; m[15] = w3;
		}
		
		inline Matrix4( const float d = 1.0f ) { 
			if(d == 1.0f) {
				loadIdentity();
			}else{  
				m[0] =  d;   m[4] = d;   m[8] =  d;   m[12] = d;
				m[1] =  d;   m[5] = d;   m[9] =  d;   m[13] = d;
				m[2] =  d;   m[6] = d;   m[10] = d;   m[14] = d;
				m[3] =  d;   m[7] = d;   m[11] = d;   m[15] = d;
			}
		}
		

		inline void loadIdentity(){
			m[0] =  1.0f;   m[4] = 0.0f;   m[8] =  0.0f;   m[12] = 0.0f;
			m[1] =  0.0f;   m[5] = 1.0f;   m[9] =  0.0f;   m[13] = 0.0f;
			m[2] =  0.0f;   m[6] = 0.0f;   m[10] = 1.0f;   m[14] = 0.0f;
			m[3] =  0.0f;   m[7] = 0.0f;   m[11] = 0.0f;   m[15] = 1.0f;
		}





		inline const Matrix4 operator*(const Matrix4& n) const {	
			
			return Matrix4(
				(m[0 * 4 + 0] * n[0 * 4 + 0]) + (m[1 * 4 + 0] * n[0 * 4 + 1]) + (m[2 * 4 + 0] * n[0 * 4 + 2]) + (m[3 * 4 + 0] * n[0 * 4 + 3]),
				(m[0 * 4 + 1] * n[0 * 4 + 0]) + (m[1 * 4 + 1] * n[0 * 4 + 1]) + (m[2 * 4 + 1] * n[0 * 4 + 2]) + (m[3 * 4 + 1] * n[0 * 4 + 3]),
				(m[0 * 4 + 2] * n[0 * 4 + 0]) + (m[1 * 4 + 2] * n[0 * 4 + 1]) + (m[2 * 4 + 2] * n[0 * 4 + 2]) + (m[3 * 4 + 2] * n[0 * 4 + 3]),
				(m[0 * 4 + 3] * n[0 * 4 + 0]) + (m[1 * 4 + 3] * n[0 * 4 + 1]) + (m[2 * 4 + 3] * n[0 * 4 + 2]) + (m[3 * 4 + 3] * n[0 * 4 + 3]),
				(m[0 * 4 + 0] * n[1 * 4 + 0]) + (m[1 * 4 + 0] * n[1 * 4 + 1]) + (m[2 * 4 + 0] * n[1 * 4 + 2]) + (m[3 * 4 + 0] * n[1 * 4 + 3]),
				(m[0 * 4 + 1] * n[1 * 4 + 0]) + (m[1 * 4 + 1] * n[1 * 4 + 1]) + (m[2 * 4 + 1] * n[1 * 4 + 2]) + (m[3 * 4 + 1] * n[1 * 4 + 3]),
				(m[0 * 4 + 2] * n[1 * 4 + 0]) + (m[1 * 4 + 2] * n[1 * 4 + 1]) + (m[2 * 4 + 2] * n[1 * 4 + 2]) + (m[3 * 4 + 2] * n[1 * 4 + 3]),
				(m[0 * 4 + 3] * n[1 * 4 + 0]) + (m[1 * 4 + 3] * n[1 * 4 + 1]) + (m[2 * 4 + 3] * n[1 * 4 + 2]) + (m[3 * 4 + 3] * n[1 * 4 + 3]),
				(m[0 * 4 + 0] * n[2 * 4 + 0]) + (m[1 * 4 + 0] * n[2 * 4 + 1]) + (m[2 * 4 + 0] * n[2 * 4 + 2]) + (m[3 * 4 + 0] * n[2 * 4 + 3]),
				(m[0 * 4 + 1] * n[2 * 4 + 0]) + (m[1 * 4 + 1] * n[2 * 4 + 1]) + (m[2 * 4 + 1] * n[2 * 4 + 2]) + (m[3 * 4 + 1] * n[2 * 4 + 3]),
				(m[0 * 4 + 2] * n[2 * 4 + 0]) + (m[1 * 4 + 2] * n[2 * 4 + 1]) + (m[2 * 4 + 2] * n[2 * 4 + 2]) + (m[3 * 4 + 2] * n[2 * 4 + 3]),
				(m[0 * 4 + 3] * n[2 * 4 + 0]) + (m[1 * 4 + 3] * n[2 * 4 + 1]) + (m[2 * 4 + 3] * n[2 * 4 + 2]) + (m[3 * 4 + 3] * n[2 * 4 + 3]),
				(m[0 * 4 + 0] * n[3 * 4 + 0]) + (m[1 * 4 + 0] * n[3 * 4 + 1]) + (m[2 * 4 + 0] * n[3 * 4 + 2]) + (m[3 * 4 + 0] * n[3 * 4 + 3]),
				(m[0 * 4 + 1] * n[3 * 4 + 0]) + (m[1 * 4 + 1] * n[3 * 4 + 1]) + (m[2 * 4 + 1] * n[3 * 4 + 2]) + (m[3 * 4 + 1] * n[3 * 4 + 3]),
				(m[0 * 4 + 2] * n[3 * 4 + 0]) + (m[1 * 4 + 2] * n[3 * 4 + 1]) + (m[2 * 4 + 2] * n[3 * 4 + 2]) + (m[3 * 4 + 2] * n[3 * 4 + 3]),
				(m[0 * 4 + 3] * n[3 * 4 + 0]) + (m[1 * 4 + 3] * n[3 * 4 + 1]) + (m[2 * 4 + 3] * n[3 * 4 + 2]) + (m[3 * 4 + 3] * n[3 * 4 + 3]));	
	}

	
		inline Matrix4& operator*=(const Matrix4& n) { 
			*this =  *this * n;
			return *this; 
		}

		inline  Vec4 operator* (const Vec4& v) const {
			float x  =  v.x * m[0] + v.y * m[4] + v.z * m[8]  + v.w * m[12];
			float y  =  v.x * m[1] + v.y * m[5] + v.z * m[9]  + v.w * m[13];
			float z  =  v.x * m[2] + v.y * m[6] + v.z * m[10] + v.w * m[14];
			float w  =  v.x * m[3] + v.y * m[7] + v.z * m[11] + v.w * m[15];
			return Vec4(x,y,z,w);
		}

		inline  Vec3 operator* (const Vec3& v) const {
			 float x = v.x * m[0] + v.y * m[4] + v.z * m[8]  + 1.0f * m[12];
			 float y = v.x * m[1] + v.y * m[5] + v.z * m[9]  + 1.0f * m[13];
			 float z = v.x * m[2] + v.y * m[6] + v.z * m[10] + 1.0f * m[14];
			 float w = v.x * m[3] + v.y * m[7] + v.z * m[11] + 1.0f * m[15];
			 return Vec3(x, y, z);
		}

		inline void print() const { 
			printf("%1.8f %1.8f %1.8f %1.8f\n%1.8f %1.8f %1.8f %1.8f\n%1.8f %1.8f %1.8f %1.8f\n%1.8f %1.8f %1.8f %1.8f\n\n",
				m[0], m[4], m[8],  m[12],
				m[1], m[5], m[9],  m[13],
				m[2], m[6], m[10], m[14],
				m[3], m[7], m[11], m[15]);
		}
		
		
		inline operator float* () { return static_cast<float*>( &m[0] ); }
		inline operator const float* () const { return static_cast<const float*>( &m[0]); }		
	};


	class Matrix3  {
		
		
	private:
		float  m[9];

	public:
		

		inline const float operator [] (int index) const {  
			return *(m + index); 
		}

		inline float& operator [] ( int index ) { 
			return *(m + index); 
		}

		inline Matrix3& operator = (const Matrix3 &m_){
			this->m[0] = m_[0]; this->m[1] = m_[1]; this->m[2] = m_[2];
			this->m[3] = m_[3]; this->m[4] = m_[4]; this->m[5] = m_[5];
			this->m[6] = m_[6]; this->m[7] = m_[7]; this->m[8] = m_[8];
			return *this;
		}



		inline Matrix3& operator = (const Matrix4 &m_){
			this->m[0] = m_[0]; this->m[1] = m_[1]; this->m[2] = m_[2];
			this->m[3] = m_[4]; this->m[4] = m_[5]; this->m[5] = m_[6];
			this->m[6] = m_[8]; this->m[7] = m_[9]; this->m[8] = m_[10];
			return *this;
		}

		inline Matrix3(const Matrix4 &m_){
			this->m[0] = m_[0]; this->m[1] = m_[1]; this->m[2] = m_[2];
			this->m[3] = m_[4]; this->m[4] = m_[5]; this->m[5] = m_[6];
			this->m[6] = m_[8]; this->m[7] = m_[9]; this->m[8] = m_[10];
		}

		
	
		inline Matrix3(float xx, float yx, float zx, 
               		       float xy, float yy, float zy,
               		       float xz, float yz, float zz) {       
			m[0] =  xx;   m[3] = xy;   m[6] =  xz;  
			m[1] =  yx;   m[4] = yy;   m[7] =  yz;
			m[2] =  zx;   m[5] = zy;   m[8] =  zz;
				
		}

		inline Matrix3( const float d = 1.0f ) { 
			if(d == 1.0f) {
				loadIdentity();
			} else {
				m[0] =  d;   m[3] = d;   m[6] =  d;  
				m[1] =  d;   m[4] = d;   m[7] =  d;  
				m[2] =  d;   m[5] = d;   m[8] =  d;  
			
			}
		}
		

		inline void loadIdentity(){
			m[0] =  1.0f;   m[3] = 0.0f;   m[6] =  0.0f;   
			m[1] =  0.0f;   m[4] = 1.0f;   m[7] =  0.0f; 
			m[2] =  0.0f;   m[5] = 0.0f;   m[8] =  1.0f; 
			
		}

		

		inline void print() const { 
			printf("%1.8f %1.8f %1.8f\n%1.8f %1.8f %1.8f\n%1.8f %1.8f %1.8f\n\n",
				m[0], m[3], m[6], 
				m[1], m[4], m[7], 
				m[2], m[5], m[8]);
		}

		inline operator float* () { return static_cast<float*>(&m[0]); }
		inline operator const float* () const { return static_cast<const float*>(&m[0]); }
	};

}

#endif
