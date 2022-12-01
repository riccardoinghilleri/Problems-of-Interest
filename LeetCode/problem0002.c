#include<stdlib.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *mylist;

mylist head_insert(mylist l, int val) {
    mylist temp = malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = l;
    return temp;
}

mylist tail_insert(mylist l, int val) {
    if (l == NULL) return head_insert(l, val);
    else {
        l->next = tail_insert(l->next, val);
        return l;
    }
}

mylist tail_list_insert(mylist l1, mylist l2) {
    if (l1 == NULL) {
        return l2;
    } else {
        l1->next = tail_list_insert(l1->next, l2);
        return l1;
    }
}

mylist addTwoNumbers(mylist l1, mylist l2) {
    int result, rest = 0;
    mylist temp = l2;
    while (l1 != NULL && temp != NULL) {
        result = (l1->val) + (temp->val) + rest;
        if (result > 9) {
            rest = result / 10;
        } else rest = 0;
        temp->val = result % 10;
        l1 = l1->next;
        temp = temp->next;
    }
    if (l1 != NULL) {
        while (l1 != NULL) {
            l2 = tail_insert(l2, ((l1->val) + rest) % 10);
            rest = (l1->val + rest) / 10;
            l1 = l1->next;
            if (rest == 0) {
                l2 = tail_list_insert(l2, l1);
                break;
            }
        }
    } else {
        while (temp != NULL) {
            int t = temp -> val; //support variable to save temp->val before editing it
            temp -> val = ((temp->val) + rest) % 10;
            rest = (t + rest) / 10;
            temp = temp->next;
            if (rest == 0) {
                break;
            }
        }
    }
    if (rest != 0) l2 = tail_insert(l2, rest);
    return l2;
}

void print(mylist l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main() {
    mylist l1 = NULL, l2 = NULL;
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l1 = head_insert(l1, 9);
    l2 = head_insert(l2, 9);
    l2 = head_insert(l2, 9);
    l2 = head_insert(l2, 9);
    l2 = head_insert(l2, 9);
    print(l1);
    print(l2);
    l2 = addTwoNumbers(l1, l2);
    print(l2);


    return 0;
}