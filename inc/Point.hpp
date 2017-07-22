#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream>
#include <cmath>

#include "utility/inc/ObjectList.hpp"

namespace cbtek {
namespace common {
namespace math{
template <typename T>
class Point
{
public:

    Point(T x=0, T y=0);

    void set(T x, T y);

    void setPosition(T x, T y);

    T getX() const;

    T getY() const;

    void setX(T x);

    void setY(T y);

    const std::string toString();

    void rotate(T degree, T originX = 0, T originY = 0);

    void move(T angle, T radius, T velX=0,T velY=0);

    void incrementX(T dx);

    void incrementY(T dy);
private:

    T m_x,m_y;

private:

};

template <typename T>
Point<T>::Point(T x, T y)
{
    this->m_x=x;this->m_y=y;
}

template <typename T>
void Point<T>::set(T x, T y)
{
    this->m_x=x;this->m_y=y;
}

template<typename T>
void Point<T>::setPosition(T x, T y)
{
    this->m_x = x;
    this->m_y = y;
}

template <typename T>
T Point<T>::getX() const
{
    return this->m_x;
}

template <typename T>
T Point<T>::getY() const
{
    return this->m_y;
}

template <typename T>
void Point<T>::setX(T x)
{
    this->m_x=x;
}

template <typename T>
void Point<T>::setY(T y)
{
    this->m_y=y;
}

template <typename T>
const std::string Point<T>::toString()
{
    std::ostringstream out;
    out << this->m_x<<" "<<this->m_y;
    return out.str();
}

template <typename T>
void Point<T>::rotate(T degree,T originX,T originY)
{
    if (degree<360)
    {
        double x=this->m_x,y=this->m_y,ox=originX,oy=originY;
        double radian=degree*0.0174532925;
        double cosValue=std::cos(radian);
        double sinValue=std::sin(radian);
        m_x = (cosValue * (x-ox)) - (sinValue*(y-oy)) + ox;
        m_y = (cosValue * (x-ox)) + (sinValue*(y-oy)) + oy;
    }
}

template <typename T>
void Point<T>::move(T angle, T radius, T velX, T velY)
{
    T degree=angle;
    if (angle>360)
    {
        degree=angle-360;
    }
    else if (angle<0)
    {
        degree= 360+angle;
    }

    double radian=(double)degree*0.0174532925;
    double cosValue=std::cos(radian);
    double sinValue=std::sin(radian);
    m_x+=((velX)+(cosValue * radius));
    m_y+=((velY)+(sinValue * radius));
}

template <typename T>
void Point<T>::incrementX(T dx)
{
    m_x+=dx;
}

template <typename T>
void Point<T>::incrementY(T dy)
{
    m_y+=dy;
}

typedef Point<float> Point2f;
typedef Point<int> Point2i;

typedef common::utility::ObjectList<Point2f> Point2fList;
typedef common::utility::ObjectList<Point2i> Point2iList;
}}} //namespace
#endif // Point<float>_H
