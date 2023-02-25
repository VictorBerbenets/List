#include "..//includes//list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);
    int size = 10;
    ListPushHead(&list, 1000);
    ListPushHead(&list, 3000);
    ListPushHead(&list, 4000);
    ListPushTail(&list, 5000);
    ListLinerize(&list);
    ListDump(list);

    ListPushLeft(&list, 2, 5423523);

    // for (int i = 1; i < size; i++) {
    //     ListPushLeft(&list, list.head, i + 10.5);
    // }

    // for (int i = 1; i < size; i++) {
    //     ListPushRight(&list, list.tail, i);
    // }
    ListDump(list);

    // ListLinerize(&list);
    
    // // ListDump(list);
    // // for (int i = 0; i < list.capacity; i++) {
    // //     PrintElementInfo(&list, i);
    // // }


    // ListPushRight(&list, 3, -777);
    // ListPushLeft(&list, 3, -555);
    // ListPushLeft(&list, 3, -455);
    // ListPushLeft(&list, 3, -355);
    // // int ls_size = list.size;
    // // for (int i = 2; i < ls_size - 5; i++) {
    // //     ListDeleteNode(&list, i);
    // // }
    // ListDump(list);

    // for (int i = 0; i < list.capacity; i++) {
    //     PrintElementInfo(&list, i);
    // }


// //    int x = list.free_node;
// //     int i = 1;
// //     while(x != (list.capacity - 1)) {
// //         printf("free[%d] = %d\n", i, x);
// //         x = list.data[x].next;
// //         i++;
// //     }
//     ListDump(list);

//     for (int i = 1; i < size; i++) {
//         ListPushLeft(&list, list.head, i + 10.5);
//     }
//     ListDump(list);

//     for (int i = 1; i < size; i++) {
//         ListPushRight(&list, list.head, i);
//     }
//     // printf("free_cell = %d\n", list.free_cell);
//     // int x = list.free_node;
//     // for (int i = 0; i < 20; i++, x = list.data[x].next) {
//     //     printf("free_cell = %d,   val = %lg\n", x, list.data[x].number);
//     // }
//     ListDump(list);

    ListDestructor(list);

    return 0;
}