#ifndef LISTIK_H
#define LISTIK_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "Validator.h"

#define Func_position(func_name) fprintf(stderr, "%s was called from:" White " %s:%s:%d\n" Grey "", #func_name, file, func, line);

typedef double elem_t;
const int List_size = 1024;

typedef struct {

    elem_t number;
    int next;
    int prev;

} node;

typedef struct {

    node* data;
    int capacity;
    int size;
    int tail;
    int head;
    int free_cell;

} List;

enum List_params {

    free_cell  = -10,
    null_elem  = -1,
    null_node  =  0,
};

#define ListConstructor(list, capacity) ListCtor(&list, capacity,  __LINE__, __PRETTY_FUNCTION__, __FILE__);
void ListCtor(List* list, int capacity, int line, const char* func, const char* file);

#define ListDestructor(list) ListDtor(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__);
void ListDtor(List* list, int line, const char* func, const char* file);

#define ListDump(list) ListInform(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__);
void ListInform(List* list, int line, const char* func, const char* file);



#endif