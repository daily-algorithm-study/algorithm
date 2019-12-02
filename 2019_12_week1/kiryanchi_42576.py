# 완주하지 못 한 선수
# remove 사용 시 정확성은 높으나 O[N^2]이 되어 효율성에서 떨어진다.

def solution(participant, completion):
    
    # 둘을 정렬한 후
    participant.sort()
    completion.sort()
    
    # participant 와 completion 을 각각 비교하는데 이 때, len(completion) = len(participant) - 1 이므로
    # 같지 않다면 같지 않은 participant 를 return 하며
    for (i, j) in zip(participant, completion):
        if (i != j):
            return i
            
    # participant 와 completion 이 모두 같다면 participant의 마지막 값을 return 해준다.
    return participant[-1]
