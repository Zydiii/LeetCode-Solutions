/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(head == NULL)
        {
            newNode->next = newNode;
            return newNode;
        }
        else if(head->next == NULL)
        {
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        else
        {
            Node* first = head->next;
            Node* last = head;
            Node* biggestNode = last;
            while(first != head && !(first->val >= insertVal && last->val <= insertVal))
            {
                last = first;
                first = first->next;
                if(last->val >= biggestNode->val)
                {
                    biggestNode = last;
                }
            }
            if(first->val >= insertVal && last->val <= insertVal)
            {
                last->next = newNode;
                newNode->next = first;
            }
            else
            {
                newNode->next = biggestNode->next;
                biggestNode->next = newNode;
            }
            return head;
        }
    }
};