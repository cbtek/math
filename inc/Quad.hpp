#pragma once
#include "MathUtils.h"
#include "utility/inc/ObjectList.hpp"

#include <string>

namespace cbtek {
namespace common {
namespace math{
template <typename T>
class Quad
{
public:

    /**
     * @brief Quad
     * @param x
     * @param y
     * @param w
     * @param h
     */
    Quad(const T & x=0, const T & y=0, const T & w=0, const T & h=0);

    /**
     * @brief getX
     * @return
     */
    T getX()const;

    /**
     * @brief getY
     * @return
     */
    T getY()const;

    /**
     * @brief getMaxX
     * @return
     */
    T getMaxX() const;

    /**
     * @brief getMaxY
     * @return
     */
    T getMaxY() const;

    /**
     * @brief getCenterX
     * @return
     */
    T getCenterX() const;

    /**
     * @brief getCenterY
     * @return
     */
    T getCenterY() const;

    /**
     * @brief setX
     * @param x
     */
    void setX(const T & x);

    /**
     * @brief setY
     * @param y
     */
    void setY(const T & y);

    /**
     * @brief translate
     * @param angle
     * @param radius
     * @param velX
     * @param velY
     */
    void translate(const T &angle, const T &radius, const T &velX=0, const T &velY=0);

    /**
     * @brief getW
     * @return
     */
    T getW()const;

    /**
     * @brief getH
     * @return
     */
    T getH()const;

    /**
     * @brief setW
     * @param w
     */
    void setW(const T & w);

    /**
     * @brief setH
     * @param h
     */
    void setH(const T & h);

    /**
     * @brief incrementX
     * @param dx
     */
    void incrementX(const T & dx);

    /**
     * @brief incrementY
     * @param dy
     */
    void incrementY(const T & dy);

    /**
     * @brief incrementW
     * @param dw
     */
    void incrementW(const T & dw);

    /**
     * @brief incrementH
     * @param dh
     */
    void incrementH(const T & dh);

    /**
     * @brief set
     * @param x
     * @param y
     * @param w
     * @param h
     */
    void set(const T & x, const T & y, const T & w, const T & h);

    /**
     * @brief intersects
     * @param quad
     * @return
     */
    bool intersects(const Quad<T>& quad);


    /**
     * @brief contains
     * @param x
     * @param y
     * @return
     */
    bool contains(const T & x, const T & y) const;

    /**
     * @brief contains
     * @param q
     * @return
     */
    bool contains(const Quad & q) const;

    /**
     * @brief setSize
     * @param w
     * @param h
     */
    void setSize(const T & w, const T & h);

    /**
     * @brief setPosition
     * @param x
     * @param y
     */
    void setPosition(const T & x, const T & y);

    /**
     * @brief moveCenterTo
     * @param x
     * @param y
     */
    void moveCenterTo(const T & x, const T & y);

    /**
     * @brief scaleW
     * @param factor
     */
    void scaleW(T factor);

    /**
     * @brief scaleH
     * @param factor
     */
    void scaleH(T factor);

    /**
     * @brief toString
     * @return
     */
    std::string toString();

    /**
     * @brief shrink
     * @param dx
     */
    void shrink(const T &dx);

    /**
     * @brief grow
     * @param dx
     */
    void grow(const T &dx);
	
    /**
     * @brief getQuadrent1
     * @return
     */
    Quad<T> getQuadrent1() const;

    /**
     * @brief getQuadrent2
     * @return
     */
    Quad<T> getQuadrent2() const;

    /**
     * @brief getQuadrent3
     * @return
     */
    Quad<T> getQuadrent3() const;

    /**
     * @brief getQuadrent4
     * @return
     */
    Quad<T> getQuadrent4() const;

    /**
     * @brief resize
     * @param w
     * @param h
     */
	void resize(T w, T h);
	
    /**
     * @brief setBottomY
     * @param y
     */
	void setBottomY(T y);
	
    /**
     * @brief setRightX
     * @param x
     */
	void setRightX(T x);
	
    /**
     * @brief getBottomY
     * @return
     */
	T getBottomY() const;
	
    /**
     * @brief getRightX
     * @return
     */
	T getRightX() const;
	
