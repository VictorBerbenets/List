#include "..//includes//list.h"

// graphviz

elem_t List::ListPushTail(List *list, elem_t value) {

    if (size_ >= capacity_) {
        ListResize(list, size_ + AdditionalMemory);
    }

    int new_tail_id = free_node_;
    data_[new_tail_id].number_ = value;
    data_[new_tail_id].prev_   = tail_;

    if (size_ == ListInitSize) {
        head_ = new_tail_id;
    }

    data_[tail_].next_ = new_tail_id;
    tail_ = new_tail_id;

    FindFreeNode(list);

    data_[tail_].next_ = 0;
    size_ ++;

    return value;
}

elem_t List::ListPushHead(List *list, elem_t value) {

    if (size_ >= capacity_) {
        ListResize(list, size_ + AdditionalMemory);
    }

    list_is_linear_ = false;
    int new_head_id = free_node_;

    data_[new_head_id].number_ = value;
    data_[new_head_id].prev_   = 0;

    if (size_ == ListInitSize) {

        list_is_linear_ = true;
        tail_           = new_head_id;
    }

    data_[head_].prev_ = free_node_;

    FindFreeNode(list);

    data_[new_head_id].next_ = head_;
    head_ = new_head_id;

    size_++;

    return value;
}

inline void List::FindFreeNode(List* list) {

    free_node_ = data_[free_node_].next_;
}

elem_t List::ListPushRight(List *list, int node_id, elem_t value) {

    if (node_id <= 0 || node_id >= capacity_) {
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
        return INVALID_NODE_ID;
    }

    if (data_[node_id].number_ == Free_Node) {

        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id. This elem is not a part of the list: %d\n",
                __PRETTY_FUNCTION__, __LINE__, node_id);
        return INVALID_NODE_ID;
    }

    if (size_ >= capacity_) {
        ListResize(list, size_ + AdditionalMemory);
    }

    if (size_ == ListInitSize || node_id == tail_) {

        return ListPushTail(list, value);
    }


    int new_elem_id = GetFree();
    int node_id_neighbour = data_[node_id].next_;

    data_[new_elem_id].number_ = value;

    FindFreeNode(list);

    data_[new_elem_id].next_ = node_id_neighbour;
    data_[node_id_neighbour].prev_ = new_elem_id;
    data_[node_id].next_ = new_elem_id;
    data_[new_elem_id].prev_ = node_id;

    size_++;
    list_is_linear_ = false;

    return value;
}

elem_t List::ListPushLeft(List *list, int node_id, elem_t value) {

    if (node_id <= 0 || node_id >= capacity_) {
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id: %d\n", __PRETTY_FUNCTION__, __LINE__, node_id);
        return INVALID_NODE_ID;
    }

    if (data_[node_id].number_ == Free_Node) {

        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey "invalid node id. This elem is not a part of the list: %d\n",
                __PRETTY_FUNCTION__, __LINE__, node_id);
        return INVALID_NODE_ID;
    }

    if (size_ >= capacity_) {
        ListResize(list, size_ + AdditionalMemory);
    }

    if (size_ == ListInitSize || node_id == head_) {

        return ListPushHead(list, value);
    }

    int left_neighbour = data_[node_id].prev_;

    return ListPushRight(list, left_neighbour, value);
}

int List::FindFirstListElem(List *list, elem_t value) {

    int node_id = head_;
    for (int node_counter = 1; node_counter < size_; node_counter++, node_id = data_[node_id].next_) {

        if (data_[node_id].number_ == value) {
            return node_id;
        }
    }

    return -1;
}

int List::FindPhysAddress(List *list, int logic_id) {

    if (size_ == ListInitSize || logic_id <= 0 || logic_id > size_) {
        return INVALID_LOGIC_ID;
    }
    if (logic_id == FirstListElem) {
        return head_;
    }

    int current_node_id = head_;
    for (int node_counter = 1; node_counter < logic_id; node_counter++) {

        current_node_id = data_[current_node_id].next_;
    }

    return current_node_id;
}

