#include "Ray.h"
namespace cbtek {
namespace common {
namespace math{

Ray::Ray()
{
}

void Ray::setDirection(const Vector3f &direction)
{
    m_direction=direction;
}

void Ray::setOrigin(const Vector3f &origin)
{
    m_origin=origin;
}

const Vector3f &Ray::getOrigin() const
{
    return m_origin;
}

const Vector3f &Ray::getDirection() const
{
    return m_direction;
}
}}} //namespace
