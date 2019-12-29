# 카드 게임

def solution(left, right):
    n =len(left)
    s = [[0 for y in range(n+1)] for x in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            if left[i-1] > right[j-1]: 
                s[i][j] = max(s[i-1][j-1], s[i-1][j], s[i][j-1]+right[j-1])
            else:  
                s[i][j] = max(s[i-1][j-1], s[i-1][j])  
    return s[n][n]
