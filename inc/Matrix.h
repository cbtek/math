#pragma once

#include <cstdlib>
#include <string>
#include <cmath>

#include "utility/inc/ObjectList.hpp"
#include "math/inc/Grid.hpp"
#include "math/inc/Vector3.hpp"

namespace cbtek {
namespace common {
namespace math{

class Matrix
{
public:

    Matrix();
    Matrix(size_t rows, size_t columns);
    Matrix(const Matrix & matrix);
    Matrix(const Vector3f & vector, const size_t defaultRowSize=3);
    Matrix(size_t rows, size_t columns, const common::utility::Float64List & values);
    Matrix & operator=(const Matrix & matrix);
    Matrix operator+(const Matrix & matrix);
    Matrix operator-(const Matrix & matrix);
    Matrix operator*(const float & scalar);
    Matrix operator*(const Matrix & scalar);
    Vector3f operator*(const Vector3f & vec);
    Matrix & operator<<(const float & value);


    float getDeterminate();
    float getInverse();
    Matrix getTransposed();
    float getValue(const size_t & rowIndex, const size_t & columnIndex)const;
    void setValue(const size_t & rowIndex, const size_t & columnIndex, const float & value);
    void setValues(const common::utility::Float64List& values);
    void initialize(const size_t &rows, const size_t &columns, const float &value=0.0f);
    size_t size()const;
    size_t rows()const;
    size_t columns()const;
    bool isValid()const;
    std::string toString();
    void setAsIdentity();
    common::utility::Float64List getValues() const;
    const float *array() const;
protected:
    common::utility::Grid<float> m_cells;
};
}}} //namespace
