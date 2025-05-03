'''
Logic is simple, do reversals in K-groups. Basically count total number of nodes in that LL and then after every iteration subtract k from it, so in this way it will run only until whole k-sized groups are present. 
Now just simply run a 1->k loop inside the while count>=k loop function and use list reversal logic  . At the end, just put prev in the last node (or the first before loop ) and curr to be the first node of new group 
'''
#Code:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Handle edge cases
        if not head or not head.next or k == 1:
            return head
        
        # Create a dummy node to simplify edge cases
        dummy = ListNode(0)
        dummy.next = head
        
        # Initialize pointers
        prev = dummy  # Points to the node before the current group
        curr = head   # Current node to process
        
        # Count total nodes
        count = 0
        temp = head
        while temp:
            count += 1
            temp = temp.next
        
        # Process each group
        while count >= k:
            # Reverse k nodes
            curr = prev.next  # First node of the group
            next_node = curr.next  # Second node of the group
            
            # Reverse k-1 links in the group
            for i in range(1, k):
                curr.next = next_node.next
                next_node.next = prev.next
                prev.next = next_node
                next_node = curr.next
            
            # Move prev to the last node of the current group (which is now curr)
            prev = curr
            
            # Decrease count by k
            count -= k
        
        return dummy.next 