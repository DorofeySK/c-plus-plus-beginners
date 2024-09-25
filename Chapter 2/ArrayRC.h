#ifndef ArrayRC_H
#define ArrayRC_H
#include "Array.h"
#include <cassert>

template <class elemType>
class ArrayRC : public Array<elemType> {
private:
    void check_range(int index) const;
public:
    ArrayRC(int arr_size = DefaultArraySize);
    ArrayRC(const elemType *arr, int arr_size);
    ArrayRC(const ArrayRC& source);

    virtual elemType& operator[] (int index) const;
};

template <class elemType>
ArrayRC<elemType>::ArrayRC(int arr_size) : Array<elemType>(arr_size) {

}

template <class elemType>
ArrayRC<elemType>::ArrayRC(const elemType *arr, int arr_size) : Array<elemType>(arr, arr_size) {

}

template <class elemType>
elemType& ArrayRC<elemType>::operator[] (int index) const {
    check_range(index);
    return arr[index];
}

template <class elemType>
inline void ArrayRC<elemType>::check_range(int index) const {
    assert(index >= 0 && index < _size);
}
#endif