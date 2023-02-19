#include "list.h"


void ListCtor(List* list, int capacity, int line, const char* func, const char* file) {

    list->capacity = capacity;
    list->data     = (node*) calloc(list->capacity, sizeof(node));
    if (!list->data) {
        fprintf(stderr, "" White "%s:%d:" Grey " In function " White " '%s': " Grey " \n", file, line, func);     
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "in calloc: couldn't give memory\n\t| " Blue " \tlist.data "
        "= %p " Grey " \n\t|\n", file, line, list->data); 
        exit(EXIT_FAILURE); 
    }

    list->data[0].prev   = 0;
    list->data[0].number = null_elem;
    list->data[0].next   = 0;

    list->tail = null_node;
    list->head = null_node;
    list->free_cell = null_node + 1;

    for (int node_number = 1; node_number < capacity; node_number++) {
        list->data[node_number].prev   = node_number - 1;
        list->data[node_number].number = free_cell;
        list->data[node_number].next   = node_number + 1;
    }
}


void ListDtor(List* list, int line, const char* func, const char* file) {

    Func_position(ListDtor(...));
    
    free(list->data);
    list -> data = nullptr;
}


void ListInform(List* list, int line, const char* func, const char* file) {
    
    fprintf(stderr, " " Blue  Blinking "\t\tList Dump" Grey "\n");
    Func_position(ListInform(...));
    fprintf(stderr, "list head:     =  %p\n", list->data);
    fprintf(stderr, "list head:     =  %d\n", list->head);
    fprintf(stderr, "list tail      =  %d\n", list->tail);
    fprintf(stderr, "list capacity  =  %d\n", list->capacity);
    fprintf(stderr, "list size      =  %d\n", list->size);
    fprintf(stderr, "list free cell =  %d\n", list->free_cell);
}