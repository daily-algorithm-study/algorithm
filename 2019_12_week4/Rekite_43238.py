#이분 탐색

def solution(n, times):
    l = 0
    r = max(times)*n
    md = []
    while l <= r:
        m = (l+r)//2
        cnt = 0
        for i in range(len(times)):
            cnt += m // times[i]
            if cnt == n:
                md.append(m)
                r = m-1
                break
            elif cnt > n:
                md.append(m)
                r = m-1
                break
        if cnt > n:
            r = m-1
        if cnt < n:
            l = m+1
            
    return min(md)
