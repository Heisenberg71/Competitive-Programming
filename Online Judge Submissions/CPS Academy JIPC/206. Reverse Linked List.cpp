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
public:
    ListNode* reverseList(ListNode* head) {
        // base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // reverse the current node's pointer
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current_node = head;
        stack<int> nodeValues;
        while(current_node != nullptr) {
            nodeValues.push(current_node -> val);
            current_node = current_node -> next;
        }

        current_node = head;
        while(current_node != nullptr) {
            current_node -> val = nodeValues.top();
            nodeValues.pop();
            current_node = current_node -> next;
        }

        return head;
    }
};
