# 디스크 컨트롤러
# 힙

import heapq

def solution(jobs):
    n = len(jobs)
    time = 0
    end = -1
    h = []
    cnt = 0
    answer = 0

    while cnt < n:
        for i in jobs:
            if end<i[0]<=time:
                answer += time - i[0]
                heapq.heappush(h, i[1])
        if len(h) > 0:
            # 대기시간
            answer += len(h)*h[0]
            end = time
            time += heapq.heappop(h)
            cnt +=1
        else:
            time +=1
    return int(answer/n)


    return answer