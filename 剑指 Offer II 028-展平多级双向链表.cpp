/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        flattenList(head);
        return head;
    }

    Node* flattenList(Node* head)
    {
        Node* node = head;
        Node* tail = nullptr;

        while(node != nullptr)
        {
            Node* next = node->next;
            if(node->child != nullptr)
            {
                Node* child = node->child;
                Node* childTail = flattenList(child);

                node->child = nullptr;
                node->next = child;
                child->prev = node;
                childTail->next = next;
                if(next != nullptr)
                    next->prev = childTail;
                
                tail = childTail;
            }
            else
                tail = node;
            
            node = next;
        }

        return tail;
        
    }
};