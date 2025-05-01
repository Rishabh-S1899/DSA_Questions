# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None: return None
        if head.next==None: return head
        temp=ListNode()
        i=head
        prev=None
        while i.next!=None:
            i=i.next
        new_head=i
        i=head
        while i!=None:
            temp=i.next
            i.next=prev
            prev=i
            i=temp

        return new_head