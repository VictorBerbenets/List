#ifndef Define_h
#define Define_h

#define PrintFuncPosition(func_name) fprintf(stderr, "%s was called from:" White " %s:%s:%d\n" Grey "", #func_name, file, func, line);
#define ListConstructor(list, capacity) ListCtor(&list, capacity,  __LINE__, __PRETTY_FUNCTION__, __FILE__);
#define ListDestructor(list) ListDtor(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__);
#define ListDump(list) ListInform(&list, __LINE__, __PRETTY_FUNCTION__, __FILE__);

#endif