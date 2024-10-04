#include <iostream>

int main() {
    const char *c = "Word";
    const char *b = "Word";
    std::cout << (void*)c << std::endl;
    std::cout << (void*)b << std::endl;
    const int number = 10;
    const int number_second = 20;
    const int *p = &number;
    const int *p2 = &number_second;
    std::cout << p << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p2 - p << std::endl;
    std::cout << *(p2 + 1) << std::endl;
    do {
        std::cout << c << " ";
        std::cout << *c << std::endl;
    } while (*c++);

    int ival = 1024;
    int &ref = ival;
    std::cout << &ival << " " << &ref << std::endl;
    int *addr = &ival;
    int *&ref_addr = addr;
    std::cout << ref_addr << std::endl;
    const int test = 10;
    std::cout << &test << std::endl;

    int arr[] = {1, 2, 3};
    std::cout << arr << " " << arr + 1 << " " << arr + 2 << std::endl;

    typedef double dd;
    dd double_number = 10.5;
    std::cout << double_number << std::endl;

    volatile int unstable_without_optimization;
    system("pause");
}