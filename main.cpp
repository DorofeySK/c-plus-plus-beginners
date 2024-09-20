#include <iostream>
#include "IntArray.h"
#include "IntArrayRC.h"

using namespace std;

void swap(IntArray &int_arr, int first_index, int second_index) {
    int tmp = int_arr[first_index];
    int_arr[first_index] = int_arr[second_index];
    int_arr[second_index] = tmp;
}

int main() {
    cout << "start" << endl;
    int start_arr[4] = {0, 1, 2, 3};
    IntArray int_arr(start_arr, 4);
    IntArrayRC int_arr_rc(start_arr, 4);
    swap(int_arr, 0, 3);
    swap(int_arr_rc, 0, 3);
    
    cout << int_arr[0] << " " << int_arr[3] << endl;
    cout << int_arr_rc[0] << " " << int_arr_rc[3] << endl;

    system("pause");
    return 0;
}