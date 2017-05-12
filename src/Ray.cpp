#include "Ray.h"
namespace common{
namespace utility{
namespace math{

Ray::Ray()
{
}

void Ray::setDirection(const common::utility::math::Vector3f &direction)
{
    m_direction=direction;
}

void Ray::setOrigin(const common::utility::math::Vector3f &origin)
{
    m_origin=origin;
}

const common::utility::math::Vector3f &Ray::getOrigin() const
{
    return m_origin;
}

const common::utility::math::Vector3f &Ray::getDirection() const
{
    return m_direction;
}
}}} //namespace
