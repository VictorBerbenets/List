#ifndef LISTIK_H
#define LISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "Validator.h"
#include "defines.h"
#include "..//GraphvizLib//Graph.h"

typedef double elem_t;
const int MaxDotCommand_Len = 150;
const int MaxStringLen      = 200;
const int FileName = 50;

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
    int Dump_Number;

} List;

enum List_params {

    Free_Node         =  -0xDEADFEED,
    ListIsLinerized   =  333,
    AdditionalMemory  =  50,
    ListIsCleared     =  9,
    FirstListElem     =  1,
    ListInitSize      =  1,
    Null_Elem         =  0,
    Null_Node         =  0,
};

enum ListErrors {

    MEM_ALLOCATED_ERR   = 5353535, 
    INVALID_LOGIC_ID    = -101,
    INVALID_NODE_ID     = 100,
    CLOSE_FILE_ERROR    = 0XDEADFEED,
    OPEN_FILE_ERROR     = 0XDEADBABE,
} ;

void ListCtor(List* list, int capacity, int line, const char* func, const char* file);

void ListDtor(List* list, int line, const char* func, const char* file);

void ListInform(List* list, const char* text, int line, const char* func, const char* file);

elem_t ListPushTail(List* list, elem_t value);

elem_t ListPushHead(List* list, elem_t value);

elem_t ListPushRight(List* list, int cell_id, elem_t value);

elem_t ListPushLeft(List* list, int cell_id, elem_t value);

int FindLogicAddress(List* list, int phys_id);

int FindPhysAddress(List* list, int logic_id);

int FindFirstListElem(List* list, elem_t value);

inline void FindFreeNode(List* list);

int ListDeleteNode(List* list, int cell_id);

void DeleteNode(List* list, int node_id);

void DeleteTail(List* list, int cell_id);

void DeleteHead(List* list, int cell_id);

void AddFreeNodeAfterDelete(List* list, int cell_id);

List ListResize(List* list, int new_capacity);

int ListLinearize(List* list);

int ListGraph(List* list);

void ClearList(List* list);

#endif