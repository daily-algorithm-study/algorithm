def solution(n, computers):
    num = 0
    bfs = []
    visited = [0]*n

    while 0 in visited:
        a = visited.index(0)
        bfs.append(a)
        visited[0] = 1

        while bfs:
            no = bfs.pop(0)

            for i in range(n):
                if visited[i] ==0:
                    if computers[no][i] == 1:
                        bfs.append(i)
                        visited[i] = 1
        num += 1

    return num