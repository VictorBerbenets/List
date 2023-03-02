#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 15);

    ListPushHead(&list, 1488);
    ListDump(list);

    ListPushTail(&list, 2000);
    ListDump(list);

    ListPushRight(&list, 1, 2200);
    ListDump(list);

    ListPushLeft(&list, 2, 2700);
    ListDump(list);

    ListPushTail(&list, 3000);
    ListDump(list);

    ListPushTail(&list, 4000);
    ListDump(list);

    ListDeleteNode(&list, list.tail);
    ListDump(list);

    ListDeleteNode(&list, list.head);
    ListDump(list);

    ListPushTail(&list, 5000);
    ListDump(list);

    ListPushHead(&list, 6000);
    ListDump(list);

    ListPushTail(&list, 7000);
    ListPushTail(&list, 7000);
    ListDump(list);

    ListLinerize(&list);
    ListDump(list);

    ListDestructor(list);

    return 0;
}