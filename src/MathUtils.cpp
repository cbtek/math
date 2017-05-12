#include "MathUtils.h"
#include <math/Point.h>

using namespace common::utility::math;

namespace common{
namespace utility{
namespace math{

Vector3f MathUtils::lerp(Vector3f start, Vector3f end, double percent)
{
    float floatPercent = (float)percent/100.0f;
    return (start + ((Vector3f(end - start))) * floatPercent);
}

Vector3f MathUtils::nlerp(Vector3f start, Vector3f end, double percent)
{
    return lerp(start,end,percent).getNormalized();
}

bool MathUtils::compare(const double &val1, const double &val2, const double &closeness)
{
    return (std::fabs(val1-val2)< closeness);
}

Point2f MathUtils::midpoint2d(const Point2f &pt1, const Point2f &pt2)
{
    Point2f point;
    double outX,outY;
    midpoint2d(pt1.getX(),pt1.getY(),pt2.getX(),pt2.getY(),outX,outY);
    point.set(outX,outY);
    return point;
}

void MathUtils::midpoint2d(double x1, double y1, double x2, double y2, double &outX, double &outY)
{
    outX = (x1+x2)/2;
    outY = (y1+y2)/2;
}

double MathUtils::clip(float n, float lower, float upper)
{
  return std::max(lower, std::min(n, upper));
}

Vector3f MathUtils::slerp(Vector3f start, Vector3f end, double percent)
{
    float floatPercent = (float)percent/100.0f;
    float dot = start.getDotProduct(end);
    MathUtils::clip(dot,-1.0f,1.0f);
    float theta = std::acos(dot)*floatPercent;
    Vector3f relativeVec = end - start * dot;
    relativeVec.normalize();
    return ((start*std::cos(theta)) + (relativeVec*std::sin(theta)));
}

Vector3f MathUtils::getSurfaceNormal(const Vector3f &v1, const Vector3f &v2)
{
            return Vector3f((v1.getY()*v2.getZ()) - (v1.getZ()*v2.getY()),
                    (v1.getZ()*v2.getX()) - (v1.getX()*v2.getZ()),
                    (v1.getX()*v2.getY()) - (v1.getY()*v2.getX())
                    );
}

std::int32_t MathUtils::getNormalizedDegree(const std::int32_t &degree)
{
    if (degree>359)
    {
        return degree-360;
    }
    else if (degree<0)
    {
        return 360+degree;
    }
    else return degree;

}


double MathUtils::translateX(double degree,double radius, double xOffset)
{
	return xOffset+(cosd(degree) * radius);
}

double MathUtils::translateY(double degree,double radius, double yOffset)
{
	return yOffset+(sind(degree) * radius);
}

bool MathUtils::pointExistsInTriangle2i(const std::int32_t &srcX, const std::int32_t &srcY, const std::int32_t &x1, const std::int32_t &y1, const std::int32_t &x2, const std::int32_t &y2, const std::int32_t &x3, const std::int32_t &y3)
{
        int as_x = srcX-x1;
        int as_y = srcY-y1;
        bool s_ab = (x2-x1)*as_y-(y2-y1)*as_x > 0;
        if((x3-x1)*as_y-(y3-y1)*as_x > 0 == s_ab) return false;
        if((x3-x2)*(srcY-y2)-(y3-y2)*(srcX-x2) > 0 != s_ab) return false;
        return true;
}

double MathUtils::sind(const std::int32_t &degree)
{
   int rangle=MathUtils::getNormalizedDegree(degree);
   return rangle<360?constants::SIN_TABLE[rangle]:0.0;
}

double MathUtils::cosd(const std::int32_t &degree)
{
    int rangle=MathUtils::getNormalizedDegree(degree);
    return rangle<360?constants::COS_TABLE[rangle]:0.0;
}

double MathUtils::tand(const std::int32_t &degree)
{
    int rangle=MathUtils::getNormalizedDegree(degree);
    return rangle<360?constants::TAN_TABLE[rangle]:0.0;

}

MathUtils::MathUtils()
{
}

double MathUtils::toDegree(const double &radian)
{
    return radian*57.2957795131;
}

double MathUtils::toRadian(const double &degree)
{
    return degree*0.0174532925;
}

double MathUtils::PI()
{
    return 3.14159265359;
}

double MathUtils::PI_OVER_180()
{
    return 0.01745329251;
}

double MathUtils::distance(const double &x1, const double &y1, const double &x2, const double &y2)
{
    return std::sqrt(std::pow(x1-x2,2) + std::pow(y1-y2,2));
}

double MathUtils::distance(const double &x1, const double &y1, const double &z1, const double &x2, const double &y2, const double &z2)
{
    return std::sqrt(std::pow(x1-x2,2) + std::pow(y1-y2,2)+std::pow(z1-z2,2));
}

bool MathUtils::isPointInTriangle(double px, double py, double pz,
                                  double tp1x, double tp1y, double tp1z,
                                  double tp2x, double tp2y, double tp2z,
                                  double tp3x, double tp3y, double tp3z)
{
    Vector3f A,B,C,P;
    A.set(tp1x,tp1y,tp1z);
    B.set(tp2x,tp2y,tp2z);
    C.set(tp3x,tp3y,tp3z);
    P.set(px,py,pz);
    return isPointInTriangle(P,A,B,C);
}

bool MathUtils::isPointInTriangle(const Vector3f &point, const Vector3f &trianglePointA, const Vector3f &trianglePointB, const Vector3f &trianglePointC)
{

    Vector3f P=point;
    Vector3f A=trianglePointA;
    Vector3f B=trianglePointB;
    Vector3f C=trianglePointC;

    // Compute vectors
    Vector3f v0 = C - A;
    Vector3f v1 = B - A;
    Vector3f v2 = P - A;

    // Compute dot products
    double dot00 = (v0.getDotProduct(v0));
    double dot01 = (v0.getDotProduct(v1));
    double dot02 = (v0.getDotProduct(v2));
    double dot11 = (v1.getDotProduct(v1));
    double dot12 = (v1.getDotProduct(v2));

    // Compute barycentric coordinates
    double invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    return ((u >= 0) && (v >= 0) && (u + v < 1));
}

size_t MathUtils::getQuadrent(const double &degree)
{
    if (degree>=0 && degree<=90)
    {
        return 0;
    }
    else if (degree>90 && degree<=180)
    {
        return 1;
    }
    else if (degree>180 && degree<=270)
    {
        return 2;
    }
    else return 3;

}

size_t MathUtils::getQuadrent(double x, double y,double originX, double originY)
{
    if (x > originX && y > originX)return 0;
    else if (x < originX && y > originX)return 1;
    else if (x < originX && y < originX)return 2;
    else if (x > originX && y < originX)return 3;
    else return 0;
}

int64_t MathUtils::roundUp(int64_t numToRound, int64_t multiple)
{
     if(multiple == 0)
     {
      return numToRound;
     }

     int64_t remainder = numToRound % multiple;
     if (remainder == 0)
      return numToRound;
     return numToRound + multiple - remainder;
}

double MathUtils::sinr(const double &radian)
{
    return std::sin(radian);
}

double MathUtils::cosr(const double &radian)
{
    return std::cos(radian);
}

double MathUtils::tanr(const double &radian)
{
    return std::tan(radian);
}

double MathUtils::PI_TIMES_2()
{
    return 6.28318530718;
}

double MathUtils::PI_OVER_2()
{
    return 1.57079632679;
}

Point<float> MathUtils::rotate2d(const double &x, const double &y, const double & ox, const double & oy, const int &angle)
{
    double rangle=toRadian(angle);
    return Point<float>(std::cos(rangle) * (x-ox) - std::sin(rangle) * (y-oy) + ox,std::sin(rangle) * (x-ox) + std::cos(rangle) * (y-oy) + oy);
}

double MathUtils::getAngle(const double &x1, const double &y1, const double &x2, const double &y2)
{

    double deltaY = -(y2 - y1);
    double deltaX = -(x2 - x1);
    return getNormalizedDegree(toDegree(std::atan2(deltaY, deltaX)));

//    double dx = x - (width/2);
//    // Minus to correct for coord re-mapping
//    double dy = -(y - (height/2));
//    double inRads = std::atan2(dy,dx);
//    // We need to map to coord system when 0 degree is at 3 O'clock, 270 at 12 O'clock
//    inRads= inRads<0?std::fabs(inRads):2*MathUtils::PI() - inRads;

}

double MathUtils::getUpdatedAngle(const double &currentAngle, const double &desiredAngle, const double &step)
{
    int currentQuadrent=getQuadrent(currentAngle);
    int desiredQuadrent=getQuadrent(desiredAngle);

    if (currentQuadrent==desiredQuadrent)
    {
        if (desiredAngle>currentAngle)
        {
            return MathUtils::getNormalizedDegree(currentAngle+step);
        }
        else
        {
            return MathUtils::getNormalizedDegree(currentAngle-step);
        }
    }

}

}}} //namespace
