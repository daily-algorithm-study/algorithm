# 소수 찾기
# 숫자 조합 후 소수 찾기
# 숫자 조합은 itertools의 permutations 모듈로 쉽게 조합 가능

import itertools

def solution(numbers):
    cnt = 0
    lists = []
    lists2 = []
    # 숫자 조합
    for i in range(1, len(numbers)+1):
        b = itertools.permutations(numbers, i)
        for p in b:
            lists.append(p)
    for i in lists:
        a = ('').join(i)
        lists2.append(int(a))
    lists2 = list(set(lists2))
    lists2.sort()
    
    # 소수 찾기
    for j in lists2:
        if j < 2:
            pass
        elif j == 2:
            cnt += 1
        else:
            for k in range(2, j):
                if j % k == 0:
                    break
                # 자기 자신만 있는 경우
                elif k == j-1:
                    cnt +=1
    return cnt
