// T.C: O(N) 
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/reverse-a-ll?source=strivers-sde-sheet

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
    // Iterative solution
    // Before changing a pointer (temp->next), always save the original next
    // node (front = temp->next), otherwise you lose access to the rest of the
    // linked list.
    ListNode* reverseList(ListNode* head) {
        // temp points to head because we dont hamper the original data
        // Points to the current node being processed.
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            // pointer-manipulation technique
            // Stores the next node before changing links.
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};