int List::FindLogicAddress(List *list, int phys_id) {

    if (size_ == ListInitSize || phys_id <= 0 || phys_id >= capacity_) {
        return INVALID_LOGIC_ID;
    }

    int current_node_id = head_;
    int node_counter = 1;
    for (; current_node_id != phys_id && node_counter != size_; node_counter++) {

        current_node_id = data_[current_node_id].next_;
    }

    return node_counter;
}

int List::ListDeleteNode(List *list, int node_id) {

    int node_id_neighbour = 0;
    if (node_id < 1 || node_id > capacity_ - 1) {
        fprintf(stderr, "" White "%s:%d:" Red " error:" Grey " can't delete this node\n", __PRETTY_FUNCTION__, __LINE__);
        return INVALID_NODE_ID;
    }

    if (size_ == ListInitSize + 1) {
        ClearList(list);
        return ListIsCleared;
    }

    else if (node_id == tail_) {

        DeleteTail(list, node_id);
    }

    else if (node_id == head_) {

        DeleteHead(list, node_id);
    }

    else {
        DeleteNode(list, node_id);
    }

    size_--;

    return node_id;
}

void List::ClearList(List *list) {

    tail_ = 0;
    head_ = 0;

    size_--;
    ListLinearize(list);
}

void List::DeleteNode(List *list, int node_id) {

    int right_neighbour = data_[node_id].next_;
    int left_neighbour  = data_[node_id].prev_;
    data_[node_id].number_ = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    data_[right_neighbour].prev_ = left_neighbour;
    data_[left_neighbour].next_  = right_neighbour;

    list_is_linear_ = false;
}

void List::DeleteTail(List *list, int node_id) {

    int node_id_neighbour  = data_[node_id].prev_;
    data_[node_id].number_ = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    tail_ = node_id_neighbour;
    data_[node_id_neighbour].next_ = 0;
}

void List::DeleteHead(List *list, int node_id) {

    int node_id_neighbour = data_[node_id].next_;
    data_[node_id].number_ = Free_Node;

    AddFreeNodeAfterDelete(list, node_id);

    head_ = node_id_neighbour;
    data_[node_id_neighbour].prev_ = 0;
}

void List::AddFreeNodeAfterDelete(List *list, int node_id) {

    int old_free_node = free_node_;

    data_[old_free_node].prev_ = node_id;
    free_node_ = node_id;

    data_[node_id].next_ = old_free_node;
    data_[node_id].prev_ = data_[old_free_node].prev_;
}

int List::ListLinearize(List *list) {

    if (list_is_linear_ == true) {

        return ListIsLinerized;
    }

    node *new_data = new node[capacity_];
    Validator(new_data == nullptr, "calloc could't give memory", return MEM_ALLOCATED_ERR;);

    int list_ptr = head_;
    if (head_) {
        head_ = 1;
    }

    tail_ = size_ - 1;

    int node_counter = 0;
    new_data[node_counter].prev_   = 0;
    new_data[node_counter].number_ = 0;
    new_data[node_counter].next_   = 0;

    for (node_counter = 1; node_counter < size_; node_counter++, list_ptr = data_[list_ptr].next_) {

        new_data[node_counter].prev_   = node_counter - 1;
        new_data[node_counter].number_ = data_[list_ptr].number_;
        new_data[node_counter].next_   = node_counter + 1;
    }
    for (node_counter = size_; node_counter < capacity_; node_counter++) {

        new_data[node_counter].prev_   = node_counter - 1;
        new_data[node_counter].number_ = Free_Node;
        new_data[node_counter].next_   = node_counter + 1;
    }

    new_data[tail_].next_ = 0;                      // tail.next points to null element
    new_data[node_counter - 1].next_ = node_counter - 1; // last free_node points to itself

    if (size_ != capacity_) {
        free_node_ = size_;
        data_[free_node_].next_ = size_ + 1;
    }
    else {
        free_node_ = 0;
    }

    delete[] data_;
    data_ = new_data;
    list_is_linear_ = true;

    return 0;
}

