from itertools import permutations
import math

def solution(numbers):
    answer = 0
    flag = 1
    arr = list(set(map(int, [''.join(j) for i in range(len(numbers)) for j in permutations(numbers, i+1)])))
    for i in arr:
        if i != 0 and i != 1:
            flag = 1
            for j in range(2, int(math.sqrt(i))+1):
                if i % j == 0:
                    flag = 0
            if flag == 1:
                answer += 1
        
    return answer
