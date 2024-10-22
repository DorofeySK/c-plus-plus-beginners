#include <iostream>
#include "MyList.h"

int main() {
    my_list mylist;
    for ( int item = 0; item < 10; ++item ) {
        mylist.insert_front( item );
        mylist.insert_end( item );
    }
    mylist.display();

    list_item *it = mylist.find( 8 );
    std::cout << "\n"
        << "Ищем значение 8: нашли?"
        << ( it ? " да!\n" : " нет!\n" );

    mylist.insert( it, 1024 );
    std::cout << "\n" <<
    "Вставка элемента 1024 после 8\n";
    mylist.display();

    int elem_cnt = mylist.remove( 8 );
    std::cout << "\n"
        << "Удалено " << elem_cnt
        << " элемент(ов) со значением 8\n";
    mylist.display();

    std::cout << "\n" << "Удален первый элемент\n";
    mylist.remove_front();
    mylist.display();
    
    std::cout << "\n" << "Удалены все элементы\n";
    mylist.remove_all();
    mylist.display();

    system("pause");
    return 0;
}