#include "..//includes//list.h"

int ListPushTail(List* list, elem_t value) {

    if (list->size >= list->capacity - 1) {
        printf("Can't push elem after tail\n");
        return InvalidNodeId;
    }
    Validator((list->size >= list->capacity - 1), "invalid elem index"; PrintFuncPosition();  return ;);

    int new_tail_id = list->free_node;
    list->data[new_tail_id].number = value;  
    list->data[new_tail_id].prev = list->tail;

    if (list->size == ListInitSize) {
        list->head = new_tail_id;
    }

    list->data[list->tail].next = new_tail_id; 
    list->tail      = new_tail_id;

    FindFreeNode();
    
    list->data[list->tail].next = 0;

    list->size ++;

    return value;
}

int ListPushHead(List* list, elem_t value) {

    if (list->size >= list->capacity - 1) {
        printf("Can't push elem before head\n");
        return InvalidNodeId;
    }
    Validator((list->size >= list->capacity - 1), "invalid elem index"; PrintFuncPosition();  return ;);

    int new_head_id = list->free_node;

    list->data[new_head_id].number = value;  
    list->data[new_head_id].prev   = 0;

    if (list->size == ListInitSize) {
        list->tail = new_head_id;
        // list->data[list->tail].prev = new_head_id;
    }

    list->data[list->head].prev = list->free_node; 

    FindFreeNode();

    list->data[new_head_id].next = list->head; 
    list->head                   = new_head_id;
        
    list->size ++;
    list->list_is_linear = false;

    return value;
}

int ListPushRight(List* list, int node_id, elem_t value) {

    if (node_id < 0 || node_id >= list->capacity) {
        printf("err\n");
        return InvalidNodeId;
    }

    if (list->size == ListInitSize || node_id == list->tail) {
        ListPushTail(list, value);
        return value;
    }

    int new_elem_id       = list->free_node;
    int node_id_neighbour = list->data[node_id].next;

    list->data[new_elem_id].number = value;

    FindFreeNode();

    list->data[new_elem_id].next       = node_id_neighbour;
    list->data[node_id_neighbour].prev = new_elem_id;
    list->data[node_id].next           = new_elem_id;
    list->data[new_elem_id].prev       = node_id;
    
    list->size ++;
    list->list_is_linear = false;

    return value;
}

int ListPushLeft(List* list, int node_id, elem_t value) {

    if (node_id < 0 || node_id >= list->capacity) {
        printf("err\n");
        return InvalidNodeId;
    }

    if (list->size == ListInitSize || node_id == list->head) {
        ListPushHead(list, value);
        return value;
    }

    int new_elem_id       = list->free_node;
    int node_id_neighbour = list->data[node_id].prev;
    list->data[new_elem_id].number = value;

    FindFreeNode();

    list->data[new_elem_id].next       = node_id;
    list->data[node_id_neighbour].next = new_elem_id;
    list->data[node_id].prev           = new_elem_id;
    list->data[new_elem_id].prev       = node_id_neighbour;
    
    list->size ++;

    return value;
}

int ListDeleteNode(List* list, int node_id) {

    int node_id_neighbour = 0;
    if (list->data[node_id].number == Free_Node || list->size == ListInitSize) {
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey " can't delete this node");
        return InvalidNodeId;

    }
    // Validator(list->data[node_id].number == Free_Node || list->size == ListInitSize, "can't delete this node", PrintFuncPosition(); \
    return -1;)
    if (list->size == ListInitSize + 1) {
        list->tail = 0;
        list->head = 0;
        // list->free_node = 1;
        // list-
    }
    else if (node_id == list->tail) {

        DeleteTail(list, node_id);   
    }

    else if (node_id == list->head) {
        
        DeleteHead(list, node_id);   
    }

    else {
        DeleteNode(list, node_id);
    }

    list->size --;
    
}

void DeleteNode(List* list, int node_id) {

    int right_neighbour = list->data[node_id].next;
    int left_neighbour  = list->data[node_id].prev;
    list->data[node_id].number = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    list->data[right_neighbour].prev = left_neighbour;
    list->data[left_neighbour].next  = right_neighbour;
}

void DeleteTail(List* list, int node_id) {

    int node_id_neighbour      = list->data[node_id].prev;
    list->data[node_id].number = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    list->tail = node_id_neighbour;
    list->data[node_id_neighbour].next = 0;   
}

void DeleteHead(List* list, int node_id) {

    int node_id_neighbour      = list->data[node_id].next;
    list->data[node_id].number = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    list->head = node_id_neighbour;
    list->data[node_id_neighbour].prev = 0;   
}