void List::ListResize(List *list, int new_capacity) { //1 argument, increase size by const

    if (new_capacity < size_) {
        fprintf(stderr, "" White "%s:%d:" Purple "Warning:" Grey "good job, fucker: you just could erased some list's data but I saved "
        "your black ass \n", __PRETTY_FUNCTION__, __LINE__);
        return ;
    }
    node* new_data = new node[new_capacity];
    Validator(new_data == nullptr, "in calloc: couldn't give memory", exit(EXIT_FAILURE););

    int node_id      = head_;
    int node_counter = 0;
    new_data[node_counter].prev_   = Null_Node;
    new_data[node_counter].number_ = Null_Node;
    new_data[node_counter].next_   = Null_Node;

    if (new_capacity != ListInitSize) { //set head
        head_ = 1;
    }
    else {
        head_ = 0;
    }

    for (node_counter = 1; node_counter < new_capacity; node_counter++, node_id = data_[node_id].next_) {

        if (node_counter < size_) {
            new_data[node_counter].number_ = data_[node_id].number_;
        }
        else {
            new_data[node_counter].number_ = Free_Node;
        }
        new_data[node_counter].prev_ = node_counter - 1;
        new_data[node_counter].next_ = node_counter + 1;
    }

    if (node_counter > 1) {
        new_data[node_counter - 1].next_ = node_counter - 1;
    }
    delete[] data_;
    data_ = new_data;

    if (size_ == capacity_) { //set free
        free_node_ = size_;
        data_[free_node_].next_ = size_ + 1;
    }

    tail_ = size_ - 1;
    data_[tail_].next_ = 0;         
    list_is_linear_ = true;
    capacity_       = new_capacity;
}


void List::ListInform(List *list, const char* text, int line, const char *func, const char *file) {

    FILE* list_log = fopen("data//list_log.html", "a");
    Validator(list_log == 0, in opening file, PrintFuncPosition(stderr););
    PrintLog("<pre>\n");
    PrintLog("-----------------------------------List Dump--------------------------------------------------\n");

    PrintFuncPosition(list_log);
    PrintLog("head:%d,\ttail:%d,\tfree node:%d;\ncapacity:%d,\tsize:%d\n", head_, tail_, \
    free_node_, capacity_, size_);
    PrintLog("Action with list: %s", text);

    ListGraph(list);
    PrintLog("<img src=\"../data/graph_%d.png\" width = \"2000px\" height = \"400px\">\n", Dump_Number_);
    PrintLog("---------------------------------------End----------------------------------------------\n\n");

    Dump_Number_++;

    char is_file_closed = fclose(list_log);
    Validator(is_file_closed != 0, in closing file, PrintFuncPosition(stderr););
}

