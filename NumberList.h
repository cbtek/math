#ifndef ObjectList_H
#define ObjectList_H

#include <vector>
namespace cbtek {
namespace common {
namespace math{


template<class T>
class ObjectList:public std::vector<T>
{
public:
    ObjectList & operator<<(const T &value);
    T * array();
private:


};

template <class T>
ObjectList<T> & ObjectList<T>::operator<<(const T & value)
{
    this->push_back(value);
    return *this;
}


template <class T>
T *ObjectList<T>::array()
{
    return &this->operator [](0);
}

}}} //namespace
#endif // ObjectList_H
