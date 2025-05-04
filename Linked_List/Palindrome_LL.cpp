/**
One simple way is to convert the linked list to an array and check if the array is a palindrome.
Complexity: O(n) time and O(n) space.

Another way is to reverse the first half of the linked list and compare it with the second half.
Complexity: O(n) time and O(1) space.
 
 */



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
        bool isPalindrome(ListNode* head) {
            if (head->next == nullptr) return true;
            ListNode* slow= head;
            ListNode* fast= head;
            ListNode* prev=nullptr;
            while(fast!=nullptr && fast->next!=nullptr){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            if (fast!=nullptr) slow=slow->next;
            prev->next=nullptr;
            ListNode* newhead=prev;
            ListNode* i=head;
            ListNode* temp=nullptr;
            prev=nullptr;
            while(i!=nullptr){
                temp=i->next;
                i->next=prev;
                prev=i;
                i=temp;
            }
    
            i=newhead;
            temp=slow;
            while(i!=nullptr and temp!=nullptr){
                if (temp->val!=i->val) return false;
                temp=temp->next;
                i=i->next;
            }
            return true;
        }
    };