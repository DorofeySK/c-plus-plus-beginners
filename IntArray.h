#ifndef IntArray_H
#define IntArray_H

class IntArray {
protected:
    int _size;
    int *arr;
    static const int DefaultArraySize = 12;
    void init(const int *arr, int arr_size);
public:
    explicit IntArray(int arr_size = DefaultArraySize);
    IntArray(const int *arr, int arr_size);
    IntArray(const IntArray &source);
    virtual ~IntArray() {delete[] arr;}

    bool operator== (const IntArray&) const;
    bool operator!= (const IntArray&) const;

    IntArray& operator= (const IntArray&);
    virtual int& operator[] (int index) const {return arr[index];}

    int size() const {return _size;}
    virtual void sort();

    virtual int max() const;
    virtual int min() const;

    virtual int find(int value) const;
};
#endif