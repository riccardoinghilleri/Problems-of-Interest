/* My Linked List Implementation
 *
 * I have kept the methods and variables public because I often needed this access. I know that this would allow
 * the user to "destroy" the linked list.
 * */

package DataStructures.LinkedLists;

public class LinkedListNode {
    public Integer data;
    public LinkedListNode next;

    public LinkedListNode(Integer data) {
        this.data = data;
        this.next = null;
    }

    public LinkedListNode() {}

    public LinkedListNode head_insert(Integer data) {
        if(this.data == null && this.next == null) {
            this.data = data;
            return this;
        }
        else {
            LinkedListNode temp = new LinkedListNode(data);
            temp.next = this;
            return temp;
        }
    }

    public void print_list() {
        LinkedListNode temp = this;
        while(temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

}
