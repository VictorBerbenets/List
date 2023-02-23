#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);
    

    ListPushTail(&list, 53);
    ListDump(list);
    ListPushRight(&list, list.tail, 432);
    ListPushRight(&list, list.tail, 532.43);
    ListPushRight(&list, list.tail, 7343.534);
    ListPushRight(&list, 2, 532523);

    // printf("free = %d\n", list.free_cell);
    // ListPushTail(&list, 543);
    // ListPushTail(&list, 743);
    // ListPushTail(&list, 843);
    // ListPushTail(&list, 943);
    // ListPushHead(&list, 645);
    // ListPushHead(&list, 646);
    // ListPushHead(&list, 647);
    // ListPushHead(&list,346645);
    // ListPushTail(&list, 100000);
    // ListPushHead(&list, 647);

    // PrintElementInfo(&list, 0); 
    // PrintElementInfo(&list, 1); 
    // PrintElementInfo(&list, 2); 
    // PrintElementInfo(&list, 3); 
    // PrintElementInfo(&list, 4); 
    // PrintElementInfo(&list, 5); 
    // PrintElementInfo(&list, 6); 
    // PrintElementInfo(&list, 7); 
    // PrintElementInfo(&list, 8); 
    // printf("list.tail = %d\n", list.tail);
    // printf("list tail data = %lg\n", list.data[list.tail].number);
    ListDump(list);

    ListDestructor(list);

    return 0;
}