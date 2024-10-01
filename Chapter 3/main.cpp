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
    system("pause");
}