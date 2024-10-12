#include <iostream>
#include <cstddef>
#include <bitset>

int main() {
    int arr[] = { 1, 2, 3 };
    int n = 1;
    size_t arr_size = sizeof arr;
    size_t elem_count = arr_size / sizeof( int );
    int *d_arr = new int[ 3 ];

    std::cout << arr_size << " " << elem_count << std::endl;
    std::cout << sizeof( arr ) << std::endl;
    std::cout << sizeof( d_arr ) << std::endl;
    std::cout << sizeof d_arr << std::endl;
    std::cout << "---------------" << std::endl;

    n = n << 1;
    std::cout << std::bitset<32>( n ) << std::endl;
    n = ~1;
    std::cout << std::bitset<32>( n ) << std::endl;
    std::cout << "---------------" << std::endl;
    n = 1 << 27;
    std::cout << std::bitset<32>( n ) << std::endl;
    n = 0 | n;
    std::cout << std::bitset<32>( n ) << std::endl;
    int m = ~n;
    std::cout << std::bitset<32>( m ) << std::endl;
    std::cout << std::bitset<32>( n & m ) << std::endl;

    std::cout << "---------------" << std::endl;
    char a = 4;
    char b = 2;
    std::cout << std::bitset<8>( a ) << std::endl;
    std::cout << std::bitset<8>( b ) << std::endl;
    std::cout << std::bitset<8>( a | b ) << std::endl;
    std::cout << "---------------" << std::endl;
    const int _size = 32;
    std::bitset<_size> bitvec;
    std::cout << bitvec.any() << std::endl;
    std::cout << bitvec.none() << std::endl;
    for ( int index = 0; index < _size; index++ ) {
        if ( index % 2 == 0 ) {
            bitvec[index] = 1;
        }
    }
    std::cout << bitvec << std::endl;
    system( "pause" );
    return 0;
}