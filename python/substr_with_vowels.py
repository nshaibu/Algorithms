"""
Number of lowercase 3 character length sub strings with exactly 2 vowels
"""

vowels = ["a", "e", "i", "o", "u"]


def solution(text: str) -> int:
    count = 0
    num_groups = len(text) // 3
    start = 0

    for _ in range(num_groups):
        end = start + 3
        sub_str = text[start:end]
        num = len([ch for ch in sub_str if ch in vowels])
        if num == 2:
            count += 1
        start = end
    return count


if __name__ == '__main__':
    assert(solution("aobide") == 2)
    assert(solution("aobidetyuityorevghtyet") == 3)
