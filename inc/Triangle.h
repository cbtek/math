#ifndef CAUMDM_TRIANGLE_H
#define CAUMDM_TRIANGLE_H

#include <math/Vector3.h>
#include <math/MathUtils.h>

namespace common{
namespace utility{
namespace math{


class Triangle
{
public:
    Triangle(const Vector3f & a=Vector3f(),
             const Vector3f & b=Vector3f(),
             const Vector3f & c=Vector3f());

     Vector3f getPointA() const;

     Vector3f getPointB() const;

     Vector3f getPointC() const;

     void setPointA(const Vector3f & pt);

     void setPointB(const Vector3f & pt);

     void setPointC(const Vector3f & pt);

     bool contains(const Vector3f & point) const;

private:
    Vector3f m_a,m_b,m_c;
};

}}} //namespace
#endif // TRIANGLE_H
