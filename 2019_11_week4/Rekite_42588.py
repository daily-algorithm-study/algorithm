# 탑
# 스택 pop을 이용해 왼쪽부터 오른쪽 제거
def solution(heights):
    answer = [0] * len(heights)
    while heights:
        tower = heights.pop()
        for i in range(len(heights)-1, -1, -1):
            if heights[i] > tower:
                answer[len(heights)] = i+1
                break
    return answer