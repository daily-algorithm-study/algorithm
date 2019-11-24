# N으로 표현
# 3주차에 4주차 3단계 문제 풀어서 4주차에 3주차 문제 풉니다
def solution(N, number):
    s = [{N}]
    for i in range(2, 9):
        a = [int(str(N)*i)]
        for idx in range(int(i/2)):
            for x in s[idx]:
                for y in s[i-idx-2]:
                    a.append(x+y)
                    a.append(x-y)
                    a.append(y-x)
                    a.append(x*y)
                    if x!=0: a.append(y//x)
                    if y!=0: a.append(x//y)
        if number in a:
            return i
        s.append(a)
    return -1

if __name__ == "__main__":
    a = solution(5, 12)
    print(a)