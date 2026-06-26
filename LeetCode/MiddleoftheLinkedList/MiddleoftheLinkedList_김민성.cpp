class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};
// 배열 이용한 방식
// 연결리스트 모든 노드 주소를 vector에 저장하고 그 배열의 인덱스를 사용해서 중간값 찾아냄
// 시간 O(N), 공간  O(N)



// 투포인터 방식
// 토끼와 거북이(저번주에 설명한거) 방식
// 두개의 포인터가 이동하는 속도 차이를 이용한거다.
// slow 포인터는 한번에 한칸씩 fast 포인터는 한번에 두칸씩 이동해서 두배 빠른 fast가 리스트의 끝에 도달했을떄 절반속도로 이동한 slow는 
// 정확히 리스트의 중간지점에 도착해있는것을 이용한 방법
// 시간 O(N), 공간 O(1)
// 그래서 토끼와 거북이 방식이 좋다.(보통 링크드리스트면 이방식)
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while ((fast != NULL) && (fast->next != NULL)) 
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };
