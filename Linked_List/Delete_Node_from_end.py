# Basic solution is to find the length of the linked list and then remove the nth element.
# Innovative solution:
# If we maintain the distance 'n' between 2 pointers, then when the ahead pointer reaches the end,
# the behind one will be n-steps behind, i.e., on the node that is to be deleted.
# If we declare the behind pointer one node before head, then it will be before the node that is to be deleted.
# Therefore, we can easily delete the required node.

# Complexity: O(N)

# Code:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Create a dummy node pointing to the head of the list
        dummy = ListNode(0, head)
        temp = dummy
        forward=head
        # Move the head pointer 'n' steps ahead
        for i in range(n):
            forward = forward.next

        # Move both forward and temp pointers until forward reaches the end
        while forward:
            forward = forward.next
            temp = temp.next

        # Remove the nth node from the end by skipping it
        temp.next = temp.next.next

        # Return the updated list starting from the node after dummy
        return dummy.next