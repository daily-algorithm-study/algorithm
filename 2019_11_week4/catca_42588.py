from collections import deque

def solution(heights):
    answer1 = []
    answer = []
    lenght = len(heights)
    for i in range(lenght):
        num = heights.pop()
        ans = 0
        for j in range(lenght-i-1):
            if num < heights[j]:
                ans = j+1
        answer1.append(ans)
    lenght1 = len(answer1)
    for i in range(lenght1):
        answer.append(answer1.pop())

    return answer
