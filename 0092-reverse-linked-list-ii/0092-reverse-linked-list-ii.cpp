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
    ListNode* reverseBetween(ListNode* list, int left, int right) {
    int count{ 1 };
    ListNode* current = list;

    ListNode* node_before_left = nullptr;
    ListNode* middle_list = nullptr;
    ListNode* middle_tail = nullptr;
    ListNode* after_right = nullptr;


    if (left == 1) {
        middle_list = list;
    }

    while (current != nullptr) {
        if (count == left - 1) {
            node_before_left = current;
            middle_list = current->next;
            // node_before_left->next = nullptr;
        }
        else if (count == right) {
            // 2, 3, 4, 5
            // 2, null
            // 3, 4, 5
            // 3, 2, null
            // 4, 5
            //
            after_right = current->next;

            middle_tail = current;
            middle_tail->next = nullptr;

            ListNode* next_noda = nullptr;
            ListNode* reverse_list = nullptr;
            ListNode* curr = middle_list;
            ListNode* tail = middle_list;
            while (curr != nullptr) {
                next_noda = curr->next;
                curr->next = reverse_list;
                reverse_list = curr;
                curr = next_noda;
            }
            middle_list = reverse_list;

            if (node_before_left != nullptr)
                node_before_left->next = middle_list;
            tail->next = after_right;

            break;
        }
        current = current->next;
        count++;
    }

    return left == 1 ? middle_list : list;
    }
};