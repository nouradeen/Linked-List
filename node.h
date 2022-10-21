#ifndef NODE_H
#define NODE_H

struct nodeEl{
    int el;
    struct nodeEl * next;
};

typedef struct nodeEl node_t;

# endif /*NODE_H*/