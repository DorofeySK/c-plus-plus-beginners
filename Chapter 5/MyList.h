#ifndef MyList_h
#include <iostream>
#define MyList_h

class list_item {
private:
    int _value;
    list_item *_next;
public:
    list_item( int value, list_item *item_to_link = 0 );
    list_item* next();
    void next( list_item *ptr );
    int value();
    void value( int value );
};

void list_item::value( int value ) {
    _value = value;
}

inline list_item::list_item( int value, list_item *item_to_link = 0 ) : _value( value ) {
    if ( !item_to_link ) {
        _next = 0;
    } else {
        _next = item_to_link->_next;
        item_to_link->_next = this;
    }
}

void list_item::next( list_item *ptr ) {
    _next = ptr;
}

int list_item::value() {
    return _value;
}

list_item* list_item::next() {
    return _next;
}

class my_list {
private:
    list_item *_at_front;
    list_item *_at_end;
    int _size;

    my_list( const my_list& );
    my_list& operator=( const my_list& );
public:
    my_list() : _at_end( 0 ), _at_front( 0 ), _size( 0 ) {}
    int size();

    void insert( list_item *ptr, int value );
    void insert_front( int value );
    void insert_end( int value );

    int remove( int value );
    void remove_front();
    void remove_all();

    list_item* find( int value );

    void display( std::ostream &os = std::cout );

    void decr();
    void incr();
};

inline void my_list::decr() {
    ++_size;
}

inline void my_list::incr() {
    --_size;
}

inline void my_list::insert( list_item *ptr, int value ) {
    if ( !ptr ) {
        insert_front( value );
    } else {
        decr();
        new list_item( value, ptr );
    }
}

inline void my_list::insert_front( int value ) {
    list_item *ptr = new list_item( value );
    if ( !_at_front ) {
        _at_front = _at_end = ptr;
    } else {
        ptr->next( _at_front );
        _at_front = ptr;
    }
    decr();
}

inline void my_list::insert_end( int value ) {
    if ( !_at_end ) {
        _at_end = _at_front = new list_item( value );
    } else {
        _at_end = new list_item( value, _at_end );
    }
    decr();
}

inline int my_list::remove( int value ) {
    list_item *front_item = _at_front;
    int elem_cnt = 0;
    while ( front_item && front_item->value() == value ) {
        front_item = front_item->next();
        remove_front();
        elem_cnt++;
    }
    if ( !front_item ) {
        return elem_cnt;
    }
    list_item *prev = front_item;
    front_item = front_item->next();

    while ( front_item ) {
        if ( front_item->value() == value ) {
            prev->next( front_item->next() );
            delete front_item;
            elem_cnt++;
            decr();
            front_item = prev->next();
            if ( !front_item ) {
                _at_end = prev;
                return elem_cnt;
            }
        } else {
            prev = front_item;
            front_item = front_item->next();
        }
    }

    return elem_cnt;
}

inline void my_list::remove_front()
{
    if ( _at_front ) {
        list_item *ptr = _at_front;
        _at_front = _at_front->next();
        decr();
        delete ptr;
    }
}

inline void my_list::remove_all() {
    while ( _at_front ) {
        remove_front();
    }
    _size = 0;
    _at_front = _at_end = 0;
}

inline int my_list::size() {
    return _size;
}

list_item* my_list::find( int value ) {
    list_item *ptr = _at_front;
    while ( ptr ) {
        if ( ptr->value() == value ) {
            break;
        }
        ptr = ptr->next();
    }
    return ptr;
}

void my_list::display( std::ostream &os = std::cout ) {
    os << "( " << _size << " ) ( ";
    list_item *ptr = _at_front;
    while ( ptr ) {
        os << ptr->value() << " ";
        ptr = ptr->next();
    }
    os << ")" << std::endl;
}

#endif