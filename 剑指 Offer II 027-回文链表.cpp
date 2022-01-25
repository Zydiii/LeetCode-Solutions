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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *last = slow->next;
        if(fast->next != nullptr)
        {
            last = last->next;
        }
        slow->next = nullptr;

        return equalList(head, reverseList(last));
    }

    bool equalList(ListNode* node1, ListNode* node2)
    {
        while(node1 != nullptr && node2 != nullptr)
        {
            if(node1->val != node2->val)
                return false;
            node1 = node1->next;
            node2 = node2->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode* head)
    {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while(cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};