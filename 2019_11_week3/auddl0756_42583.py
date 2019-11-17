# solution 함수의 매개변수로 다리 길이 bridge_length,
#  다리가 견딜 수 있는 무게 weight, 트럭별 무게 truck_weights가
#  주어집니다. 이때 모든 트럭이 다리를 건너려면 최소 몇 초가
# 걸리는지 return 하도록 solution 함수를 완성하세요.

# 다리를 queue로 형상화. 1초 마다 체크
# 참고 : https://mentha2.tistory.com/16

def solution(bridge_length, weight, truck_weights):
    q=[0]*bridge_length
    ans=0
    sumq = 0
    while q:
        ans+=1
        sumq-=q[0]
        q.pop(0)
        if truck_weights:
            if sumq+truck_weights[0]<=weight:
                sumq += truck_weights[0]
                q.append(truck_weights.pop(0))
            else:
                q.append(0)
    return ans


#[first: error code]
# def solution(bridge_length, weight, truck_weights):
#     answer = 0
#     #is_full=False
#     sum_t=0
#     print("len:",len(truck_weights))
#     for i in range(0,len(truck_weights)):
#         sum_t+=truck_weights[i]
#         if sum_t<=weight:       #entered
#             answer+=1
#             continue
#         else:                   #already full.
#             #sum_t-=truck_weights[i]
#             answer+=bridge_length
#             #answer+=1
#             sum_t=truck_weights[i]
#             continue
#     else:
#         answer += bridge_length
#     return answer
