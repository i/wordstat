#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#include "node.h"

struct node * add(struct node * head, char * data){
    struct node * t = (struct node *)malloc(sizeof( struct node ) );
    t->data = (char *)malloc(sizeof(char)*strlen(data)+1);
    strcpy(t->data, data);
    t->next = head;
    return t;
}

struct node * insert(struct node * head, char * data){
    struct node * ptr = head;
    struct node * prev;
    struct node * t;
    struct node * sptr;
    int c = 0;

    t = (struct node *)malloc( sizeof(struct node) );
    t->occurances = 1;
    t->versions = 1;
    t->data = (char *)malloc( sizeof(char)*strlen(data)+1);
    strcpy(t->data, data);

/*    printf("inserting %s\n",data);*/
    while ( ptr != NULL ){
        prev = ptr;
        c = strcasecmp( data, ptr->data );
/*        printf("%d\n",c);*/
        if (c == 0){
/*            printf("%s and %s are equal\n", data, ptr->data);*/
            ptr->occurances++;
            sptr = ptr;
            while ( sptr != NULL ){
                if( (strcmp(data, sptr->data)) == 0 ){
                    break;
                }
                ptr->versions++;
                prev = ptr;
                sptr = sptr->similar;
            }
            break;
        }
        else if (c < 0){
/*            printf("%s < %s\n", data, ptr->data);*/
            ptr = ptr->left;
        }
        else if (c > 0){
            ptr = ptr->right;
        }
    }
    if (head == NULL){
/*        printf("head NULL...new tree\n");*/
        return t;
    }
    if ( c < 0 ){
        prev->left = t;
        return head;
    }
    else if (c > 0){
        prev->right = t;
        return head;
    }
    return head;
}

void iot(struct node * ptr){
    if(ptr->left != NULL){
        iot(ptr->left);
    }
    printf("%s\t\t\t%d\t\t\t%d\n", ptr->data, ptr->occurances, ptr->versions);
    if(ptr->right != NULL){
        iot(ptr->right);
    }
    return;
}
