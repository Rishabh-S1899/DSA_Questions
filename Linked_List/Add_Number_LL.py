# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p1=l1
        p2=l2
        sum_val=l1.val+l2.val
        carry=0
        if(sum_val//10):
            sum_val=sum_val%10
            carry=1
        new_head=ListNode(sum_val,None)
        p1=l1.next
        p2=l2.next
        prevnode=new_head
        while(p1!=None and p2!=None):
            sum_val=p1.val+p2.val+carry
            carry=0
            if(sum_val//10):
                # print(sum_val)
                sum_val=sum_val%10
                carry=1            
            temp=ListNode(sum_val,None)
            prevnode.next=temp
            prevnode=temp
            p1=p1.next
            p2=p2.next
        while(p1!=None):
            sum_val=p1.val+carry
            carry=0
            if (sum_val//10):
                sum_val=sum_val%10
                carry=1
            temp=ListNode(sum_val,None)
            prevnode.next=temp
            prevnode=temp
            p1=p1.next
        
        while(p2!=None):
            sum_val=p2.val+carry
            carry=0
            if (sum_val//10):
                # print(sum_val)
                sum_val=sum_val%10
                carry=1
            temp=ListNode(sum_val,None)
            prevnode.next=temp
            prevnode=temp
            p2=p2.next
        
        if carry==1:
            temp=ListNode(1,None)
            prevnode.next=temp
        
        return new_head
    
# The above code is a solution to the problem of adding two numbers represented as linked lists.

# The function `addTwoNumbers` takes two linked lists `l1` and `l2` as input, where each node contains a single digit.
# The digits are stored in reverse order, meaning that the 1's digit is at the head of the list.
# The function returns a new linked list representing the sum of the two numbers.
# The solution iterates through both linked lists, adding the corresponding digits along with any carry from the previous addition.
# If the sum of two digits exceeds 9, it carries over to the next digit.
# The process continues until all digits from both lists are processed.
# If there is still a carry left after processing both lists, a new node with the value of 1 is added to the end of the result list.
# The final result is a linked list representing the sum of the two input numbers, also in reverse order.
# The code handles cases where the two linked lists are of different lengths and ensures that any remaining digits are processed correctly.
# The time complexity of the solution is O(max(m, n)), where m and n are the lengths of the two linked lists.
# The space complexity is O(max(m, n)) as well, since a new linked list is created to store the result.