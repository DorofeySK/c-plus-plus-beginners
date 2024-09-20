#ifndef IntArrayRC_H
#define IntArrayRC_H
#include "IntArray.h"

class IntArrayRC : public IntArray {
private:
    void check_range(int index) const;
public:
    IntArrayRC(int arr_size = DefaultArraySize);
    IntArrayRC(const int *arr, int arr_size);
    IntArrayRC(const IntArray &source);

    virtual int& operator[] (int index) const;
};
#endif