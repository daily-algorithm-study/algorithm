#연속되는 수를 판별하여 최초의 수는 answer에 담지만 최초의 수 이후의 연속되는 같은 수는 담지 않도록 제어함 
def solution(arr):
    answer = []
    def check(a):
        if len(answer)!=0:
            if a == answer[len(answer)-1]:
                return True
            else:
                return False
        else:
            return False

    for i in arr:
        if check(i)==True:
            continue
        if check(i)==False:
            answer.append(i)
            continue
    #answer.reverse()
    return answer
