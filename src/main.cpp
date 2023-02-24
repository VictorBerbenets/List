#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);
    int size = 10;
    // ListDeleteNode(&list, list.tail);
    // ListPushHead(&list, 1000);
    // ListPushTail(&list, 5000);

    for (int i = 1; i < size; i++) {
        ListPushRight(&list, list.tail, i);
    }

    for (int i = 1; i < size; i++) {
        ListPushLeft(&list, list.head, i + 10.5);
    }

    ListDump(list);
    ListDeleteNode(&list, list.head);
    
    // printf("free_cell = %d\n", list.free_cell);
    // int x = list.free_node;
    // for (int i = 0; i < 20; i++, x = list.data[x].next) {
    //     printf("free_cell = %d,   val = %lg\n", x, list.data[x].number);
    // }
    ListDump(list);

    ListDestructor(list);

    return 0;
}