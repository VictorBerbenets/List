#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 15);
    char string[MaxStringLen] = {};   

    ListDump(list, "Creating list");

    ListPushHead(&list, 1488);
    ListDump(list, "Pushing %lg to head\n", list.data[list.head].number);

    ListPushTail(&list, 2000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListDump(list, "Pushing right after node id: %d value: %lg\n", 1, ListPushRight(&list, 1, 2150));

    ListDump(list, "Pushing right after node id: %d value: %lg\n", 1, ListPushRight(&list, 1, 2200));
    
    ListDump(list, "Pushing left before node id: %d value: %lg\n", 2, ListPushLeft(&list, 2, 2700));

    ListPushTail(&list, 3000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 4000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListDump(list, "Deleted node with id: %d\n", ListDeleteNode(&list, list.tail));
    ListDump(list, "Deleted node with id: %d\n", ListDeleteNode(&list, list.head));

    ListPushTail(&list, 5000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushHead(&list, 6000);
    ListDump(list, "Pushing %lg to head\n", list.data[list.head].number);

    ListPushTail(&list, 7000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListLinearize(&list);
    ListDump(list, "Linearizing list\n");

    ListDestructor(list);

    return 0;
}