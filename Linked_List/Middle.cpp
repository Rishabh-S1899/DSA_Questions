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
            if (head->next==nullptr) return head;
            ListNode* fast=head;
            ListNode* slow=head;
            ListNode* mid=nullptr;
            while(fast!=nullptr and fast->next!=nullptr){
                slow=slow->next;
                mid=fast->next;
                fast=mid->next;
            }
            return slow;
        }
    };