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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) return head;

        ListNode* first = head;
        ListNode* result = head;

        while (1)
        {
            result = result->next;
            first = first->next;
            if (first->next == nullptr) return result;
            first = first->next;
            if (first->next == nullptr) return result;
        }
    }
};

