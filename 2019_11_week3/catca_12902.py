def solution(n):
    answer = 3
    number = 1
    num = n//2
    if num <= 1: return 3
    for i in range(num - 1):
        answer1 = answer * 3 + number * 2
        number, answer = answer + number, answer1
    
    return answer % 1000000007
