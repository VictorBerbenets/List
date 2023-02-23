#include "..//includes//list.h"

int ListPushTail(List* list, elem_t value) {

    if (list->size >= list->capacity - 1) {
        printf("Can't push elem after tail\n");
        return -1;
    }

    int new_tail_id = list->free_cell;
    list->data[new_tail_id].number = value;  
    list->data[new_tail_id].prev = list->tail;

    if (list->size == ListInitSize) {
        list->head = new_tail_id;
        // list->data[list->head].next = new_tail_id;
    }

    list->data[list->tail].next = new_tail_id; 
    list->tail      = new_tail_id;

    list->free_cell = list->data[list->free_cell].next;
    list->data[list->tail].next = 0;

    list->size ++;
    return value;
}

int ListPushHead(List* list, elem_t value) {

    if (list->size >= list->capacity - 1) {
        printf("Can't push elem before head\n");
        return -1;
    }

    int new_head_id = list->free_cell;

    list->data[new_head_id].number = value;  
    list->data[new_head_id].prev   = 0;

    if (list->size == ListInitSize) {
        list->tail = new_head_id;
        list->data[list->tail].prev = new_head_id;
    }

    list->data[list->head].prev = list->free_cell; 

    list->free_cell = list->data[list->free_cell].next;

    list->data[new_head_id].next = list->head; 
    list->head                   = new_head_id;
        
    list->size ++;

    return value;
}

int ListPushRight(List* list, int cell_id, elem_t value) {

    if (cell_id < 0 || cell_id >= list->capacity) {
        printf("err\n");
    }

    if (list->size == ListInitSize || cell_id == list->tail) {
        ListPushTail(list, value);
        return value;
    }

    int new_elem_id   = list->free_cell;
    int after_cell_id = list->data[cell_id].next;

    list->data[new_elem_id].number = value;

    list->data[new_elem_id].next   = after_cell_id;
    list->data[after_cell_id].prev = new_elem_id;
    list->data[cell_id].next       = new_elem_id;
    list->data[new_elem_id].prev   = cell_id;
    
    list->size ++;
    
    return value;
}



void ListCtor(List* list, int capacity, int line, const char* func, const char* file) {

    list->capacity = capacity;

    list->data = (node*) calloc(capacity, sizeof(node));
    Validator(list->data == nullptr, "in calloc: couldn't give memory", PrintFuncPosition(); exit(EXIT_FAILURE));

    list->data[0].prev   = Null_Elem;
    list->data[0].number = 0;
    list->data[0].next   = Null_Elem;

    list->size = ListInitSize;
    list->tail = Null_Node;
    list->head = Null_Node;
    list->data[Null_Node].next = 0;
    list->data[Null_Node].prev = 0;

    list->free_cell = 1;

    for (int node_number = 1; node_number < capacity; node_number++) {
        list->data[node_number].prev   = node_number - 1;
        list->data[node_number].number = Free_Cell;
        list->data[node_number].next   = node_number + 1;
    }
}


void ListDtor(List* list, int line, const char* func, const char* file) {
    
    free(list->data);
    list -> data = nullptr;
}

void PrintElementInfo(List* list, int elem_id) {

    if (elem_id < 0 || elem_id >= list->capacity) {
        fprintf(stderr, "" Red "error: " Grey " there is not element with such index"
        " in the list\n");
        return ;
    }
    fprintf(stderr, "\t\t" Purple Blinking "Element Dump" Grin "\n");
    fprintf(stderr, "prev index: %d\n", list->data[elem_id].prev);
    fprintf(stderr, "index:      %d\n", elem_id);
    fprintf(stderr, "next index: %d\n", list->data[elem_id].next);
    fprintf(stderr, "value:      %lg\n" Grey "", list->data[elem_id].number);
}

void ListInform(List* list, int line, const char* func, const char* file) {
    
    fprintf(stderr, "\n" Blue "------------------------------------------" Blinking "List Dump" Blue "------------------------------"
    "------------" Grey "\n");
    PrintFuncPosition();
    fprintf(stderr, "\n");
    fprintf(stderr, "list data ptr    =  %p\n", list->data);
    fprintf(stderr, "list head        =  %d\n", list->head);
    fprintf(stderr, "list tail        =  %d\n", list->tail);
    fprintf(stderr, "list capacity    =  %d\n", list->capacity);
    fprintf(stderr, "list size        =  %d\n", list->size);
    fprintf(stderr, "list free cell   =  %d\n\n", list->free_cell);

    fprintf(stderr, "list elemenst in order:\n");
    // int data_num = 1;
    // int elem_id  = list->head;
    
    // for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].next) {
    //     fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    // }
    // fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);
    // fprintf(stderr, "" Blue "---------------------------------------------------------------------------------------------" Grey "\n\n");
    int data_num = 1;
    int elem_id  = list->tail;
    
    for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].prev) {
        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    }
    fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);
    fprintf(stderr, "" Blue "---------------------------------------------------------------------------------------------" Grey "\n\n");
}