#ifndef RAY_H
#define RAY_H

#include <math/Vector3.h>
namespace common{
namespace utility{
namespace math{

class Ray
{

public:

    Ray();

    void setDirection(const common::utility::math::Vector3f & origin);

    void setOrigin(const common::utility::math::Vector3f & origin);

    const common::utility::math::Vector3f & getOrigin() const;

    const common::utility::math::Vector3f & getDirection() const;

private:

    common::utility::math::Vector3f m_origin;

    common::utility::math::Vector3f m_direction;
};
}}} //namespace
#endif // RAY_H
