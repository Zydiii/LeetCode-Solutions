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
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            if(fast->next != nullptr)
                fast = fast->next;
        }

        ListNode *last = slow->next;
        slow->next = nullptr;

        linkList(head, reverseList(last), dummy);
    }

    void linkList(ListNode* first, ListNode* last, ListNode* head)
    {
        ListNode *prev = head;
        while(first != nullptr && last != nullptr)
        {
            prev->next = first;
            ListNode *tmp = first->next;
            first->next = last;
            prev = last;
            first = tmp;
            last = last->next;
        }

        if(first != nullptr)
            prev->next = first;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};