#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);

    ListPushHead(&list, 523);
    for (int i = 1; i < 5; i++) {
        ListPushLeft(&list, i, i);
    }
    ListDump(list);
       for (int i = 0; i < list.capacity; i++) {
        PrintElementInfo(&list, i);
    }
    // printf("[] = %d\n", FindFirstListElem(&list, 4));
    for (int i = 1; i < 10; i++) {
        ListPushRight(&list, i, 1000*i);
    }

    // // ListDump(list);

    ListLinerize(&list);

    ListDump(list);

    int ls_size = list.size;

    for (int i = 0; i < ls_size - 1; i++) {
        printf("list.head = %d\n", list.head);
        printf("list.tail = %d\n", list.tail);
        ListDeleteNode(&list, list.head);
    }
    ListDump(list);
       for (int i = 0; i < list.capacity; i++) {
        PrintElementInfo(&list, i);
    }
    // ListLinerize(&list);
    // ListDump(list);
    // int x = list.head;
    // printf("Phys_id[%d] = %d\n", x, FindPhysAddress(&list, x));
    // printf("Logic  [%d] = %d\n", x, FindLogicAddress(&list, x));
    // printf("List is linear = %d\n", list.list_is_linear);


    // ListResize(&list, 10);
    // ListDump(list);

    // for (int i = 0; i < list.capacity; i++) {
    //     PrintElementInfo(&list, i);
    // }
    // ListResize(&list, 100);
    // for (int i = 1; i < 5; i++) {
    //     ListPushLeft(&list, list.head, 700*(i + 1));
    // }
    // ListDump(list);

    // for (int i = 0; i < list.capacity; i++) {
    //     PrintElementInfo(&list, i);
    // }
    ListDestructor(list);

    return 0;
}