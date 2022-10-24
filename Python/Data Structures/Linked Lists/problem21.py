# Problem 2.1
# Write code to remove duplicates from an unsorted linked list. Temporary buffer is not allowed.
#
# Solution
# - Time complexity: O(n^2).
# - Space complexity: O(1)
# If we use a temporary buffer we will be able to reach time and space complexities both equal to O(n).
# Look at the Java implementation for this solution.

import LinkedList as ll


def delete_duplicates(linked_list):
    temp = linked_list.head
    while temp is not None:
        cur = temp
        while cur.next is not None:
            if temp.data == cur.next.data:
                cur.next = cur.next.next
            else:
                cur = cur.next
        temp = temp.next


l = ll.LinkedList()
l.head_insert(4)
l.head_insert(4)
l.head_insert(2)
l.head_insert(0)
l.head_insert(2)
print("Starting list:", end=" ")
l.print_list()
delete_duplicates(l)
print("Ending list:", end=" ")
l.print_list()