void AddFreeNodeAfterDelete(List* list, int node_id) {

    int old_free_node = list->free_node;

    list->data[old_free_node].prev = node_id;
    list->free_node = node_id;
    list->data[node_id].next = old_free_node;
    list->data[node_id].prev   = list->data[old_free_node].prev;
}

List ListLinerize(List* list) {

    node* new_data = (node*) calloc(list->capacity, sizeof(node));

    int list_ptr     = list->head;
    int node_counter = 0;

    new_data[node_counter].prev   = 0;
    new_data[node_counter].number = 0;
    new_data[node_counter].next   = 0;

    for (node_counter = 1; node_counter < list->capacity; node_counter++, list_ptr = list->data[list_ptr].next) {

        new_data[node_counter].prev   = node_counter - 1;
        new_data[node_counter].number = list->data[list_ptr].number;
        new_data[node_counter].next   = node_counter + 1;
    }

    list->free_node = node_counter;

    free(list->data);
    list->data = new_data;

    return *list;
}

void ListCtor(List* list, int capacity, int line, const char* func, const char* file) {

    list->capacity = capacity;

    list->data = (node*) calloc(capacity, sizeof(node));
    Validator(list->data == nullptr, "in calloc: couldn't give memory", PrintFuncPosition(); exit(EXIT_FAILURE););

    list->data[0].prev   = Null_Elem;
    list->data[0].number = 0;
    list->data[0].next   = Null_Elem;

    list->size = ListInitSize;
    list->tail = Null_Node;
    list->head = Null_Node;
    list->data[Null_Node].next = 0;
    list->data[Null_Node].prev = 0;

    list->free_node = 1;

    for (int node_number = 1; node_number < capacity; node_number++) {
        list->data[node_number].prev   = node_number - 1;
        list->data[node_number].number = Free_Node;
        list->data[node_number].next   = node_number + 1;
    }

    list->list_is_linear = true;
}


void ListDtor(List* list, int line, const char* func, const char* file) {
    
    list->tail = 0;
    list->size = 0;

    for (int node_number = 1; node_number < list->capacity; node_number++) {
        list->data[node_number].prev   = 0;
        list->data[node_number].number = 0;
        list->data[node_number].next   = 0;
    }
    list->capacity = 0;

    free(list->data);
    list -> data = nullptr;
}

void PrintElementInfo(List* list, int elem_id) {

    if (elem_id < 0 || elem_id >= list->capacity) {
        fprintf(stderr, "" Red "error: " Grey " there is not element with such index in the list\n");
        return ;
    }
    Validator((elem_id < 0 || elem_id >= list->capacity), "invalid elem index"; PrintFuncPosition();  return ;);

    fprintf(stderr, "\t\t" Purple Blinking "Element Dump" Grin "\n");
    fprintf(stderr, "prev index: %d\n", list->data[elem_id].prev);
    fprintf(stderr, "index:      %d\n", elem_id);
    fprintf(stderr, "next index: %d\n", list->data[elem_id].next);
    fprintf(stderr, "value:      %lg\n" Grey "", list->data[elem_id].number);
}

void ListInform(List* list, int line, const char* func, const char* file) {

    PrintListDump();
    PrintFuncPosition();

    fprintf(stderr, "\n");
    fprintf(stderr, "list data ptr    =  %p\n", list->data);
    fprintf(stderr, "list head        =  %d\n", list->head);
    fprintf(stderr, "list tail        =  %d\n", list->tail);
    fprintf(stderr, "list capacity    =  %d\n", list->capacity);
    fprintf(stderr, "list size        =  %d\n", list->size);
    fprintf(stderr, "list free node   =  %d\n\n", list->free_node);

    fprintf(stderr, "list elemenst from 'head' to 'tail' in order:\n");
    int data_num = 1;
    int elem_id  = list->head;

    fprintf(stderr, "" Blue "---------------------------------------------------------------------------------------------" Grey "\n");
    for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].next) {
        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    }
        fprintf(stderr, "elem_id = %d\n", elem_id);

    fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);
    fprintf(stderr, "" Blue "---------------------------------------------------------------------------------------------" Grey "\n");
    fprintf(stderr, "list elemenst from 'tail' to 'head' in order:\n");
    data_num = 1;
    elem_id  = list->tail;
    
    for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].prev) {
        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    }
        fprintf(stderr, "elem_id = %d\n", elem_id);

    fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);                    
    PrintListDumpEnd();
}