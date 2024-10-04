#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>
using namespace std;

class String;
istream& operator>>( istream&, String&);
ostream& operator<<( ostream&, const String&);

class String {
private:
    int _size;
    char *_string;
    void init( const char* );
public:
    String();
    String( const char* );
    String( const String& );

    ~String();

    String& operator=( const String& );
    String& operator=( const char* );

    bool operator==( const String& );
    bool operator==( const char* );

    char& operator[] ( int );

    int size() const {return _size;} //default inline 
    char* c_str() const {return _string;} //default inline
};

inline void String::init( const char *src ) { //inline f() must be in header file
    if ( !src ) {
        _size = 0;
        _string = 0;
    } else {
        _size = strlen( src );
        _string = new char[ _size + 1 ];
        strcpy( _string, src );
    }
}

inline String::String() {
    init( 0 );
}

inline String::String( const char *str ) {
    init( str );
}

inline String::String( const String &src ) {
    init( src._string );
}

inline String::~String() {
    delete [] _string;
}

String &String::operator=( const String &src) {
    if ( this != &src ) {
        delete [] _string;
        _size = src._size;
        if ( !src._string ) {
            _string = 0;
        } else {
            _string = new char[ _size + 1 ];
            strcpy( _string, src._string );
        }
    }
    return *this;
}

inline String &String::operator=( const char *src )
{
    delete [] _string;
    if ( !src ) {
        _size = 0;
        _string = 0;
    } else {
        _size = strlen( src );
        _string = new char[ _size + 1 ];
        strcpy( _string, src );
    }
    return *this;
}

inline bool String::operator==(const String &rhs)
{
    if ( _size != rhs._size ) {
        return false;
    }
    return strcmp( _string, rhs._string ) == 0;
}

inline bool String::operator==( const char *cstr ) {
    return strcmp( _string, cstr ) == 0;
}

inline char &String::operator[]( int index) {
    assert( index >= 0 && index < _size );
    return _string[index];
}

inline istream &operator>>(istream &is, String &src) {
    const int limit_string_size =4096;
    char in_buf[ limit_string_size ];
    is >> setw( limit_string_size ) >> in_buf;
    src = in_buf;
    return is;
}

inline ostream &operator<<(ostream &os, const String &src) {
    return os << src.c_str();
}


#endif