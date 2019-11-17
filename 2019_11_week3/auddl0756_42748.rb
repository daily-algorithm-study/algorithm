#array의 commands[i][0]-1번째부터 commands[i][1]-1번째까지 자르고 정렬하면 arr2입니다.
#arr2 배열의 commands[i][2]-1번째 숫자는 answer배열에 추가됩니다.


def solution(array, commands)
  answer = []
  arr2=[]
  i=0
  while i<commands.length
    arr2 = array[commands[i][0]-1 ..commands[i][1]-1].sort!
    answer.push(arr2[commands[i][2]-1])
    i+=1
  end
  return answer
end