    /**
     * @brief alignHCenter Aligns quad to horizontal center
     * @param totalAreaWidth Total Width of area to align quad in
     */
    Quad<T>& alignHCenter(T totalAreaWidth);

    /**
     * @brief alignVCenter Aligns quad to vertical center
     * @param totalAreaHeight Total height of area to align quad in
     */
    Quad<T>& alignVCenter(T totalAreaHeight);


    /**
     * @brief alignLeft Aligns quad to left
     */
    Quad<T>& alignLeft();

    /**
     * @brief alignRight Aligns quad to right
     * @param totalAreaWidth Total Width of area to align quad in
     */
    Quad<T>& alignRight(T totalAreaWidth);

    /**
     * @brief alignTop Aligns quad to top
     */
    Quad<T>& alignTop();

    /**
     * @brief alignBottom Aligns quad to bottom
     * @param totalAreaHeight Total height of area to align quad in
     */
    Quad<T>& alignBottom(T totalAreaHeight);

private:

    T m_x,m_y,m_w,m_h;

};

template<class T>
void Quad<T>::setBottomY(T y)
{
	m_y = y-m_h;
}
	
template<class T>
void Quad<T>::setRightX(T x)
{
	m_x = x-m_w;
}

template<class T>
T Quad<T>::getBottomY() const
{
	return m_y+m_h;
}

template<class T>
T Quad<T>::getRightX() const
{
	return m_x+m_w;
}

template<class T>
void Quad<T>::resize(T w, T h)
{
		m_w=w;
		m_h=h;
}

template<class T>
Quad<T>::Quad(const T &x, const T &y, const T &w, const T &h)
{
    set(x,y,w,h);
}

template<class T>
T Quad<T>::getX()const{return m_x;}

template<class T>
T Quad<T>::getY()const{return m_y;}

template<class T>
T Quad<T>::getMaxX() const
{
    return m_x+m_w;
}

template<class T>
T Quad<T>::getMaxY() const
{
    return m_y+m_h;
}

template<class T>
T Quad<T>::getCenterX() const
{
    return m_x+(.5*m_w);
}

template<class T>
T Quad<T>::getCenterY() const
{
    return m_y+(.5*m_h);
}

template<class T>
void Quad<T>::setX(const T & x){m_x=x;}

template<class T>
void Quad<T>::setY(const T & y){m_y=y;}

template<class T>
void Quad<T>::translate(const T &angle, const T &radius, const T &velX, const T &velY)
{
    T degree=MathUtils::getNormalizedDegree(angle);
    m_x+=((static_cast<double>(velX)+(static_cast<double>(MathUtils::cosd(degree)) * static_cast<double>(radius))));
    m_y+=((static_cast<double>(velY)+(static_cast<double>(MathUtils::sind(degree)) * static_cast<double>(radius))));
}

template<class T>
T Quad<T>::getW()const{return m_w;}

template<class T>
T Quad<T>::getH()const{return m_h;}

template<class T>
void Quad<T>::setW(const T & w){m_w=w;}

template<class T>
void Quad<T>::setH(const T & h){m_h=h;}

template<class T>
void Quad<T>::incrementX(const T &dx)
{
    m_x+=dx;
}

template<class T>
void Quad<T>::incrementY(const T &dy)
{
    m_y+=dy;
}

template<class T>
void Quad<T>::incrementW(const T &dw)
{
    m_w+=dw;
}

template<class T>
void Quad<T>::incrementH(const T &dh)
{
    m_h+=dh;
}

template<class T>
void Quad<T>::set(const T & x, const T & y, const T & w, const T & h)
{
    m_x=x;
    m_y=y;
    m_w=w;
    m_h=h;
}

template<typename T>
bool Quad<T>::intersects(const Quad<T> &quad)
{
    if (this == &quad)
    {
        return false;
    }

    return this->contains(quad.getX(), quad.getY()) ||
            this->contains(quad.getX() + quad.getW(), quad.getY())||
            this->contains(quad.getX() + quad.getW(), quad.getY() + quad.getH())||
            this->contains(quad.getX(), quad.getY() + quad.getH());
}

template<class T>
bool Quad<T>::contains(const T &x, const T &y) const
{
    return ((x>=m_x && x<=(m_x+m_w)) && (y>=m_y && y<=(m_y+m_h)));
}

template<class T>
bool Quad<T>::contains(const Quad &q) const
{
    return contains(q.getX(),q.getY()) ||
           contains(q.getMaxX(),q.getMaxY()) ||
           contains(q.getX(),q.getMaxY()) ||
           contains(q.getMaxX(),q.getY());
}

template<class T>
void Quad<T>::moveCenterTo(const T & x, const T & y)
{
    setX(x-(m_w/2));
    setY(y-(m_h/2));
}

template<typename T>
void Quad<T>::scaleH(T factor)
{
    m_h *= factor;
}

template<typename T>
void Quad<T>::scaleW(T factor)
{
    m_w *= factor;
}

template<class T>
std::string Quad<T>::toString()
{
    std::ostringstream out;
    out <<"("<< m_x<<", "<<m_y<<") : ("<<m_w<<", "<<m_h<<")";
    return out.str();
}
template<class T>
void Quad<T>::shrink(const T &dx)
{
    m_w-=dx;
    m_h-=dx;
    m_x+=dx;
    m_y+=dx;
}

template<class T>
void Quad<T>::grow(const T &dx)
{
    m_w+=(dx+dx);
    m_h+=(dx+dx);
    m_x-=dx;
    m_y-=dx;
}

template<class T>
void Quad<T>::setSize(const T &w, const T &h)
{
    m_w=w;
    m_h=h;
}

template<class T>
void Quad<T>::setPosition(const T &x, const T &y)
{
    m_x=x;
    m_y=y;
}
template<class T>
Quad<T> Quad<T>::getQuadrent1() const
{
    Quad<T> q;
    q.set(this->getCenterX(),this->getY(),this->getW()/2,this->getH()/2);
    return q;

}

template<class T>
Quad<T> Quad<T>::getQuadrent2() const
{
    Quad<T> q;
    q.set(this->getX(),this->getY(),this->getW()/2,this->getH()/2);
    return q;
}

template<class T>
Quad<T> Quad<T>::getQuadrent3() const
{
    Quad<T> q;
    q.set(this->getX(),this->getCenterY(),this->getW()/2,this->getH()/2);
    return q;
}

template<class T>
Quad<T> Quad<T>::getQuadrent4() const
{
    Quad<T> q;
    q.set(this->getCenterX(),this->getCenterY(),this->getW()/2,this->getH()/2);
    return q;
}


template<class T>
Quad<T>& Quad<T>::alignHCenter(T totalAreaWidth)
{
    T halfW = getW() / 2;
    T halfArea = totalAreaWidth / 2;
    if (halfW > halfArea)
    {
        setX(halfW - halfArea);
    }
    else
    {
        setX(halfArea - halfW);
    }
    return (*this);
}

template<class T>
Quad<T>& Quad<T>::alignVCenter(T totalAreaHeight)
{
    T halfH = getH() / 2;
    T halfArea = totalAreaHeight / 2;
    if (halfH > halfArea)
    {
        setY(halfH - halfArea);
    }
    else
    {
        setY(halfArea - halfH);
    }
    return (*this);
}


template<class T>
Quad<T>& Quad<T>::alignLeft()
{
    setX(0);
    return (*this);
}

template<class T>
Quad<T>& Quad<T>::alignRight(T totalAreaWidth)
{
   setX(totalAreaWidth - getW());
   return (*this);
}

template<class T>
Quad<T>& Quad<T>::alignTop()
{
    setY(0);
    return (*this);
}

template<class T>
Quad<T>& Quad<T>::alignBottom(T totalAreaHeight)
{
    setY(totalAreaHeight - getH());
    return (*this);
}

typedef Quad<double> Quad2d;
typedef Quad<float> Quad2f;
typedef Quad<int> Quad2i;

typedef common::utility::ObjectList<Quad2d> Quad2dList;
typedef common::utility::ObjectList<Quad2f> Quad2fList;
typedef common::utility::ObjectList<Quad2i> Quad2iList;
}}} //namespace
