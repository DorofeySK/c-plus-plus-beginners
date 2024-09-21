#include "IntArray.h"

void IntArray::init(const int *arr, int arr_size) {
    _size = arr_size;
    this->arr = new int[_size];
    for (int index = 0; index < _size; index++) {
        if (!arr) {
            this->arr[index] = 0;
        } else {
            this->arr[index] = arr[index];
        }
    }
}

IntArray::IntArray (int arr_size) {
    init(0, arr_size);
}

IntArray::IntArray(const int *arr, int arr_size) {
    init(arr, arr_size);
}

IntArray::IntArray(const IntArray &source) {
    init(source.arr, source._size);
}

void IntArray::sort() {

}

int IntArray::max() const {
    return 0;
}

int IntArray::min() const {
    return 0;
}

int IntArray::find(int value) const {
    return 0;
}
