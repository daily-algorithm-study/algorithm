from collections import deque
def solution(prices):
    prices = deque(prices)
    answer = []
    for i in range(len(prices)):
        count = 0
        num = prices.popleft()
        for i in prices:
            if num > i:
                count += 1
                break
            count += 1
        answer.append(count)
        
    return answer
