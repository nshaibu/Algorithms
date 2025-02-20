import typing


def two_sums(nums: typing.List[int], target: int) -> typing.Tuple[int, int]:
    visited = {}
    
    for index, element in enumerate(nums):
        sub_target = abs(target - element)
        if sub_target in visited:
            return index, visited[sub_target]
        else:
            visited[element] = index


if __name__ == '__main__':
    print(two_sums([3, 4, 7, 8, 4, 8], 10))
