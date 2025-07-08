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
    public int pairSum(ListNode head) {
        int listSize = 0;
        ListNode currentNode = head;
        while(currentNode != null) {
            listSize++;
            currentNode = currentNode.next;
        }

        int halfSize = listSize/2 - 1;
        currentNode = head;
        while(halfSize > 0) {
            currentNode = currentNode.next;
            halfSize--;
        }

        ListNode prevNode = null;
        while(currentNode != null) {
            // System.out.println(currentNode.val);

            ListNode nextNode = currentNode.next;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        ListNode backPointer = prevNode;
        ListNode frontPointer = head;
        int maxValue = 0;
        while(true) {
            System.out.println(frontPointer.val);
            System.out.println(backPointer.val);
            System.out.println();

            maxValue = Math.max(maxValue, frontPointer.val + backPointer.val);

            if(backPointer.next == frontPointer) {
                break;
            }

            frontPointer = frontPointer.next;
            backPointer = backPointer.next;
        }

        return maxValue;
    }
}
