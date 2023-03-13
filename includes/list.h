#ifndef LISTIK_H
#define LISTIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "colors.h"
#include "Validator.h"
#include "defines.h"
#include "..//GraphvizLib//Graph.h"

typedef double elem_t;
const int MaxDotCommand_Len = 150;
const int MaxStringLen      = 200;
const int FileName = 50;

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

class List {

public:

    List(int capacity) {

    if (capacity <= 0) {
        capacity = AdditionalMemory;
    }
    capacity_ = capacity;
    data_     = new node[capacity_];
    
    (data_[0]).prev_ = Null_Elem;
    data_[0].number_ = 0;
    data_[0].next_   = Null_Elem;

    size_ = ListInitSize;
    tail_ = Null_Node;
    head_ = Null_Node;

    data_[Null_Node].next_ = 0;
    data_[Null_Node].prev_ = 0;
    free_node_ = 1;
    int node_number = 1;
    for (; node_number < capacity_; node_number++) {
        data_[node_number].prev_   = node_number - 1;
        data_[node_number].number_ = Free_Node;
        data_[node_number].next_   = node_number + 1;
    }

    data_[node_number - 1].next_ = node_number - 1;
    list_is_linear_ = true;
    Dump_Number_    = 0;
    }
    
    List(const List &list) {
        
        capacity_ = list.capacity_;
        data_     = new node[capacity_]; 

        Dump_Number_    = list.Dump_Number_;
        list_is_linear_ = list.list_is_linear_;
        free_node_      = list.free_node_;
        size_ = list.size_;
        head_ = list.head_;
        tail_ = list.tail_;

        for (int node_number = 0; node_number < capacity_; node_number++) {
            data_[node_number].prev_   = list.data_[node_number].prev_;
            data_[node_number].number_ = list.data_[node_number].number_;
            data_[node_number].next_   = list.data_[node_number].next_;
        }
    }

    List& operator = (const List &list) {
        delete[] this->data_;
        capacity_ = list.capacity_;
        data_     = new node[capacity_]; 

        Dump_Number_    = list.Dump_Number_;
        list_is_linear_ = list.list_is_linear_;
        free_node_      = list.free_node_;
        size_ = list.size_;
        head_ = list.head_;
        tail_ = list.tail_;
        for (int node_number = 0; node_number < capacity_; node_number++) {
            data_[node_number].prev_   = list.data_[node_number].prev_;
            data_[node_number].number_ = list.data_[node_number].number_;
            data_[node_number].next_   = list.data_[node_number].next_;
        }

        return *this;
    }

    void ListInform(List* list, const char* text, int line, const char* func, const char* file);
    void DeleteNode(List* list, int node_id);
    void DeleteTail(List* list, int cell_id);
    void DeleteHead(List* list, int cell_id);
    void AddFreeNodeAfterDelete(List* list, int cell_id);
    void ClearList(List* list);
    inline void FindFreeNode(List* list);
    elem_t ListPushTail(List* list, elem_t value);
    elem_t ListPushHead(List* list, elem_t value);
    elem_t ListPushRight(List* list, int cell_id, elem_t value);
    elem_t ListPushLeft(List* list, int cell_id, elem_t value);
    int FindLogicAddress(List* list, int phys_id);
    int FindPhysAddress(List* list, int logic_id);
    int FindFirstListElem(List* list, elem_t value);
    int ListDeleteNode(List* list, int cell_id);
    int ListLinearize(List* list);
    int ListGraph(List* list);
    void ListResize(List* list, int new_capacity);

    int GetSize();
    int GetCap();
    int GetTail();
    int GetHead();
    int GetFree();
    int GetLinear();
    int GetDumpNum();
    elem_t GetValue(int id);

    ~List() {
        delete[] data_;
    }

private:
    class node {
    public:
        elem_t number_;
        int next_;
        int prev_;

    };

    node* data_;
    int capacity_;
    int size_;
    int tail_;
    int head_;
    int free_node_;
    int Dump_Number_;
    bool list_is_linear_;
};

#endif