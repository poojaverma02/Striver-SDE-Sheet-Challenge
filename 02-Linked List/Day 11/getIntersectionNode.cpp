// T.C: O(N + M)
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/find-the-intersection-point-of-y-ll?source=strivers-sde-sheet

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Edge case
        if (headA == NULL || headB == NULL) return NULL;

        // Initialize two pointers to traverse the lists
        ListNode *d1 = headA;
        ListNode *d2 = headB;

        // Traverse both lists until the pointers meet
        while (d1 != d2) {
            d1 = (d1 == NULL) ? headB : d1->next;
            d2 = (d2 == NULL) ? headA : d2->next;
        }
        return d1;

        // Return the intersection node
        return d1;
    }
};