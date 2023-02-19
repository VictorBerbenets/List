#include "list.h"



int main() {

    List list = {};
    ListConstructor(list, 50);
    
    ListDump(list);

    ListDestructor(list);

    return 0;
}