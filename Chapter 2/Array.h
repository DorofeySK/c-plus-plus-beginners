#ifndef Array_H
#define Array_H

template <class elemType>
class Array {
protected:
    int _size;
    elemType *arr;
    static const int DefaultArraySize = 12;
    void init(const elemType *arr, int arr_size);
public:
    explicit Array(int arr_size = DefaultArraySize);
    Array(const elemType *arr, int arr_size);
    Array(const Array& source);
    virtual ~Array() {delete[] arr;}

    bool operator== (const Array&) const;
    bool operator!= (const Array&) const;

    Array& operator= (const Array&);
    virtual elemType& operator[] (int index) const {return arr[index];}

    int size() const {return _size;}
    virtual void sort();

    virtual elemType max() const;
    virtual elemType min() const;

    virtual int find(elemType value) const;
};

template <class elemType>
void Array<elemType>::init(const elemType *arr, int arr_size) {
    _size = arr_size;
    this->arr = new elemType[_size];
    for (int index = 0; index < _size; index++) {
        if (!arr) {
            this->arr[index] = 0;
        } else {
            this->arr[index] = arr[index];
        }
    }
}

template <class elemType>
Array<elemType>::Array(int arr_size) {
    init(0, arr_size);
}

template <class elemType>
Array<elemType>::Array(const elemType *arr, int arr_size) {
    init(arr, arr_size);
}

template <class elemType>
Array<elemType>::Array(const Array& source) {
    init(source.arr, source._size);
}

template <class elemType>
void Array<elemType>::sort() {

}

template <class elemType>
elemType Array<elemType>::max() const {
    return 0;
}

template <class elemType>
elemType Array<elemType>::min() const {
    return 0;
}

template <class elemType>
int Array<elemType>::find(elemType value) const {
    return 0;
}

#endif