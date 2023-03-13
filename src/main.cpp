#include "..//includes//list.h"


int main() {
    
    List list(10);
    char string[MaxStringLen] = {};   

    ListDump(list, "Creating list\n");

    list.ListPushHead(&list, 1488);
    ListDump(list, "Pushing %lg to head\n", list.GetValue(list.GetHead()));
 
    list.ListPushHead(&list, 1488);
    ListDump(list, "Pushing %lg to head\n", list.GetValue(list.GetHead()));


    // list.ListResize(&list, 5);
    // ListLinearize(&list);

    ListDump(list, "Resizing list\n");
    list.ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushRight(&list, 3, 555);
    ListDump(list, "Pushing %lg after %d id\n", list.GetValue(4), 3);

    list.ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushTail(&list, 2100);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushTail(&list, 3000);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushTail(&list, 4000);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    ListDump(list, "Deleted node with id: %d\n", list.ListDeleteNode(&list, 2));
    ListDump(list, "Deleted node with id: %d\n", list.ListDeleteNode(&list, 3));

    list.ListPushTail(&list, 5000);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListPushHead(&list, 6000);
    ListDump(list, "Pushing %lg to head\n", list.GetValue(list.GetHead()));

    list.ListPushTail(&list, 7000);
    ListDump(list, "Pushing %lg to tail\n", list.GetValue(list.GetTail()));

    list.ListLinearize(&list);
    ListDump(list, "list linearizing\n");

    List list2(5);

    list2 = list; 

    list2.ListPushHead(&list2, -100);
    ListDump(list2, "Pushing %lg to head\n", list2.GetValue(list2.GetHead()));


    return 0;
}