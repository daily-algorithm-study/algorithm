class Solution {
    public int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        
        answer[0] = 0;

        for (int i = 1; i < heights.length; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (heights[j]>heights[i]){
                    answer[i] = j+1;
                    break;
                }
            }
            
        }
        
        return answer;
    }
}
