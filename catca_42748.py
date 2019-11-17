def solution(array, commands):
    answer = []
    num=[]
    for i in range(len(commands)):
        knife1 = commands[i][0] - 1
        knife2 = commands[i][1]
        num = array[knife1:knife2]
        num.sort()
        number = commands[i][2] 
        number1 = num[number - 1]
        answer.append(number1)
    return answer
