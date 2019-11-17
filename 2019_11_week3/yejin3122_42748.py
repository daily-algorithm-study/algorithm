# 정렬
def solution(array, commands):
    answer = []
    cnt = 0
    
    for x,y,z in commands:
        temp = array[x-1:y]
        temp.sort()
        answer.append(temp[z-1])
        cnt += 1
    
    return answer
