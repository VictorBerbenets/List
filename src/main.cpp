#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);

    for (int i = 0; i < 10; i++) {
        ListPushRight(&list, i, 1000*i);
    }
    ListDump(list);

    for (int i = 1; i < 5; i++) {
        ListPushLeft(&list, i, 100000*i);
    }
    ListDump(list);

    ListLinerize(&list);

    ListDump(list);

    int ls_size = list.size;

    for (int i = 0; i < ls_size; i++) {
        ListDeleteNode(&list, list.head);
    }
    ListLinerize(&list);

    ListDump(list);
    printf("List is linear = %d\n", list.list_is_linear);


    ListResize(&list, 10);
    ListDump(list);

    for (int i = 0; i < list.capacity; i++) {
        PrintElementInfo(&list, i);
    }
    ListResize(&list, 100);
    for (int i = 1; i < 5; i++) {
        ListPushLeft(&list, list.head, 700*(i + 1));
    }
    ListDump(list);

    for (int i = 0; i < list.capacity; i++) {
        PrintElementInfo(&list, i);
    }
    ListDestructor(list);

    return 0;
}