# 42883
# 큰 수 만들기, 탐욕법

def solution(number, k):
    answer = []
    for i, n in enumerate(number):
        while len(answer) > 0 and answer[-1] < n and k > 0:
            answer.pop()
            k-=1
        if k == 0:
            answer += list(number[i:])
            break
        answer.append(n)
    return ''.join(answer[:len(answer)-k])

if __name__ == "__main__":
    a = solution("1924", 2)
    b = solution("1231234", 3)
    c = solution("4177252841", 4)
    print(a)
    print(b)
    print(c)