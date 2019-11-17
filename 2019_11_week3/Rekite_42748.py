# k번째 수 (정렬)
def solution(array, commands):
    answer = []
    for i in range(len(commands)):
        a = commands[i][0]
        b = commands[i][1]
        c = commands[i][2]

        s = array[a-1:b]
        s.sort()
        answer.append(s[c - 1])

    return answer

if __name__ == "__main__":
    a = solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]])
    print(a)