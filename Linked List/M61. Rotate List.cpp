// https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

// Runtime Beats: 100.00%        Memory Beats: 31.20%

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;

        int size = 1;
        ListNode* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
            size++;
        }

        if (k % size == 0)
            return head;

        k %= size;
        temp->next = head;
        temp = head;

        while (--size != k)
            temp = temp->next;

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};