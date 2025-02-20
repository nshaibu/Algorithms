import typing


class Node(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @classmethod
    def initialize(cls, nums: typing.List[int]):
        head = Node()
        node = head
        for element in nums:
            node.val = element
            node.next = Node(val=-1)
            node = node.next
        return head

    @staticmethod
    def show(node: "Node"):
        nums = []
        while node and node.val >= 0:
            nums.append(node.val)
            node = node.next
        return nums


def add_two_numbers(
    l1: typing.Optional[Node], l2: typing.Optional[Node]
) -> typing.Optional[Node]:
    head = Node()
    node = head

    carry_over = 0
    l1_val = l1.val
    l2_val = l2.val

    while l2 or l1:
        carry_over, node.val = divmod(l2_val + l1_val + carry_over, 10)
        node.next = Node(val=-1)

        l2 = l2.next if l2.next and l2.next.val >= 0 else None
        l1 = l1.next if l1.next and l1.next.val >= 0 else None

        l1_val = l1.val if l1 else 0
        l2_val = l2.val if l2 else 0
        node = node.next

    if carry_over != 0:
        node.val = carry_over

    return head


if __name__ == "__main__":
    l1 = Node.initialize([2, 4, 10])
    l2 = Node.initialize([5, 6, 4])

    l3 = add_two_numbers(l1, l2)

    print(Node.show(l1))
    print(Node.show(l2))
    print(Node.show(l3))
