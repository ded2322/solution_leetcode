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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Сложность по времени O(n), сложность по памяти O(n + k )
        ListNode* output_list = new ListNode(0);
        ListNode* current_output_list = output_list;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val == list2->val) {
                ListNode* next1 = list1->next;
                ListNode* next2 = list2->next;

                current_output_list->next = list1;
                current_output_list = current_output_list->next;
                current_output_list->next = list2;

                current_output_list = current_output_list->next;
                list1 = next1;
                list2 = next2;
            }
            else if (list1->val < list2->val) {
                current_output_list->next = list1;
                list1 = list1->next;
                current_output_list = current_output_list->next;
            }
            else {
                current_output_list->next = list2;
                list2 = list2->next;
                current_output_list = current_output_list->next;
            }
        }

        if (list1 != nullptr) current_output_list->next = list1;
        if (list2 != nullptr) current_output_list->next = list2;
        return output_list->next;
    }
};