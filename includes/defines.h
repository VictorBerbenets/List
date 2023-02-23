#ifndef Define_h
#define Define_h

#define PrintFuncPosition() fprintf(stderr, "%s was called from:" White " %s:%s:%d\n" Grey "", __PRETTY_FUNCTION__, file, func, line)
#define ListConstructor(list, capacity) ListCtor(&list, capacity,  __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define ListDestructor(list) ListDtor(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define ListDump(list) ListInform(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define FindFreeCell() list->free_cell = list->data[list->free_cell].next

#define PrintListDump() fprintf(stderr, "\n" Blue "**************************************************************************"   \
    "*******************\n");                                                                                                     \
    fprintf(stderr, "------------------------------------------" Blinking "List Dump" Blue "------------------------------"        \
    "------------\n");                                                                                                              \
    fprintf(stderr, "*********************************************************************************************" Grey "\n");

#define PrintListDumpEnd() fprintf(stderr, "*[%d] = %lg <------ End of list\n", data_num, list->data[elem_id].number);                    \
    fprintf(stderr, "" Blue "*********************************************************************************************\n");            \
    fprintf(stderr, "---------------------------------------" Blinking "End Dump" Blue "----------------------------------------------\n"); \
    fprintf(stderr, "*********************************************************************************************" Grey "\n\n");


#endif