#pragma once

#include "math/inc/Line.h"
#include "math/inc/Point.h"
#include "math/inc/Quad.h"
#include "math/inc/MathUtils.h"

#include <iostream>

namespace cbtek {
namespace common {
namespace math {

class Hexagon
{
public:
    /**
     * @brief Hexagon
     * @param x
     * @param y
     * @param width
     * @param height
     */
    Hexagon(const int & x=0, const int & y=0, const int & width=4 , const int & height=4);

    /**
     * @brief getSide
     * @param index
     * @return
     */
    const Line2i * getSide(const int &index) const;

    /**
     * @brief x
     * @return
     */
    int x() const;

    /**
     * @brief y
     * @return
     */
    int y() const;

    /**
     * @brief w
     * @return
     */
    int w() const;

    /**
     * @brief h
     * @return
     */
    int h() const;

    /**
     * @brief move
     * @param x
     * @param y
     */
    void move(const int & x, const int & y);

    /**
     * @brief resize
     * @param w
     * @param h
     */
    void resize(const int & w, const int & h);

    /**
     * @brief setBounds
     * @param x
     * @param y
     * @param w
     * @param h
     */
    void setBounds(const int & x, const int & y,const int & w, const int & h);

    /**
     * @brief contains
     * @param x
     * @param y
     * @return
     */
    bool contains(const int & x, const int & y) const;

    /**
     * @brief intersects
     * @param x
     * @param y
     * @return
     */
    bool intersects(const int & x, const int & y) const;

private:
    void update();
    Line2i m_sides[6];
    Quad<std::int64_t> m_quad;
};
}}} //namespace
