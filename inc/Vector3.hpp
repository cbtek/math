//#-------------------------------------------------
//#
//# File Vector3.h created by shadowefusion on 05-01-2014 at 10:15:34 PM
//#
//#-------------------------------------------------

#pragma once

#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>

namespace cbtek {
namespace common {
namespace math{

template<typename T>
class Vector3
{

public:
    Vector3(const T & x=0, const T & y=0, const T & z=0);
	~Vector3();

    Vector3<T> operator+(const Vector3<T> & vec);
    Vector3<T> operator-(const Vector3<T> & vec);
    Vector3<T> operator*(const T & scalar);
    Vector3<T> operator/(const Vector3<T> & vec);
    Vector3<T> & operator+=(const Vector3<T> & vec);
    Vector3<T> & operator-=(const Vector3<T> & vec);
    Vector3<T> getCrossProduct(const Vector3<T> & vec);
    Vector3<T> getNormalized();
    void addX(T value) { m_values[0] += value; }
    void addY(T value) { m_values[1] += value; }
    void addZ(T value) { m_values[2] += value; }

    void reset() { m_values[0] = m_values[1] = m_values[2] = 0; }
    void set(const T & x=0, const T & y=0, const T & z=0);
    void setX(const T &x);
    void setY(const T &y);
    void setZ(const T &z);
    void operator*=(const T & scalar);
    void normalize();
    void incrementX(const T & dx);
    void incrementY(const T & dy);
    void incrementZ(const T & dz);
    void increment(const T & dx, const T & dy, const T & dz);
    void operator/=(const T & scalar);

    T max() const;
    T min() const;
    std::string toString() const
    {
        std::ostringstream out;
        out << "x: " << m_values[0] << ", ";
        out << "y: " << m_values[1] << ", ";
        out << "z: " << m_values[2];
        return out.str();
    }

    T getDotProduct(const Vector3<T> & vec) const;
    T getMagnitude();
    T getAngle(const Vector3<T> & point);
    T getX() const;
    T getY() const;
    T getZ() const;
    const T *array() const;
private:

