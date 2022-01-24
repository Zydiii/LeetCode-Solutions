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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);
        return reverseList(addList(r1, r2));
    }

    ListNode* addList(ListNode* r1, ListNode* r2)
    {
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        ListNode* cur = dummy;
        while(r1 != nullptr || r2 != nullptr)
        {
            int val1 = r1 == nullptr ? 0 : r1->val;
            int val2 = r2 == nullptr ? 0 : r2->val;
            int sum = val1 + val2 + carry;
            
            carry = sum >= 10 ? 1 : 0;
            sum = carry == 0 ? sum : sum - 10;
            cur->next = new ListNode(sum);
            cur = cur->next;

            r1 = r1 == nullptr ? nullptr : r1->next;
            r2 = r2 == nullptr ? nullptr : r2->next;
        }

        if(carry != 0)
        {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
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