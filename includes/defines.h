#ifndef Define_h
#define Define_h

#define PrintFuncPosition(output) fprintf(output, "%s was called from:%s:%s:%d\n", __PRETTY_FUNCTION__, file, func, line)
#define ListConstructor(list, capacity) ListCtor(&list, capacity,  __LINE__, __PRETTY_FUNCTION__, __FILE__)
#define ListDestructor(list) ListDtor(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__)

#define ListDump(list, ...)                                             \
    sprintf(string,__VA_ARGS__);                                         \
    ListInform(&list, string, __LINE__, __PRETTY_FUNCTION__, __FILE__);

#define PrintDot(...) fprintf(dot_file, __VA_ARGS__);
#define PrintLog(...) fprintf(list_log, __VA_ARGS__);

#endif