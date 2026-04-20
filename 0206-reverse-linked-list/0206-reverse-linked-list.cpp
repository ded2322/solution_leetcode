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
    ListNode* reverseList(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* current_noda = head;
        ListNode* previos_noda = nullptr;

        while (current_noda != nullptr) {
            next = current_noda->next;
            current_noda->next = previos_noda;
            previos_noda = current_noda;
            current_noda = next;
        }
        return previos_noda;
    }
};