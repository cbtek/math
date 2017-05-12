#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H

#include <math/Vector3.h>


namespace common{
namespace utility{
namespace math{


class SimplePolygon
{
public:
    virtual const common::utility::math::Vector3f & vertex(const size_t & index)=0;

    virtual const size_t vertexCount()=0;

    virtual void addVertex(const common::utility::math::Vector3f & vertex)=0;

    virtual void setVertex(const size_t & index, const common::utility::math::Vector3f & vertex)=0;

    virtual const bool contains(const common::utility::math::Vector3f & point)=0;

};
}}} //namespace
#endif // POLYGON_H
