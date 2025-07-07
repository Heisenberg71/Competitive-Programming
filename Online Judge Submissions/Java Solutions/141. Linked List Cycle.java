/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) {
            return false;
        }
        ListNode slowPointer = head.next;
        if(slowPointer == null) {
            return false;
        }
        ListNode fastPointer = head.next.next;
        if(fastPointer == null) {
            return false;
        }

        while(fastPointer != slowPointer) {
            if(fastPointer == null) {
                return false;
            }
            slowPointer = slowPointer.next;
            if(fastPointer.next != null) {
                fastPointer = fastPointer.next.next;
            }
            else {
                return false;
            }
        }

        return true;
    }
}
