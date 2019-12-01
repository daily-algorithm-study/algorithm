def fact(n):
    if n == 1:
        return 1
    return n* fact(n-1)

def solution(n):
    return fact(2*n)/(fact(n+1) * fact(n))
