#ifndef NODE_H
#define NODE_H

struct node{
    char * data;
    struct node * next;
    struct node * left;
    struct node * right;
    struct node * similar;
    int occurances;
    int versions;
};

struct node * add(struct node *, char *);
struct node * insert(struct node *, char *);
void iot(struct node *);

#endif
