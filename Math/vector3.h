#pragma once

#include <cmath>

namespace Ethan
{
	namespace MATH
	{

		template <typename T> 
		class CVector3
		{
		public:
			CVector3 ()											// default constructor
			{ x = y = z = T(0);}


			CVector3 ( const T& x, const T& y, const T& z)		// normal constructor
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			CVector3 ( const CVector3& v)
			{
				this->x = v.x;
				this->y = v.y;
				this->z = v.z;
			}

			~CVector3 ( )
			{}

			T operator & ( CVector3& v ) const					// dot product
			{
				return this->x*v.x + this->y*v.y + this->z*v.z;
			}

			CVector3 operator + ( CVector3& v ) const			// add
			{
				return CVector3(this->x+v.x, this->y+v.y, this->z+v.z);
			}

			CVector3 operator - ( const CVector3& v ) const			// subtraction
			{
				return CVector3(this->x-v.x, this->y-v.y, this->z-v.z);
			}

			CVector3 operator * ( CVector3& v )	const		// cross product
			{
				return CVector3(this->y*v.z-this->z*v.y, this->z*v.x-this->x*v.z, this->x*v.y-this->y*v.x);
			}

			CVector3 operator * ( const CVector3& v )	const		// cross product
			{
				return CVector3(this->y*v.z-this->z*v.y, this->z*v.x-this->x*v.z, this->x*v.y-this->y*v.x);
			}

			CVector3 operator * ( T k )	const						// scale 
			{
				return CVector3(this->x*k, this->y*k, this->z*k);
			}

			CVector3& operator = ( const CVector3& v )
			{
				this->x = v.x;
				this->y = v.y;
				this->z = v.z;
				return *this;
			}

			T operator [] (int index) const
			{
				return m[index];
			}

			T& operator [] (int index)
			{
				return m[index];
			}

			void unify()
			{
				double vnor = norm()+0.0000001;
				x = T(x/vnor);
				y = T(y/vnor);
				z = T(z/vnor);
			}

			void RangeUnify(T min, T max)
			{
				if (x>max)	x=max;
				if (y>max)	y=max;
				if (z>max)	z=max;

				if (x<min)	x=min;
				if (y<min)	y=min;
				if (z<min)	z=min;
			}

			double norm()
			{
				return sqrt(x*x + y*y + z*z);
			}

		public:
			union
			{	struct{ T m[3]; };
				struct{ T x,y,z; };
			};
		};

		typedef CVector3<float>			vector3f;
		typedef CVector3<double>		vector3d;
		typedef CVector3<int>			vector3i;
	}
}