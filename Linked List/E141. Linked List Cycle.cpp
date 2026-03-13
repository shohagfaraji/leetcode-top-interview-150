// https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 97.47%        Memory Beats: 22.25%

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
    bool hasCycle(ListNode* head) {
        while (head) {
            if (head->val == 9999999)
                return true;
            head->val = 9999999;
            head = head->next;
        }
        return false;
    }
};