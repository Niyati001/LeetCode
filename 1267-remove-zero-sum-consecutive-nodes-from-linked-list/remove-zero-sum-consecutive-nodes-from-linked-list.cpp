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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> mp;
        int prefixSum = 0;

        // Pass 1: Store the last node for each prefix sum
        for (ListNode* curr = &dummy; curr != nullptr; curr = curr->next){
            prefixSum += curr->val;
            mp[prefixSum] = curr;
        }

        // Pass 2: Skip zero-sum sequences
        prefixSum = 0;

        for (ListNode* curr = &dummy; curr != nullptr; curr = curr->next){
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
        }

        return dummy.next;
    }
};
