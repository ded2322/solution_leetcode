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
    bool hasCycle(ListNode *head) {
            ListNode* first_position = head;
        ListNode* past_position = head;

        while (first_position != nullptr 
            && first_position->next != nullptr && first_position->next->next != nullptr) {

            first_position = first_position->next->next;
            past_position = past_position->next;

            if (first_position == past_position) return true;
        }
        
        return false;
    }
};