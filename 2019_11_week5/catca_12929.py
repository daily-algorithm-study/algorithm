#올바른 괄호의 갯수

def solution(n): 
    def factorial(n): 
        if n == 1: return 1 
        return n* factorial(n-1)
    return factorial(2*n) / (factorial(n+1) * factorial(n))
