#include "customarray.cpp"

IntArray::IntArray (int sz) {
    _size = sz;
    arr = new int[_size];
    for (int index = 0; index < _size; index++) {
        arr[index] = 0;
    }
}

IntArray::IntArray(int *arr, int array_size) {
    _size = array_size;
    this->arr = new int[_size];
    for (int index = 0; index < _size; index++) {
        this->arr[index] = arr[index];
    }    
}

