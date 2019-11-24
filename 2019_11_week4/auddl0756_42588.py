# 가장 오른쪽에서 좌측으로 가며 수신한 각 송신탑을 answer 리스트 마지막에 insert

def solution(heights):
    answer = []

    i=len(heights)-1
    j=i
    while i>=0:
        j=i
        while j>0:
             j-=1
             if heights[i] <heights[j]:
                answer.insert(0,j+1)
                break
        else:
            answer.insert(0,0)
        i-=1
    return answer
