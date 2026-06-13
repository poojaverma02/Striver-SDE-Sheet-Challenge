// T.C: O(N) + O(N - (K % N))
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/rotate-a-ll?source=strivers-sde-sheet

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
    // Function to rotate the list by k steps
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        // Calculating length
        ListNode* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            ++length;
            temp = temp->next;
        }

        // Link last node to first node
        temp->next = head;
        // When k is more than length of list
        k = k % length;
        // To get end of the list
        int end = length - k;
        while (end-- > 0) temp = temp->next;

        // Breaking last node link and pointing to NULL
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};