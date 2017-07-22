#pragma once

#include "math/inc/Vector3.hpp"

namespace cbtek {
namespace common {
namespace math{

class Motion3f : public Vector3f
{
public:

    Motion3f(const float & x=0, const float & y=0, const float & z=0);

    void setVelocity(const Vector3f & velocity);

    const Vector3f & getVelocity() const;

    void setSpeed(const float & speed);

    const float getSpeed() const;

private:

    Vector3f m_velocity;

    float m_speed;
};
}}} //namespace
