#나누어서 떨어지면 answer 리스트에 추가하기

def solution(arr, divisor):
    answer = []
    for i in arr:
        if i%divisor==0:
            answer.append(i)
    
    if len(answer)!=0:
        answer.sort()
    else:
        answer.append(-1)
    return answer
