#include "..//includes//list.h"

// graphviz

int ListPushTail(List* list, elem_t value) {

    // if (list->size >= list->capacity) {
    //     fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid list size for push: %d\n", __PRETTY_FUNCTION__, __LINE__, list->size);
    //     return InvalidNodeId;
    // } //call resize
    Validator((list->size >= list->capacity), "invalid elem index"; PrintFuncPosition();  return ;);

    int new_tail_id = list->free_node;
    list->data[new_tail_id].number = value;  
    list->data[new_tail_id].prev = list->tail;

    if (list->size == ListInitSize) {
        list->head = new_tail_id;
    }

    list->data[list->tail].next = new_tail_id; 
    list->tail = new_tail_id;

    FindFreeNode();
    
    list->data[list->tail].next = 0;

    list->size ++;

    return value;
}
//func return list size
int ListPushHead(List* list, elem_t value) {

    if (list->size >= list->capacity) {
        // fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid list size for push: %d\n", __PRETTY_FUNCTION__, __LINE__, list->size);
        // return InvalidNodeId;
    } //call resize
    // Validator((list->size >= list->capacity - 1), "invalid elem index"; PrintFuncPosition();  return ;);

    int new_head_id = list->free_node;

    list->data[new_head_id].number = value;  
    list->data[new_head_id].prev   = 0;

    if (list->size == ListInitSize) {
        list->tail = new_head_id;
    }

    list->data[list->head].prev = list->free_node; 

    FindFreeNode();

    list->data[new_head_id].next = list->head; 
    list->head                   = new_head_id;
        
    list->size ++;
    list->list_is_linear = false;

    return value;
}
//do func to find logic address
int ListPushRight(List* list, int node_id, elem_t value) {

    // if (node_id < 0 || node_id >= list->capacity) {
    //     fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
    //     return InvalidNodeId;
    // }
    if (list->data[node_id].number == Free_Node || list->size >= list->capacity) {

        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
        return InvalidNodeId;
    }

    if (list->size == ListInitSize || node_id == list->tail) {
        
        return ListPushTail(list, value);
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

    // if (node_id <= 0 || node_id >= list->capacity) {
    //     fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
    //     return InvalidNodeId;
    // }
    if (list->data[node_id].number == Free_Node || list->size >= list->capacity) {

        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
        return InvalidNodeId;
    }

    if (list->size == ListInitSize || node_id == list->head) {
        
        return ListPushHead(list, value);
    }

    int left_neighbour = list->data[node_id].prev;

    return ListPushRight(list, left_neighbour, value);
}
// Find for logic index
// Find first elem по значению
// find physical addres on logic and reverse
int FindPhysAddress(List* list, int logic_id) {
    if (logic_id) {
        return ;
    }

    int current_node_id = list->head;
    for (int node_counter = 1; node_counter < logic_id; node_counter++) {

        current_node_id = list->data[current_node_id].next;
    }

    return current_node_id;
}

int FindLogicAddress(List* list, int phys_id) {
    if (phys_id) {
        return ;
    }

    int current_node_id = list->head;
    int node_counter = 1;
    for ( ; current_node_id != phys_id; node_counter++) {

        current_node_id = list->data[current_node_id].next;

        if(node_counter == list->size) {
            break;
        }
    }

    return node_counter;
}

int ListDeleteNode(List* list, int node_id) {

    int node_id_neighbour = 0;
    if (list->data[node_id].number == Free_Node || list->size == ListInitSize) {
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey " can't delete this node\n", __PRETTY_FUNCTION__, __LINE__);
        return InvalidNodeId;
    }
    // Validator(list->data[node_id].number == Free_Node || list->size == ListInitSize, "can't delete this node", PrintFuncPosition(); \
    return -1;)
    if (list->size == ListInitSize + 1) { //check that

        ClearList(list);
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

    return node_id;
}

void ClearList(List* list) {

    list->tail = 0;
    list->head = 0;
    list->data[1].next   = list->free_node;
    list->list_is_linear = false;
    list->free_node      = 1;

    //free node
    //do liner
}

void DeleteNode(List* list, int node_id) {

    int right_neighbour = list->data[node_id].next;
    int left_neighbour  = list->data[node_id].prev;
    list->data[node_id].number = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    list->data[right_neighbour].prev = left_neighbour;
    list->data[left_neighbour].next  = right_neighbour;

    list->list_is_linear = false;
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
    list->data[node_id].prev = list->data[old_free_node].prev;
}

int ListLinerize(List* list) {

    if (list->list_is_linear == true) {

        return ListIsLinerized;
    }
    node* new_data = (node*) calloc(list->capacity, sizeof(node));
    Validator(new_data == nullptr, "calloc could't give memory", return 523);

    int list_ptr     = list->head;
    list->head       = 1;
    list->tail       = list->size - 1;
    int node_counter = 0;

    new_data[node_counter].prev   = 0;
    new_data[node_counter].number = 0;
    new_data[node_counter].next   = 0;

    for (node_counter = 1; node_counter < list->size; node_counter++, list_ptr = list->data[list_ptr].next) {
        new_data[node_counter].prev   = node_counter - 1;
        new_data[node_counter].number = list->data[list_ptr].number;
        new_data[node_counter].next   = node_counter + 1;
    }
    for (node_counter = list->size; node_counter < list->capacity; node_counter++) {
        new_data[node_counter].prev   = node_counter - 1;
        new_data[node_counter].number = Free_Node;
        new_data[node_counter].next   = node_counter + 1;
    }

    new_data[list->tail].next = 0;                      //tail.next points to null element
    new_data[node_counter - 1].next = node_counter - 1; // last free_node points to itself

    list->free_node = list->size;
    list->data[list->free_node].next = list->size + 1;

    free(list->data);
    list->data = new_data;

    list->list_is_linear = true;

    return 0;
}

List ListResize(List* list, int new_capacity) {


    if (new_capacity < list->size) {
        fprintf(stderr, "" White "%s:%d:" Purple "Warning:" Grey "good job, fucker: you just erased some list's data: \n",\
         __PRETTY_FUNCTION__, __LINE__);
    }
    
    ListLinerize(list);
    list->data = (node*) realloc(list->data, new_capacity*sizeof(node));
    // Validator(list->data == nullptr, "in realloc: couldn't give memory", PrintFuncPosition(); exit(EXIT_FAILURE););

    if (new_capacity >= list->capacity) {
        
        int node_id = list->capacity;
        for ( ; node_id < new_capacity; node_id++) {
            list->data[node_id].prev   = node_id - 1;
            list->data[node_id].number = Free_Node;
            list->data[node_id].next   = node_id + 1;
        }

        list->data[node_id - 1].next = node_id - 1;
    }
    else if (list->size < new_capacity) {
        list->data[new_capacity - 1].next = new_capacity - 1;
    }
    else {
        list->size = new_capacity;
        list->tail = new_capacity - 1;
        list->data[list->tail].next = 0;
        list->free_node = new_capacity;
    }

    list->capacity = new_capacity;
    
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
    PrintBlueLine()

    int data_num = 1;
    int elem_id  = list->head;

    for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].next) {
        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    }

    fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);
    PrintBlueLine()

    fprintf(stderr, "list elemenst from 'tail' to 'head' in order:\n");

    data_num = 1;
    elem_id  = list->tail;
    
    for ( ; data_num < list->size; data_num++, elem_id = list->data[elem_id].prev) {
        fprintf(stderr, "[%d] = %lg\n", data_num, list->data[elem_id].number);
    }

    fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);                    
    PrintListDumpEnd();
}