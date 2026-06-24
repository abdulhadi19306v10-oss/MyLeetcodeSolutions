/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head simplifies list construction
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Continue while there are nodes to process or a carry left over
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from the current nodes, or 0 if the end is reached
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate total sum for this place value
            int sum = carry + x + y;
            
            // Update the carry for the next iteration (e.g., 15 / 10 = 1)
            carry = sum / 10;
            
            // Create a new node with the digit (e.g., 15 % 10 = 5)
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            // Move l1 and l2 pointers forward
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // Store the actual result and clean up the dummy node to prevent memory leaks
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};