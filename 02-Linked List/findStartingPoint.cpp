// T.C: O(N)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-the-starting-point-in-ll?source=strivers-sde-sheet

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
    // Function to find the first node
    // Of the loop in a linked list
    ListNode* findStartingPoint(ListNode* head) {
        // Initialize a slow and fast
        // Pointers to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect the loop
        while (fast != NULL && fast->next != NULL) {
            // Move slow one step
            slow = slow->next;

            // Move fast two steps
            fast = fast->next->next;

            // If slow and fast meet,
            // a loop is detected
            if (slow == fast) {
                // Reset the slow pointer
                // To the head of the list
                slow = head;

                // Phase 2: Find the first node of the loop
                while (slow != fast) {
                    // Move slow and fast one step
                    // At a time
                    slow = slow->next;
                    fast = fast->next;

                    // When slow and fast meet again,
                    // It's the first node of the loop
                }

                // Return the first node of the loop
                return slow;
            }
        }

        // If no loop is found,
        // Return NULL
        return NULL;
    }
};