/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void reverseLinkedList(ListNode* leftOfLeftNode, ListNode* leftNode, ListNode* rightNode){
        auto currNode = leftNode;

        ListNode* rightOfRightNode = rightNode -> next;
        ListNode* nextNode = leftNode -> next;

        while(currNode != rightNode){
            auto nextNextNode = nextNode -> next;
            nextNode -> next = currNode;
            currNode = nextNode;
            nextNode = nextNextNode;
        }
        
        if(leftOfLeftNode != NULL) leftOfLeftNode -> next = rightNode;
        leftNode -> next = rightOfRightNode;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* leftOfLeftNode = NULL;
        ListNode* prevNode = NULL;
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        ListNode* rightOfRightNode = NULL;
        ListNode* nextNode = NULL;
        
        int position = 1;
        ListNode* currNode = head;
        while(currNode != NULL){
            if(position == left){
                leftNode = currNode;
                leftOfLeftNode = prevNode;
                nextNode = leftNode -> next;
            }
            if(position == right){
                rightNode = currNode;
                rightOfRightNode = rightNode -> next;
            }

            if(left <= position && position <= right){
                auto nextNextNode = nextNode -> next;
                nextNode -> next = currNode;
                currNode = nextNode;
                nextNode = nextNextNode;
            }

            prevNode = currNode;
            currNode = currNode -> next;
            position++;
        }

        if(leftOfLeftNode != NULL) leftOfLeftNode -> next = rightNode;
        leftNode -> next = rightOfRightNode;
        
        //reverseLinkedList(leftOfLeftNode, leftNode, rightNode);

        return (head == leftNode) ? rightNode : head;
    }
};
