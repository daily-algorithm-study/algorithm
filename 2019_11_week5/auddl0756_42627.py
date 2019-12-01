#참고 :https://one-step-a-day.tistory.com/60
#푼 방식:
#         0. 처리할 수 있는 작업 중 가장 짧은 작업부터 처리하는 것이 가장 빨리 처리할 수 있는 방식이라고 함.
#         1. 큐에 작업을 시간 순으로 정렬해서 넣기
#         2. 큐에서 현재 처리할 수 있는 작업들을 a_jobs로 모두 옮김.
#         3. a_jobs에 작업이 있으면 짧은 길이 순으로 정렬하고 가장 짧은 작업을 실행하고 시간 추가.
#         4. 위 작업을 반복함.
def solution(jobs):
    answer=0
    t=0
    t_spent=[]
    a_jobs=[]
    #heapq.heapify(jobs)
    q=[]
    for i in jobs:
        q.append(i)
    #print(q)
    q.sort()
    #print(q)
    while(q):
        while(q and q[0][0] <t+1):
            print("q[0][0]:", q[0][0])
            a_jobs.append(q.pop(0))

           # print("ajobs: ",a_jobs)
        if(a_jobs):
            a_jobs.sort(reverse=True,key=lambda x:x[1])
            work=a_jobs.pop()
            t+=work[1]
            print("work :",work)
            t_spent.append(t-work[0])
           # print("tspent",t_spent)
        else:
            t+=1

    while(a_jobs):
        work=a_jobs.pop()
        t+=work[1]
        t_spent.append(t-work[0])

    answer=int(sum(t_spent)/len(t_spent))

    return answer
