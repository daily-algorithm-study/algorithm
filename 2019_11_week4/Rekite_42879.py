#도둑질
#dp
def solution(money):
    sel = [money[0], money[0]] # 첫번째 집 선택
    sel2 = [0, money[1]] # 첫번째 집 선택x

    for i in range(2, len(money)-1):
        sel.append(max(sel[i-2]+money[i], sel[i-1]))

    for i in range(2, len(money)):
        sel2.append(max(sel2[i-2]+money[i], sel2[i-1]))

    return max(sel[-1], sel2[-1])

if __name__ == "__main__":
    a = solution([1, 2, 3, 1])
    print(a)