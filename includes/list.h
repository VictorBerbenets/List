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
    int free_node;
    int list_is_linear;

} List;

enum List_params {

    Free_Node         =  -0xDEADFEED,
    Null_Elem         =  -777,
    ListIsLinerized   =  333,
    AdditionalMemory  =  10,
    ListIsCleared     =  9,
    FirstListElem     =  1,
    ListInitSize      =  1,
    Null_Node         =  0,
};

enum ListErrors {

    InvalidLogicId = -101,
    InvalidNodeId  = 100,
    MemoryGetError,
} ;

void ListCtor(List* list, int capacity, int line, const char* func, const char* file);

void ListDtor(List* list, int line, const char* func, const char* file);

void ListInform(List* list, int line, const char* func, const char* file);

void PrintElementInfo(List* list, int elem_id);

int ListPushTail(List* list, elem_t value);

int ListPushHead(List* list, elem_t value);

int ListPushRight(List* list, int cell_id, elem_t value);

int ListPushLeft(List* list, int cell_id, elem_t value);

int FindLogicAddress(List* list, int phys_id);

int FindPhysAddress(List* list, int logic_id);

int FindFirstListElem(List* list, elem_t value);

int ListDeleteNode(List* list, int cell_id);

void DeleteNode(List* list, int node_id);

void DeleteTail(List* list, int cell_id);

void DeleteHead(List* list, int cell_id);

void AddFreeNodeAfterDelete(List* list, int cell_id);

List ListResize(List* list, int new_capacity);

int ListLinerize(List* list);

void ClearList(List* list);

#endif