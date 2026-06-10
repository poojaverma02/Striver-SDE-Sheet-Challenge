// T.C: O(N)  
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/remove-nth-node-from-the-back-of-the-ll?source=strivers-sde-sheet

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Creating pointers
        ListNode* fastp = head;
        ListNode* slowp = head;

        /*Move the fastp pointer
        N nodes ahead*/
        for (int i = 0; i < n; i++) {
            fastp = fastp->next;
        }

        /*If fastp becomes NULL
        the Nth node from the
        end is the head*/
        if (fastp == NULL) {
            return head->next;
        }

        /*Move both pointers
        Until fastp reaches the end*/
        while (fastp->next != NULL) {
            fastp = fastp->next;
            slowp = slowp->next;
        }

        // Delete the Nth node from the end
        ListNode* delNode = slowp->next;
        slowp->next = slowp->next->next;
        delete delNode;
        return head;
    }
};