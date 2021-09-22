/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

// @lc code=start
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int listLength = getListLength(head);
        int eachSize = listLength / k;
        int remain = listLength % k;

        vector<ListNode*> result;
        int subsetCount = 0;
        int subsetSize = 0;

        while(head != nullptr)
        {
            if(subsetSize == 0)
            {
                result.push_back(head);
                subsetCount++;

                subsetSize++;
                head = head->next;
            }
            else if (subsetSize < eachSize)
            {
                head = head->next;
                subsetSize++;
            }
            else if(subsetSize == eachSize)
            {
                if(subsetCount <= remain)
                {
                    head = head->next;
                    subsetSize = 0;
                }
                else
                {
                    subsetSize = 0;
                }
            }
            else
            {
                subsetSize = 0;
            }
        }

        while(subsetCount < k)
        {
            result.push_back(nullptr);
            subsetCount++;
        }

        for(int i = 0; i < result.size(); i++)
        {
            ListNode* node = result[i];

            if(i < remain)
            {
                result[i] = generateNewList(result[i], eachSize + 1);
            }
            else
            {
                result[i] = generateNewList(result[i], eachSize);
            }
        }
        
        return result;
    }

    int getListLength(ListNode* head)
    {
        int count = 0;

        while(head != nullptr)
        {
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* generateNewList(ListNode* node, int size)
    {
        if(size == 0)
        {
            return nullptr;
        }
        else
        {
            // cout << size << endl;

            ListNode* newNode = node;
            ListNode* nextNode = newNode;

            for(int i = 0; i < size - 1; i++)
            {
                // cout << i << endl;
                nextNode = nextNode->next;
            }
            nextNode->next = nullptr;
            return newNode;
        }
    }
};
// @lc code=end

