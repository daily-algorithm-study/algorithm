#같은 숫자는 싫어
def solution(arr):
    answer = []
    answer.append(arr[0])
    cnt = 0
    for n in arr:
        if n != answer[cnt]:
            answer.append(n)
            cnt += 1
    return answer
