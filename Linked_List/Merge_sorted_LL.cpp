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
            if(list1==nullptr) return list2;
            if(list2==nullptr) return list1;
            ListNode* p1=list1;
            ListNode* p2=list2;
            ListNode* list_ptr=nullptr;
            ListNode* newhead=nullptr;
            if(list1->val >list2->val){
                newhead=list2;
                p2=list2->next;
            }
            else{
                newhead=list1;
                p1=list1->next;
            } 
            list_ptr=newhead;
            while(p1 != nullptr && p2 != nullptr){
                if(p2->val <= p1->val){
                    list_ptr->next=p2;
                    
                    p2=p2->next;
                }
                else{
                    list_ptr->next=p1;
                    p1=p1->next;
                }
                list_ptr=list_ptr->next;
            }
            while(p1 != nullptr){
                list_ptr->next = p1;
                list_ptr=list_ptr->next;
                p1=p1->next;
            }
            while(p2 != nullptr){
                list_ptr->next = p2;
                list_ptr=list_ptr->next;
                p2=p2->next;
            }
    
            return newhead;
        }
    };


// Time Complexity: O(n+m) where n and m are the lengths of the two lists
// Space Complexity: O(1) as we are not using any extra space
// The logic is simple, we keep 2 pointers p1 and p2 for the two lists. We compare the values of the nodes pointed by p1 and p2.
// We add the smaller node to the new list and move the pointer of that list to the next node. We repeat this process until we reach the end of one of the lists.