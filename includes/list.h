#ifndef LISTIK_H
#define LISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "Validator.h"
#include "defines.h"



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

    Null_Elem  =  -0XDEADBABE123,
    Free_Cell  =  1,
    Null_Node  =  0,
};

void ListCtor(List* list, int capacity, int line, const char* func, const char* file);

void ListDtor(List* list, int line, const char* func, const char* file);

void ListInform(List* list, int line, const char* func, const char* file);

int ListPushRight(List* list, int cell_id, elem_t value);

int ListPushLeft(List* list, int cell_id, elem_t value);




#endif