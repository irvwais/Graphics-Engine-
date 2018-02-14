#pragma once

#include "Matrix.h"
#include "MatrixStack.h"



namespace MATH {

	class StackMngr {
	public:
		
		enum StdMatricies {
			PROJECTION, MODELVIEW, NORMAL
		};

	private:
		static StackMngr* instance; 
		MatrixStack* projection;
		MatrixStack* modelView; 
		MatrixStack* currentMatrixStack; /// Point to the top of whichever stack is currently active
		float normal[9];   /// The normal matrix doesn't need a stack


		StackMngr(); /// Default starting condition of the Manager is PROJECTION matrix
		~StackMngr();

	public:
		/// Don't allow these to be created by default
		StackMngr(const StackMngr&) = delete;
		StackMngr(StackMngr&&) = delete;
		StackMngr& operator=(const StackMngr&) = delete;
		StackMngr& operator=(StackMngr&&) = delete;
		
	public:
		static StackMngr* getInstance();

		
		static void deleteInstance();


		void matrixMode(StdMatricies whichMatrix);

		void loadIdentity();
		void loadMatrix(const Matrix4& m);   
		void multMatrix(const Matrix4& m);
		
		void pushMatrix();			/// Warning: can throw a std::string exception on overflow 
		void popMatrix();			/// Warning: can throw a std::string exception on underflow 


		void scale(const float x, const float y, const float z);	
		void translate(const float x, const float y, const float z);
		void rotate(const float radians, const float x, const float y, const float z);


		void perspective( const float fovy, const float aspect,const float zNear, const float zFar);
		void lookAt( const Vec3& eye, const Vec3& at, const Vec3& up );

		/// An inline operator overload to mult a vector by the top of the matrix stack
		inline Vec4 operator * ( const Vec4& v ) const { return *currentMatrixStack * v;}
		const float* getMatrixfv(StdMatricies whichMatrix);

		/// Just return the currently active matrix as a float array
		const float* getMatrixfv() ;

		void print() ;
	};

}