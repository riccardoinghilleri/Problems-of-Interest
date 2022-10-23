#ifndef C_LISTS_H
#define C_LISTS_H

#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *next;
};

typedef struct node *list;

list head_insert(list l, int data) {
    list temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = l;
    return temp;
}

list tail_insert(list l, int data) {
    if(l == NULL) return head_insert(l, data);
    else {
        l -> next = tail_insert(l -> next, data);
        return l;
    }
}

list head_remove(list l) {
    if(l != NULL) {
        list temp = l;
        l = l -> next;
        free(temp);
    }
    return l;
}

list tail_remove(list l) {
    if(l != NULL){
        if(l -> next == NULL) return head_remove(l);
        else {
            l -> next = tail_remove(l -> next);
            return l;
        }
    } else return l;
}

list element_remove(list l, int data) {
    if(l == NULL) return l;
    if(l -> data == data) return head_remove(l);
    else {
        l -> next = element_remove(l -> next, data);
        return l;
    }
}

void print_list(list l) {
    while(l != NULL) {
        printf("%d -> ", l -> data);
        l = l-> next;
    }
    printf("NULL\n");
}
#endif
