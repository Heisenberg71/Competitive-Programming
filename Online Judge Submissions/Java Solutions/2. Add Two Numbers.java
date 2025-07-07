/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyNode = new ListNode(0);
        ListNode startNode = dummyNode;
        int carry = 0;
        while(l1 != null || l2 != null) {
            int sum = carry;
            carry = 0; 
            if(l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            startNode.next = new ListNode(sum);
            startNode = startNode.next;
        }
        if(carry == 1) {
            startNode.next = new ListNode(1);
        }
        return dummyNode.next;
    }
}
