#pragma once

#include "math/inc/Hexagon.h"
#include <cstdlib>

namespace cbtek {
namespace common {
namespace math {


class HexagonGrid
{
public:
    HexagonGrid();
    HexagonGrid(const int &rows, const int & columns,const int & width=4, const int & height=4);
    void initialize(const int &rows, const int & columns,const int & width=4, const int & height=4);
    const Hexagon * getHexagon(const size_t & index);
    const Hexagon * getHexagon(const size_t & row,const size_t & column);
    size_t getCount() const;
    size_t rowCount() const;
    size_t columnCount() const;

private:
    size_t m_count,m_rowCount,m_colCount;
    Hexagon * m_grid;
};
}}} //namespace
