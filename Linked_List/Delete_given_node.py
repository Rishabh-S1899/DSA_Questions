'''Since we do not have the backward access to given node, we swap the values with the next node and then delete that one, since they have just requested that we need to remove the value from the array and not the exact node address.'''
#Code:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val= node.next.val
        node.next=node.next.next
        