    T m_values[3];
};


template<typename T>
Vector3<T>::~Vector3()
{
}
template<typename T>
Vector3<T>::Vector3(const T & x, const T & y,const T & z)
{
    set(x,y,z);
}
template<typename T>
void Vector3<T>::set(const T &x, const T &y, const T &z)
{
    this->m_values[0]=x;
    this->m_values[1]=y;
    this->m_values[2]=z;
}
template<typename T>
T Vector3<T>::getX() const
{
    return this->m_values[0];
}
template<typename T>
T Vector3<T>::getY() const
{
    return this->m_values[1];
}
template<typename T>
T Vector3<T>::getZ() const
{
    return this->m_values[2];
}
template<typename T>
void Vector3<T>::setX(const T &x)
{
    this->m_values[0]=x;
}
template<typename T>
void Vector3<T>::setY(const T &y)
{
    this->m_values[1]=y;
}
template<typename T>
void Vector3<T>::setZ(const T &z)
{
    this->m_values[2]=z;
}
template<typename T>
Vector3<T> Vector3<T>::operator +(const Vector3<T>&vec)
{
    return Vector3(vec.getX()+m_values[0],vec.getY()+m_values[1],vec.getZ()+m_values[2]);
}
template<typename T>
Vector3<T> Vector3<T>::operator -(const Vector3<T>&vec)
{

    return Vector3(m_values[0]-vec.getX(),m_values[1]-vec.getY(),m_values[2]-vec.getZ());
}
template<typename T>
T Vector3<T>::getDotProduct(const Vector3<T>&vec)const
{
    return (vec.getX()*m_values[0]) + (vec.getY()*m_values[1]) + (vec.getZ()*m_values[2]);
}
template<typename T>
Vector3<T> Vector3<T>::getCrossProduct(const Vector3<T>&vec)
{
    Vector3 returnVec;
    returnVec.set
            (
             (m_values[1]*vec.getZ()) - (m_values[2]*vec.getY()),
             (m_values[0]*vec.getZ()) - (m_values[2]*vec.getX()),
             (m_values[0]*vec.getY()) - (m_values[1]*vec.getX())
            );
    return returnVec;
}
template<typename T>
const T *Vector3<T>::array()const
{
    return this->m_values;
}
template<typename T>
Vector3<T> Vector3<T>::operator *(const T &scalar)
{
    return Vector3(m_values[0]*scalar,m_values[1]*scalar,m_values[2]*scalar);
}
template<typename T>
void Vector3<T>::operator*=(const T &scalar)
{
    m_values[0]*=scalar;
    m_values[1]*=scalar;
    m_values[2]*=scalar;
}
template<typename T>
Vector3<T> Vector3<T>::operator /(const Vector3<T>&vec)
{
    if (vec.getX()!=0 && vec.getY()!=0 && vec.getZ()!=0)
    {
        return Vector3(m_values[0]/vec.getX(),m_values[1]/vec.getY(),m_values[2]/vec.getZ());
    }
    return Vector3();
}
template<typename T>
void Vector3<T>::operator/=(const T & scalar)
{
    if (scalar>0 || scalar<0)
    {
        m_values[0]/=scalar;
        m_values[1]/=scalar;
        m_values[2]/=scalar;
    }
}

template<typename T>
T Vector3<T>::max() const
{
    auto max = 0.0;
    if (m_values[0] > m_values[1])
    {
        max = m_values[0];
    }
    else
    {
        max = m_values[1];
    }

    if (m_values[2] > max)
    {
        max = m_values[2];
    }
    return max;
}

template<typename T>
T Vector3<T>::min() const
{
    auto min = 0.0;
    if (m_values[0] < m_values[1])
    {
        min = m_values[0];
    }
    else
    {
        min = m_values[1];
    }

    if (m_values[2] < min)
    {
        min = m_values[2];
    }
    return min;
}

template<typename T>
Vector3<T> &Vector3<T>::operator +=(const Vector3<T>&vec)
{
    this->m_values[0]+=vec.getX();
    this->m_values[1]+=vec.getY();
    this->m_values[2]+=vec.getZ();
    return *this;
}
template<typename T>
Vector3<T> &Vector3<T>::operator -=(const Vector3<T>&vec)
{

    this->m_values[0]-=vec.getX();
    this->m_values[1]-=vec.getY();
    this->m_values[2]-=vec.getZ();
    return *this;
}
template<typename T>
T Vector3<T>::getMagnitude()
{
    return std::abs(std::sqrt((m_values[0]*m_values[0])+(m_values[1]*m_values[1])+(m_values[2]*m_values[2])));
}
template<typename T>
void Vector3<T>::normalize()
{
    const T mag=std::abs(this->getMagnitude());
    if (mag==0)
    {
        return;
    }
    set(m_values[0]/mag,m_values[1]/mag,m_values[2]/mag);

}
template<typename T>
void Vector3<T>::incrementX(const T &dx)
{
    this->m_values[0]+=dx;
}
template<typename T>
void Vector3<T>::incrementY(const T &dy)
{
    this->m_values[1]+=dy;
}
template<typename T>
void Vector3<T>::incrementZ(const T &dz)
{
    this->m_values[2]+=dz;
}
template<typename T>
void Vector3<T>::increment(const T &dx, const T &dy, const T &dz)
{
    this->m_values[0]+=dx;
    this->m_values[1]+=dy;
    this->m_values[2]+=dz;
}
template<typename T>
T Vector3<T>::getAngle(const Vector3<T>&point)
{
    T deltaY = point.getY() - m_values[1];
    T deltaX = point.getX() - m_values[0];
    return std::atan2(deltaY,deltaX) * 180/3.14;
}
template<typename T>
Vector3<T> Vector3<T>::getNormalized()
{
    const T mag=std::abs(this->getMagnitude());
    if (mag==0)
    {
        return Vector3();
    }
    return Vector3(m_values[0]/mag,m_values[1]/mag,m_values[2]/mag);
}

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
typedef Vector3<int> Vector3i;

}}} //namespace
