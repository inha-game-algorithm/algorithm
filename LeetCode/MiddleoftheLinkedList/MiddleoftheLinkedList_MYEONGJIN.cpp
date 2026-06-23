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
        ListNode* two = head;
        while(two && two->next)
        {
            two = two->next->next;
            head = head->next;
        }
        return head;
    }
};

// 투 포인터 기법(Two-Pointer Technique) 중 하나인 '토끼와 거북이(Hare and Tortoise)' 알고리즘 개념을 익히자!

// 다른 지점(1/3, 1/4)로의 응용가능
// while (fast && fast->next && fast->next->next) {
//        fast = fast->next->next->next; // 3칸 이동
//        slow = slow->next;             // 1칸 이동
//    }
//while (fast && fast->next && fast->next->next && fast->next->next->next) {
//        fast = fast->next->next->next->next; // 4칸 이동
//        slow = slow->next;                   // 1칸 이동
//    }

// 비효율적인거 아닌가? -> 같은 주소를 반복적으로 사용하므로 CPU의 캐시 메모리를 극한으로 사용할 수 있음
// O(N)으로 탐색으로 하면서 CPU의 메모리를 극한으로 활용하여 효율적으로 원하는 1/N 지점을 탐색 가능
