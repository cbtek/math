#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H

#include "math/Vector3.h>


namespace cbtek {
namespace common {
namespace math{


class SimplePolygon
{
public:
    virtual const Vector3f & vertex(const size_t & index)=0;

    virtual const size_t vertexCount()=0;

    virtual void addVertex(const Vector3f & vertex)=0;

    virtual void setVertex(const size_t & index, const Vector3f & vertex)=0;

    virtual const bool contains(const Vector3f & point)=0;

};
}}} //namespace
#endif // POLYGON_H
