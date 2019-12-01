# 나누어 떨어지는 숫자 배열 (연습 문제)
# return sorted([n for n in arr if n%divisor ==0]) or [-1]) 한 줄
def solution(arr, divisor):
    answer = [-1]
    for i in range(len(arr)):
        if arr[i] % divisor == 0:
            answer.append(arr[i])
            if -1 in answer:
                answer.remove(-1)
    answer.sort()
    return answer