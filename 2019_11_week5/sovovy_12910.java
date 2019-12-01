import java.util.ArrayList;
import java.util.Arrays;

class Solution {
  public int[] solution(int[] arr, int divisor) {
      
        ArrayList<Integer> tmp = new ArrayList<>();
        
        for (int a: arr) {
            if (a % divisor == 0) {
                tmp.add(a);
            }
        }
        
        if (tmp.size() == 0)
            return new int[]{-1};

        int[] answer = new int[tmp.size()];

        for (int i = 0; i < answer.length; i++) {
            answer[i] = tmp.get(i);
        }
      
        Arrays.sort(answer);
        return answer;
        
        // 한줄 코드
        // return Arrays.stream(arr).filter(i-> i%divisor==0).toArray();
  }
}
