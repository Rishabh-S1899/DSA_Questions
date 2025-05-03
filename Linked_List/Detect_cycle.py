# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Initialize two pointers, fast and slow, both starting at the head of the linked list
        fast = head
        slow = head

        # Traverse the linked list
        while fast is not None and fast.next is not None:
            # Move the fast pointer two steps ahead
            fast = fast.next.next
            # Move the slow pointer one step ahead
            slow = slow.next
            # If the fast and slow pointers meet, a cycle is detected
            if slow == fast:
                return True
        
        # If the loop ends, no cycle is present in the linked list
        return False