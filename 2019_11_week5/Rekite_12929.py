# 올바른 괄호의 개수
# 참고, 카탈란 수
from math import factorial as f

def solution(n):
    return f(2*n)//(f(n)*f(n+1))