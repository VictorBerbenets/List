#ifndef Define_h
#define Define_h

#define PrintFuncPosition() fprintf(stderr, "%s was called from:" White " %s:%s:%d\n" Grey "", __PRETTY_FUNCTION__, file, func, line)
#define ListConstructor(list, capacity) ListCtor(&list, capacity,  __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define ListDestructor(list) ListDtor(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define ListDump(list) ListInform(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define FindFreeNode() list->free_node = list->data[list->free_node].next

#define PrintListDump()                                                                                                          \
    fprintf(stderr, "\n" Blue "*********************************************************************************************\n"); \
    fprintf(stderr, "------------------------------------------" Blinking "List Dump" Blue "------------------------------"        \
    "------------\n");                                                                                                              \
    fprintf(stderr, "*********************************************************************************************" Grey "\n");

#define PrintListDumpEnd()                                                                                                                \
    fprintf(stderr, "" Blue "*********************************************************************************************\n");            \
    fprintf(stderr, "---------------------------------------" Blinking "End Dump" Blue "----------------------------------------------\n"); \
    fprintf(stderr, "*********************************************************************************************" Grey "\n\n");

#define PrintBlueLine() \
    fprintf(stderr, "" Blue "---------------------------------------------------------------------------------------------" Grey "\n");
#endif