def solution(s):
    answer = ''
    slice = len(s)//2
    if (len(s) % 2) == 1 : answer = s[slice]
    else: answer = s[slice-1:slice+1]
    return answer
