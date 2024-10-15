#ifndef MyStack_h
#define MyStack_h

#include <vector>
#include <iostream>

class MyStack {
private:
    int _top;
    std::vector<int> _stack;
public:
    MyStack( int capacity ) : _stack( capacity ), _top( 0 ) {}
    bool pop( int &value );
    bool push( int value );

    bool full();
    bool empty();
    void display();

    int size();
};

int MyStack::size() {
    return _top;
}

bool MyStack::empty() {
    return _top == 0;
}

bool MyStack::full() {
    return _top < _stack.size() ? false : true;
}

bool MyStack::pop( int &top_value ) {
    if ( empty() ) {
        return false;
    }
    top_value = _stack[ --_top ];
    std::cout  << "pop: " << top_value << std::endl;
    return true;
}

bool MyStack::push( int value ) {
    std::cout << "push: " << value << std::endl;
    if ( full() ) {
        return false;
    }
    _stack[ _top++ ] = value;
    return true;
}

void MyStack::display() {
    std::cout << "( " << size() << " ) ( bot: )";
    for (auto elem : _stack) {
        std::cout << elem << " ";
    }
    std::cout << ":top )" << std::endl;
}

#endif