def solution(money):
    answer = 0
    length = len(money)
    dp = [[0]*2 for i in range(length)]
    
    #첫번째 집부터 털었을 때
    dp[0][0] = money[0]
    dp[1][0] = money[0]
    for i in range(2, length - 1):
        dp[i][0] = max(dp[i-2][0] + money[i], dp[i-1][0])

    #두번째 집부터 털었을 때
    dp[0][1] = 0
    dp[1][1] = money[1]
    for i in range(2, length):
        dp[i][1] = max(dp[i-2][1] + money[i], dp[i-1][1])
     
    return max(dp[length-2][0], dp[length-1][1])
