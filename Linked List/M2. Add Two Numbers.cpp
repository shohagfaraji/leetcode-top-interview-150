// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

// Runtime Beats: 100.00%        Memory Beats: 12.65%

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
        ListNode* sum = new ListNode();
        ListNode* curr = sum;

        while (l1 && l2) {
            curr->val = (l1->val + l2->val);

            if (l1->next != nullptr) {
                l1->next->val += (curr->val / 10);
            } else if (l2->next != nullptr) {
                l2->next->val += (curr->val / 10);
            } else {
                if (curr->val > 9) {
                    ListNode* temp = new ListNode(curr->val / 10);
                    curr->val %= 10;
                    curr->next = temp;
                    return sum;
                }
            }

            curr->val %= 10;

            l1 = l1->next;
            l2 = l2->next;

            if (l1 && l2) {
                ListNode* temp = new ListNode();
                curr->next = temp;
                curr = curr->next;
            }
        }

        if (!l2) {
            while (l1) {
                ListNode* temp = new ListNode();
                curr->next = temp;
                curr = curr->next;

                if (l1->val > 9) {
                    curr->val = (l1->val % 10);
                    if (l1->next != nullptr) {
                        l1->next->val += (l1->val / 10);
                        l1 = l1->next;
                    } else {
                        ListNode* temp = new ListNode(l1->val / 10);
                        curr->next = temp;
                        curr = curr->next;
                        break;
                    }
                } else {
                    curr->val = l1->val;
                    l1 = l1->next;
                }
            }
        } else {
            while (l2) {
                ListNode* temp = new ListNode();
                curr->next = temp;
                curr = curr->next;

                if (l2->val > 9) {
                    curr->val = (l2->val % 10);
                    if (l2->next != nullptr) {
                        l2->next->val += (l2->val / 10);
                        l2 = l2->next;
                    } else {
                        ListNode* temp = new ListNode(l2->val / 10);
                        curr->next = temp;
                        curr = curr->next;
                        break;
                    }
                } else {
                    curr->val = l2->val;
                    l2 = l2->next;
                }
            }
        }

        return sum;
    }
};