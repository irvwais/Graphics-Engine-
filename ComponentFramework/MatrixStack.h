#pragma once 
#include "MMath.h"
namespace  MATH {

class MatrixStack {		
	protected:
		int	stackDepth;  
		int	stackPointer;
		Matrix4	*stack;

	public:
		MatrixStack(int stackDepth_ = 32);
		~MatrixStack();

		MatrixStack(const MatrixStack&) = delete;
		MatrixStack(MatrixStack&&) = delete;
		MatrixStack& operator=(const MatrixStack&) = delete;
		MatrixStack& operator=(MatrixStack&&) = delete;



		void loadIdentity();

		void loadMatrix(const Matrix4 m);

		void multMatrix(const Matrix4 m);

		void pushMatrix();				/// Warning: can throw a std::string exception on overflow 
		void popMatrix();				/// Warning: can throw a std::string exception on underflow

		void scale(const float x, const float y, const float z);	
		void translate(const float x, const float y, const float z);
		void rotate(const float angle, const float x, const float y, const float z);

		/// These are copies of the OpenGL glu library 
		void orthographic(const float xMin, const float xMax,
						  const float yMin, const float yMax,
						  const float zMin, const float zMax);
	
		void perspective( const float fovy, const float aspect, const float zNear, const float zFar);
		void lookAt( const Vec3& eye, const Vec3& at, const Vec3& up );

		void unOrtho(const Matrix4 & ortho);

		inline Vec4 operator * ( const Vec4& v ) const { return stack[stackPointer] * v;}
		
		const float* getMatrixfv() const ;
		void print() const;
	};	
}