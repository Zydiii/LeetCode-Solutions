/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = listSize(headA);
        int sizeB = listSize(headB);

        bool flag = sizeA > sizeB;
        int delta = flag ? sizeA - sizeB : sizeB - sizeA;

        ListNode *p1 = flag ? headA : headB;
        for(int i = 0; i < delta; i++)
        {
            p1 = p1->next;
        }
        ListNode *p2 = flag ? headB : headA;

        while(p1 != p2 && p1 != nullptr && p2 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }

    int listSize(ListNode* node)
    {
        int count = 0;
        while(node != nullptr)
        {
            count++;
            node = node->next;
        }
        return count;
    }
};