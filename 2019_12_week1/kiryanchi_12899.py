# 3진법에서 개념을 따온 형태

def solution(n):
    number = ('1', '2', '4')
    answer = ''

    while n>0:
        n -= 1
        answer = number[n % 3] + answer
        n //= 3
        
    return answer
    
# 반성할 점
#   1. 너무 숫자에 혈안이 돼 숫자를 문자로 생각하지 못 했던 점
