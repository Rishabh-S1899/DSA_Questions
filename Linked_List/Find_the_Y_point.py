''' 
Basic solution is using a map and then checking if the node already exists or not.
Time : O(m+n)
Space: O(m+n)

Space efficient solution would be to use 2 pointers, such that if one reaches the end, point it to the start of other list again. This woul;d equalise the length differences and the pointers would meet either at 1 point or at none if no common present.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        temp1=headA
        temp2=headB

        while(temp1!=temp2):
            
            if temp1!=None:
                temp1=temp1.next
            else: temp1=headB
            
            if temp2!=None:
                temp2=temp2.next

            else: temp2=headA
        
        return temp1
# Time Complexity: O(m+n) where m and n are the lengths of the two linked lists.
# Space Complexity: O(1) as we are not using any extra space.
# The algorithm uses two pointers to traverse the linked lists, and they will meet at the intersection point if it exists.