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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* front = head;
        ListNode* back = dummy;
        for(int i = 0; i < n; i++)
        {
            front = front->next;
        }

        while(front != nullptr)
        {
            front = front -> next;
            back = back -> next;
        }

        back->next = back->next->next;

        return dummy->next;
    }
};