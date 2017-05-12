#ifndef NGON_H
#define NGON_H
#include <math/SimplePolygon.h>
#include <Exception.h>

#include <vector>

namespace common{
namespace utility{
namespace math{

CREATE_EXCEPTION(VertexOutOfBoundsException, "Vertex index is out of bounds")

class Ngon : public SimplePolygon
{
public:
    Ngon();

    const common::utility::math::Vector3f & vertex(const size_t & index);

    const size_t vertexCount();

    void addVertex(const common::utility::math::Vector3f & vertex);

    void setVertex(const size_t & index, const common::utility::math::Vector3f & vertex);

    const bool contains(const common::utility::math::Vector3f & point);
private:
    typedef std::vector<Vector3f> VertexVector;
     VertexVector m_vertices;
};
}}} //namespace
#endif // NGON_H
