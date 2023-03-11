#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 20);
    char string[MaxStringLen] = {};   

    ListDump(list, "Creating list\n");

    ListPushHead(&list, 1488);
    ListDump(list, "Pushing %lg to head\n", list.data[list.head].number);
 
    ListPushHead(&list, 1488);
    ListDump(list, "Pushing %lg to head\n", list.data[list.head].number);


    ListResize(&list, 5);
    // ListLinearize(&list);

    ListDump(list, "Resizing list\n");

    ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);


    ListPushTail(&list, 3000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushTail(&list, 4000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListDump(list, "Deleted node with id: %d\n", ListDeleteNode(&list, 2));
    ListDump(list, "Deleted node with id: %d\n", ListDeleteNode(&list, 3));

    ListPushTail(&list, 5000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListPushHead(&list, 6000);
    ListDump(list, "Pushing %lg to head\n", list.data[list.head].number);

    ListPushTail(&list, 7000);
    ListDump(list, "Pushing %lg to tail\n", list.data[list.tail].number);

    ListLinearize(&list);
    ListDump(list, "list linearizing\n");

    ListDestructor(list);

    return 0;
}