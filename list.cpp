#include <stdio.h>
#include <stdlib.h>

enum LIST_INFO {

    LIST_NOT_EMPTY = 0,
    EMPTY_LIST     = 1,
};


typedef double Data;


struct Node {

    struct Node* next_node;
    Data data;
    int  list_size;
} ;

typedef struct Node* List;

Data list_pop(List* list);
Data list_get(List  list);
Node* list_init();

void list_push (List* list, Data value);
void list_destructor (List* list);
void list_dump(List list);
int  is_list_empty(List list);


int main () {
    
    List list = list_init();

    //list_init(&list);

    int number_of_elements = 0;
    scanf("%d", &number_of_elements);
    Data* array_of_arguments = (Data*) calloc(number_of_elements, sizeof(Data));

    for(int i = 0; i < number_of_elements; i++) {
        scanf("%lg", array_of_arguments + i);
        list_push(&list, array_of_arguments[i]);
    }

    // list_destructor(&list);
    list_dump(list);
    for (int i = 0; i < number_of_elements; i++) {
        printf("pop[%d] = %lg\n", i, list_pop(&list));
    }
    list_dump(list);
    
    free(array_of_arguments);

    return 0;
}

List list_init() {

    return nullptr;
}


void list_push(List* list, Data value) {

    List pointer = (List) malloc(sizeof(Node));
    pointer->next_node = *list;
    pointer->data = value;
    //(*list)->list_size ++;
    *list = pointer;

}

Data list_pop(List* list) {
    
    List node_pointer = *list;
    Data return_value = node_pointer->data;

    node_pointer = node_pointer->next_node;
    free(*list);
    *list = node_pointer;

    return return_value;
}

Data list_get(List list) {

    return list->data;
}

int is_list_empty(List list) {

    if (list) {
        return LIST_NOT_EMPTY;
    }
    return EMPTY_LIST;
}


void list_dump(List list) {

    List node_pointer = list;
    //printf("list size = %d\n", list->list_size);
    int number = 0;
    for ( ; !is_list_empty(node_pointer); number++) {
        printf("[%d] = %lg\n", number, node_pointer->data);
        node_pointer = node_pointer->next_node;
    }

    if (number == 0) {
        printf("List is empty\n");
    }
}

void list_destructor (List* list) {

    for ( ; is_list_empty(*list); *list = (*list)->next_node) {
        free(*list);
    }
}