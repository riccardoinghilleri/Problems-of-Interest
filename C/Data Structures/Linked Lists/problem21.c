/* Problem 2.1
 * Write code to remove duplicates from an unsorted linked list. Temporary buffer is not allowed.
 *
 * Solution
 * - Time complexity: O(n^2).
 * - Space complexity: O(1)
 * If we use a temporary buffer we will be able to reach time and space complexities both equal to O(n).
 * Look at the Java implementation for this solution.
 */

#include "stdio.h"
#include "lists.h"

void delete_duplicates(list l);

int main() {
    list l = NULL;
    l = tail_insert(l, 3);
    l = tail_insert(l, 2);
    l = tail_insert(l, 3);
    l = tail_insert(l, 1);
    l = tail_insert(l, 1);
    l = tail_insert(l, 5);
    printf("Starting list: ");
    print_list(l);
    delete_duplicates(l);
    printf("Ending list: ");
    print_list(l);

    return 0;
}

void delete_duplicates(list l) {
    list temp = l, cur = NULL;
    while(temp != NULL) {
        cur = temp;
        while(cur -> next != NULL) {
            if(temp -> data == (cur -> next) -> data)
                cur -> next = (cur -> next) -> next;
            else
                cur = cur -> next;
        }
        temp = temp -> next;
    }
}