int List::ListGraph(List *list) {

    DotStartGraph("data//list.dot");
    Validator(dot_file == nullptr, in opening file:'data//list.dot', return OPEN_FILE_ERROR;);

    const char dot_header[] = "digraph List {\n"
                              "\tdpi = 100;\n"
                              "\tfontname = \"Comic Sans MS\";\n"
                              "\tfontsize = 20;\n"
                              "\trankdir  = LR;\n";
    PrintDot(dot_header);

    DotSetGraph("lightgreen", 1.3, 0.5, "rounded", "green", 2.);
    DotSetEdge("darkgrey", "onormal", 1., 1.2);

    // General list information
    PrintDot("List_Inform [shape = record, color = yellow, style = solid, label = \"linear:%s | free:%d | size:%d | capacity: %d\"]\n\n",\
            list_is_linear_ == true? "true":"false", free_node_, size_, capacity_);

    PrintDot("node%d [shape = record, color = brown, style = solid, label = \"node_id:%d|<p> prev:%d| value:%d|<n>next:%d\"]\n",
             0, 0, Null_Node, Null_Elem, Null_Node);

    for (int phys_node_id = 1; phys_node_id < capacity_; phys_node_id++)
    {

        if (phys_node_id == head_)
        {
            PrintDot("node%d [shape = record, color = red, style = solid, label = \"node_id:%d|<p> prev:%d| value:%lg|<n>next:%d\"]\n",
                     phys_node_id, phys_node_id, data_[phys_node_id].prev_, data_[phys_node_id].number_, data_[phys_node_id].next_);
        }
        if (phys_node_id == tail_)
        {
            PrintDot("node%d [shape = record, color = red, style = solid, label = \"node_id:%d|<p> prev:%d| value:%lg|<n>next:%d\"]\n",
                     phys_node_id, phys_node_id, data_[phys_node_id].prev_, data_[phys_node_id].number_, data_[phys_node_id].next_);
        }
        if (phys_node_id != head_ && phys_node_id != tail_)
        {
            PrintDot("node%d [shape = record, color = %s, style = solid, label = \"node_id:%d|<p> prev:%d| value:%lg|<n>next:%d\"]\n",\
                     phys_node_id, data_[phys_node_id].number_ == Free_Node ? "purple":"green", phys_node_id, data_[phys_node_id].prev_,\
                     data_[phys_node_id].number_, data_[phys_node_id].next_);
        }
    }
    PrintDot("\n\n\n");

    // making invisible connections
    int node_ptr = head_;
    PrintDot("edge[style=invis, constraint = true]")
    PrintDot("node%d ", Null_Node);
    for (int i = 1; i < size_; i++, node_ptr = data_[node_ptr].next_) {
        PrintDot("-> node%d ", node_ptr);
    }

    node_ptr = free_node_;
    PrintDot("-> node%d ", node_ptr);
    node_ptr = data_[node_ptr].next_;
    for (int i = size_; i < capacity_; i++, node_ptr = data_[node_ptr].next_) {
        PrintDot("-> node%d ", node_ptr);
    }
    PrintDot("\nHead -> node%d\n", head_);
    PrintDot("Tail -> node%d\n", tail_);
    PrintDot("Free_Node -> node%d\n", free_node_);
    PrintDot("Null -> node%d\n", Null_Node);
    
    // making visible connections
    PrintDot("edge[style=solid, constraint = false]")
    PrintDot("node%d:p -> node%d;", head_, Null_Elem);
    PrintDot("node%d:n ", head_);

    int node_id = head_;
    int prev_id = node_id;
    node_id = data_[node_id].next_;
    int phys_node_id = 1;
    for ( ; phys_node_id < size_; phys_node_id++, node_id = data_[node_id].next_) {
        if (node_id == 0) {
            break;
        }
        PrintDot("-> node%d;", node_id);
        PrintDot("node%d:p ->node%d;", node_id, prev_id);
        PrintDot("node%d:n ", node_id);

        prev_id = node_id;
    }
    PrintDot(" -> node%d\n", node_id);

    node_id = free_node_;
    prev_id = node_id;
    PrintDot("node%d:n ", node_id);
    node_id = data_[node_id].next_;
    for ( ; phys_node_id < capacity_ - 2; phys_node_id++, node_id = data_[node_id].next_) {
        if (node_id == capacity_) {
            break;
        }
        PrintDot("-> node%d ", node_id);
        PrintDot("node%d:p ->node%d;", node_id, prev_id);
        PrintDot("node%d:n ", node_id);

        prev_id = node_id;
    }
    PrintDot(" -> node%d\n", node_id);

    PrintDot("Head -> node%d\n", head_);
    PrintDot("Tail -> node%d\n", tail_);
    PrintDot("Free_Node -> node%d\n", free_node_);
    PrintDot("Null -> node%d\n", Null_Node);

    DotEndGraph(dot_file);
    DotPrintGraph(file, Dump_Number_);

    return Dump_Number_;
}
elem_t List::GetValue(int id) {
    return data_[id].number_;
}
int List::GetSize() {
    return size_;
}
int List::GetCap() {
    return capacity_;
}
int List::GetTail() {
    return tail_;
}
int List::GetHead() {
    return head_;
}
int List::GetFree() {
    return free_node_;
}
int List::GetLinear() {
    return list_is_linear_;
}
int List::GetDumpNum() {
    return Dump_Number_;
}