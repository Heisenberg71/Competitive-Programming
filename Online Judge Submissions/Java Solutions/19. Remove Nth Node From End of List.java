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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int listSize = 0;
        ListNode currentNode = head;
        while(currentNode != null) {
            listSize++;
            currentNode = currentNode.next;
        }

        int nodeIndexFromBegining = listSize - n - 1;
        ListNode dummyHead = new ListNode(0, head);
        currentNode = dummyHead;
        while(nodeIndexFromBegining >= 0) {
            currentNode = currentNode.next; 
            nodeIndexFromBegining--;
        }
        currentNode.next = currentNode.next.next;

        return dummyHead.next;
    }
}
