#include "IntArrayRC.h"
#include <cassert>

IntArrayRC::IntArrayRC(int arr_size) : IntArray(arr_size) {

}

IntArrayRC::IntArrayRC(const int *arr, int arr_size) : IntArray(arr, arr_size) {

}

int& IntArrayRC::operator[] (int index) const {
    check_range(index);
    return arr[index];
}

inline void IntArrayRC::check_range(int index) const {
    assert(index >= 0 && index < _size);
}