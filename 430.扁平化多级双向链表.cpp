/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
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
    vector<Node*> v;

public:
    Node* flatten(Node* head) {
        dfs(head);

        int size = v.size();
        
        for(int i = 0;i < size;i++){
            if(i + 1 < size) 
                v[i]->next = v[i+1];
            if(i > 0) 
                v[i]->prev = v[i-1];
            v[i]->child = nullptr;
        }
        return head;
    }

    void dfs(Node* head){
        if(head==nullptr) 
            return;
        v.push_back(head);
        dfs(head->child);
        dfs(head->next);
    }
};
// @lc code=end

