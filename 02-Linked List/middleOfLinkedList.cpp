// T.C: O(N/2)  
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-middle-of-linked-list?source=strivers-sde-sheet

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
   public:
    // Hare & Tortoise (Fast & Slow Pointer) Approach
    // Slow pointer moves 1 step at a time
    // Fast pointer moves 2 steps at a time
    // When fast reaches the end, slow will be at the middle

    ListNode* middleOfLinkedList(ListNode* head) {
        // Initialize both pointers at the head
        ListNode* slow = head;
        ListNode* fast = head;

        // Continue until fast reaches the end
        // Check fast and fast->next to avoid null pointer access
        while (fast != NULL && fast->next != NULL) {
            // Move slow pointer by 1 node
            slow = slow->next;

            // Move fast pointer by 2 nodes
            fast = fast->next->next;
        }

        // Slow pointer now points to the middle node
        // For even-length lists, it returns the second middle node
        return slow;
    }
};
