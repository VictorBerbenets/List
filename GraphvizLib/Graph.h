#ifndef GRAPH_H
#define GRAPH_H

#define DotPrint(...) fprintf(dot_file, __VA_ARGS__);

#define DotStartGraph(file_name)         \
    const int Name_Size = 100;            \
    char file[Name_Size] = file_name;      \
    FILE* dot_file = fopen(file, "w+");     

#define SetRankdir(dir) fprintf(dot_file, "rankdir = %s", #dir);

#define DotSetGraph(GraphStyle) fprintf(dot_file, "%s", #GraphStyle)

#define DotSetEdge(SetStyle) fprintf(dot_file, "%s", #SetStyle)

#define DotSetNodeStyle(shape, style, fillcolor, fontcolor, margin) \
    fprintf(dot_file, "node [shape=%s, style=%s, fillcolor=%s, fontcolor=%s, margin = %s];", \
    #shape, #style, #fillcolor, #fontcolor, #margin);

#define DotSetNode(node_name, shape, style, fillcolor, fontcolor, margin) \
    fprintf(dot_file, "node [shape=%s, style=%s, fillcolor=%s, fontcolor=%s, margin = %s];", \
    #shape, #style, #fillcolor, #fontcolor, #margin);

#define DotSetLinkStyle()

#define DotCreateNode()


#define DotEndGraph(file_name)                 \
    DotPrint("}")                               \
    fclose(file_name);                     

#define PrintGraph(file, picture_numb)                                              \
    const int dot_len = 150;                                                         \
    char dot_png[dot_len] = "";                                                       \
    sprintf(dot_png, "dot -Tpng %s -o data//graph_%d.png", file, picture_numb);        \
    system(dot_png);

#endif