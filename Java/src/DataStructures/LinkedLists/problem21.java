/* Problem 2.1
 * Write code to remove duplicates from an unsorted linked list.
 *
 * Solution
 * - Time complexity: O(n).
 * - Space complexity: O(n).
 */

package DataStructures.LinkedLists;

import java.util.HashSet;

public class problem21 {
    public static void delete_duplicates(LinkedListNode l) {
        HashSet<Integer> set = new HashSet<>();
        LinkedListNode prev = null;
        while(l != null) {
            if(set.contains(l.data)) {
                prev.next = l.next;
            } else {
                set.add(l.data);
                prev = l;
            }
            l = l.next;
        }
    }

    public static void main(String[] args) {
        LinkedListNode l = new LinkedListNode();
        l = l.head_insert(4);
        l = l.head_insert(3);
        l = l.head_insert(5);
        l = l.head_insert(3);
        l = l.head_insert(5);
        l.print_list();
        delete_duplicates(l);
        l.print_list();
    }
}
