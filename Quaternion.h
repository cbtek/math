#ifndef QUATERNION_H
#define QUATERNION_H

#include<string>
#include "math/Vector3.h>
#include "math/Matrix.h>

namespace cbtek {
namespace common {
namespace math{


class Quaternion
{
public:

    Quaternion();
    Quaternion(const float & x, const float & y, const float & z, const float & w);
    Quaternion(const Vector3f & vec);
    Quaternion(const Vector3f & axis, const float & radians);

    Quaternion(const Quaternion & quat);
    Quaternion(const Matrix & matrix);
    Quaternion(const float & axisAngleX, const float & axisAngleY, const float & axisAngleZ);
    Quaternion & operator=(const Quaternion & quat);

    void set(const float & x, const float & y, const float & z,const float & w);
    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;
    void setVector(const Vector3f & vec);
    Vector3f getVector() const;
    void setX(const float &x);
    void setY(const float &y);
    void setZ(const float &z);
    void setW(const float &w);

    Quaternion operator+(const Quaternion & quat);
    Quaternion operator-(const Quaternion & quat);
    Quaternion operator*(const float & scalar);
    Quaternion operator*(const Quaternion & quat);
    Vector3f operator*(const Vector3f & vec);
    Quaternion operator/(const Quaternion & quat);
    Quaternion getConjugate();
    Quaternion getNormalized();
    void toAxisAngle(Vector3f & axis, float & radians);
    void setAsIdentity();
    void normalize();



    Vector3f getRotatedVector(const Vector3f & vec);
    float * array();
    std::string toString();
    float getXRotation(); //pitch
    float getYRotation(); //yaw
    float getZRotation(); //roll

private:
    float m_values[4];
};
}}} //namespace
#endif // QUATERNION_H
