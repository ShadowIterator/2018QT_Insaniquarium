#ifndef SI_GEOMETRY_HPP
#define SI_GEOMETRY_HPP

#include "global.h"

namespace SI
{

template<class T>
class Vector2
{
public:
	T x;
	T y;
//	T z;

public:
	Vector2() :x(0), y(0)
	{
	}
	Vector2(const T& tx, const T& ty) :x(tx), y(ty)
	{
	}
	Vector2(const Vector2& tv) :x(tv.x), y(tv.y)
	{
	}
	void modify(const T& tx, const T& ty)
	{
		x = tx; y = ty;
	}
	void modify(const Vector2& tv)
	{
		x = tv.x; y = tv.y;
	}
	T len() const
	{
		return std::sqrt(x * x + y * y);
	}
	T len2() const
	{
		return (x * x + y * y );
	}
	Vector2 operator + (const Vector2& tv) const
	{
		return Vector2(x + tv.x, y + tv.y);
	}
	Vector2 operator - (const Vector2& tv) const
	{
		return Vector2(x - tv.x, y - tv.y);
	}
	Vector2 operator * (const T& a) const
	{
		return Vector2(a * x, a * y);
	}
	T operator % (const Vector2& tv) const	//dot
	{
		return  x * tv.x + y * tv.y;
	}
	Vector2 operator * (const Vector2& tv) const	//cross
	{
		return y * tv.x - x * tv.y;
	}
	Vector2 operator / (const T& a) const
	{
		return Vector2(x / a, y / a);
	}
	Vector2 normalize() const
	{
		T L = len();
		return Vector2(x / L, y / L);
	}
	Vector2 reLength(const T& k) const
	{
		T L = len();
		return Vector2(x * k / L, y * k / L);
	}
	void _normalize()
	{
		T L = len();
		x /= L; y /= L;
	}
	void _reLength(const T& k)
	{
		T L = len();
		x = x * k / L;
		y = y * k / L;
	}

	friend std::ostream& operator << (std::ostream& out, const Vector2& tv)
	{
		out << "( " << tv.x << " , " << tv.y << " )";
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Vector2& tv)
	{
		in >> tv.x >> tv.y;
		return in;
	}

	friend Vector2& operator += (Vector2& A, const Vector2& B)
	{
		A = A + B;
		return A;
	}
	friend Vector2& operator -= (Vector2& A, const Vector2& B)
	{
		A = A - B;
		return A;
	}
	friend Vector2& operator *= (Vector2& A, const T& k)
	{
		A = A * k;
		return A;
	}
	friend Vector2& operator /= (Vector2& A, const T& k)
	{
		A = A / k;
		return A;
	}
	friend Vector2& operator *= (Vector2& A, const Vector2& B)
	{
		A = A * B;
		return A;
	}
	friend Vector2 operator - (const Vector2& A)
	{
		return Vector2(-A.x, -A.y);
	}
	T Distance2(const Vector2& A)
	{
		return dist2(*this, A);
	}
	T Distance(const Vector2& A)
	{
		return dist(*this, A);
	}
//	T& GetCoord(int axis)
//	{
//		if (axis == 0) return x;
//		if (axis == 1) return y;
//		if (axis == 2) return z;
//	}

//	void AssRandomVector()
//	{
//		do {
//			x = 2 * ran() - 1;
//			y = 2 * ran() - 1;
//			z = 2 * ran() - 1;
//		} while (x * x + y * y + z * z > 1 || x * x + y * y + z * z < EPS);
//		_normalize();
//	}
//	Vector2 GetAnVerticalVector()
//	{
//		Vector2 ret = *this * Vector2(0, 0, 1);
//		if (ret.IsZeroVector()) ret = Vector2(1, 0, 0);
//		else ret._normalize();
//		return ret;
//	}
	bool IsZeroVector()
	{
		return DBcmp(x, 0) == 0 && DBcmp(y, 0) == 0;
	}
	void Input(std::stringstream& fin)
	{
		fin >> x >> y;
	}
//	Vector2 Reflect(Vector2 N)
//	{
//		return *this - N * (2 * ((*this) % N));
//	}
//	Vector2 Refract(Vector2 N, T n)
//	{
//		Vector2 V = normalize();
//		T cosI = -(N % V), cosT2 = 1 - (n * n) * (1 - cosI * cosI);
//		if (cosT2 > EPS) return V * n + N * (n * cosI - sqrt(cosT2));
//		return V.Reflect(N);
//	}
//	Vector2 Diffuse()
//	{
//		Vector2 Vert = GetAnVerticalVector();
//		T theta = acos(sqrt(ran()));
//		T phi = ran() * 2 * PI;
//		return Rotate(Vert, theta).Rotate(*this, phi);
//	}
//	Vector2 Rotate(Vector2 axis, T theta)
//	{
//		Vector2 ret;
//		double cost = cos(theta);
//		double sint = sin(theta);
//		ret.x += x * (axis.x * axis.x + (1 - axis.x * axis.x) * cost);
//		ret.x += y * (axis.x * axis.y * (1 - cost) - axis.z * sint);
//		ret.x += z * (axis.x * axis.z * (1 - cost) + axis.y * sint);
//		ret.y += x * (axis.y * axis.x * (1 - cost) + axis.z * sint);
//		ret.y += y * (axis.y * axis.y + (1 - axis.y * axis.y) * cost);
//		ret.y += z * (axis.y * axis.z * (1 - cost) - axis.x * sint);
//		ret.z += x * (axis.z * axis.x * (1 - cost) - axis.y * sint);
//		ret.z += y * (axis.z * axis.y * (1 - cost) + axis.x * sint);
//		ret.z += z * (axis.z * axis.z + (1 - axis.z * axis.z) * cost);
//		return ret;
//	}



};

typedef Vector2<double> Point2lf;
typedef Vector2<double> Vector2lf;

template<typename T>
T dist2(const Vector2<T>& v1, const Vector2<T>& v2)
{
	T dx = v1.x - v2.x;
	T dy = v1.y - v2.y;
//	T dz = v1.z - v2.z;
	return (dx * dx + dy * dy);
}

template<typename T>
T dist(const Vector2<T>& v1, const Vector2<T>& v2)
{
	T dx = v1.x - v2.x;
	T dy = v1.y - v2.y;
//	T dz = v1.z - v2.z;
	return std::sqrt(dx * dx + dy * dy);
}



}

#endif // SI_GEOMETRY_HPP
