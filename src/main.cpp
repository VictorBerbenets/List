#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);
    int size = 10;

    ListPushHead(&list, 1000);
    ListPushTail(&list, 5000);

    for (int i = 1; i < size; i++) {
        ListPushRight(&list, list.tail, i);
    }

    for (int i = 1; i < size; i++) {
        ListPushLeft(&list, list.head, i + 10.5);
    }
    
    ListDump(list);

    ListDestructor(list);

    return 0;
}