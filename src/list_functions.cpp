#include "..//includes//list.h"


int ListPushRight(List* list, int cell_id, elem_t value) {
    if (cell_id < 0 || cell_id >= list->capacity) {
        printf("err\n");
    }

    list->free_cell = -list->data[list->free_cell].next;
}



void ListCtor(List* list, int capacity, int line, const char* func, const char* file) {

    list->capacity = capacity;
    list->data     = (node*) calloc(list->capacity, sizeof(node));
    Validator(list->data == nullptr, "in calloc: couldn't give memory", fprintf(stderr, "%s"
    " was called from" White ":%s:%s:%d" Grey "\n\n", __PRETTY_FUNCTION__, file, func, line); \
    exit(EXIT_FAILURE));

    list->data[0].prev   = 0;
    list->data[capacity - 1].number = Null_Elem;
    list->data[0].next   = 0;

    list->tail = Null_Node;
    list->head = Null_Node;
    list->free_cell = Null_Node + 1;

    for (int node_number = 1; node_number < capacity - 1; node_number++) {
        list->data[node_number].prev   = node_number - 1;
        list->data[node_number].number = -Free_Cell - node_number;
        list->data[node_number].next   = node_number + 1;
    }
}


void ListDtor(List* list, int line, const char* func, const char* file) {

    // PrintFuncPosition(ListDtor(...));
    
    free(list->data);
    list -> data = nullptr;
}


void ListInform(List* list, int line, const char* func, const char* file) {
    
    fprintf(stderr, "\n" Blue  Blinking "\t\tList Dump" Grey "\n");
    PrintFuncPosition(ListInform(...));
    fprintf(stderr, "list data      =  %p\n", list->data);
    fprintf(stderr, "list head      =  %d\n", list->head);
    fprintf(stderr, "list tail      =  %d\n", list->tail);
    fprintf(stderr, "list capacity  =  %d\n", list->capacity);
    fprintf(stderr, "list size      =  %d\n", list->size);
    fprintf(stderr, "list free cell =  %d\n\n", list->free_cell);

    fprintf(stderr, "list elemenst:\n");
    for (int data_num = 0; data_num < list->capacity; data_num++) {

        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[data_num].number);
    }
}