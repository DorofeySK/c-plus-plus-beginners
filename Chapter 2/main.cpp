#include <iostream>
#include "Array.h"
#include "ArrayRC.h"

using namespace std;

template<class elemType>
void swap(Array<elemType> &int_arr, int first_index, int second_index) {
    int tmp = int_arr[first_index];
    int_arr[first_index] = int_arr[second_index];
    int_arr[second_index] = tmp;
}

int main() {
    cout << "start" << endl;
    int start_arr[4] = {1, 2, 3, 4};
    Array<int> int_arr(start_arr, 4);
    ArrayRC<int> int_arr_rc(start_arr, 4);
    
    swap(int_arr, 0, 3);
    swap(int_arr_rc, 0, 3);
    
    cout << int_arr[0] << " " << int_arr[3] << endl;
    cout << int_arr_rc[0] << " " << int_arr_rc[3] << endl;

    system("pause");
    return 0;
}