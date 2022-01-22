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
    ListNode *detectCycle(ListNode *head) {
        ListNode *nodeInLoop = getNodeInLoop(head);
        
        if(nodeInLoop == nullptr)
            return nullptr;

        ListNode *node = head;
        cout << nodeInLoop->val << endl;
        while(node != nodeInLoop)
        {
            node = node->next;
            nodeInLoop = nodeInLoop->next;
        } 
        
        return node;
    }

    ListNode *getNodeInLoop(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head->next;
        ListNode *fast = slow->next;
        while(fast != nullptr && slow != nullptr)
        {
            if(fast == slow)
                return slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr)
                fast = fast->next;
        }
        return nullptr;
    }
};