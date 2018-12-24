#ifndef RAY_H
#define RAY_H

#include "math/Vector3.h>
namespace cbtek {
namespace common {
namespace math{

class Ray
{

public:

    Ray();

    void setDirection(const Vector3f & origin);

    void setOrigin(const Vector3f & origin);

    const Vector3f & getOrigin() const;

    const Vector3f & getDirection() const;

private:

    Vector3f m_origin;

    Vector3f m_direction;
};
}}} //namespace
#endif // RAY_H
