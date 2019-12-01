#디스크 컨트롤러
#힙
import heapq
def solution(jobs):
    lenght = len(jobs)
    time, end, queue = 0, -1, []
    count = 0
    answer = 0
    while count < lenght:
        for i in jobs:
            if end < i[0] <= time:
                answer += (time - i[0])
                heapq.heappush(queue, i[1])
        if len(queue) > 0:
            answer += len(queue) * queue[0]
            end = time
            time += heapq.heappop(queue)
            count += 1
        else:
            time += 1
    
    return (answer//lenght)
