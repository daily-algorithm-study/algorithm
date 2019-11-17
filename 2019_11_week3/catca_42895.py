answer = 8
def solu(N, number, count, num):
    global answer
    if num == number:
        answer = min(answer, count)
    if count > 8:
        return
    n = 0
    for i in range(0,8-count):
        n = n * 10 + N
        solu(N, number, count + i+1, num + n)
        solu(N, number, count + i+1, num - n)
        solu(N, number, count + i+1, num * n)
        solu(N, number, count + i+1, num / n)


def solution(N, number):
    global answer
    solu(N, number, 0, 0)
    if answer == 9:
        return -1
    return answer
