class IntArray {
private:
    int _size;
    int *arr;
    static const int DefaultArraySize = 12;
public:
    explicit IntArray(int sz = DefaultArraySize);
    IntArray(int *arr, int array_size);
    IntArray(const IntArray &source);

    bool operator== (const IntArray&) const;
    bool operator!= (const IntArray&) const;

    IntArray& operator= (const IntArray&);

    int size() const {return _size;}
    void sort();

    int max() const;
    int min() const;

    int find(int value) const;
};