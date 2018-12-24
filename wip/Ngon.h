#ifndef NGON_H
#define NGON_H
#include "math/SimplePolygon.h>
#include <Exception.h>

#include <vector>

namespace cbtek {
namespace common {
namespace math{

CREATE_EXCEPTION(VertexOutOfBoundsException, "Vertex index is out of bounds")

class Ngon : public SimplePolygon
{
public:
    Ngon();

    const Vector3f & vertex(const size_t & index);

    const size_t vertexCount();

    void addVertex(const Vector3f & vertex);

    void setVertex(const size_t & index, const Vector3f & vertex);

    const bool contains(const Vector3f & point);
private:
    typedef std::vector<Vector3f> VertexVector;
     VertexVector m_vertices;
};
}}} //namespace
#endif // NGON_H
